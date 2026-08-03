# Contributing to This Project

[![Unreal Engine 5](https://img.shields.io/badge/Unreal_Engine-5.5-0E1128?logo=unrealengine&logoColor=white)](https://www.unrealengine.com/)
[![C++](https://img.shields.io/badge/C%2B%2B-20-00599C?logo=cplusplus&logoColor=white)](https://isocpp.org/)
[![Git LFS](https://img.shields.io/badge/Git_LFS-enabled-F64935?logo=git-lfs&logoColor=white)](https://git-lfs.com/)

> **Version**: 1.0
> **Last Updated**: 2026-08-02

Thank you for your interest in contributing! This document covers setup, code style, the C++/Blueprint boundary, Git workflow, and the PR process specific to a UE5 game project cloned from Unreal-Game-Template.

---

## Table of Contents

1. [Getting Started](#1-getting-started)
2. [Development Setup](#2-development-setup)
3. [The C++/Blueprint Boundary](#3-the-cblueprint-boundary)
4. [Code Style Guidelines](#4-code-style-guidelines)
5. [Git Workflow](#5-git-workflow)
6. [Pull Request Process](#6-pull-request-process)
7. [Testing Requirements](#7-testing-requirements)
8. [Working with Binary Content (Git LFS)](#8-working-with-binary-content-git-lfs)
9. [Issue Reporting](#9-issue-reporting)
10. [Community Standards](#10-community-standards)

---

## 1. Getting Started

### 1.1 Prerequisites

- Unreal Engine 5.5+ with the C++ toolchain (Visual Studio 2022 on Windows, Clang on Linux)
- Git + [Git LFS](https://git-lfs.com/)
- [`just`](https://github.com/casey/just)
- [`pre-commit`](https://pre-commit.com/)
- Familiarity with UE5's `UCLASS`/`UPROPERTY`/`UFUNCTION` reflection system, Behavior Trees, and Chaos Physics basics

### 1.2 Finding Issues to Work On

- **Good First Issues**: labeled `good-first-issue`
- **Help Wanted**: labeled `help-wanted`
- **Bug Fixes**: labeled `bug`
- **Feature Requests**: labeled `feature`

Issues use the structured templates under [`.github/ISSUE_TEMPLATE/`](../.github/ISSUE_TEMPLATE/) — fill in Component and Priority exactly as listed; these map to Project Board fields.

---

## 2. Development Setup

```bash
git lfs install
git clone https://github.com/YOUR_ORG/YOUR_GAME.git
cd YOUR_GAME
git remote add upstream https://github.com/YOUR_ORG/YOUR_GAME.git

just generate-project-files
just build::editor

pip install pre-commit
pre-commit install
```

---

## 3. The C++/Blueprint Boundary

This is the single most important architectural rule in the project (see [`.agent/AGENTS.md`](../.agent/AGENTS.md) §3.1 and §6.1):

| Layer | Allowed | Forbidden |
| --- | --- | --- |
| **C++** (`Source/`) | All gameplay-critical logic: AI, physics/collision, core rules/state machines, animation blending | — |
| **Blueprint** | UI event glue, designer-tunable curves/Data Assets, one-off scripted sequences (cutscenes, menus) | Per-tick spatial/utility/physics computation across many AI actors |

If you're unsure which side a piece of logic belongs on, default to C++ and expose only the specific tunable parameters designers need via `UPROPERTY(EditDefaultsOnly)`.

---

## 4. Code Style Guidelines

### 4.1 C++ Style

| Rule | Specification |
| --- | --- |
| Line length | 120 characters |
| Braces | Allman (own line) |
| Naming | UE5 prefixes: `A`/`U`/`F`/`E`/`I`/`T` — see `.agent/rules/cpp_gameplay.md` |
| Containers | `TArray`/`TMap`/`TSet`, not `std::` equivalents, across the UObject/GC boundary |
| Comments | Doxygen `/** */` on public declarations only where the name isn't self-evident |

```bash
just validation::cpp     # check formatting
just validation::fix     # auto-fix formatting
```

### 4.2 Blueprint Style

- Name Blueprint assets with a `BP_` prefix.
- Keep event graphs shallow — extract reusable logic into a C++ base class or a Blueprint Function Library rather than duplicating graph logic across widgets/actors.

---

## 5. Git Workflow

### 5.1 Branch Naming

```
<type>/<short-description>
```

| Type | Purpose |
| --- | --- |
| `feature/` | New features |
| `fix/` | Bug fixes |
| `physics/` | Collision/Chaos-specific changes |
| `ai/` | Behavior Tree / Utility AI changes |
| `Docs/` | Documentation changes |
| `ci/` | CI/CD changes |
| `perf/` | Performance improvements |

### 5.2 Commit Messages

Follow [Conventional Commits](https://www.conventionalcommits.org/):

```
<type>(<scope>): <description>

[optional body]

[optional footer(s)]
```

Example:

```
feat(ai): add flanking consideration to attack utility set

Adds a normalized exponential-decay consideration scoring lateral
approach angle, so the AI stops funneling exclusively down the center.

Closes #42
```

---

## 6. Pull Request Process

1. Ensure `just check` passes locally (lint + build + automation tests).
2. Fill in the [PR template](../.github/PULL_REQUEST_TEMPLATE.md) completely, including Component/Priority matching a Project Board option verbatim.
3. For any change affecting AI weights, physics constants, or run/match statistics, include a `just monitoring::diff-telemetry` result in the Test Plan.
4. At least one approval required; automated checks (CI) must pass.

---

## 7. Testing Requirements

| Change type | Required coverage |
| --- | --- |
| Core gameplay/rules | `just test.gameplay`, including state-machine boundary cases |
| Physics/collision | `just test.physics`, including both a Block-path and an Overlap-path case |
| AI/Utility | `just test::ai` + a `just monitoring::headless-sim` statistical diff for any weight change |
| Everything else | `just test::automation` |

See [`.agent/rules/testing_qa.md`](../.agent/rules/testing_qa.md) for the full edge-case philosophy.

---

## 8. Working with Binary Content (Git LFS)

- Run `git lfs install` once per machine and `git lfs pull` after every fetch/clone.
- New binary asset extensions must be added to [`.gitattributes`](../.gitattributes) **before** the first file of that type is committed.
- `pre-commit`'s `check-added-large-files` hook will block a >1MB file that isn't LFS-tracked — this is intentional, not a bug to work around.
- Never `git add -f` a Binaries/Intermediate/Saved path.

---

## 9. Issue Reporting

Use the [bug](../.github/ISSUE_TEMPLATE/bug_agent.yml) or [feature](../.github/ISSUE_TEMPLATE/feature_agent.yml) issue templates. For simulation/AI bugs, include the headless-sim seed if you have one — it turns an intermittent report into a reproducible one.

---

## 10. Community Standards

We are committed to a welcoming, inclusive environment. Be respectful, be constructive, be patient, and welcome diverse perspectives.

---

## License

By contributing, you agree that your contributions will be licensed under the same license as the project ([MIT](../LICENSE)).

---

**Thank you for contributing!**
