# Rule: Code Review

**Scope:** All PRs.

## Enforced

1. Apply the severity protocol from `.agent/AGENTS.md` §7 — CRITICAL items block merge unconditionally, HIGH items block merge unless explicitly waived by a human reviewer with a reason recorded in the PR, MEDIUM/LOW are fix-soon/nice-to-have.
2. A PR touching AI weights, physics constants, or match/run statistics is not reviewable without an attached `monitoring::diff-telemetry` result.
3. A PR is not "done" without: `just validation::cpp` clean, `just test::automation` green, and — if it changed the module map — `Docs/ARCHITECTURE.md` updated in the same PR.
4. Reviewers check module-boundary compliance (`.agent/AGENTS.md` §3.1) explicitly, not just "does it compile and pass tests" — a boundary violation can pass every test and still be wrong architecture.

## Rejected on sight

- A PR description with an empty or templated-but-unfilled Test Plan section.
- A review approval on a PR with an unresolved CRITICAL-severity comment.

See `.agent/workflows/code_review.md`.
