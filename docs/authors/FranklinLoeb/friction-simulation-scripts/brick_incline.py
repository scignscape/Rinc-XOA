"""
brick_incline.py
================
Step 3 of the thought experiment: a BRICK SLIDING down an inclined plane in a
vacuum (no rolling), with sensors embedded in the brick and a laser tracking
it from outside.

WHAT STEPS 1 AND 2 TAUGHT US (marble_incline.py)
------------------------------------------------
  * For a rolling marble, friction does no work. The only loss was rolling
    resistance, and the deviation from ideal was a few micrometres (ppm).
  * That tiny baseline was itself uncertain by a factor of about 100,
    because it depends on a measured material property, not on theory.

WHAT IS DIFFERENT FOR A SLIDING BRICK
-------------------------------------
Sliding friction does work the whole way down. The deviation from the
frictionless case is no longer ppm-sized; it is tens of percent:

      frictionless:   a0 = g sin(theta)
      with friction:  a  = g (sin(theta) - mu_k cos(theta))
      fractional loss of acceleration = mu_k / tan(theta)

So detecting friction is easy. The hard part moves somewhere else: knowing
what mu_k "should" be. mu_k is not a constant of nature. It is an empirical
number that depends on the surfaces, and standard physics cannot calculate
it from first principles for a real pair of surfaces.

PHYSICS ASSUMPTIONS (read these first)
--------------------------------------
1. Rigid rectangular brick, uniform density, sliding on its largest face.
2. Rigid flat plane at fixed angle theta. Uniform gravity g. Vacuum.
3. The brick is already sliding (released with a tiny nudge). It keeps
   sliding only if tan(theta) > mu_k. To START from rest it needs
   tan(theta) > mu_s, the static coefficient, which is larger and unknown.
4. Coulomb friction: friction force = mu_k * N, independent of speed and
   contact area. This is an approximation; section 5 tests how much a
   realistic speed dependence changes the answer.
5. One-dimensional motion straight down the slope. No tipping, no yaw.
6. Heat: all friction work becomes heat at the interface. Each body is
   treated as a thick solid heated at its surface. The share of heat going
   into the brick is estimated from the materials' thermal effusivities;
   this is crude because the plane sees a MOVING heat source.
7. Pressure: the brick and plane are perfectly flat, so the pressure across
   the face varies in a straight line from back to front.

WHAT EACH SENSOR MEASURES
-------------------------
Accelerometer (inside the brick, axes along and normal to the contact face)
    An accelerometer does not feel gravity directly; it feels the contact
    forces. So along the slope it reads  -mu_k g cos(theta)  (friction only)
    and normal to the face it reads  g cos(theta).  Their ratio is mu_k,
    with no need to know g or theta. Its weak point is axis alignment.

Pressure sensors (across the contact face)
    Friction acts at the face, below the centre of mass (height h). To stop
    the brick rotating, the support force must shift FORWARD by e = mu_k * h.
    So pressure is higher at the leading edge:
        p(s) = p_mean * (1 + 12 e s / L^2),  s from -L/2 (rear) to +L/2 (front)
    A frictionless brick would show uniform pressure. The tilt of the
    pressure profile is a second, independent measurement of mu_k.

Temperature sensors (at the contact face)
    Friction power per unit area is  q = mu_k * p * v.  It grows as the
    brick speeds up. The sensors see the AVERAGE ("nominal") surface
    warming, which is small. The true contact happens at microscopic high
    spots, where brief "flash" temperatures are far higher but too small
    and too fast for an embedded sensor to resolve.

Laser (outside)
    Speed and position versus time, as before. Gives a, and so mu_k if g
    and theta are known.

UNKNOWNS (variables to account for later, not assumed away)
-----------------------------------------------------------
Carried over from steps 1 and 2 (still apply):
  wear_rate, surface_roughness, adhesion, plane_flatness, angle_uncertainty,
  g_local, residual_gas, temperature, surface_charge, magnetic_effects,
  release_conditions, laser_effects, vibration, earth_rotation,
  real_contact_area, asperity_plasticity, surface_films, micro_slip

New in step 3:
  mu_k_itself         not predictable from theory; must be measured for the
                      exact surfaces, in vacuum. Table values are typical only.
  mu_s                static coefficient; decides whether sliding starts
  speed_dependence    mu_k changes with sliding speed (usually a few percent
                      per factor of 10 in speed); speed changes during a run
  load_dependence     mu_k can change with pressure (Coulomb's law is approximate)
  running_in          mu_k drifts over the first metres as surfaces wear in
  third_body          wear debris trapped in the contact changes friction
  vacuum_cleaning     in vacuum, oxide and water films are not replaced once
                      worn off; clean metals can seize (cold weld)
  stick_slip          jerky motion instead of smooth sliding
  heat_partition      share of heat entering brick vs. plane (moving source)
  asperity_size       radius of the microscopic contact spots; sets flash
                      temperature; unknown within a factor of 10 or more
  hardness            sets real contact area; varies with alloy and treatment
  flash_softening     hot spots soften, changing mu_k during the run
  thermal_expansion   uneven heating warps the face, changing pressure
  flatness_brick      micrometre-level waviness dominates the real pressure
                      distribution at this light load
  elastic_tilt        the brick and plane are not rigid; edges dig in
  tipping_and_yaw     brick rocking or rotating about the normal
  sensor_intrusion    holes and wires for sensors change the surface and
                      stiffness of the very face being measured
  sensor_depth        a temperature sensor below the surface sees a delayed,
                      weakened signal
  accelerometer_axes  alignment of sensor axes to the contact face
  accelerometer_bias  offset and drift, temperature sensitivity
  sensor_response     response times versus a run lasting under a second
  data_link           wires drag; wireless or onboard logging needed
"""

