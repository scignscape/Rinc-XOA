"""
nano_incline.py
===============
Step 4 of the thought experiment: a NANOPARTICLE at quantum scale, pushed
(not rolled, not slid under gravity) across a surface, with an atomic force
microscope (AFM) tip.

WHAT STEPS 1-3 TAUGHT US
------------------------
  * Marble (step 1-2): rolling resistance leaves the marble only ~6 um
    behind ideal after 2 s -- a few parts per million, and uncertain by a
    factor of ~100.
  * Brick (step 3): sliding friction is measurable (tens of percent), but
    mu_k itself cannot be predicted from first principles; predicting it
    would already be a breakthrough, and repeat runs scatter 2-10%.

WHAT IS DIFFERENT AT THE NANOSCALE
----------------------------------
The incline stops working. Gravity is about a hundred billion times too
weak to slide the particle, so friction has to be measured by pushing it
with an AFM tip. There is no friction coefficient any more: friction comes
from the atomic bumpiness of the surface and from how well the two atomic
lattices line up, not from load. And shrinking the experiment makes the
search for new physics harder, not easier -- the baseline goes from
uncertain by a factor of 2-4 (brick) to uncertain by orders of magnitude.

NUMBERS IN THIS SCRIPT
----------------------
The headline friction values (700 / 50 / 1 pN at 4 K), the 246 pm lattice
spacing, the 0.08 eV per slip, the 1 pN / 25 pm precision, the cantilever
noise figures, and the tunnelling probabilities are the values from the
Step 4 summary. Material numbers here are typical values from memory, not
measurements. Where a textbook relation is used to turn one of those
values into another (e.g. Prandtl-Tomlinson force -> barrier energy), the
result is a consistency check, not an independent prediction.

PHYSICS ASSUMPTIONS (read these first)
--------------------------------------
1. A 300-atom gold cluster, about 2 nm across, on graphite. Mass is
   300 x the mass of one gold atom.
2. The contact is described by the Prandtl-Tomlinson model: the tip drags
   the particle through a periodic surface potential with lattice spacing
   a = 246 pm (graphite). The maximum lateral force for a sinusoidal
   corrugation of total barrier E is F_max = 2*pi*E / a.
3. Thermal hopping: the particle attempts to hop with frequency f0 ~ 1e12
   per second (a typical phonon frequency) and succeeds with probability
   exp(-E / kT) per attempt, E being the barrier per hopping unit.
4. Downhill drift is a biased random walk: each hop gains a tiny downhill
   energy dE = m*g*a (generous case: vertical wall, sin(theta) = 1), so
   the bias per hop is dE / kT. Drift only shows above the random walk
   once the number of hops N exceeds 1 / bias^2.
5. Tunnelling probabilities are stated values from the Step 4 summary,
   not computed here: ~1e-1100 per attempt for the whole cluster, ~1e-13
   per attempt for a single hydrogen atom below ~100 K.
6. No string-theory or Covariant Compactification prediction enters
   anywhere: neither theory gives a number for friction at this scale.

UNKNOWNS (variables to account for later, not assumed away)
-----------------------------------------------------------
Carried over from steps 1-3 (still apply):
  wear_rate, surface_roughness, adhesion, plane_flatness, angle_uncertainty,
  g_local, residual_gas, temperature, surface_charge, magnetic_effects,
  release_conditions, laser_effects, vibration, earth_rotation,
  real_contact_area, asperity_plasticity, surface_films, micro_slip

New / dominant in step 4:
  barrier_per_atom   1-50 meV per contact atom; moves friction from zero
                     to nanonewtons
  lattice_matching   changes friction by orders of magnitude; can change
                     mid-slide if the particle turns
  contamination      one stray molecule under the particle can dominate
  hop_attempt_rate   uncertain by orders of magnitude
  tip_effects        the AFM tip touches the particle and alters the measurement
  contact_atoms      how many atoms actually touch; rough, ~10-50
"""

import math

