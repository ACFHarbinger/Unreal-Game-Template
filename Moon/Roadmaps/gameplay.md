# Roadmap: Gameplay Systems

## 1. Core Game State

**Goal:** a single, authoritative core game-state/rules subsystem that other systems (AI, UI, audio) read from and emit events to, rather than each maintaining their own copy of "what's currently true."

### Options

- **Option A — Single `UGameInstanceSubsystem` owning all core state.** Simple, centralized, easy to reason about. Risk: becomes a god-object if not disciplined about what belongs in it vs. in per-actor components.
- **Option B — Distributed state across `AGameStateBase`/`APlayerState`/per-actor components, coordinated by events.** More idiomatic UE5, scales better to multiplayer replication. Risk: harder to get a single "current state" snapshot for debugging/telemetry.
- **Option C — Hybrid: `AGameStateBase` for replicated/networked-visible state, a subsystem for server-only bookkeeping.** Recommended starting point — matches UE5's own separation of concerns and defers a full Option B redesign until multiplayer is actually needed.

**Recommendation:** Option C. Start with `AGameTemplateGameMode`/`AGameTemplateGameState` per the standard UE5 pattern; introduce a subsystem only for genuinely server-only bookkeeping that doesn't need replication.

## 2. Rules Engine

**Goal:** if the game has non-trivial rules/adjudication logic (turn structure, scoring, win conditions), isolate it from rendering/UI per `.agent/AGENTS.md` §3.1.

Pattern: the rules subsystem holds state and raises events; it does not directly mutate other systems' state or trigger UI transitions itself. See `.agent/rules/documentation.md` and `.agent/workflows/error_debug.md` for why this shape is preferred — it's independently testable and produces an audit trail for free.

## 3. Edge Cases

Track known edge cases in rules/state-machine logic here as they're discovered, with a link to the regression test that covers each one. Empty until Phase 1 lands.