import math

G = 9.80665  # standard gravity, m/s^2


# ---------------------------------------------------------------------------
# PARAMETERS YOU CAN CHANGE
# ---------------------------------------------------------------------------
PARAMS = dict(
    length=0.100,      # brick length along the slope, metres
    width=0.050,       # brick width across the slope, metres
    height=0.025,      # brick height normal to the slope, metres
    angle_deg=45.0,    # incline angle. Must exceed atan(mu_k) to keep sliding.
    track=1.0,         # sliding distance, metres
    asperity_radius=5e-6,  # radius of a microscopic contact spot, m. UNKNOWN.
    sensor_depth=1e-3,     # how far below the face the temperature sensor sits
)

# Typical handbook-style material values. Replace with measured ones.
MATERIALS = dict(
    #            density  conductivity  heat cap.   hardness
    #            kg/m^3   W/(m K)       J/(kg K)    Pa
    steel=dict(rho=7850, k=50.0, c=490.0, hard=2.0e9),
    glass=dict(rho=2500, k=1.0,  c=840.0, hard=5.5e9),
)

# Kinetic friction coefficients: (low, typical, high). These are typical
# published ranges for dry sliding, NOT measurements of our surfaces.
# The spread inside each range is real: it is the baseline uncertainty.
PAIRS = [
    dict(name="steel on steel, dry, normal surface films",
         brick="steel", plane="steel", mu=(0.30, 0.45, 0.60)),
    dict(name="steel on steel, clean surfaces in vacuum",
         brick="steel", plane="steel", mu=(0.80, 1.20, 3.00)),
    dict(name="glass on steel, dry",
         brick="glass", plane="steel", mu=(0.40, 0.55, 0.70)),
]

# Classical effects that change mu_k, as rough fractional sizes (low, high).
# Order-of-magnitude estimates to be replaced by measurement.
CLASSICAL_UNKNOWNS = [
    ("surface roughness / real contact area",        0.05, 0.30),
    ("adhesion and surface films (worse in vacuum)", 0.20, 3.00),
    ("wear, running-in, trapped debris",             0.10, 0.50),
    ("speed dependence within one run",              0.02, 0.15),
    ("friction heating (hot-spot softening)",        0.001, 0.05),
    ("micro-slip, stick-slip, vibration",            0.01, 0.20),
    ("flatness / uneven pressure / edge loading",    0.01, 0.10),
]
# Repeatability of mu_k between nominally identical runs, after the surfaces
# have been run in and conditions are well controlled (low, high).
REPEATABILITY = (0.02, 0.10)


