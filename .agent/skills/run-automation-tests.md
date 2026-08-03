# Skill: Run Automation Tests

**When to use:** Before opening a PR, or when investigating a CI failure.

## Steps

1. Full suite: `just test::automation`.
2. Domain-filtered: `just test.gameplay` / `just test.physics` / `just test::ai` (see `Tools/Test/justfile`).
3. Reports land under `Saved/Automation/Reports` — open `index.html` for a readable failure breakdown.
4. For a flaky-looking failure, re-run with a fixed seed if the test is physics/AI-related, to rule out nondeterminism vs. a genuine regression.
5. If CI (`​.github/workflows/ci.yml`) fails but the same command passes locally, check for an environment difference first (self-hosted `ue5`-labeled runner config, `UE5_ROOT`) before assuming the test itself is wrong.
