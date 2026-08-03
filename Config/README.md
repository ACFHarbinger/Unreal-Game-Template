# Config/

Unreal Engine `.ini` configuration overrides for `GameTemplate.uproject`.

| File | Contents |
| --- | --- |
| `DefaultEngine.ini` | Custom Object Channel name registration, Chaos Physics substepping, default GameMode/map wiring. |
| `DefaultGame.ini` | Project identity (`GeneralProjectSettings`) — rename `ProjectName`/`CompanyName`/`Description` when you clone this template. |
| `DefaultInput.ini` | Legacy input placeholder — UE 5.5 defaults to Enhanced Input (Content/ Data Assets), so real bindings live in `Content/`, not here. |
| `DefaultEditor.ini` | Editor-only settings (packaging defaults, source control compatibility). |

**Do not renumber existing Object Channels once defined** — this breaks every already-serialized Physics Asset in the project. See [`.agent/rules/physics_collision.md`](../.agent/rules/physics_collision.md) and [`Source/GameTemplate/Physics/`](../Source/GameTemplate/Physics/) for the C++-side aliases.

**Caveat**: these `.ini` files were hand-authored without a licensed Unreal Engine install available to generate/verify them via the Editor's Project Settings UI. The section names and field syntax match documented UE 5.x conventions, but have not been round-tripped through the Editor. If any section fails to parse on first open, use Project Settings in-editor (Maps & Modes, Physics, Collision, Input) to let it rewrite the offending block — the intent is documented in each section's comment regardless of exact syntax survival.