# ---------------------------------------------------------------------------
# BASIC MODEL
# ---------------------------------------------------------------------------
def brick_properties(p, material):
    """Mass, contact area, and centre-of-mass height for the brick."""
    m = MATERIALS[material]
    volume = p["length"] * p["width"] * p["height"]
    return dict(mass=m["rho"] * volume, area=p["length"] * p["width"],
                h=p["height"] / 2.0)

def accelerations(angle_deg, mu_k):
    """Returns (a_frictionless, a_with_friction). Negative a means it stops."""
    th = math.radians(angle_deg)
    return G * math.sin(th), G * (math.sin(th) - mu_k * math.cos(th))

def run_summary(p, mu_k):
    """Closed-form motion over the track, compared with frictionless."""
    a0, a = accelerations(p["angle_deg"], mu_k)
    L = p["track"]
    t0, v0 = math.sqrt(2 * L / a0), math.sqrt(2 * L * a0)
    if a <= 0:
        return dict(slides=False, a0=a0, a=a, t0=t0, v0=v0)
    t, v = math.sqrt(2 * L / a), math.sqrt(2 * L * a)
    return dict(slides=True, a0=a0, a=a, t0=t0, v0=v0, t=t, v=v,
                loss=1.0 - a / a0,              # fractional loss of acceleration
                lag=L - 0.5 * a * t0 ** 2)      # how far behind when the
                                                # frictionless brick finishes

def effusivity(material):
    """Thermal effusivity sqrt(k rho c): how well a surface soaks up heat."""
    m = MATERIALS[material]
    return math.sqrt(m["k"] * m["rho"] * m["c"])

def sensor_signals(p, pair, mu_k):
    """What each embedded sensor would read, for one material pair and mu_k."""
    th = math.radians(p["angle_deg"])
    bp = brick_properties(p, pair["brick"])
    run = run_summary(p, mu_k)
    N = bp["mass"] * G * math.cos(th)
    p_mean = N / bp["area"]

    # Pressure tilt: support force shifts forward by e = mu_k * h.
    e = mu_k * bp["h"]
    tilt = 6.0 * e / p["length"]            # fractional rise at leading edge

    # Heat. Flux grows linearly with time because speed does: q = mu p v.
    q_end = mu_k * p_mean * run["v"]
    energy = mu_k * N * p["track"]
    e_b, e_p = effusivity(pair["brick"]), effusivity(pair["plane"])
    # Surface warming of a thick solid under a flux rising linearly in time:
    #   dT = q_end * sqrt(t) / (1.329 * effusivity)
    dT_shared = q_end * math.sqrt(run["t"]) / (1.329 * (e_b + e_p))
    dT_all_brick = q_end * math.sqrt(run["t"]) / (1.329 * e_b)
    mb = MATERIALS[pair["brick"]]
    dT_bulk = energy / (bp["mass"] * mb["c"])           # if all heat spread evenly
    kappa = mb["k"] / (mb["rho"] * mb["c"])             # thermal diffusivity

    # Real contact: only microscopic high spots touch. Their total area is
    # about load / hardness of the softer body.
    hard = min(MATERIALS[pair["brick"]]["hard"], MATERIALS[pair["plane"]]["hard"])
    area_real = N / hard
    # Flash temperature at one spot (slow-source formula, heat shared by
    # both bodies):  dT = 8 q r / (3 pi (k1 + k2)),  q = mu * hardness * v
    k_sum = MATERIALS[pair["brick"]]["k"] + MATERIALS[pair["plane"]]["k"]
    def flash(r):
        return 8.0 * (mu_k * hard * run["v"]) * r / (3.0 * math.pi * k_sum)

    return dict(mass=bp["mass"], N=N, p_mean=p_mean, h=bp["h"],
                acc_along=-mu_k * G * math.cos(th), acc_normal=G * math.cos(th),
                e=e, tilt=tilt, p_front=p_mean * (1 + tilt), p_rear=p_mean * (1 - tilt),
                q_end=q_end, energy=energy, dT_shared=dT_shared,
                dT_all_brick=dT_all_brick, dT_bulk=dT_bulk,
                diff_length=math.sqrt(kappa * run["t"]),
                sensor_delay=p["sensor_depth"] ** 2 / kappa,
                area_real=area_real, area_fraction=area_real / bp["area"],
                flash=flash, run=run)


