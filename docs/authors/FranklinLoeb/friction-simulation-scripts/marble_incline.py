"""
marble_incline.py
=================
Step 1 of a thought experiment: a solid sphere (marble) on an inclined plane,
in a vacuum, with its speed tracked by a laser.

Question for this step: how far does the marble's motion deviate from ideal
rolling once realistic contact forces are switched on?

PHYSICS ASSUMPTIONS (read these first)
--------------------------------------
1. Rigid, uniform solid sphere: moment of inertia I = (2/5) m R^2.
2. Rigid flat plane at a fixed angle theta. Uniform gravity g.
3. Vacuum: no air drag, no buoyancy.
4. The marble starts at rest, not spinning.
5. Motion is one-dimensional, straight down the slope.

IMPORTANT POINT ABOUT "FRICTIONLESS ROLLING"
--------------------------------------------
Rolling without slipping NEEDS friction: static friction is what makes the
sphere spin. But in perfect rolling the contact point is momentarily at rest,
so that friction does no work and removes no energy. So:

  * Ideal rolling (the reference case):   a = (5/7) g sin(theta)
  * No friction at all (pure sliding):    a = g sin(theta)      [printed for reference]

Changing the friction coefficient mu therefore changes NOTHING while the
marble keeps rolling. A deviation from the ideal case can only come from:

  (A) SLIPPING. If static friction is too weak the marble skids. Rolling
      needs roughly  mu_s >= (2/7) tan(theta).  Kinetic friction mu_k then acts.

  (B) ROLLING RESISTANCE. Real contacts are a small patch, not a point. The
      support force acts slightly ahead of the centre, by a length b, giving
      a retarding torque  tau = b * N.  The dimensionless rolling-resistance
      coefficient is  c_rr = b / R.  This is the term that actually drains
      energy from a rolling marble, and it is where radius enters the model.

Result used as a check on the simulation (rolling regime):

      a = (5/7) g (sin(theta) - c_rr cos(theta))
      fractional speed loss = c_rr / tan(theta) = b / (R tan(theta))

Mass cancels out of every equation in this model. It is kept as a parameter
because real contact physics (deformation, adhesion) will depend on it later.

UNKNOWNS NOT MODELLED YET (variables to account for later, not assumed away)
---------------------------------------------------------------------------
Each of these could change the result and needs its own parameter eventually:

  wear_rate          atoms shed from marble/plane; mu and b drift over time
                     and over repeated runs (hooks below: mu_k_of_t, b_of_t)
  surface_roughness  real surfaces are never perfectly smooth, even polished
  adhesion           van der Waals / Casimir-type attraction at the contact;
                     dominant for very smooth surfaces in vacuum (cold welding)
  elastic_hysteresis Hertz contact deformation; sets b, depends on load,
                     material stiffness, and speed
  b_dependence       b itself probably depends on R, m, speed, temperature
  asphericity        deviation of the marble from a perfect sphere
  density_variation  non-uniform density changes I away from (2/5) m R^2
  plane_flatness     waviness / local slope errors of the plane
  angle_uncertainty  how well theta is known (enters directly via sin(theta))
  g_local            local gravity and its uncertainty
  residual_gas       no real vacuum is perfect
  temperature        thermal expansion, material properties, friction
  surface_charge     electrostatic forces (charging is common in vacuum)
  magnetic_effects   eddy currents if either body conducts
  release_conditions initial push or spin from the release mechanism
  laser_effects      radiation pressure, heating, measurement noise/resolution
  vibration          ground and apparatus vibration
  earth_rotation     Coriolis deflection (tiny, but so is the target effect)
"""

import math

G = 9.80665  # standard gravity, m/s^2


# ---------------------------------------------------------------------------
# PARAMETERS YOU CAN CHANGE
# ---------------------------------------------------------------------------
PARAMS = dict(
    radius=0.010,      # R, metres (1 cm marble)
    mass=0.0105,       # m, kg (glass marble of that size); cancels out here
    angle_deg=10.0,    # incline angle theta, degrees
    mu_s=0.50,         # static friction coefficient (decides IF it slips)
    mu_k=0.40,         # kinetic friction coefficient (acts WHILE slipping)
    b=1.0e-5,          # rolling-resistance length, metres. c_rr = b / R
    t_end=2.0,         # how long to simulate, seconds
    dt=1.0e-4,         # time step, seconds
)

# Hooks for time-dependent contact properties (e.g. wear). By default they
# are constant. Replace them later with functions of time t.
def mu_k_of_t(t, mu_k):
    return mu_k

def b_of_t(t, b):
    return b


# ---------------------------------------------------------------------------
# REFERENCE CASES (closed form)
# ---------------------------------------------------------------------------
def ideal_rolling(t, angle_deg):
    """Ideal rolling without slipping, no energy loss. Returns (x, v)."""
    a = (5.0 / 7.0) * G * math.sin(math.radians(angle_deg))
    return 0.5 * a * t * t, a * t

def frictionless_sliding(t, angle_deg):
    """No friction at all: the marble slides without spinning. Returns (x, v)."""
    a = G * math.sin(math.radians(angle_deg))
    return 0.5 * a * t * t, a * t


