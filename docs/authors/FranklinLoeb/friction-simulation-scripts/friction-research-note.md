# Friction as a Test of Fundamental Physics: A Negative Result

**Franklin Loeb**
Ronin Institute Fellow
11 November 2026

## Abstract

We asked whether contact forces and friction could provide a tabletop test of string theory or of Tom Lawrence's Covariant Compactification theory. We simulated first, before building anything: a marble rolling down an inclined plane, a sliding brick with embedded sensors, and a nanoparticle cluster on an inclined plane. In all three cases, the effect that would have to be measured is swamped by classical unknowns, and neither theory makes a specific, testable prediction about friction. Predicting the friction coefficient from first principles, with standard physics alone, would already be a breakthrough. This note records the failed attempt, with the scripts and numbers, so that others do not replicate it mindlessly — and so that someone else might take it further.

## Acknowledgements

Thank you to Tom Lawrence (Warped and Broken, Ronin Institute Fellow) for his honest answer — that his theory is not yet developed enough for predictions, or for doing things better than string theory — and for his encouragement to play with the friction question anyway. He wrote that it is my question rather than his, that he is glad I am playing around with it, and that a diversion like this is often worth running with: you can learn a lot from running with an idea and seeing where it goes, and you never know where it may turn out to be relevant in future. He could have been a lot more cynical about it, and he was not.

## 1. The question

Contact forces and friction are still being studied today. Could string theory, or Covariant Compactification, make a prediction about them that could be tested on a tabletop — for example, with a perfectly smooth sphere rolling down an inclined plane, in a vacuum, with a laser tracking its speed?

The attraction was the beauty of connecting the simplest physics experiment you could possibly do with the most advanced physics there is. The worry, stated at the outset, was that if proving string theory was as easy as rolling a ball down a hill, someone would have done it already.

The plan was: simulate first, then experiment ("code then experiment"). Step 1 is to calculate what deviation would be expected — that calculation tells whether the effect is measurable, and how precise the laser must be.

## 2. Step 1–2: The marble

A 1 cm glass marble rolling down a 10° slope for 2 seconds.

First, with a placeholder rolling-resistance length, the marble ended 0.57% slower and 13.8 mm behind the ideal rolling result. Friction itself does not slow a rolling marble at all — the contact point is at rest in perfect rolling, so friction does no work. The deviation came from rolling resistance (the contact is a small patch, not a point) and from slipping.

Then, with a Hertz contact calculation (glass on steel, load ≈ 0.101 N, effective modulus ≈ 55.1 GPa, contact radius ≈ 24 micrometres, peak pressure ≈ 84 MPa), the expected deviation collapsed to about **2.6 parts per million: the marble ends ~6 micrometres behind ideal after 2 seconds, not 13.8 mm**. The first placeholder was about 2,000 times too large.

The loss is a hysteresis fraction, alpha, which must be measured: alpha = 0.0001 gives 0.26 ppm, alpha = 0.001 (central) gives 2.6 ppm, alpha = 0.01 gives 25.5 ppm. Adhesion, which could be ~5% of the load for smooth clean surfaces, and micro-slip, are not in that number at all. The baseline is uncertain by a factor of about 100.

**Covariant Compactification makes no specific, testable prediction about contact forces or friction.** It covers geometry and gauge fields, gives no numerical couplings, masses, or deviations, never mentions friction, contact forces, atoms, condensed matter, or lab experiments, and says 4D gravity is unchanged. Contact forces are electromagnetic, and the theory cannot yet describe them. String theory likewise says nothing specific about friction: at everyday energies it reduces to the Standard Model plus general relativity, so at marble scale it predicts the same friction as ordinary physics.

## 3. Step 3: The sliding brick

A sliding brick is better than a rolling marble for measuring friction, because friction does work when something slides. On a 45° slope over 1 m, steel on steel (μk = 0.30–0.60) loses 30–60% of its acceleration to friction — easy to measure.

The obstacle is the friction coefficient itself: **μk cannot be predicted**. Neither string theory nor Covariant Compactification predicts it. Embedded sensors could measure it precisely — an accelerometer reads the friction and load directly, and their ratio is μk; friction shifts the support force forward, giving +34% pressure at the leading edge and −34% at the rear; the face warms by only ~40–80 thousandths of a kelvin. But the instruments are hundreds to tens of thousands of times more precise than the baseline is known: predicting μk for fresh surfaces is uncertain by ~23% at best, up to a factor of 4, dominated by adhesion and surface films in vacuum. Repeating the same run on worn-in surfaces, μk scatters by ~2–10%.

A bigger brick is better than a small one in the real world: load is bigger, so adhesion and films are a smaller fraction, flatness and edge effects are a smaller fraction, and sensors are less intrusive.

## 4. Step 4: The nanoparticle cluster

Going smaller, to get closer to quantum effects, makes it worse, not better.

A 300-atom gold cluster on graphite, ~2 nm across: gravity is ~100 billion times too weak to slide the particle. Adhesion holds it with 4 × 10¹¹ times its weight. It never slides down an incline — it is frozen, or hops randomly, and downhill drift would take ~100 years to show above random wandering. There is no friction coefficient at this scale: friction comes from atomic bumpiness and lattice matching, not load. It must be measured by pushing with an AFM tip: ~700 pN for matched lattices, ~50 pN for disordered contact, ~1 pN for mismatched crystal. Warmth reduces friction, and friction rises with speed — the opposite of the brick. Quantum tunnelling is not relevant for the particle (chance per attempt ~10⁻¹¹⁰⁰ or smaller).

The baseline has gone from uncertain by a factor of 2–4 (brick) to uncertain by orders of magnitude. Shrinking the experiment makes the search for new physics harder, not easier.

## 5. Conclusion: a negative result

- Marble: deviation ~2.6 ppm, baseline uncertain by a factor of ~100.
- Brick: friction measurable, but μk itself unpredictable, uncertain by ~23% to a factor of 4.
- Nanoparticle: gravity negligible against adhesion, no friction coefficient, baseline uncertain by orders of magnitude.
- Neither string theory nor Covariant Compactification predicts friction.

**Predicting friction from first principles, with standard physics alone, would already be a breakthrough.** I was aiming even higher than I needed to.

This note is published as a negative result. If someone takes this failed work and makes it actually work, that is the point.

## Scripts

All three simulation scripts and plots are saved with this note:

- `marble_incline.py` / `marble_incline.png`
- `brick_incline.py` / `brick_incline.png`
- `nano_incline.py` / `nano_incline.png`

They were written with an AI coding assistant (Fable 5.2 / Claude Code), run and verified locally on 11 November 2026. Material numbers in the scripts are typical published values from memory, not new measurements; the Hertz contact numbers in Section 2 were calculated independently and agree with the simulation.

## References

- Lawrence, T. Covariant Compactification: A Radical Revision of Kaluza-Klein Unification. Preprints.org, DOI 10.20944/preprints202303.0314, v3 posted 25 March 2025. Not peer-reviewed.
- Lawrence, T. Warped and Broken, https://warpedandbroken.com ; YouTube playlist, https://www.youtube.com/playlist?list=PL0YyplRPhqcgpmcsxSSriNfZ0fi5xGcBy
- Loeb, F. Collatz Box Universes, https://github.com/numberwonderman/Collatz-box-universes