# ---------------------------------------------------------------------------
# TIME-STEPPING SIMULATION (for cases where mu_k is not constant)
# ---------------------------------------------------------------------------
def simulate(p, mu_fn, dt=1e-5):
    """
    Slide the brick down the track with mu_k given by mu_fn(v, x).
    Returns lists t, x, v. Stops at the end of the track or if it halts.
    """
    th = math.radians(p["angle_deg"])
    s, c = math.sin(th), math.cos(th)
    t, x, v = 0.0, 0.0, 1e-6                 # tiny nudge so it is "sliding"
    T, X, V = [t], [x], [v]
    while x < p["track"] and v > 0 and t < 60:
        a = G * (s - mu_fn(v, x) * c)
        v_new = v + a * dt
        x += 0.5 * (v + v_new) * dt
        v = v_new
        t += dt
        T.append(t); X.append(x); V.append(v)
    return T, X, V


# ---------------------------------------------------------------------------
# REPORTS
# ---------------------------------------------------------------------------
def line(char="="):
    print(char * 78)

def report_deviation(p):
    line(); print("1. DEVIATION FROM FRICTIONLESS SLIDING"); line()
    a0, _ = accelerations(p["angle_deg"], 0.0)
    r0 = run_summary(p, 0.0)
    print(f"angle = {p['angle_deg']:.1f} deg, track = {p['track']:.2f} m")
    print(f"frictionless: a = {a0:.3f} m/s^2, time = {r0['t0']:.4f} s, "
          f"final speed = {r0['v0']:.3f} m/s")
    print()
    for pair in PAIRS:
        print(pair["name"])
        print(f"  {'mu_k':>5} | {'accel':>8} | {'accel lost':>10} | {'time':>8} | "
              f"{'end speed':>9} | {'behind by':>9} | keeps sliding above")
        print(f"  {'':>5} | {'(m/s^2)':>8} | {'(%)':>10} | {'(s)':>8} | "
              f"{'(m/s)':>9} | {'(m)':>9} | (deg)")
        print("  " + "-" * 74)
        for mu in pair["mu"]:
            r = run_summary(p, mu)
            min_angle = math.degrees(math.atan(mu))
            if r["slides"]:
                print(f"  {mu:5.2f} | {r['a']:8.3f} | {100 * r['loss']:10.1f} | "
                      f"{r['t']:8.4f} | {r['v']:9.3f} | {r['lag']:9.3f} | {min_angle:.1f}")
            else:
                print(f"  {mu:5.2f} | {'DOES NOT SLIDE at this angle':^55} | {min_angle:.1f}")
        print()
    print("'behind by' = distance behind a frictionless brick at the moment the")
    print("frictionless brick reaches the end of the track.")
    print("Rule: accel lost = mu_k / tan(theta). Compare the marble: about 0.0003 %.")
    print()

    print("Same thing at other angles (steel on steel, mu_k = 0.45):")
    print(f"  {'angle':>6} | {'accel lost (%)':>14}")
    for ang in [30, 35, 45, 60, 75, 85]:
        _, a = accelerations(ang, 0.45)
        a0 = G * math.sin(math.radians(ang))
        txt = f"{100 * (1 - a / a0):14.1f}" if a > 0 else "  does not slide"
        print(f"  {ang:6.0f} | {txt}")
    print()


