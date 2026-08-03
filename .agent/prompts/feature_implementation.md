# Feature Implementation Prompt

**Intent:** Implement a new gameplay feature end-to-end, respecting module boundaries and test coverage requirements.

## The Prompt

I want to implement [FEATURE DESCRIPTION] in this project.

Context:
- This touches the [Core / Physics / AI / Animation / Audio / UI / Network] module(s) under `Source/GameTemplate/`.
- Relevant existing design discussion: [link to `Moon/Roadmaps/*.md` section, or "none — this is new"].

Task:
1. Check `Moon/ROADMAP.md` and the relevant `Moon/Roadmaps/*.md` file for existing design options before proposing an approach.
2. Identify which module(s) this belongs in per `.agent/AGENTS.md` §3.1, and follow the corresponding `.agent/workflows/*.md` playbook.
3. Implement in C++ following `.agent/rules/cpp_gameplay.md` (and the domain-specific rules file for the module touched).
4. Add Automation Test coverage per `.agent/workflows/testing_qa.md`, including the domain's required edge cases (state-machine boundary conditions for gameplay logic; collision-matrix completeness for Physics changes; normalized scoring for AI changes).
5. Run `just validation::cpp` and the relevant `just test::*` filter before declaring the feature complete.

Constraints:
- Do not introduce Blueprint logic for per-tick multi-actor computation.
- Do not commit new binary asset types without confirming `.gitattributes` LFS coverage.
- If the feature isn't in the roadmap yet, add it to the relevant `Moon/Roadmaps/*.md` file as part of this change.
