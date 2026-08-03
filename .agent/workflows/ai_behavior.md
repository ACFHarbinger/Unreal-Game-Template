# Workflow: AI Behavior Changes

1. **Classify the change.** Structural/tactical (Behavior Tree) vs. atomic in-context choice (Utility AI) — see `.agent/rules/ai_behavior.md` §2.
2. **Check existing considerations.** Don't duplicate a scoring curve that already exists under a different name; extend or reuse.
3. **Normalize and document.** New/changed curves must clamp to `[0,1]` and state their shape in a doc comment.
4. **Weight-change protocol.** Any change to existing Utility weights requires a `just monitoring::headless-sim runs=100` baseline before and after, diffed with `just monitoring::diff-telemetry` — AI weight changes are exactly the kind of "obviously fine" change that produces surprising aggregate regressions.
5. **Test.** Add a deterministic scoring unit test (fixed inputs → expected score) under `Source/GameTemplate/Tests/`.
6. **Use the Gameplay Debugger.** Visualize scores/tree state before reading logs when debugging AI behavior.