def report_sensors(p):
    line(); print("2. WHAT THE EMBEDDED SENSORS WOULD READ"); line()
    for pair, mu in [(PAIRS[0], PAIRS[0]["mu"][1]), (PAIRS[2], PAIRS[2]["mu"][1])]:
        s = sensor_signals(p, pair, mu)
        r = s["run"]
        print(f"{pair['name']}, mu_k = {mu:.2f}")
        print(f"  brick mass {s['mass']:.3f} kg, load N = {s['N']:.2f} N, "
              f"run time {r['t']:.3f} s, end speed {r['v']:.2f} m/s")
        print(f"  ACCELEROMETER")
        print(f"    along slope          : {s['acc_along']:+.3f} m/s^2   (friction only)")
        print(f"    normal to face       : {s['acc_normal']:+.3f} m/s^2")
        print(f"    ratio = mu_k         : {-s['acc_along'] / s['acc_normal']:.3f}")
        print(f"  PRESSURE (perfectly flat surfaces assumed)")
        print(f"    mean                 : {s['p_mean']:.0f} Pa")
        print(f"    leading edge         : {s['p_front']:.0f} Pa  (+{100 * s['tilt']:.1f} %)")
        print(f"    trailing edge        : {s['p_rear']:.0f} Pa  (-{100 * s['tilt']:.1f} %)")
        print(f"    support force shift  : {s['e'] * 1e3:.2f} mm forward (= mu_k * h)")
        print(f"  HEAT AND TEMPERATURE")
        print(f"    friction heat, whole run     : {s['energy']:.2f} J")
        print(f"    heating power per area, end  : {s['q_end']:.0f} W/m^2")
        print(f"    face warming, heat shared    : {s['dT_shared'] * 1e3:.1f} mK")
        print(f"    face warming, all into brick : {s['dT_all_brick'] * 1e3:.1f} mK  (upper bound)")
        print(f"    whole-brick average warming  : {s['dT_bulk'] * 1e3:.2f} mK  (upper bound)")
        print(f"    heat soaks in about          : {s['diff_length'] * 1e3:.2f} mm during the run")
        print(f"    sensor {p['sensor_depth'] * 1e3:.1f} mm deep lags by about : "
              f"{s['sensor_delay'] * 1e3:.0f} ms")
        print(f"  MICROSCOPIC CONTACT (not visible to the sensors)")
        print(f"    real contact area            : {s['area_real'] * 1e12:.0f} um^2 "
              f"= {s['area_fraction']:.1e} of the face")
        print(f"    flash temperature at a spot, by spot radius (UNKNOWN):")
        for r_asp in [1e-6, 5e-6, 2e-5]:
            print(f"        radius {r_asp * 1e6:4.0f} um  ->  about {s['flash'](r_asp):6.0f} K")
        print()


def report_precision(p):
    line(); print("3. PRECISION NEEDED TO MEASURE mu_k"); line()
    pair, mu = PAIRS[0], PAIRS[0]["mu"][1]
    s = sensor_signals(p, pair, mu)
    r = s["run"]
    th = math.radians(p["angle_deg"])
    print(f"Case: {pair['name']}, mu_k = {mu:.2f}, angle {p['angle_deg']:.0f} deg.")
    print("Each column: the precision that ONE instrument needs, on its own, to")
    print("pin down mu_k to the target in the first column.")
    print()
    print(f"{'target':>9} | {'acceler-':>9} | {'sensor':>9} | {'incline':>9} | "
          f"{'laser':>9} | {'laser':>9} | {'pressure':>10} | {'temper-':>9}")
    print(f"{'on mu_k':>9} | {'ometer':>9} | {'axis tilt':>9} | {'angle':>9} | "
          f"{'position':>9} | {'timing':>9} | {'front-rear':>10} | {'ature':>9}")
    print(f"{'':>9} | {'(milli-g)':>9} | {'(arcsec)':>9} | {'(arcsec)':>9} | "
          f"{'(um)':>9} | {'(us)':>9} | {'(Pa)':>10} | {'(mK)':>9}")
    print("-" * 95)
    arcsec = math.degrees(1) * 3600
    for frac in [0.10, 0.01, 1e-3, 1e-4, 1e-6]:
        dmu = frac * mu
        d_acc = G * math.cos(th) * dmu                    # accelerometer, m/s^2
        d_axis = dmu / (1 + mu ** 2)                      # sensor axis tilt, rad
        d_theta = dmu / (1 + mu * math.tan(th))           # incline angle, rad
        d_x = p["track"] * d_acc / r["a"]                 # laser position
        d_t = 0.5 * r["t"] * d_acc / r["a"]               # laser timing
        d_p = s["p_mean"] * 12 * s["h"] * dmu / p["length"]   # front-rear difference
        d_T = s["dT_shared"] * frac                       # face temperature
        label = f"{frac * 100:g} %" if frac >= 1e-4 else f"{frac * 1e6:g} ppm"
        print(f"{label:>9} | {d_acc / G * 1e3:9.3g} | {d_axis * arcsec:9.3g} | "
              f"{d_theta * arcsec:9.3g} | {d_x * 1e6:9.3g} | {d_t * 1e6:9.3g} | "
              f"{d_p:10.3g} | {d_T * 1e3:9.3g}")
    print()
    print("Units: milli-g = thousandth of g. arcsec = 1/3600 degree. um = micrometre.")
    print("us = microsecond. mK = thousandth of a kelvin.")
    print("Formulas: d(mu) = d(a)/(g cos)           accelerometer or laser")
    print("          d(mu) = (1 + mu^2) d(tilt)     accelerometer axis alignment")
    print("          d(mu) = (1 + mu tan) d(theta)  incline angle (laser method only)")
    print("          mu    = e / h                  pressure profile")
    print("The temperature column assumes the heat partition is known exactly,")
    print("which it is not, so temperature cannot give mu_k to better than tens of %.")
    print()


