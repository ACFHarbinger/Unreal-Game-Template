# Skill: Systematic Bug Hunt

**When to use:** An intermittent or hard-to-reproduce bug, especially in AI/physics.

## Steps

1. Get a reproducible seed: run `just monitoring::headless-sim runs=1` repeatedly with incrementing seeds until the symptom reproduces, and record the seed.
2. Bisect by subsystem: disable/mock one subsystem at a time (AI, physics response, animation) to isolate which layer the symptom depends on.
3. Use the domain debug visualization (Gameplay Debugger, collision contact markers, Animation Blueprint debugger) before reading logs.
4. Once isolated, follow `.agent/workflows/error_debug.md`'s root-cause-not-symptom-patch discipline.
5. Write the regression test using the exact seed that reproduced the bug.
