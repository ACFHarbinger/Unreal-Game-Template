# Documentation Update Prompt

**Intent:** Keep `.agent/`, `Docs/`, and `Docs/Moon/` documentation synchronized with a completed code change.

## The Prompt

I just completed [CHANGE DESCRIPTION] in this project. Update the documentation accordingly.

Task:
1. If this completes a `Docs/Docs/Moon/ROADMAP.md` item: move it to `Docs/CHANGELOG.md` in the established dated-entry format, citing concrete files/functions/config keys touched — not a vague summary.
2. If this changes system design: update `Docs/ARCHITECTURE.md` and the relevant `Docs/Docs/Moon/Roadmaps/*.md` file in the same change. If the decision is significant and hard to reverse, add a new numbered ADR under `Docs/Adr/` instead of only updating `ARCHITECTURE.md`.
3. If this introduces a new recurring task pattern: add a corresponding file under `.agent/skills/`.
4. If this introduces a new domain area (not covered by any existing `.agent/workflows/*.md`): add matching `workflows/`, `rules/`, and (if applicable) `skills/` files — these are kept 1:1 by filename per domain.
5. Verify no fact now lives in two places claiming different states (e.g., an item marked both "in progress" in the roadmap and "done" in the changelog).

Output: the specific diffs to each documentation file, not a general description of what should change.
