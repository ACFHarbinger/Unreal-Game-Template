# Refactor Safety Prompt

**Intent:** Refactor existing code without changing observable simulation behavior, with explicit safety verification.

## The Prompt

I want to refactor [CODE/MODULE DESCRIPTION] in this project without changing its runtime behavior.

Task:
1. Before touching anything, run the full relevant test scope to establish a baseline: `just test::automation` plus, if the refactor touches Physics/AI/core gameplay, `just monitoring::headless-sim runs=100` for a statistical baseline.
2. Identify all call sites and confirm none rely on incidental (undocumented) behavior of the code being refactored — check for `UPROPERTY`/`UFUNCTION` reflection usage from Blueprint, since those are API surfaces even if not called from other C++.
3. Perform the refactor preserving the existing naming-prefix conventions (`.agent/rules/cpp_gameplay.md`) and module boundaries (`.agent/AGENTS.md` §3.1).
4. Re-run the exact same baseline tests/simulation batch and diff against the pre-refactor baseline (`just monitoring::diff-telemetry`) — a refactor that changes aggregate simulation statistics is not behavior-preserving, regardless of how "obviously equivalent" the code looks.
5. Report: what was moved/renamed, why observable behavior is unchanged, and the before/after test results.

Constraints:
- Do not combine a refactor with a behavior change in the same diff — split them.
- If the refactor touches deterministic-seed-sensitive code, verify byte-for-byte identical output on a fixed-seed run before and after.
