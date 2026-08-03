# Rule: AI Behavior (Behavior Trees + Utility AI)

**Scope:** `Source/GameTemplate/AI/`.

## Enforced

1. Utility consideration curves are normalized to `[0.0, 1.0]` and documented with their shape (linear/quadratic/logistic/exponential-decay) in a comment above the scoring function.
2. Structural/tactical constraints (formation, positioning discipline) live in Behavior Trees; atomic in-context action choice (what to do *right now*) lives in Utility AI. Don't let Utility AI override a Behavior Tree's positional constraint for an actor it doesn't currently own.
3. A hardcoded `if/else` decision chain is not an acceptable substitute for a scored consideration once one exists for that decision category — it reintroduces scripted-feeling, un-tunable behavior.
4. Any tie-breaking or exploration randomness in AI decision-making is seeded and reproducible wherever a replay buffer or headless simulation harness observes it.

## Rejected on sight

- A new Utility consideration whose curve isn't clamped/normalized.
- AI decision logic implemented as nested Blueprint branches for more than a couple of actors at once.

See `.agent/workflows/ai_behavior.md`.
