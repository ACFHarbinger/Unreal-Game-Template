# Skill: Add a Physics Collision Channel

**When to use:** A new gameplay interaction needs its own Object Channel (not adequately covered by `WorldStatic`/`Pawn`/etc.).

## Steps

1. Pick the next unused `ECC_GameTraceChannelN` slot — check `Source/GameTemplate/Physics/` for the highest one in use.
2. Add the named alias to the `GameTemplateCollision` namespace (or equivalent) in `Source/GameTemplate/Physics/`.
3. Register the name in `Config/DefaultEngine.ini` under `[/Script/Engine.CollisionProfile]` `+DefaultChannelResponses`.
4. Update the collision-response matrix doc comment (in the same header) with the new channel's Block/Overlap/Ignore behavior against every existing channel.
5. Set explicit responses in every actor constructor that should interact with the new channel — don't rely on the engine default.
6. Add both a Block-path and an Overlap-path Automation Test.
7. **Never renumber an existing channel** — see `.agent/rules/physics_collision.md`.
