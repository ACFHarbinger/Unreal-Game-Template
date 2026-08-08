# Workflow: Reviewing a PR

1. **Read the PR template fields first.** Component, Priority, Test Plan, Agent Declaration (`.github/PULL_REQUEST_TEMPLATE.md`) — an incomplete template is grounds for requesting changes before a line-by-line review.
2. **Check module boundaries.** Cross-reference the diff against `.agent/AGENTS.md` §3.1's critical boundaries table.
3. **Apply the severity protocol.** Classify every finding as CRITICAL/HIGH/MEDIUM/LOW per `.agent/AGENTS.md` §7 and say so explicitly in the review comment.
4. **Verify test evidence.** For AI/physics/statistics-affecting changes, confirm a `monitoring::diff-telemetry` result is attached and looks sane, not just present.
5. **Verify documentation kept pace.** If the module map, roadmap, or a design decision changed, confirm `Docs/`/`Docs/Moon/` were updated in the same PR.
6. **Approve only when CRITICAL/HIGH items are resolved** (or HIGH is explicitly waived with a recorded reason).