# --------------------------------------------------------------------------
# Parameters: the Step 4 summary values
# --------------------------------------------------------------------------
PARAMS = {
    "n_atoms": 300,                 # gold atoms in the cluster
    "au_mass_u": 196.97,           # atomic mass units per gold atom
    "diameter_nm": 2.0,            # cluster diameter, nm
    "lattice_pm": 246.0,           # graphite lattice spacing, pm
    "adhesion_over_weight": 4e11,  # adhesion / weight (Step 4 summary)
    "friction_pN": {               # lateral force at 4 K, pN (Step 4 summary)
        "matched lattices": 700.0,
        "disordered contact": 50.0,
        "mismatched crystal": 1.0,
    },
    "heat_per_slip_eV": 0.08,      # energy dissipated per slip (Step 4 summary)
    "force_resolution_pN": 1.0,    # needed force resolution
    "position_resolution_pm": 25.0,
    "cantilever_noise_pN": {300.0: 0.5, 4.0: 0.06},  # thermal noise, pN
    "tunnel_cluster": 1e-1100,     # per-attempt, whole cluster (stated value)
    "tunnel_hydrogen": 1e-13,      # per-attempt, single H below ~100 K (stated)
    "attempt_rate": 1e12,          # hopping attempt frequency, per second
    "barrier_meV": 10.0,           # representative barrier per hop, meV
    "contact_atoms": 30,           # rough number of atoms in contact
    "contact_atoms_range": (10, 50),
}

U_KG = 1.66053906660e-27           # kg per atomic mass unit
K_B = 1.380649e-23                # J/K
EV_J = 1.602176634e-19            # J per eV
G = 9.80665                       # m/s^2


def report_scale(p):
    print("=" * 72)
    print("NANOPARTICLE ON A SURFACE: step 4 -- gravity stops working")
    print("=" * 72)
    m = p["n_atoms"] * p["au_mass_u"] * U_KG
    a = p["lattice_pm"] * 1e-12
    weight = m * G
    adhesion = p["adhesion_over_weight"] * weight
    print(f"cluster            = {p['n_atoms']} gold atoms, ~{p['diameter_nm']:.0f} nm across")
    print(f"mass               = {m:.3e} kg")
    print(f"weight             = {weight:.3e} N")
    print(f"adhesion           = {adhesion:.3e} N  ({adhesion * 1e12:.0f} pN)")
    print(f"  adhesion / weight = {p['adhesion_over_weight']:.1e} (Step 4 summary value)")
    print()
    print("Downhill energy gained by moving one lattice site (vertical wall,")
    print("the most generous case -- any real slope is worse):")
    dE = m * G * a
    for T in (300.0, 4.0):
        print(f"  T = {T:5.0f} K:  dE = {dE:.3e} J  = {dE / K_B / T:.2e} kT")
    print("  Moving one site downhill gains ~1e-11 of the thermal energy.")
    print("  Left alone the particle is frozen in place or hops at random;")
    print("  it never slides down on its own. It must be pushed with an")
    print("  AFM tip.")
    print()
    return {"mass": m, "weight": weight, "adhesion": adhesion, "dE": dE, "a": a}


def report_friction(p, s):
    print("FRICTION FROM LATTICE MATCHING (Prandtl-Tomlinson consistency check)")
    print("  F_max = 2*pi*E / a  ->  E = F_max * a / (2*pi).")
    print("  The forces are the Step 4 values; the barrier energies are")
    print("  what those forces imply, not independent predictions.")
    print()
    print(f"  {'case':>20} | {'F at 4 K':>9} | {'barrier E':>11} | {'per contact atom':>16}")
    print(f"  {'':>20} | {'(pN)':>9} | {'(meV)':>11} | {'(meV, ~30 atoms)':>16}")
    print("  " + "-" * 66)
    a = s["a"]
    for label, F_pN in p["friction_pN"].items():
        F = F_pN * 1e-12
        E_meV = F * a / (2 * math.pi) / EV_J * 1e3
        print(f"  {label:>20} | {F_pN:9.0f} | {E_meV:11.1f} | "
              f"{E_meV / p['contact_atoms']:16.2f}")
    print()
    print("  The matched case implies ~6 meV per contact atom, inside the")
    print("  stated 1-50 meV range. The mismatched case implies a total")
    print("  barrier of only ~0.2 meV -- below that range, i.e. effectively")
    print("  no barrier at all. That is the point: a mismatched lattice")
    print("  washes the corrugation out, which is why its friction is ~700x")
    print("  smaller. The three values and the barrier range are consistent")
    print("  with each other -- but that consistency is not a prediction.")
    print("  Lattice matching alone changes friction by a factor of ~700.")
    print()
    print("  Warmth: at room temperature and slow pushing, the disordered")
    print("  contact drops from 50 pN to nearly zero -- thermal hopping")
    print("  moves the particle before the tip has to drag it.")
    print("  Friction RISES with speed here, the opposite of the brick.")
    print()


