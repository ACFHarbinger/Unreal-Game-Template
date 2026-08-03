# Debugging Prompt

**Intent:** Resolve a gameplay/engine bug using systematic root-cause analysis and existing project debug tooling.

## The Prompt

I am encountering [SYMPTOM DESCRIPTION] in this project.

Context:
- Subsystem involved: [Physics/AI/Animation/Audio/UI/Networking/Core Gameplay].
- Reproduction: [steps, or "intermittent — need a headless seed to reproduce deterministically"].
- Relevant files: [file paths].

Task:
Analyze the provided code and identify the root cause following `.agent/rules/error_debug.md`'s methodology:
1. Reproduce headlessly with a fixed seed if the bug is physics/AI-related (`just monitoring::headless-sim runs=1`).
2. Use the domain's debug visualization first (collision contact markers for Physics; Gameplay Debugger scores for AI; log dump for a gameplay subsystem) before reading logs blind.
3. Identify which layer actually owns the bug — a visible symptom in one subsystem (e.g., a wrong outcome) is often rooted in a different layer (e.g., a collision-channel misconfiguration or an AI weight regression).

Constraints:
- Do not propose a fix that patches the symptom (e.g., nudging a collision radius) without identifying the owning layer.
- Provide the corrected code and explain why it fixes the root cause, referencing the specific invariant from `.agent/rules/*.md` that was violated.
- Propose an Automation Test that would have caught this bug, per `.agent/workflows/testing_qa.md`.
