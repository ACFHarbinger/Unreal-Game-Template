# Roadmap: Animation & Audio

## 1. IK Targeting

Full-Body IK / Control Rig targeting for procedural interaction (reaching, foot placement, look-at) — plan per-actor requirements here before implementation. See `.agent/rules/animation_rigging.md`.

## 2. Ragdoll Blending

Kinematic-to-ragdoll (or physical-animation) blend strategy on impact/death/knockback. Track the blend-weight curve design and impulse-determinism requirements here (see `.agent/AGENTS.md` §8.3).

## 3. MetaSounds

Spatial audio and gameplay-reactive sound design plan. Define the parameter surface (see `.agent/rules/audio_metasounds.md`) before building graphs.

## 4. Crowd / Ambient Systems (if applicable)

Placeholder for any ambient population system (crowd, wildlife, background actors) with its own lightweight animation/audio needs distinct from primary gameplay actors.