def report_drift(p, s):
    print("WHY THE DRIFT TAKES ~100 YEARS TO SHOW")
    print("  Each hop is biased downhill by bias = dE / kT. After N hops the")
    print("  drift is N*bias lattice spacings but the random walk has spread")
    print("  sqrt(N) spacings, so drift only wins once N > 1 / bias^2.")
    print()
    dE = s["dE"]
    f0 = p["attempt_rate"]
    E = p["barrier_meV"] * 1e-3 * EV_J
    for T in (300.0, 4.0):
        kT = K_B * T
        bias = dE / kT
        n_star = 1.0 / bias ** 2
        f_hop = f0 * math.exp(-E / kT) if E / kT < 700 else 0.0
        t_star = n_star / f_hop if f_hop > 0 else float("inf")
        years = t_star / (365.25 * 24 * 3600)
        print(f"  T = {T:5.0f} K:  bias = {bias:.2e} per hop, "
              f"hops needed = {n_star:.2e}")
        print(f"            hop rate = {f_hop:.2e} /s (barrier "
              f"{p['barrier_meV']:.0f} meV), time to show drift = "
              f"{t_star:.2e} s = {years:.0f} years")
    print()
    print("  Order of magnitude: decades. The Step 4 summary said about")
    print("  100 years -- same order, given the barrier and attempt rate")
    print("  are each uncertain by orders of magnitude.")
    print()


def report_speed(p):
    print("SPEED DEPENDENCE (thermal activation, textbook form)")
    print("  F(v) = F_cold + (kT / x_b) * ln(v / v_ref), x_b ~ 0.1 nm.")
    print("  At 300 K, kT / x_b is about 41 pN per factor of e in speed.")
    print()
    kT = K_B * 300.0
    xb = 0.1e-9
    slope_pN = kT / xb * 1e12
    print(f"  thermal slope at 300 K = {slope_pN:.0f} pN per e-fold of speed")
    print(f"  {'speed':>12} | {'extra force over cold value':>28}")
    print("  " + "-" * 44)
    v_ref = 1e-9  # 1 nm/s reference
    for v in (1e-9, 1e-8, 1e-7, 1e-6):
        extra = slope_pN * math.log(v / v_ref)
        print(f"  {v * 1e9:10.0f} nm/s | {extra:+24.0f} pN")
    print()
    print("  Over three factors of 10 in speed the thermal term grows by")
    print(f"  ~{slope_pN * math.log(1000):.0f} pN -- larger than the whole")
    print("  50 pN disordered-contact friction. At room temperature the")
    print("  disordered case is washed out by thermal hopping, exactly as")
    print("  the Step 4 summary said.")
    print()


def report_precision(p):
    print("SIGNAL AND PRECISION NEEDED")
    print(f"  signal: sawtooth force, one tooth per lattice site "
          f"({p['lattice_pm']:.0f} pm), peaks 50-800 pN")
    print(f"  force resolution needed: ~{p['force_resolution_pN']:.0f} pN; "
          f"position ~{p['position_resolution_pm']:.0f} pm")
    for T, noise in sorted(p["cantilever_noise_pN"].items()):
        print(f"  cantilever thermal noise at {T:.0f} K: {noise:.2f} pN "
              f"(adequate vs 1 pN resolution)")
    print(f"  heat per slip: {p['heat_per_slip_eV']:.2f} eV -- no temperature "
          f"rise is measurable")
    print()
    print("QUANTUM TUNNELLING (stated values, not computed here)")
    print(f"  whole 300-atom cluster: ~1e-1100 per attempt -- irrelevant")
    print(f"  single hydrogen atom: ~1e-13 per attempt below ~100 K -- the")
    print("  only case in the table where tunnelling is observable.")
    print("  The particle moves by thermal hopping: classical statistics.")
    print()


