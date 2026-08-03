# Workflow: UI / HUD Changes

1. **Confirm the module exists.** `Source/GameTemplate/UI/` is created on first real UI work — see `.agent/AGENTS.md` §3.
2. **Design the read-only data contract.** Define what gameplay state the widget needs to read (a C++ struct/delegate), before building the UMG layout.
3. **Bind, don't poll.** Prefer delegate/event bindings for state that changes on discrete triggers; reserve per-tick polling for genuinely continuous values.
4. **Batch for scale.** If the UI represents many actors at once, prototype with a realistic actor count early, not just 1-2 in the Editor viewport.
5. **Test.** Cover any UI-side computed display logic (e.g., a formatted countdown, a derived meter percentage) with a pure-logic unit test where feasible.