def report_classical_floor(p):
    line(); print("4. HOW BIG MUST A DEVIATION BE TO STAND OUT?"); line()
    print("Rough size of each classical effect on mu_k (order of magnitude only):")
    print(f"  {'effect':<46} | {'low':>7} | {'high':>7}")
    print("  " + "-" * 66)
    lo_sq = hi_sq = 0.0
    for name, lo, hi in CLASSICAL_UNKNOWNS:
        print(f"  {name:<46} | {100 * lo:6.1f}% | {100 * hi:6.0f}%")
        lo_sq += lo ** 2; hi_sq += hi ** 2
    lo_tot, hi_tot = math.sqrt(lo_sq), math.sqrt(hi_sq)
    print("  " + "-" * 66)
    print(f"  {'combined (added in quadrature)':<46} | {100 * lo_tot:6.1f}% | {100 * hi_tot:6.0f}%")
    print()
    print("Two different floors:")
    print(f"  (a) PREDICTING mu_k from scratch for new surfaces: uncertain by about")
    print(f"      {100 * lo_tot:.0f} % at best, up to a factor of {1 + hi_tot:.0f} (the table above).")
    print(f"  (b) REPEATING the same run on run-in surfaces, well controlled:")
    print(f"      scatter of about {100 * REPEATABILITY[0]:.0f} % to {100 * REPEATABILITY[1]:.0f} % in mu_k.")
    print()
    mu = PAIRS[0]["mu"][1]
    th = math.radians(p["angle_deg"])
    r = run_summary(p, mu)
    print(f"To stand out at 3 times the scatter (steel on steel, mu_k = {mu:.2f}):")
    print(f"  {'floor':<34} | {'needed shift':>12} | {'in mu_k':>8} | {'in accel':>9} | "
          f"{'at track end':>12}")
    print("  " + "-" * 86)
    rows = [("(b) best-case repeatability", REPEATABILITY[0]),
            ("(b) typical repeatability", REPEATABILITY[1]),
            ("(a) prediction, best case", lo_tot),
            ("(a) prediction, worst case", hi_tot)]
    for label, f in rows:
        shift = 3 * f
        dmu = shift * mu
        d_acc = G * math.cos(th) * dmu
        d_x = p["track"] * d_acc / r["a"]
        print(f"  {label:<34} | {100 * shift:10.0f} % | {dmu:8.3f} | "
              f"{d_acc:7.3f}   | {d_x * 1e3:9.0f} mm")
    print("  ('at track end' = change in distance covered in the nominal run time)")
    print()
    print("Compare with section 3: good instruments can plausibly reach about")
    print("0.01 % of mu_k. The classical scatter (2 % to 300 %) is hundreds to")
    print("tens of thousands of times larger than that.")
    print("Averaging n repeat runs shrinks random scatter by sqrt(n), but not")
    print("drifts such as wear, which move mu_k steadily in one direction.")
    print()