def report_theories():
    print("STRING THEORY AND COVARIANT COMPACTIFICATION")
    print("  Neither makes a specific, testable prediction about friction")
    print("  at atomic or quantum scales.")
    print("  * String theory: atomic friction is electromagnetism plus")
    print("    ordinary quantum mechanics at thousandths of an eV. It offers")
    print("    no calculation of any quantity in this model.")
    print("  * Covariant Compactification: as found in step 2, it does not")
    print("    yet contain atoms or charged matter, and it leaves ordinary")
    print("    gravity unchanged. Gravity is negligible here anyway.")
    print()
    print("CONCLUSION")
    print("  The baseline has gone from uncertain by a factor of 2-4 (brick)")
    print("  to uncertain by ORDERS OF MAGNITUDE here: the barrier per")
    print("  contact atom alone (1-50 meV) moves friction from zero to")
    print("  nanonewtons, lattice matching changes it by ~700x, one stray")
    print("  molecule can dominate, and the hop attempt rate is uncertain")
    print("  by orders of magnitude. Shrinking the experiment makes the")
    print("  search for new physics harder, not easier.")
    print()


def make_plot(p, s, filename="nano_incline.png"):
    """Optional plot. Skipped quietly if matplotlib is not installed."""
    try:
        import matplotlib
        matplotlib.use("Agg")
        import matplotlib.pyplot as plt
        import numpy as np
    except ImportError:
        print("(matplotlib not installed, skipping plot)")
        return
    plt.rcParams.update({"font.size": 14, "lines.linewidth": 2.5})
    fig, ax = plt.subplots(3, 1, figsize=(10, 15))

    # Panel 1: stick-slip force vs tip displacement, three lattice matchings.
    a = s["a"]
    x = np.linspace(0, 3 * a, 600)
    colors = ["#0072b2", "#d55e00", "#009e73"]
    for (label, F_pN), col in zip(p["friction_pN"].items(), colors):
        F = F_pN * np.sin(2 * np.pi * x / a)
        ax[0].plot(x * 1e12, F, color=col, label=f"{label}: {F_pN:.0f} pN peak")
    ax[0].set_xlabel("tip displacement (pm)")
    ax[0].set_ylabel("lateral force (pN)")
    ax[0].set_title("Stick-slip force, one tooth per lattice site (246 pm), at 4 K")
    ax[0].legend(fontsize=11)
    ax[0].grid(True)

    # Panel 2: friction vs speed (thermal activation) at 300 K and 4 K.
    v = np.logspace(-9, -6, 200)  # 1 nm/s to 1 um/s
    kT300 = K_B * 300.0
    kT4 = K_B * 4.0
    xb = 0.1e-9
    F_cold = p["friction_pN"]["matched lattices"]
    for T, kT, sty in ((300.0, kT300, "-"), (4.0, kT4, "--")):
        F = F_cold + (kT / xb * 1e12) * np.log(v / 1e-9)
        ax[1].plot(v * 1e9, F, sty, color="#0072b2",
                   label=f"matched, {T:.0f} K")
    ax[1].axhline(50, color="#d55e00", linestyle=":",
                  label="disordered contact, cold: 50 pN")
    ax[1].set_xscale("log")
    ax[1].set_xlabel("pushing speed (nm/s)")
    ax[1].set_ylabel("friction force (pN)")
    ax[1].set_title("Friction rises with speed (thermal activation)")
    ax[1].legend(fontsize=11)
    ax[1].grid(True)

    # Panel 3: random-walk spread vs downhill drift vs time.
    dE = s["dE"]
    bias = dE / (K_B * 300.0)
    E = p["barrier_meV"] * 1e-3 * EV_J
    f_hop = p["attempt_rate"] * math.exp(-E / (K_B * 300.0))
    t = np.logspace(0, 12, 400)  # seconds to ~30,000 years
    n = f_hop * t
    spread = np.sqrt(n) * a * 1e12  # pm
    drift = n * bias * a * 1e12     # pm
    ax[2].plot(t / (365.25 * 24 * 3600), spread, color="#0072b2",
               label="random-walk spread")
    ax[2].plot(t / (365.25 * 24 * 3600), drift, color="#d55e00",
               label="downhill drift")
    ax[2].set_xscale("log")
    ax[2].set_yscale("log")
    ax[2].set_xlabel("time (years)")
    ax[2].set_ylabel("distance (pm)")
    ax[2].set_title("Drift vs random wandering at 300 K (barrier 10 meV)")
    ax[2].legend(fontsize=11)
    ax[2].grid(True)

    fig.tight_layout()
    fig.savefig(filename, dpi=120)
    print(f"Plot saved to {filename}")


if __name__ == "__main__":
    s = report_scale(PARAMS)
    report_friction(PARAMS, s)
    report_drift(PARAMS, s)
    report_speed(PARAMS)
    report_precision(PARAMS)
    report_theories()
    make_plot(PARAMS, s)
