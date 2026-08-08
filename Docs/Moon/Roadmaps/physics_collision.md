# Roadmap: Physics & Collision

## 1. Pure Geometry Prototype

Validate movement/collision math using engine basic-shape meshes before any art integration. See `Moon/ROADMAP.md` Phase 0 and `.agent/rules/physics_collision.md`.

## 2. Object Channels & Collision Response Matrix

Define custom Object Channels here as the design needs them. Template starting point (adjust to your actual gameplay needs):

| Channel | Purpose |
| --- | --- |
| `Interactable` | Actors the player/AI can interact with directly. |
| `Hazard` | Actors that deal damage/negative effects on contact. |

Full response matrix (Block/Overlap/Ignore per pair) goes in `Source/GameTemplate/Physics/`'s header doc comment once channels are defined — never renumber a channel once shipped.

## 3. Subdivided Physics Assets

If per-region hit detection matters (e.g., headshots, limb-specific ragdoll), plan the subdivided Physics Asset structure here before implementing — retrofitting is expensive.

## 4. Substepping

Chaos Physics substepping configuration (`bSubstepping`, `MaxSubstepDeltaTime`, `MaxSubsteps`) in `Config/DefaultEngine.ini` — tune once high-velocity gameplay (projectiles, fast-moving actors) exists, validate with `just test.physics`.

## 5. Weather / Environmental Physics (if applicable)

Placeholder for any environmental physics affecting movement/projectiles (wind, water, weather) — fill in when the design calls for it.
