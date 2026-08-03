# Rule: Documentation

**Scope:** `Docs/`, `Moon/`, `.agent/`, root-level `README.md`.

## Enforced

1. **One source of truth per fact.** An item lives in exactly one of `Moon/ROADMAP.md` (in progress/planned) or `Docs/CHANGELOG.md` (done) at a time — never both, never neither once started.
2. Completed work moves from the roadmap to the changelog in the same change that completes it, with concrete files/functions/config keys cited — not a vague summary.
3. A significant, hard-to-reverse architectural decision gets a numbered ADR under `Docs/Adr/`, not just a paragraph in `Docs/ARCHITECTURE.md`. ADRs are immutable once accepted; reversals get a new superseding ADR.
4. `.agent/rules/`, `.agent/workflows/`, and `.agent/skills/` are kept 1:1 by filename per domain where applicable — introducing a new domain rules file without a matching workflows file is incomplete.
5. Code comments explain *why*, not *what* — the "what" should be evident from well-named UE5 reflection macros and types.

## Rejected on sight

- A roadmap item marked complete with no corresponding changelog entry (or vice versa).
- An architecture-affecting decision documented only in a PR description, nowhere in `Docs/`.

See `.agent/workflows/documentation.md`.
