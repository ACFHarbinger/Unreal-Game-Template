# Rule: Animation & Rigging

**Scope:** `Source/GameTemplate/Animation/` (introduce when animation work starts), Control Rig assets, Physical Animation Component usage.

## Enforced

1. Blend weights between scripted animation and physics-driven motion (ragdoll, physical animation) are exposed as tunable `UPROPERTY(EditDefaultsOnly)` curves, not hardcoded constants — animators need to iterate without a C++ recompile.
2. IK targets are computed in C++ for anything driving more than a handful of actors per tick; Blueprint IK setup is fine for one-off/cinematic rigs.
3. Ragdoll/physical-animation impulse randomness is seeded wherever a replay buffer or networked client observes the result (see `.agent/AGENTS.md` §8.3).
4. Use `FQuat` for any rotation under active physics/spin — `FRotator` Euler angles risk gimbal lock.

## Rejected on sight

- A blend weight hardcoded as a magic number instead of an exposed, documented curve.
- Non-seeded `FMath::VRand()`/`FMath::Rand()` in a ragdoll impulse path that's part of a replay or networked flow.

See `.agent/workflows/animation_rigging.md`.
