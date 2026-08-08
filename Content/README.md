# Content/

Empty by design. `Content/` holds Unreal's binary asset formats (`.uasset`, `.umap`) which are Git LFS-tracked (see [`.gitattributes`](../.gitattributes)) and cannot be hand-authored outside the Editor — so this repo ships no binary assets, only this placeholder.

## The one manual step required to run Phase 0

`Config/DefaultEngine.ini` points the project's default map at `/Game/Maps/TestMap`, which doesn't exist yet. `AGameTemplateGameMode` spawns everything it needs at runtime (ground plane, placeholder actors) using engine built-in basic-shape meshes, so the level itself can be **completely empty**:

1. Open the project in the Unreal Editor (`just editor`, after `just build::editor` succeeds).
2. **File → New Level → Empty Level**.
3. **File → Save Current Level As...** → `Content/Maps/TestMap`.
4. Press Play — the GameMode's `BeginPlay` should spawn the ground plane and placeholder actors.

If it doesn't work as described, that's expected risk called out in [`Source/README.md`](../Source/README.md) — this code was authored without a licensed UE5 install to compile/run it against. File the discrepancy as a `bug` issue with the exact error, per [`.github/ISSUE_TEMPLATE/bug_agent.yml`](../.github/ISSUE_TEMPLATE/bug_agent.yml).

No other `Content/` assets are required until `Docs/Docs/Moon/ROADMAP.md` Phase 3 (Vertical Slice) — see [`Docs/Docs/Moon/Roadmaps/architecture.md`](../Docs/Moon/Roadmaps/architecture.md) §1 for the planned asset pipeline.
