# Workflow: Physics & Collision Changes

1. **Identify the channel(s) affected.** Check `Source/GameTemplate/Physics/` for existing named channels before adding a new `ECC_GameTraceChannelN`.
2. **Update the response matrix.** Every actor type that can touch the new/changed channel needs an explicit response — update the matrix table in the relevant header's doc comment.
3. **Register in `Config/DefaultEngine.ini`.** New channel name goes under `[/Script/Engine.CollisionProfile]` `+DefaultChannelResponses`.
4. **Validate substepping.** If the change involves a high-velocity body, confirm `bSubstepping=True` is still in effect and run `just test.physics`.
5. **Debug visually first.** Use collision contact markers / `p.chaos` debug draw commands before reading logs — a wrong response is usually visible immediately.
6. **Test.** Add both a Block-path and an Overlap-path Automation Test case for the new response.
