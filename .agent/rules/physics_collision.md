# Rule: Physics & Collision

**Scope:** `Source/GameTemplate/Physics/`, `Config/DefaultEngine.ini` collision sections, any actor constructor setting collision responses.

## Enforced

1. Every custom Object Channel is named and registered in `Config/DefaultEngine.ini` under `[/Script/Engine.CollisionProfile]`, with the C++-side alias living in `Source/GameTemplate/Physics/` — never a bare `ECC_GameTraceChannelN` magic number in gameplay code.
2. Object Channel numbers are never renumbered once shipped — it silently breaks every already-serialized Physics Asset that references them.
3. Every new actor type gets an explicit Block/Overlap/Ignore response entry for every existing custom channel — no relying on the engine default for gameplay-relevant channels.
4. Physics substepping (`bSubstepping=True`) stays enabled for any body involved in high-velocity contact; `MaxSubstepDeltaTime`/`MaxSubsteps` changes require a `just test.physics` pass before merge.
5. `bGenerateOverlapEvents` / `SetNotifyRigidBodyCollision(true)` enabled only where gameplay actually consumes the event — indiscriminate enabling floods the simulation with resting-contact reports.

## Rejected on sight

- A new actor type with no entry in the collision-response matrix for an existing custom channel.
- Disabling substepping on a body with high-velocity contact without an explicit performance justification and a `monitoring::diff-telemetry` result attached.

See `.agent/workflows/physics_collision.md`.
