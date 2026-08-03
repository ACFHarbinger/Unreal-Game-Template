# Skill: Add a Utility AI Consideration

**When to use:** Adding a new scoring factor to a Utility AI decision (e.g., a new consideration for an existing action, or a new action entirely).

## Steps

1. Add a `UUtilityConsiderationAsset`-derived (or equivalent scoring function) with a documented curve shape (linear/quadratic/logistic/exponential-decay).
2. Clamp the output to `[0.0, 1.0]` — no exceptions.
3. Wire it into the relevant action's consideration set, following whatever aggregation the existing Utility AI uses (product, weighted average, etc. — match the existing pattern, don't introduce a second aggregation scheme without an ADR).
4. Add a deterministic unit test: fixed input → expected score, at minimum at the curve's boundaries (0, 1, and one interior point).
5. If this changes existing action selection frequency in aggregate, run `just monitoring::headless-sim runs=100` before/after and attach `monitoring::diff-telemetry` output to the PR.
