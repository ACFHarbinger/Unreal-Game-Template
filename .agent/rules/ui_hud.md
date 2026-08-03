# Rule: UI / HUD

**Scope:** `Source/GameTemplate/UI/` (introduce when UI work starts), UMG widgets.

## Enforced

1. UI reads gameplay/simulation state; it never computes or mutates it. A widget that decides gameplay outcomes (rather than displaying them) is a boundary violation — see `.agent/AGENTS.md` §3.1.
2. Widgets update via bound gameplay events/delegates, not per-tick polling of arbitrary game state, unless the polled value genuinely changes every frame (e.g., a live meter).
3. HUD elements that render per-tick data for many actors (e.g., markers over a crowd) batch their draw calls rather than issuing one Slate/UMG element per actor naively.

## Rejected on sight

- A Blueprint widget event graph that decides a gameplay outcome (e.g., which actor "wins" an interaction) instead of just displaying a result computed in C++.
- Per-actor UMG widgets spawned for every actor in a large simulated population without a pooling/batching strategy.

See `.agent/workflows/ui_hud.md`.