# ---------------------------------------------------------------------------
# SIMULATION WITH CONTACT FORCES
# ---------------------------------------------------------------------------
def simulate(radius, mass, angle_deg, mu_s, mu_k, b, t_end, dt):
    """
    Step the marble forward in time with friction and rolling resistance.

    State: x (position down the slope), v (speed), w (spin rate, rad/s).
    Returns a dict of lists: t, x, v, w, regime ("roll", "slip" or "rest").
    """
    th = math.radians(angle_deg)
    s, c = math.sin(th), math.cos(th)
    N = mass * G * c                          # support force from the plane
    I = 0.4 * mass * radius ** 2              # solid sphere

    x = v = w = 0.0
    t = 0.0
    out = dict(t=[], x=[], v=[], w=[], regime=[])
    n_steps = int(round(t_end / dt))

    for i in range(n_steps + 1):
        mu_k_now = mu_k_of_t(t, mu_k)
        c_rr = b_of_t(t, b) / radius          # rolling resistance coefficient

        slip_speed = v - w * radius           # zero when rolling perfectly
        rolling_now = abs(slip_speed) < 1e-9

        # Static friction needed to keep rolling (from the two equations of
        # motion with a = alpha * R):  f = (2/7) m g sin + (5/7) c_rr m g cos
        mu_needed = (2.0 / 7.0) * s / c + (5.0 / 7.0) * c_rr

        if rolling_now and mu_s >= mu_needed:
            if v == 0.0 and s <= c_rr * c:
                # Slope too shallow to overcome rolling resistance.
                regime, a, alpha = "rest", 0.0, 0.0
            else:
                regime = "roll"
                a = (5.0 / 7.0) * G * (s - c_rr * c)
                alpha = a / radius
        else:
            regime = "slip"
            # Kinetic friction opposes the slip at the contact point.
            direction = 1.0 if slip_speed >= 0 else -1.0
            f = direction * mu_k_now * N              # acts up-slope if +
            a = G * s - f / mass
            torque = f * radius - c_rr * N * radius   # friction spins it up,
            if w == 0.0 and torque < 0:               # rolling resistance
                torque = 0.0                          # opposes the spin
            alpha = torque / I

        out["t"].append(t); out["x"].append(x); out["v"].append(v)
        out["w"].append(w); out["regime"].append(regime)

        # Accelerations are constant within a step, so this update is exact.
        x += v * dt + 0.5 * a * dt * dt
        v_new = v + a * dt
        w_new = w + alpha * dt
        # If the slip changed sign during the step, the marble has "caught"
        # and starts rolling: lock the spin to the speed.
        if regime == "slip" and (v_new - w_new * radius) * slip_speed < 0:
            w_new = v_new / radius
        v, w = v_new, w_new
        t += dt

    return out


# ---------------------------------------------------------------------------
# DEVIATION FROM THE IDEAL CASE
# ---------------------------------------------------------------------------
def deviation_at_end(**p):
    """Run one simulation; return deviation from ideal rolling at t_end."""
    sim = simulate(**p)
    t = sim["t"][-1]
    x_id, v_id = ideal_rolling(t, p["angle_deg"])
    dv = sim["v"][-1] - v_id
    dx = sim["x"][-1] - x_id
    return dict(
        dv=dv, dx=dx,
        dv_pct=100.0 * dv / v_id,
        dx_pct=100.0 * dx / x_id,
        regime=sim["regime"][-1],
        v=sim["v"][-1], x=sim["x"][-1],
    )


def print_main_report(p):
    sim = simulate(**p)
    c_rr = p["b"] / p["radius"]
    tan_th = math.tan(math.radians(p["angle_deg"]))

    print("=" * 72)
    print("MARBLE ON AN INCLINE: ideal rolling vs. with contact forces")
    print("=" * 72)
    print(f"radius           = {p['radius'] * 1000:.3f} mm")
    print(f"mass             = {p['mass'] * 1000:.3f} g")
    print(f"angle            = {p['angle_deg']:.2f} degrees")
    print(f"mu_s, mu_k       = {p['mu_s']:.3f}, {p['mu_k']:.3f}")
    print(f"b                = {p['b']:.3e} m   (c_rr = b/R = {c_rr:.3e})")
    print(f"mu_s needed to roll without slipping = "
          f"{(2 / 7) * tan_th + (5 / 7) * c_rr:.4f}")
    print(f"regime           = {sim['regime'][-1]}")
    print()
    print("Speed and position over time")
    print(f"{'t (s)':>6} | {'v ideal':>9} {'v real':>9} {'diff':>11} {'diff %':>9}"
          f" | {'x ideal':>9} {'x real':>9} {'diff':>11}")
    print(f"{'':>6} | {'(m/s)':>9} {'(m/s)':>9} {'(mm/s)':>11} {'':>9}"
          f" | {'(m)':>9} {'(m)':>9} {'(mm)':>11}")
    print("-" * 86)
    n = len(sim["t"]) - 1
    for k in range(1, 9):
        i = n * k // 8
        t = sim["t"][i]
        x_id, v_id = ideal_rolling(t, p["angle_deg"])
        dv, dx = sim["v"][i] - v_id, sim["x"][i] - x_id
        print(f"{t:6.2f} | {v_id:9.5f} {sim['v'][i]:9.5f} {dv * 1e3:+11.4f} "
              f"{100 * dv / v_id:+9.4f} | {x_id:9.5f} {sim['x'][i]:9.5f} "
              f"{dx * 1e3:+11.4f}")

    d = deviation_at_end(**p)
    x_fr, v_fr = frictionless_sliding(p["t_end"], p["angle_deg"])
    print()
    print(f"READ-OFF at t = {p['t_end']:.2f} s:")
    print(f"  Speed deviation    : {d['dv'] * 1e3:+.4f} mm/s  ({d['dv_pct']:+.4f} %)")
    print(f"  Position deviation : {d['dx'] * 1e3:+.4f} mm    ({d['dx_pct']:+.4f} %)")
    print(f"  (negative = slower / behind the ideal marble)")
    if d["regime"] == "roll":
        print(f"  Formula check      : -c_rr/tan(theta) = {-100 * c_rr / tan_th:+.4f} %")
    print(f"  For reference, zero friction (pure sliding): v = {v_fr:.5f} m/s, "
          f"x = {x_fr:.5f} m")
    print()
    return sim


