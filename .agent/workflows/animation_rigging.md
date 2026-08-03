# Workflow: Animation & Rigging Changes

1. **Confirm the module exists.** `Source/GameTemplate/Animation/` is created on first real animation work, not scaffolded speculatively — see `.agent/AGENTS.md` §3.
2. **Expose tunables.** Blend curves, IK weight ranges, and ragdoll thresholds go through `UPROPERTY(EditDefaultsOnly)` so animators/designers can iterate in the Editor.
3. **Determinism check.** If the change touches ragdoll/physical-animation randomness and the actor is observable via replay or networking, seed it — see `.agent/rules/animation_rigging.md` §3.
4. **Visual validation first.** Use the Animation Blueprint debugger / Control Rig viewport before assuming a C++-side bug.
5. **Test.** Where feasible, cover blend-weight boundary logic (e.g., "impact force above threshold X switches to full ragdoll") with a pure-logic Automation Test.
