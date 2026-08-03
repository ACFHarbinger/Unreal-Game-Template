# Source/

C++ game modules for `GameTemplate.uproject`.

```
Source/
├── GameTemplate.Target.cs         # Game target
├── GameTemplateEditor.Target.cs   # Editor target
├── GameTemplateServer.Target.cs   # Headless dedicated-server target (Infra/Docker, Tools/Monitoring)
└── GameTemplate/                  # The one runtime module (GameTemplate.Build.cs)
    ├── Core/          # Game mode, character, player controller
    ├── Physics/       # Custom Object Channel constants (Config/DefaultEngine.ini registers the names)
    ├── AI/            # (empty placeholder — add Behavior Tree/Utility AI code here)
    └── Tests/          # Compiled Automation Test specs (IMPLEMENT_SIMPLE_AUTOMATION_TEST)
```

**Status**: Phase 0 (Pure Geometry Prototype, [`Moon/ROADMAP.md`](../Moon/ROADMAP.md)) scaffolding is authored — `AGameTemplateGameMode` spawns a ground plane and a handful of `AGameTemplateCharacter` placeholder actors using the engine's built-in basic-shape meshes, so no `Content/` assets are required to compile and run.

**This has not been compiled or run** — it was authored without a licensed Unreal Engine install available in the authoring environment. Before trusting any of it:

1. `git lfs pull` (harmless no-op today — no LFS content exists yet).
2. `just generate-project-files` to generate IDE project files.
3. `just build::editor` and fix whatever the compiler flags — hand-authored UE5 C++ without a compiler in the loop is exactly the risk `.agent/AGENTS.md` §8.1 calls out.
4. Create the one missing manual asset (`Content/Maps/TestMap`) — see [`Content/README.md`](../Content/README.md).
5. `just test::automation` to run `GameTemplate.Core.Sanity`.

Planned module growth beyond Phase 0, per `.agent/AGENTS.md` §3: `AI/` (real Behavior Tree/Utility AI code), `Animation/`, `Audio/`, `UI/`, `Network/` — each introduced when its corresponding roadmap phase actually starts, not speculatively ahead of time.

**Rename checklist** when cloning this template for a real project: replace `GameTemplate` with your project name across every file in this directory, the `.uproject`, `Config/*.ini` (`ProjectName`), the root `Justfile` (`project_name :=`), and `.agent/AGENTS.md`.
