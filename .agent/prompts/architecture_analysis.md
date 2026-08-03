# Architecture Analysis Prompt

**Intent:** Evaluate whether a proposed change fits the existing architectural boundaries before implementation begins.

## The Prompt

I'm considering [PROPOSED CHANGE] for this project.

Task:
1. Cross-reference `.agent/AGENTS.md` §3 (module boundaries) and `Docs/ARCHITECTURE.md` — does this change fit cleanly into an existing module, or does it need a new one?
2. Check `Docs/Adr/` for any prior Architecture Decision Record covering the affected subsystem — does the proposed change align with or contradict a documented decision? If it contradicts one, a new superseding ADR is needed, not a silent departure.
3. Check `Moon/Roadmaps/architecture.md` and the relevant domain roadmap for prior option analysis on this exact area.
4. Identify every module boundary the change would cross and flag any that violate `.agent/AGENTS.md` §3.1's critical boundaries table (e.g., a gameplay subsystem depending on rendering, Utility AI overriding Behavior Tree structural constraints).
5. Recommend an approach, with trade-offs, in the same format as the existing `Moon/Roadmaps/*.md` files (Options A/B/C, pros/cons, recommendation) so it can be appended directly if approved.

Output: a short options analysis, not an implementation — implementation should follow only after the architectural fit is confirmed.
