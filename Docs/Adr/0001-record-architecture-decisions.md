# 1. Record architecture decisions

Date: 2026-08-02

## Status

Accepted

## Context

We need a lightweight way to record significant, hard-to-reverse technical decisions so future contributors (human or LLM agent) understand *why* the system looks the way it does, not just *what* it does.

## Decision

We will use Architecture Decision Records (ADRs), one per decision, numbered sequentially under `Docs/Adr/`, following the format described by [Michael Nygard](https://cognitect.com/blog/2011/11/15/documenting-architecture-decisions).

## Consequences

- Every ADR is immutable once accepted; a reversal gets a new ADR that supersedes it, rather than editing history.
- `Docs/ARCHITECTURE.md` links to relevant ADRs instead of re-explaining their reasoning.
- `.agent/prompts/architecture_analysis.md` and `.agent/workflows/documentation.md` both reference `Docs/Adr/` as a required check before proposing or landing an architectural change.
