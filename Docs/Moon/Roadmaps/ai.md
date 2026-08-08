# Roadmap: AI

## 1. Behavior Trees

**Goal:** structural/tactical AI — formation, positioning discipline, high-level task selection.

### Options

- **Option A — One Behavior Tree per archetype/role.** Easy to author and debug per-role, but duplicated substructure across similar roles.
- **Option B — One shared Behavior Tree with role-conditional branches (Blackboard-driven).** Less duplication, harder to visually debug per-role behavior.

**Recommendation:** Start with Option A for the first 2-3 roles; refactor toward shared subtrees (Behavior Tree's native "linked tree" feature) once duplication becomes a maintenance cost, not before.

## 2. Utility AI

**Goal:** atomic in-context action scoring for the actor(s) that need fine-grained decision-making (see `.agent/rules/ai_behavior.md`).

Canonical consideration set: define per-action considerations here as they're implemented, each with its curve shape and normalization documented. Empty until Phase 1 lands.

## 3. Navigation

Nav mesh validation and AI clumping-avoidance strategy (e.g., RVO avoidance, formation offsets) — track findings and configuration here as Phase 1 work begins.
