# Rule: Testing & QA

**Scope:** `Source/GameTemplate/Tests/`, `Tools/Monitoring/`, `Tools/Test/`.

## Enforced

1. Every new gameplay-rules code path (state transition, collision-response branch, AI decision branch) ships with an Automation Test in the same PR — no "add tests later."
2. Prefer pure-logic unit tests (no World/PIE) wherever the logic under test can be exercised without spinning up a level — they're faster and less flaky than functional tests.
3. Any change to AI weights, physics constants, or anything that affects aggregate match/run statistics requires a `just monitoring::headless-sim` + `just monitoring::diff-telemetry` result attached to the PR.
4. State-machine boundary conditions (exactly-at-threshold cases) get explicit test coverage, not just the "obviously true/false" interior cases.
5. Determinism-sensitive code (anything replayed or networked) gets a fixed-seed reproducibility test: same seed in, byte-identical output out.

## Rejected on sight

- A new rules/adjudication branch with zero test coverage.
- An AI-weight PR with no `monitoring::diff-telemetry` evidence attached.

See `.agent/workflows/testing_qa.md`.
