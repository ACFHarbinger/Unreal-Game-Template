# AGENTS.md - Instructions for Coding Assistant LLMs

[![Unreal Engine 5](https://img.shields.io/badge/Unreal_Engine-5.5-0E1128?logo=unrealengine&logoColor=white)](https://www.unrealengine.com/)
[![C++](https://img.shields.io/badge/C%2B%2B-20-00599C?logo=cplusplus&logoColor=white)](https://isocpp.org/)
[![Git LFS](https://img.shields.io/badge/Git_LFS-enabled-F64935?logo=git-lfs&logoColor=white)](https://git-lfs.com/)
[![Just](https://img.shields.io/badge/Just-Task_Runner-000000?logoColor=white)](https://github.com/casey/just)
[![CI](https://github.com/YOUR_ORG/Unreal-Game-Template/actions/workflows/ci.yml/badge.svg)](https://github.com/YOUR_ORG/Unreal-Game-Template/actions/workflows/ci.yml)

> **Version**: 1.0
> **Last Updated**: 2026-08-02
> **Purpose**: Comprehensive guide for AI coding assistants working on a project cloned from Unreal-Game-Template

This document is the authoritative reference for AI assistants (Claude, Gemini, Copilot, etc.) working on a game built from this template. It covers mission, architecture, coding standards, and operational guidelines for a generic Unreal Engine 5 game project. **Replace the placeholder pitch in §1 with your actual game's concept** — everything else is meant to be kept largely as-is.

---

## Table of Contents

1. [Project Overview & Mission](#1-project-overview--mission)
2. [Technical Stack & Governance](#2-technical-stack--governance)
3. [Core Architectural Boundaries](#3-core-architectural-boundaries)
4. [Key CLI Entry Points (Operational Playbook)](#4-key-cli-entry-points-operational-playbook)
5. [External Access and Tool Usage Rules](#5-external-access-and-tool-usage-rules)
6. [Domain-Specific Coding Standards](#6-domain-specific-coding-standards)
7. [AI Review & Severity Protocol](#7-ai-review--severity-protocol)
8. [Known Constraints & "No-Go" Areas](#8-known-constraints--no-go-areas)
9. [Usage Note](#9-usage-note)
10. [Data Formats & Schemas](#10-data-formats--schemas)
11. [Testing Guidelines for AI](#11-testing-guidelines-for-ai)
12. [Common Patterns & Anti-Patterns](#12-common-patterns--anti-patterns)
13. [Appendix: Quick Reference](#13-appendix-quick-reference)

---

## Detailed Module Documentation

This document provides a high-level overview. For deep dives, consult [`.agent/workflows/`](workflows/) (domain playbooks), [`.agent/rules/`](rules/) (enforced constraints), and [`Moon/Roadmaps/`](../Moon/Roadmaps/) (design options and rationale per subsystem).

---

## 1. Project Overview & Mission

**GameTemplate** is a generic Unreal Engine 5 game project scaffold. Replace this section with your actual game's core concept, mission statement, and key capabilities table before starting real development — an accurate §1 is what makes `.agent/prompts/master_context.md` and `.agent/prompts/architecture_analysis.md` useful; a placeholder pitch here produces generic, low-value AI assistance.

### 1.1 Mission Statement (template)

Deliver [your game's core promise], where:

1. [Design pillar 1 — a concrete, testable property of the shipped game].
2. [Design pillar 2].
3. [Design pillar 3].

### 1.2 Key Capabilities (Target) — template

| Capability | Description |
| --- | --- |
| **[Capability]** | [What it does, in one sentence]. |
| **[Capability]** | [What it does, in one sentence]. |

---

## 2. Technical Stack & Governance

### 2.1 Runtime Environment

| Component | Specification | Notes |
| --- | --- | --- |
| **Engine** | Unreal Engine 5.5+ | Chaos Physics, substepped where high-velocity contact matters. |
| **Language** | C++20 | All gameplay-critical logic (AI, physics, core systems) is native C++. |
| **Scripting** | Blueprint | UI glue, event triggering, and designer-tunable curves **only** — never core per-tick simulation logic for many actors at once. |
| **Build** | UnrealBuildTool / RunUAT | Invoked via `just build.*` (see [`Tools/Build/justfile`](../Tools/Build/justfile)). |
| **VCS** | Git + Git LFS | All binary content (`.uasset`, `.umap`, textures, audio, meshes) **must** go through LFS — see `.gitattributes`. |

### 2.2 Primary Systems

| System | Technology | Purpose |
| --- | --- | --- |
| Physics | Chaos Physics, custom Object Channels | Deterministic, granular collision where gameplay depends on it. |
| AI | Behavior Trees + Utility AI (hybrid, where applicable) | Global director → tactical Behavior Trees → in-context Utility scoring. |
| Animation | Control Rig, IK, Physical Animation Component | Blends scripted animation into physically-driven motion where needed. |
| Audio | MetaSounds | Spatial audio, gameplay-reactive sound design. |
| Networking (optional) | Replication / rollback per genre needs | Only build out once single-player/local gameplay is validated. |

### 2.3 Quality Control Tools

| Tool | Purpose | Command |
| --- | --- | --- |
| **clang-format** | C++ style enforcement | `just validation::cpp` / `just validation::fix` |
| **Automation Testing** | UE5's native functional/unit test framework | `just test::automation` |
| **Headless simulation/QA** | Accelerated, rendering-free runs for regression telemetry | `just monitoring::headless-sim runs=1000` |
| **pre-commit** | LFS large-file gate, clang-format, markdown link check | `pre-commit run --all-files` |

---

## 3. Core Architectural Boundaries

Maintain **strict separation of concerns** across modules under `Source/GameTemplate/`:

```
Source/GameTemplate/
├── Core/              # Game mode, pawn/controller base classes, core game state
├── Physics/           # Physics Assets, custom Object Channels, collision matrix
├── AI/                # Behavior Trees, Utility AI, and/or simple controllers
├── Animation/         # (add when needed) Control Rig, IK, ragdoll blending
├── Audio/             # (add when needed) MetaSounds graphs
├── UI/                # (add when needed) HUD, menus
├── Network/           # (add when needed) replication/rollback
└── Tests/             # Automation Test specs
```

Only introduce a subfolder when its corresponding roadmap phase actually starts — don't scaffold speculative empty modules ahead of time (mirrors `Moon/ROADMAP.md`'s phased approach).

### 3.1 Critical Boundaries

| Boundary | Rule |
| --- | --- |
| Gameplay systems → rendering/UI | Core gameplay/simulation state must not depend on rendering/UI state; UI reads simulation state, it doesn't drive it. |
| AI tiers (if hybrid) | A global director sets posture → Behavior Trees enforce tactical shape → Utility AI activates for the actor(s) that need fine-grained scoring. Don't let Utility AI override Behavior Tree structural constraints for actors it doesn't own. |
| Physics determinism | Random seeds must be standardized/deterministic wherever the outcome is observed by more than one client (replay, networked play). |
| Blueprint boundary | Blueprint may read simulation state and trigger events; it must never compute per-tick spatial awareness, utility scores, or physics-based logic across many actors at once. |

---

## 4. Key CLI Entry Points (Operational Playbook)

Always reference these when proposing changes or workflows (full recipe list: `just help`):

### 4.1 Setup & Build

| Action | Command |
| --- | --- |
| Regenerate IDE project files | `just generate-project-files` |
| Build Editor target | `just build::editor` |
| Build game target (config override) | `just build.game config=Shipping` |
| Build headless dedicated-server target | `just build.server` |
| Build everything | `just build.all` |
| Package (cook + stage + archive) | `just build.package` |

### 4.2 Run

| Action | Command |
| --- | --- |
| Open the Editor | `just editor` |
| Launch standalone PIE on a map | `just play map=TestMap` |

### 4.3 Test & QA

| Action | Command |
| --- | --- |
| Full Automation Testing suite (headless) | `just test::automation` |
| Gameplay systems tests only | `just test.gameplay` |
| Physics/collision matrix tests only | `just test.physics` |
| AI scoring tests only | `just test::ai` |
| N headless simulations + telemetry | `just monitoring::headless-sim runs=1000` |
| Aggregate telemetry into a summary report | `just monitoring::analyze-telemetry` |
| Diff two telemetry summaries (regression check) | `just monitoring::diff-telemetry baseline=... current=...` |

### 4.4 Lint / Format

| Action | Command |
| --- | --- |
| Check C++ formatting | `just validation::cpp` |
| Auto-fix C++ formatting | `just validation::fix` |
| Full pre-commit run | `just validation::pre-commit` |

### 4.5 Full Local Gate

| Action | Command |
| --- | --- |
| Lint + build + automation tests | `just check` |

---

## 5. External Access and Tool Usage Rules

### 5.1 Web Search Authorization

| Purpose | Authorization Level |
| --- | --- |
| **Unreal Engine 5.x API docs** | ✅ Authorized — verify APIs against the exact engine version in use (Chaos Physics, Control Rig, MetaSounds APIs change across minor versions). |
| **Bug investigation** | ✅ Authorized — Epic's Developer Community forums, GitHub issues. |
| **Domain/genre research** | ✅ Authorized — cite sources when implementing rules or mechanics based on external references. |

### 5.2 Restricted Actions

| Action | Status | Reason |
| --- | --- | --- |
| Commit binary content outside Git LFS | ❌ Restricted | Bloats repo history irreversibly; verify `.gitattributes` coverage first. |
| Modify `Config/DefaultEngine.ini` physics substep settings | ⚠️ Requires review | Directly affects tunneling prevention and determinism. |
| Push to `main` | ❌ Restricted | Requires PR review. |
| Regenerate `.uproject` / module `.Build.cs` by hand without the Editor | ⚠️ Requires review | High risk of malformed module descriptors. |

---

## 6. Domain-Specific Coding Standards

### 6.1 UE5 C++ Conventions

**Naming prefixes** (enforced, not stylistic preference — UHT relies on them):

| Prefix | Meaning | Example |
| --- | --- | --- |
| `A` | Actor subclass | `AGameTemplateCharacter` |
| `U` | UObject subclass (non-Actor) | `UUtilityConsiderationAsset` |
| `F` | Plain struct/value type | `FGameplayEvent` |
| `E` | Enum | `EGameplayEventSeverity` |
| `I` | Interface | `IInteractable` |
| `T` | Template | `TCircularBuffer` |

```cpp
// CORRECT: engine containers, UPROPERTY-managed lifetime, explicit reflection
UCLASS()
class GAMETEMPLATE_API AGameTemplateCharacter : public ACharacter
{
    GENERATED_BODY()

public:
    UPROPERTY(EditDefaultsOnly, Category = "Physics")
    TObjectPtr<UPhysicsAsset> BodyPhysicsAsset;

    UFUNCTION(BlueprintCallable, Category = "AI")
    void EvaluateUtilityActions();

private:
    TArray<FGameplayEvent> RecentEvents;
};

// WRONG: raw pointers/STL containers for engine-managed objects bypass GC and reflection
class AGameTemplateCharacter : public ACharacter
{
    std::vector<GameplayEvent*> recentEvents; // ❌ not GC-tracked, not Blueprint-visible
};
```

**Rules**:
- Prefer `TArray`/`TMap`/`TSet` over `std::vector`/`std::map`/`std::set` for anything crossing the UObject/GC boundary.
- No C++ exceptions or RTTI (`dynamic_cast`) — UE5 builds with both disabled by default; use `Cast<T>()` and return-code/`TOptional` error handling instead.
- Every `UPROPERTY` pointer to a `UObject` uses `TObjectPtr` (UE5.1+ convention), not raw `T*`.

### 6.2 Physics & Collision

Prefer subdivided Physics Assets when per-limb/per-region fidelity matters for gameplay (hit detection, ragdoll); don't over-engineer a single capsule setup for actors where coarse collision is sufficient.

```cpp
// CORRECT: an explicit, documented collision response per channel
FootComponent->SetCollisionResponseToChannel(ECC_Interactable, ECR_Overlap);

// WRONG: relying on a default response silently changes behavior when a new
// channel is added later — always be explicit for gameplay-critical channels.
```

- Enable hit-event generation (`bGenerateOverlapEvents` / `SetNotifyRigidBodyCollision(true)`) **only** on bodies that need it — indiscriminate enabling floods the simulation with resting-contact reports and tanks performance.
- Physics substepping must stay enabled for any body involved in high-velocity contact — see [`.agent/rules/physics_collision.md`](rules/physics_collision.md).

### 6.3 Gameplay Systems

Keep gameplay-critical state machines and rules subsystems isolated from rendering/UI (§3.1). A subsystem that "holds state and reacts to events" is generally easier to reason about, test, and replay than one that directly triggers side effects the instant a condition is met — prefer the former shape unless the design explicitly calls for immediate action.

```cpp
// CORRECT: raise an event, let the owning system decide when/whether to act
if (bConditionMet)
{
    GameplaySubsystem->RaiseEvent(EventTimestamp, Context);
}

// WRONG: skipping the event bus and mutating global state directly from a
// deeply nested call site makes the trigger hard to find and test in isolation
if (bConditionMet)
{
    GameState->ForceTransition(); // ❌ no audit trail, hard to unit test
}
```

### 6.4 AI: Utility Scoring

Utility curves must be normalized to `[0.0, 1.0]` and documented with the shape (linear/quadratic/logistic/exponential-decay) they use — see [`.agent/rules/ai_behavior.md`](rules/ai_behavior.md). Never hardcode a decision by `if/else` chain where a scored consideration already exists — that reintroduces the "choice paralysis / scripted feel" a Utility-AI layer exists to avoid.

### 6.5 Code Style

- **Line length**: 120 columns (`.clang-format` enforced via `just validation::cpp`).
- **Braces**: Allman style (own line), matching Epic's public coding standard.
- **Comments**: Doxygen-style `/** */` on all public `UCLASS`/`UFUNCTION`/`UPROPERTY` declarations that aren't self-evident from naming; no restating of the signature in prose.

---

## 7. AI Review & Severity Protocol

### 7.1 CRITICAL (Must Fix Immediately)

- Gameplay subsystems mutating global/shared state directly instead of going through the established event/message path, where that path exists for a reason (auditability, replay, networking).
- Non-deterministic physics seeds where determinism is observed (replay, networked play).
- Binary assets committed outside Git LFS.
- Blueprint containing per-tick spatial/utility/physics logic across many actors.

### 7.2 HIGH (Fix Before Merge)

- Missing collision-response entries in the Object Channel matrix for a new actor type.
- Physics substepping disabled/misconfigured on a high-velocity body.
- Utility AI consideration curves not normalized to `[0.0, 1.0]`.
- Automation test regressions in CI.

### 7.3 MEDIUM (Fix Soon)

- `std::` container usage crossing the UObject/GC boundary.
- Missing Doxygen comments on public `UCLASS`/`UFUNCTION` declarations.
- Inefficient per-tick allocations in AI/physics hot paths.

### 7.4 LOW (Nice to Have)

- Naming-prefix inconsistencies in non-reflected helper types.
- Documentation typos.
- Minor UI/HUD styling.

---

## 8. Known Constraints & "No-Go" Areas

### 8.1 Engine-Regenerated Directories

| Path | Rule |
| --- | --- |
| `Binaries/`, `Intermediate/`, `Saved/`, `DerivedDataCache/` | Never edit or commit — regenerated by the Editor/UBT, excluded via `.gitignore`. |
| `*.uproject`, `Source/*/*.Build.cs`, `Source/*/*.Target.cs` | Only regenerate/modify through the Editor's "Add C++ Class" flow or with explicit human review — hand-edits are a frequent source of malformed module descriptors. |

### 8.2 Physics Sensitivity

Substepping and collision-channel configuration in `Config/DefaultEngine.ini` directly govern whether fast-moving actors tunnel through thin colliders at high velocity. Changes here require validation against `just test.physics` before merge — see [`.agent/rules/physics_collision.md`](rules/physics_collision.md).

### 8.3 Determinism for Replays & Multiplayer

Any state-machine transition logic and randomness that is observed by more than one client (replay buffer, networked reconciliation) must be reproducible. Never introduce a non-seeded `FMath::Rand()` call in a path that replay or network reconciliation will replay.

### 8.4 Protected Files

| File/Directory | Protection Level |
| --- | --- |
| `Config/DefaultEngine.ini` collision channel section | Never renumber existing Object Channels — breaks serialized Physics Assets. |
| `*.uasset` / `*.umap` | Binary, non-diffable — coordinate before editing the same asset as a teammate/agent. |
| `.env`, license files (`*.lic`) | Never commit. |

---

## 9. Usage Note

### 9.1 Session Initialization

```bash
# 1. Verify Git LFS is installed and content is pulled
git lfs install
git lfs pull

# 2. Regenerate project files if Source/ changed
just generate-project-files

# 3. Build the Editor target
just build::editor
```

### 9.2 Reference Files

| File | Purpose |
| --- | --- |
| `CLAUDE.md` / `GEMINI.md` | Pointer files to this document. |
| `Moon/ROADMAP.md` | Phased execution backlog. |
| `Docs/ARCHITECTURE.md` | System design documentation. |
| `Docs/CHANGELOG.md` | Completed-work log. |
| `Docs/Adr/` | Architecture Decision Records. |

---

## 10. Data Formats & Schemas

### 10.1 Generic Gameplay Event (template)

```cpp
struct FGameplayEvent
{
    double TimestampSeconds;
    TWeakObjectPtr<AActor> SourceActor;
    TWeakObjectPtr<AActor> TargetActor;
    FName EventType;
    FVector_NetQuantize ContactLocation;
};
```

### 10.2 Headless Telemetry Output (per simulated run) — template

```json
{
  "run_id": "sim_000482",
  "seed": 482,
  "duration_sec": 300,
  "events": 14,
  "outcome": "win",
  "ai_deadlocks": 0
}
```

---

## 11. Testing Guidelines for AI

### 11.1 Before Making Changes

```bash
# Changing Physics Assets / collision channels?
just test.physics

# Changing Behavior Tree / Utility AI scoring?
just test::ai

# Changing core gameplay-rules logic?
just test.gameplay
```

### 11.2 After Making Changes

```bash
just validation::cpp
just test::automation
```

### 11.3 Edge Cases That Must Have Explicit Coverage

- Boundary conditions of any state machine (e.g. a rule that fires exactly at a threshold).
- Determinism: same seed, same replayed output.
- Collision-response completeness: every new actor type has an entry for every existing Object Channel.
- Utility AI scoring: curve output normalized and monotonic where the design intends it.

---

## 12. Common Patterns & Anti-Patterns

### 12.1 Preferred Patterns

```cpp
// ✅ Use TObjectPtr + UPROPERTY for GC-tracked references
UPROPERTY()
TObjectPtr<UUtilityConsiderationAsset> ActionConsideration;

// ✅ Normalize utility scores explicitly, with the curve shape documented
float Score = FMath::Clamp(ExponentialDecay(DistanceToTarget, /*DecayRate=*/0.08f), 0.f, 1.f);

// ✅ Timestamp every event a rules/gameplay subsystem consumes
GameplaySubsystem->RecordEvent(GetWorld()->GetTimeSeconds(), EventContext);

// ✅ Gate heavy per-tick work behind an explicit tick interval where fidelity allows
PrimaryActorTick.TickInterval = 0.0f; // 0 for gameplay-critical actors; consider >0 for background actors
```

### 12.2 Anti-Patterns to Avoid

```cpp
// ❌ Don't compute per-actor spatial awareness in Blueprint for many actors at once
//    (severe CPU bottleneck)

// ❌ Don't use a single capsule collider where per-region fidelity is a gameplay requirement
CapsuleComponent->SetCollisionProfileName("Pawn"); // loses granularity where it matters

// ❌ Don't use Euler angles where gimbal lock risk matters (e.g. free-spinning bodies)
FRotator BodyRotation; // ❌ use FQuat under spin physics

// ❌ Don't let a rules/gameplay subsystem silently bypass its own event/audit path
if (ConditionMet) { GameState->ForceTransition(); } // ❌ removes auditability/testability

// ❌ Don't seed randomness non-deterministically in a replayed/networked path
ImpulseDirection += FMath::VRand(); // ❌ use a seeded stream when replay/network will replay this
```

---

## 13. Appendix: Quick Reference

### 13.1 Key File Locations (once `Source/` is generated)

| Purpose | Location |
| --- | --- |
| Game module entry | `Source/GameTemplate/GameTemplate.Build.cs` |
| Core gameplay | `Source/GameTemplate/Core/` |
| Physics Assets / collision config | `Source/GameTemplate/Physics/`, `Config/DefaultEngine.ini` |
| AI | `Source/GameTemplate/AI/` |
| Automation test specs | `Source/GameTemplate/Tests/` |
| Task runner recipes | `Tools/*/justfile` |

### 13.2 Environment Variables

| Variable | Purpose |
| --- | --- |
| `UE5_ROOT` | Path to the Unreal Engine install used by `Tools/Build/justfile`. |

---

**This guide is the authoritative reference for AI assistants working on a project cloned from Unreal-Game-Template. Keep it updated as the codebase evolves — and replace the placeholder §1 pitch before treating any of the domain-specific guidance as gospel for your actual game.**
