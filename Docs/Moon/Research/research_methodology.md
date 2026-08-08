# Research Methodology & Guidelines

Guidelines and protocols for conducting technical research, architectural spikes, and Unreal Engine 5 feature evaluations.

## Overview

In this project, research is a collaborative effort to explore new C++ gameplay systems, evaluate Unreal Engine 5 plugins and rendering pipelines, and prototype subsystem capabilities before they are formally adopted into `Source/GameTemplate/`. This document outlines our standard research methodology to ensure that findings are structured, reproducible, and aligned with our system design principles.

---

## 1. Initiating Research

Research is typically initiated via an issue labeled with `type/research` or `type/spike`. Before starting:
1. Create a dedicated feature branch named `research/<issue-number>-<short-description>`.
2. Define clear boundaries to avoid "scope creep". A research spike should have a fixed duration (usually 2-5 days).

## 2. Research Steps

### Phase 1: Literature & Ecosystem Review
Explore Epic Games documentation, C++ API specs, and community plugins. Document options in the research note.

### Phase 2: Prototyping (Spikes)
Build a minimalist proof-of-concept. Experimental code should:
- Live in `Source/GameTemplate/` (or a dedicated plugin under `Plugins/`) but be clearly isolated (e.g. in a `Spike/` or `Experimental/` namespace).
- Avoid changing existing production code interfaces unless necessary.
- Include a minimal C++ test driver or test map to demonstrate functionality.

### Phase 3: Evaluation
Benchmark frame times, memory allocations, draw calls, and assess developer ergonomics in Unreal Editor.

## 3. Documenting Findings

Upon completion, the researcher must compile findings into a research note under `Docs/Moon/Research/` utilizing the `TEMPLATE.md` structure. The research note must be committed to the branch, and a Pull Request opened for review.
Once the PR is approved and merged, the decisions made should be codified in an [Architectural Decision Record (ADR)](../Adr/0001-record-architecture-decisions.md) if they alter the project's long-term structure or technologies.
