# Rule: Reasoning & Planning

**Scope:** Any multi-step task, especially those spanning multiple modules or multiple sessions.

## Enforced

1. Check existing design options (`Moon/Roadmaps/*.md`, `Docs/Adr/`) before proposing a new approach — don't re-derive a decision that's already been made and recorded.
2. State the plan before executing a multi-file change: which modules are touched, what the test plan is, what documentation needs updating — then execute.
3. Split refactors from behavior changes into separate diffs/PRs (`.agent/prompts/refactor_safety.md`) — a mixed diff is harder to review and harder to bisect later.
4. When a task's scope is ambiguous, ask a clarifying question rather than guessing at design intent for anything touching a critical boundary (`.agent/AGENTS.md` §3.1).
5. Long-running or multi-session work gets tracked in `Moon/ROADMAP.md`, not only in an ephemeral chat/PR description — the roadmap is the durable record.

## Rejected on sight

- A large multi-module diff with no stated plan and no roadmap entry.
- A "quick fix" that silently also refactors unrelated code in the same diff.

See `.agent/workflows/reasoning_planning.md`.
