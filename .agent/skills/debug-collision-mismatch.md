# Skill: Debug a Collision Response Mismatch

**When to use:** Two actors are interacting differently than the response matrix says they should (e.g., something Blocks when it should Overlap).

## Steps

1. Reproduce with `p.chaos` or the engine's collision debug draw enabled to see the actual response in real time.
2. Check each actor's constructor for an explicit `SetCollisionResponseToChannel` call — a missing one falls back to the profile default, which frequently isn't what the matrix table documents.
3. Confirm the channel wasn't accidentally renumbered (compare `Source/GameTemplate/Physics/` against `Config/DefaultEngine.ini`'s registered names — they must agree).
4. Check for a collision **profile** (`SetCollisionProfileName`) silently overriding a per-channel response set earlier in the same constructor — profile assignment order matters.
5. Once fixed, add the missing response as an explicit test case per `.agent/rules/physics_collision.md`.
