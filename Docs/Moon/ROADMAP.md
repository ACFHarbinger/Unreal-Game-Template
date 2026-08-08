# GameTemplate — Master Roadmap

*Template roadmap. Replace the milestone table below with your actual game's phased plan; keep the "How to Use This Document" section and the per-domain roadmap links as scaffolding.*

Completed items move to [`Docs/CHANGELOG.md`](../Docs/CHANGELOG.md) as they land — see [`.agent/rules/documentation.md`](../.agent/rules/documentation.md) for the one-source-of-truth rule.

---

## How to Use This Document

This document defines the **phased execution sequence**. Each item links to the corresponding section in a domain-specific roadmap file for full option analysis and trade-offs.

Section-specific roadmaps:
- [Gameplay — Core systems, state machines, rules](roadmaps/gameplay.md)
- [AI — Behavior Trees, Utility AI](roadmaps/ai.md)
- [Physics & Collision — Chaos, Object Channels, Substepping](roadmaps/physics_collision.md)
- [Animation & Audio — IK, Ragdoll, MetaSounds](roadmaps/animation_audio.md)
- [UI/UX — HUD, Menus, Settings](roadmaps/ui_ux.md)
- [Networking — Multiplayer (if/when needed)](roadmaps/networking.md)
- [Architecture & Tooling — CI, Asset Pipeline, Scope Management](roadmaps/architecture.md)
- [QA & Testing — Headless Simulation, Automation Testing](roadmaps/qa_testing.md)

Phases are ordered by dependency. Items within a phase are independent and can be parallelized unless a dependency is noted.

---

## Phase 0 — Pure Geometry Prototype (Priority 0, Validate the Math Before Any Art)

Prove core movement/collision/AI math on placeholder geometry before any art or animation integration — skipping this and building on an unproven foundation is the highest-risk mistake a new UE project can make.

