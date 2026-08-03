# GameTemplate — Changelog

*Completed items are archived here from [`Moon/ROADMAP.md`](../Moon/ROADMAP.md), most recent first. An item lives in exactly one of the two documents at a time — see [`.agent/rules/documentation.md`](../.agent/rules/documentation.md).*

---

## Unreleased

Template scaffolding established: `.agent/` AI-assistant instructions (prompts, rules, workflows, skills), `.github/` issue/PR templates and CI/Docs/agent-sync workflows, `Moon/` roadmap structure, `Tools/` Just task-runner submodules, `Infra/` dedicated-server hosting scaffolding (Docker, Kubernetes, Helm, Terraform, Ansible), `.devcontainer/` for consistent local C++ tooling, and pre-commit gates.

Phase 0 (Pure Geometry Prototype) gameplay scaffolding authored — **not yet compiled or validated** against a licensed Unreal Engine install, so this stays in `Moon/ROADMAP.md` as in-progress rather than landing here as a dated, completed entry (see `.agent/rules/documentation.md`'s one-source-of-truth rule):

- `GameTemplate.uproject` + `Source/{GameTemplate,GameTemplateEditor}.Target.cs` + `Source/GameTemplate/GameTemplate.Build.cs` — module/target scaffolding.
- `Source/GameTemplate/Core/{GameTemplateGameMode,GameTemplateCharacter,GameTemplatePlayerController}.*` — minimal GameMode/Character/PlayerController stubs following the `AMARLGameCharacter`/`AFootballRefereeGameMode`-style naming pattern.
- `Source/GameTemplate/Tests/GameTemplateGameModeTest.cpp` — placeholder deterministic Automation Test.

See [`Source/README.md`](../Source/README.md) and [`Content/README.md`](../Content/README.md) for the exact steps needed to compile and run this for the first time.

---

*Nothing shipped yet. This file's format follows [Keep a Changelog](https://keepachangelog.com/): each dated entry cites concrete files/functions/config keys changed, not vague summaries — see prior entries as they accumulate for the expected level of detail.*
