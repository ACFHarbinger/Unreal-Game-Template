# Workflow: Testing & QA

1. **Classify the test::** Pure-logic unit test (no World) vs. functional test (needs PIE/a level) vs. statistical (headless simulation batch).
2. **Write the narrowest test that proves the behavior.** Don't reach for a functional test when a pure-logic one would do.
3. **Cover boundary conditions explicitly.** Exactly-at-threshold, off-by-one actor counts, empty-input cases.
4. **For AI/physics-constant changes:** run `just monitoring::headless-sim runs=100` before and after, then `just monitoring::diff-telemetry baseline=... current=...` — attach the diff to the PR.
5. **Run the full suite before declaring done:** `just test::automation`, plus the domain-filtered target (`test.physics`/`test::ai`/`test.gameplay`) for the area touched.
6. **CI parity.** Confirm the same commands run in `.github/workflows/ci.yml`'s `build-and-test` job — a local-only test that CI doesn't run isn't a gate.
