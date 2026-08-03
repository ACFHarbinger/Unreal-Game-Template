# Rule: Networking & Multiplayer

**Scope:** `Source/GameTemplate/Network/` (introduce when networking work starts).

## Enforced

1. Replicated properties use the narrowest `UPROPERTY(Replicated...)` condition that's correct (`COND_OwnerOnly`, `COND_SkipOwner`, etc.) — don't default to unconditional replication for actor-heavy scenes.
2. Server-authoritative gameplay logic never trusts a client-reported value for anything that affects match/game state outside cosmetic prediction.
3. Any rollback/reconciliation path depends on the same determinism guarantees as replay (`.agent/AGENTS.md` §8.3) — seeded randomness, reproducible state transitions.
4. RPCs are the narrowest type that satisfies the use case (`Server`/`Client`/`NetMulticast`, `Reliable`/`Unreliable`) — document why `Reliable` was chosen when used, since it has bandwidth/ordering cost.

## Rejected on sight

- Client-authoritative gameplay-affecting state with no server validation.
- A new replicated actor with no thought given to relevancy/priority for large actor counts.

See `.agent/workflows/networking_multiplayer.md`.
