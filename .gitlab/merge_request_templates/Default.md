### Target Issue
<!-- Required. Exactly one issue number, e.g. Closes #123 -->
Closes #

### Component Impacted
<!-- Exactly one of the values below. Must match a Project Board "Component" option verbatim. -->
- [ ] Core: Gameplay
- [ ] Core: Physics & Collision
- [ ] AI: Behavior Tree
- [ ] AI: Utility AI
- [ ] Animation & Rigging
- [ ] Audio: MetaSounds
- [ ] UI / HUD
- [ ] Networking
- [ ] Tooling / CI

### Priority
<!-- Exactly one of the values below. Must match a Project Board "Priority" option verbatim. -->
- [ ] Tier 1: Playable MVP
- [ ] Tier 2: Core Systems
- [ ] Tier 3: Vertical Slice
- [ ] Tier 4: Alpha & Beta / Backburner

### Summary of Changes
<!-- What changed and why, in 1-3 bullet points. -->
-

### Dependencies
<!-- Other issues/MRs this depends on, or that depend on this. "None" if not applicable. -->

### Test Plan
<!-- Bulleted checklist of how this was verified. Reference the specific just recipes run. -->
- [ ] `just validation::cpp`
- [ ] `just test::automation` (or the relevant filtered target: `test.gameplay` / `test.physics` / `test::ai`)
- [ ] `just monitoring::headless-sim` + `monitoring::diff-telemetry` (required for any change affecting AI weights, physics constants, or run/match statistics)

### Agent Declaration
<!-- Filled by the authoring agent. Leave "manual" if a human wrote this MR. -->
- Author: <!-- agent | manual -->
- Model / Agent ID: <!-- e.g. claude-sonnet-5, or "n/a" -->
- Autonomous: <!-- yes | no -->