def print_sensitivity(p):
    def sweep(title, key, values, fmt, extra=None):
        print(title)
        print(f"  {key:>12} | {'speed dev %':>12} | {'pos dev (mm)':>13} | regime")
        print("  " + "-" * 54)
        for val in values:
            q = dict(p); q[key] = val
            if extra:
                extra(q)
            d = deviation_at_end(**q)
            print(f"  {fmt.format(val):>12} | {d['dv_pct']:+12.4f} | "
                  f"{d['dx'] * 1e3:+13.4f} | {d['regime']}")
        print()

    print("=" * 72)
    print(f"SENSITIVITY CHECK (deviation from ideal rolling at t = {p['t_end']} s)")
    print("One parameter varied at a time; the rest stay at the values above.")
    print("=" * 72)

    sweep("1. Incline angle (degrees)", "angle_deg",
          [1, 2, 5, 10, 20, 30, 45, 60, 75], "{:.0f}")

    sweep("2. Radius (metres), with b held fixed so c_rr = b/R changes", "radius",
          [0.001, 0.002, 0.005, 0.010, 0.020, 0.050], "{:.3f}")

    def keep_ratio(q):                     # keep mu_k at 80% of mu_s
        q["mu_k"] = 0.8 * q["mu_s"]
    sweep("3. Friction coefficient mu_s (mu_k set to 0.8 * mu_s)", "mu_s",
          [0.01, 0.02, 0.04, 0.05, 0.06, 0.10, 0.50, 1.00], "{:.2f}", keep_ratio)

    sweep("4. Rolling-resistance length b (metres)", "b",
          [0.0, 1e-7, 1e-6, 1e-5, 1e-4], "{:.0e}")

    sweep("5. Mass (kg): expected to make no difference in this model", "mass",
          [0.001, 0.0105, 0.1], "{:.4f}")


def make_plot(p, sim, filename="marble_incline.png"):
    """Optional plot. Skipped quietly if matplotlib is not installed."""
    try:
        import matplotlib
        matplotlib.use("Agg")
        import matplotlib.pyplot as plt
    except ImportError:
        print("(matplotlib not installed, skipping plot)")
        return

    t = sim["t"]
    ideal = [ideal_rolling(ti, p["angle_deg"]) for ti in t]
    x_id = [q[0] for q in ideal]
    v_id = [q[1] for q in ideal]

    plt.rcParams.update({"font.size": 16, "lines.linewidth": 3})
    fig, ax = plt.subplots(3, 1, figsize=(10, 15), sharex=True)

    ax[0].plot(t, v_id, "k--", label="ideal rolling")
    ax[0].plot(t, sim["v"], color="#d55e00", label="with contact forces")
    ax[0].set_ylabel("speed (m/s)"); ax[0].legend(); ax[0].grid(True)
    ax[0].set_title("Marble on incline: ideal vs. with contact forces")

    ax[1].plot(t, x_id, "k--", label="ideal rolling")
    ax[1].plot(t, sim["x"], color="#d55e00", label="with contact forces")
    ax[1].set_ylabel("position (m)"); ax[1].legend(); ax[1].grid(True)

    ax[2].plot(t, [(a - b_) * 1e3 for a, b_ in zip(sim["v"], v_id)],
               color="#0072b2", label="speed deviation (mm/s)")
    ax[2].plot(t, [(a - b_) * 1e3 for a, b_ in zip(sim["x"], x_id)],
               color="#009e73", label="position deviation (mm)")
    ax[2].set_ylabel("deviation from ideal"); ax[2].set_xlabel("time (s)")
    ax[2].legend(); ax[2].grid(True)

    fig.tight_layout()
    fig.savefig(filename, dpi=120)
    print(f"Plot saved to {filename}")


if __name__ == "__main__":
    sim = print_main_report(PARAMS)
    print_sensitivity(PARAMS)
    make_plot(PARAMS, sim)
