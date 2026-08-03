# Workflow: C++ Gameplay Changes

1. **Locate the module.** Confirm the change belongs in `Core/`, `Physics/`, `AI/`, `Animation/`, `Audio/`, `UI/`, or `Network/` per `.agent/AGENTS.md` §3. If none fit, propose a new subfolder via `.agent/prompts/architecture_analysis.md` first.
2. **Check the roadmap.** Read the relevant `Moon/Roadmaps/*.md` section — don't re-derive a design that's already been through options analysis.
3. **Write the class.** Follow `.agent/rules/cpp_gameplay.md`: correct prefix, `TObjectPtr` members, explicit tick policy.
4. **Wire reflection deliberately.** Only expose `UPROPERTY(EditDefaultsOnly)`/`BlueprintReadOnly` for values designers actually need to tune — don't reflex-expose everything.
5. **Add a test::** A pure-logic Automation Test (no World/PIE) for anything computable without spinning up a level; a functional test otherwise. See `.agent/workflows/testing_qa.md`.
6. **Build & lint.** `just build::editor`, `just validation::cpp`.
7. **Update docs if the module map changed.** `Docs/ARCHITECTURE.md`'s module map must match `Source/GameTemplate/`'s actual folder structure.
