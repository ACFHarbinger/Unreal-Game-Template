# Skill: Update Architecture Documentation

**When to use:** A change alters the module map, a critical boundary, or a previously-recorded design decision.

## Steps

1. Update `Docs/ARCHITECTURE.md`'s module map and any affected data-flow diagram (Mermaid) in the same PR as the code change.
2. If the change reverses or significantly modifies a decision recorded in `Docs/Adr/`, write a new numbered ADR that supersedes the old one — never edit an accepted ADR's Decision section.
3. Update `.agent/AGENTS.md` §3 if a module boundary itself changed (not just its contents).
4. Cross-check `Docs/Docs/Moon/Roadmaps/architecture.md` for any option-analysis text that's now stale.
5. Run a repo-wide grep for the old architecture description to make sure no stale copy remains in `README.md`, `Docs/index.md`, or elsewhere.