def report_speed_dependence(p):
    line(); print("5. EXAMPLE OF A CLASSICAL UNKNOWN: mu_k THAT CHANGES WITH SPEED"); line()
    mu0 = PAIRS[0]["mu"][1]
    print("Assume mu_k falls by a fixed percentage for every 10-fold rise in speed")
    print(f"(reference: mu_k = {mu0:.2f} at 1 mm/s). Constant-mu result for comparison.")
    print()
    print(f"  {'drop per 10x':>12} | {'run time':>9} | {'end speed':>9} | "
          f"{'mu_k a constant-mu':>18} | {'apparent':>9}")
    print(f"  {'drop per 10x':>12} | {'(s)':>9} | {'(m/s)':>9} | "
          f"{'fit would report':>18} | {'shift':>9}")
    print("  " + "-" * 70)
    th = math.radians(p["angle_deg"])
    for drop in [0.0, 0.02, 0.05, 0.10]:
        def mu_fn(v, x, drop=drop):
            decades = math.log10(max(v, 1e-3) / 1e-3)
            return mu0 * (1.0 - drop * decades)
        T, X, V = simulate(p, mu_fn)
        a_eff = 2 * p["track"] / T[-1] ** 2            # what the laser would infer
        mu_fit = math.tan(th) - a_eff / (G * math.cos(th))
        print(f"  {100 * drop:10.0f} % | {T[-1]:9.4f} | {V[-1]:9.3f} | "
              f"{mu_fit:18.4f} | {100 * (mu_fit / mu0 - 1):+8.1f}%")
    print()
    print("Speed runs from about 1 mm/s to about 3 m/s in one run (over 3 factors")
    print("of 10), so even a 2 % drop per factor of 10 shifts the apparent mu_k by")
    print("about 6 %. It must be measured and modelled before any small anomaly")
    print("could be claimed.")
    print()


def make_plot(p, filename="brick_incline.png"):
    """Optional plot. Skipped quietly if matplotlib is not installed."""
    try:
        import matplotlib
        matplotlib.use("Agg")
        import matplotlib.pyplot as plt
    except ImportError:
        print("(matplotlib not installed, skipping plot)")
        return
    plt.rcParams.update({"font.size": 16, "lines.linewidth": 3})
    fig, ax = plt.subplots(3, 1, figsize=(10, 16))

    styles = [("frictionless", 0.0, "--"), ("mu_k = 0.30", 0.30, "-"),
              ("mu_k = 0.45", 0.45, "-."), ("mu_k = 0.60", 0.60, ":")]
    colors = ["black", "#0072b2", "#d55e00", "#009e73"]
    for (label, mu, sty), col in zip(styles, colors):
        _, a = accelerations(p["angle_deg"], mu)
        t_end = math.sqrt(2 * p["track"] / a)
        ts = [t_end * i / 200 for i in range(201)]
        ax[0].plot(ts, [a * t for t in ts], sty, color=col, label=label)
        ax[1].plot(ts, [0.5 * a * t * t for t in ts], sty, color=col, label=label)
    ax[0].set_title(f"Steel brick sliding on steel, {p['angle_deg']:.0f} degree incline")
    ax[0].set_ylabel("speed (m/s)"); ax[0].set_xlabel("time (s)")
    ax[0].legend(); ax[0].grid(True)
    ax[1].set_ylabel("position (m)"); ax[1].set_xlabel("time (s)")
    ax[1].legend(); ax[1].grid(True)

    L = p["length"]
    for (label, mu, sty), col in zip(styles, colors):
        s = sensor_signals(p, PAIRS[0], mu) if mu > 0 else None
        tilt = s["tilt"] if s else 0.0
        xs = [-L / 2, L / 2]
        ax[2].plot([x * 1e3 for x in xs], [1 - tilt, 1 + tilt], sty, color=col, label=label)
    ax[2].set_xlabel("position along contact face (mm): rear on left, front on right")
    ax[2].set_ylabel("pressure / mean pressure")
    ax[2].set_title("Pressure across the contact face (ideal flat surfaces)")
    ax[2].legend(); ax[2].grid(True)

    fig.tight_layout()
    fig.savefig(filename, dpi=120)
    print(f"Plot saved to {filename}")


if __name__ == "__main__":
    report_deviation(PARAMS)
    report_sensors(PARAMS)
    report_precision(PARAMS)
    report_classical_floor(PARAMS)
    report_speed_dependence(PARAMS)
    make_plot(PARAMS)
