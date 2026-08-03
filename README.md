<div align="center">

# Unreal-Game-Template

**A generic Unreal Engine 5 project template — clone it, rename `GameTemplate`, start shipping.**
Combines standard Unreal Engine project conventions with an "agentic" LLM-assisted dev framework (`.agent/`), full DevOps tooling (`Infra/`, `.devcontainer/`, `.github/`), and documentation scaffolding, so a new project starts with governance and CI already solved.

<img alt="CI" src="https://img.shields.io/github/actions/workflow/status/YOUR_ORG/Unreal-Game-Template/ci.yml?branch=main&label=CI">
<img alt="Docs" src="https://img.shields.io/github/actions/workflow/status/YOUR_ORG/Unreal-Game-Template/docs.yml?branch=main&label=docs">
<img alt="PRs Welcome" src="https://img.shields.io/badge/PRs-welcome-brightgreen.svg">
<a href="LICENSE"><img alt="License: MIT" src="https://img.shields.io/badge/License-MIT-blue.svg"></a>

</br>

<img alt="Unreal Engine 5" src="https://img.shields.io/badge/Unreal_Engine-5.5-0E1128?logo=unrealengine&logoColor=white">
<img alt="C++" src="https://img.shields.io/badge/C%2B%2B-20-00599C?logo=cplusplus&logoColor=white">
<img alt="Git LFS" src="https://img.shields.io/badge/Git_LFS-enabled-F64935?logo=git-lfs&logoColor=white">
<img alt="Just" src="https://img.shields.io/badge/Just-Task_Runner-000000?logoColor=white">
<img alt="Dependabot" src="https://img.shields.io/badge/Dependabot-enabled-025E8C?logo=dependabot&logoColor=white">
<img alt="pre-commit" src="https://img.shields.io/badge/pre--commit-FAB040?logo=pre-commit&logoColor=white">

<p>
  <a href="#what-this-is"><strong>What This Is</strong></a> |
  <a href="#using-this-template"><strong>Using This Template</strong></a> |
  <a href="#repository-layout"><strong>Layout</strong></a> |
  <a href="#getting-started"><strong>Getting Started</strong></a> |
  <a href="#the-agent-framework"><strong>.agent/ Framework</strong></a> |
  <a href="#devops--hosting"><strong>DevOps & Hosting</strong></a> |
  <a href="#contributing"><strong>Contributing</strong></a>
</p>

</div>

---

## What This Is

This is not a game — it is a **starting point for one**. Clone it, do a project-wide rename of `GameTemplate` to your real project name, and you inherit:

- A clean `Source/GameTemplate/` module (GameMode, Character, PlayerController stubs) following standard UE5 conventions, ready to build.
- An `.agent/` framework of prompts, rules, workflows, and skills so Claude/Gemini/Copilot-class coding assistants have consistent, enforced guardrails from commit one.
- CI/CD (`.github/workflows/`), a `Justfile` task runner, lint/test/QA tooling (`Tools/`), and pre-commit gates.
- Dedicated-server hosting scaffolding (`Infra/`) for when you need matchmaking and headless Linux servers in production, plus a devcontainer for consistent local C++ tooling.
- Documentation scaffolding (`Docs/`, `Moon/`) with ADRs, a phased roadmap format, and an architecture doc template.

## Using This Template

1. Clone (or use GitHub's "Use this template" if you push this to a template repo).
2. Rename the project: `GameTemplate` → `YourGameName` across `*.uproject`, `Source/GameTemplate/**`, `Source/GameTemplate.Target.cs`, `Source/GameTemplateEditor.Target.cs`, `Config/*.ini` (`ProjectName`), `Justfile` (`project_name :=`), and `.agent/AGENTS.md`.
3. Open in the Unreal Editor once to let it regenerate `Binaries/`/`Intermediate/` and confirm the module compiles.
4. Replace this README's pitch/design-pillars sections with your actual game's concept — everything else (tooling, CI, `.agent/`) is meant to be kept as-is.
5. Delete `Plugins/README.md`'s placeholder note once you've added real plugins, and delete any `Infra/` subsystem you don't need (see each subdirectory's `README.md`).

## Repository Layout

```
Unreal-Game-Template/
├── Source/            # C++ game modules — Source/GameTemplate/{Core,AI,Physics,Tests}
├── Content/           # UE5 content (binary, Git LFS) — empty placeholder until first asset
├── Config/            # DefaultEngine/Game/Input/Editor.ini
├── Plugins/           # Optional first-party/third-party plugins (see Plugins/README.md)
├── Tools/             # Just submodules: build, ci, helper, lint, qa, test
├── Docs/              # Architecture, changelog, ADRs, mkdocs site source
├── Moon/              # Master roadmap + per-domain roadmap docs
├── Docker/            # Headless Linux build/CI/docs container definitions
├── Infra/             # Dedicated-server hosting: docker, k8s, helm, terraform, ansible
├── .devcontainer/     # VS Code Dev Container for UE C++ tooling
├── .agent/            # AI coding-assistant instructions, prompts, rules, workflows, skills
├── .github/           # Issue/PR templates, CI/Docs/agent-sync workflows, Dependabot
├── Git/               # CONTRIBUTING.md, codecov.yaml, hooks/pre-commit
└── Justfile           # Root task-runner entry point
```