| # | Item | Status | Effort | Roadmap Link |
| --- | --- | --- | --- | --- |
| 0.1 | Spawn N placeholder actors on a flat plane; implement basic pathfinding movement | 🔄 Code scaffolded (`AGameTemplateGameMode`, `AGameTemplateCharacter`, `AGameTemplatePlayerController`) — uses engine basic-shape meshes, no `Content/` assets needed; unvalidated, see [`Source/README.md`](../Source/README.md) | ~3d | [physics_collision.md §1](roadmaps/physics_collision.md#1-pure-geometry-prototype) |
| 0.2 | Implement any custom Object Channels the design needs | ⬜ Not started — see [`Source/GameTemplate/Physics/`](../Source/GameTemplate/Physics/) placeholder | ~2d | [physics_collision.md §2](roadmaps/physics_collision.md#2-object-channels--collision-response-matrix) |
| 0.3 | Debug visualization for core interactions | ⬜ Not started | ~1d | [physics_collision.md §1](roadmaps/physics_collision.md#1-pure-geometry-prototype) |
| 0.4 | Validate the prototype simulation runs stably over an extended period | ⬜ Not started — blocked on 0.1–0.3 compiling and running in a licensed UE5 install | ~2d | [qa_testing.md §1](roadmaps/qa_testing.md#1-headless-simulation-harness) |
| 0.5 | Create the first `Content/Maps/` level and confirm first successful compile + PIE run | ⬜ Not started — the one manual Editor step required; see [`Content/README.md`](../Content/README.md) | ~1h | — |

---

## Phase 1 — Playable MVP (Milestone 1)

**Core deliverable**: the core loop is playable end-to-end with placeholder art.

| # | Item | Effort | Roadmap Link |
| --- | --- | --- | --- |
| 1.1 | Core game-state/rules subsystem | ~1w | [gameplay.md §1](roadmaps/gameplay.md#1-core-game-state) |
| 1.2 | Tactical/structural AI (Behavior Trees) | ~2w | [ai.md §1](roadmaps/ai.md#1-behavior-trees) |
| 1.3 | Utility AI in-context decision scoring | ~2w | [ai.md §2](roadmaps/ai.md#2-utility-ai) |
| 1.4 | Navigation mesh validation, AI clumping avoidance | ~1w | [ai.md §3](roadmaps/ai.md#3-navigation) |
| 1.5 | Headless simulation harness (no rendering) | ~1w | [qa_testing.md §1](roadmaps/qa_testing.md#1-headless-simulation-harness) |

---

## Phase 2 — Core Systems (Milestone 2)

**Core deliverable**: all gameplay-critical subsystems (physics, rules, AI) are feature-complete against placeholder art.

| # | Item | Effort | Roadmap Link |
| --- | --- | --- | --- |
| 2.1 | Subdivided Physics Assets where per-region collision fidelity matters | ~2w | [physics_collision.md §3](roadmaps/physics_collision.md#3-subdivided-physics-assets) |
| 2.2 | Physics substepping tuned to eliminate tunneling at high velocity | ~1w | [physics_collision.md §4](roadmaps/physics_collision.md#4-substepping) |
| 2.3 | Core rules engine / state machine | ~2w | [gameplay.md §2](roadmaps/gameplay.md#2-rules-engine) |
| 2.4 | Save/load and persistence design spike | ~1w | [architecture.md §2](roadmaps/architecture.md#2-persistence) |
| 2.5 | Multiplayer design spike (if the game needs it) | [Research] | [networking.md §1](roadmaps/networking.md#1-design-spike) |

---

## Phase 3 — Vertical Slice (Milestone 3)

**Core deliverable**: one fully rendered level/scene, real art, functional UI, spatial audio.

| # | Item | Effort | Roadmap Link |
| --- | --- | --- | --- |
| 3.1 | IK targeting / procedural animation | ~2w | [animation_audio.md §1](roadmaps/animation_audio.md#1-ik-targeting) |
| 3.2 | Ragdoll/physical-animation blending | ~2w | [animation_audio.md §2](roadmaps/animation_audio.md#2-ragdoll-blending) |
| 3.3 | Core HUD/UI | ~1w | [ui_ux.md §1](roadmaps/ui_ux.md#1-core-hud) |
| 3.4 | Spatial audio / MetaSounds integration | ~1w | [animation_audio.md §3](roadmaps/animation_audio.md#3-metasounds) |
| 3.5 | One rendered level via the real asset pipeline | [Research] | [architecture.md §1](roadmaps/architecture.md#1-asset-pipeline) |

---

## Phase 4 — Alpha & Beta (Milestone 4)

**Core deliverable**: full feature set, progression systems, CPU/memory hardening.

| # | Item | Effort | Roadmap Link |
| --- | --- | --- | --- |
| 4.1 | Progression/meta systems | [Long-term] | [architecture.md §3](roadmaps/architecture.md#3-progression) |
| 4.2 | UE5 CPU threading/memory profiling pass | ~2w | [architecture.md §4](roadmaps/architecture.md#4-cpu-and-memory-hardening) |
| 4.3 | Automated QA bots / adversarial testing | ~2w | [qa_testing.md §2](roadmaps/qa_testing.md#2-adversarial-automated-testing) |
| 4.4 | Extensive edge-case pass across all rules/state machines | ~2w | [gameplay.md §3](roadmaps/gameplay.md#3-edge-cases) |

---

## Phase 5 — Advanced / Post-Launch (Research Required)

| # | Item | Effort | Roadmap Link |
| --- | --- | --- | --- |
| 5.1 | Full multiplayer with rollback/reconciliation | [Long-term] | [networking.md §2](roadmaps/networking.md#2-rollback-reconciliation) |
| 5.2 | LLM-based scope-creep monitor over commit history vs. design doc | [Research] | [architecture.md §5](roadmaps/architecture.md#5-scope-creep-monitoring) |

---

## Dependency Notes

- Phase 0 must be validated stable before any Phase 1 AI tuning begins — tuning against an unstable physics foundation produces misleading results.
- Phase 2's rules engine depends on Phase 0's Object Channel matrix (0.2) being finalized — reopening the channel matrix after rules logic is built risks silent regressions.
- Phase 5.1 (networking) is explicitly gated on Phase 2's core systems being stable — see [`.agent/workflows/networking_multiplayer.md`](../.agent/workflows/networking_multiplayer.md).