Unreal Engine's own conventions (`Source/`, `Content/`, `Config/`, `Plugins/`, `Docker/`) keep PascalCase; the cross-cutting framework directories (`.agent/`, `Docs/`, `Git/`, `Moon/`, `Infra/`, `.devcontainer/`) are lowercase per this template's cross-project standard.

## Getting Started

### Prerequisites

- [Unreal Engine 5.5+](https://www.unrealengine.com/) with the C++ toolchain (Visual Studio 2022 on Windows, or Clang on Linux)
- [Git LFS](https://git-lfs.com/) — required once `Content/` holds real binary assets
- [`just`](https://github.com/casey/just) — task runner used for all build/test/lint recipes
- [`pre-commit`](https://pre-commit.com/) — for local formatting/lint gates

### Clone & build

```bash
git lfs install
git clone https://github.com/YOUR_ORG/Unreal-Game-Template.git
cd Unreal-Game-Template

just generate-project-files
just build::editor
just editor
```

### Local dev gates

```bash
pre-commit install
just check   # clang-format check + editor build + automation tests
```

Run `just help` (or `just` with no arguments) for the full recipe list, and `just <module>::` (e.g. `just build::`) to list a submodule's recipes.

## The `.agent/` Framework

[`​.agent/AGENTS.md`](.agent/AGENTS.md) is the authoritative reference for AI coding assistants (Claude, Gemini, Copilot, etc.) working in a repo cloned from this template. It documents architecture boundaries, coding standards, and operational guardrails, and is genericized to any gameplay domain:

- [`.agent/rules/`](.agent/rules/) — enforced constraints per domain (`cpp_gameplay`, `animation_rigging`, `audio_metasounds`, `networking_multiplayer`, `ui_hud`, `physics_collision`, `ai_behavior`, `testing_qa`, `error_debug`, `documentation`, `code_review`, `reasoning_planning`).
- [`.agent/workflows/`](.agent/workflows/) — the operational playbook matching each rules file 1:1.
- [`.agent/skills/`](.agent/skills/) — narrow, repeatable task recipes (adding a Behavior Tree task, adding a collision channel, running automation tests, etc.).
- [`.agent/prompts/`](.agent/prompts/) — copy/paste prompt templates for common session types (feature implementation, debugging, refactor safety, architecture analysis, documentation sync, master context init).

`CLAUDE.md` and `GEMINI.md` at the repo root are one-line pointers into `.agent/AGENTS.md` so every assistant reads the same source of truth.

## DevOps & Hosting

- **CI** (`.github/workflows/ci.yml`) — clang-format + markdown lint on GitHub-hosted runners; UnrealBuildTool build + Automation Tests on a self-hosted `ue5`-labeled runner.
- **Docs** (`.github/workflows/docs.yml`) — builds and deploys the MkDocs site from `Docs/` to GitHub Pages.
- **Agent sync** (`.github/workflows/agent_sync.yml`) — syncs `Moon/ROADMAP.md`/`Docs/CHANGELOG.md` deltas to a GitHub Project board.
- **Dedicated servers** (`Infra/`) — `Infra/Docker/` (Linux headless server image + matchmaking-adjacent local stack), `Infra/K8s/` (Kustomize base+overlays for running dedicated server pods), `Infra/Helm/` (chart alternative to raw `kubectl apply -k`), `Infra/Terraform/` (cloud resource skeleton — registry, cluster, managed DB for match/session state), `Infra/Ansible/` (bare-metal/VM provisioning for self-hosted CI or dedicated-server fleets outside k8s).
- **Dev Container** (`.devcontainer/`) — clang, CMake, and the .NET/Mono runtime UnrealBuildTool needs, for a consistent local C++ toolchain independent of host OS.

## Contributing

See [`Git/CONTRIBUTING.md`](Git/CONTRIBUTING.md) for branch naming, commit conventions, the C++/Blueprint boundary rules, and the PR process. Issues use the templates under [`.github/ISSUE_TEMPLATE/`](.github/ISSUE_TEMPLATE/) (structured, agent-parsable for backlog automation).

## Documentation

| Document | Purpose |
| --- | --- |
| [`.agent/AGENTS.md`](.agent/AGENTS.md) | Authoritative reference for AI coding assistants. |
| [`Moon/ROADMAP.md`](Moon/ROADMAP.md) | Phased execution backlog template. |
| [`Docs/CHANGELOG.md`](Docs/CHANGELOG.md) | Completed-work log. |
| [`Docs/ARCHITECTURE.md`](Docs/ARCHITECTURE.md) | System design template. |
| [`Docs/Adr/`](Docs/Adr/) | Architecture Decision Records. |
| [`Git/CONTRIBUTING.md`](Git/CONTRIBUTING.md) | Contribution guidelines. |

---

<div align="center">

Licensed under [MIT](LICENSE).

</div>
