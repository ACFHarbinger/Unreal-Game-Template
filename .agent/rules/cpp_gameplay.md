# Rule: C++ Gameplay Conventions

**Scope:** All C++ under `Source/GameTemplate/`.

## Enforced

1. UE5 naming prefixes (`A`/`U`/`F`/`E`/`I`/`T`) are mandatory — UHT relies on them, not just style.
2. `TArray`/`TMap`/`TSet` over `std::` containers for anything crossing the UObject/GC boundary.
3. `TObjectPtr<T>` for every `UPROPERTY` pointer to a `UObject` (UE5.1+ convention) — never raw `T*`.
4. No C++ exceptions, no `dynamic_cast`/RTTI — use `Cast<T>()` and `TOptional`/return-code error handling.
5. 120-column line length, Allman braces, Doxygen `/** */` on public `UCLASS`/`UFUNCTION`/`UPROPERTY` declarations that aren't self-evident from naming.
6. `PrimaryActorTick.TickInterval` set explicitly and deliberately for any actor spawned in bulk — don't leave dozens of AI-controlled actors ticking every frame at full fidelity without a documented reason.

## Rejected on sight

- Blueprint containing per-tick spatial/physics/utility computation for more than a handful of actors.
- A new `UCLASS` with no module prefix on its exported macro (`GAMETEMPLATE_API`).
- Silent renumbering of an existing `UENUM`/collision channel value.

See `.agent/workflows/cpp_gameplay.md` for the step-by-step playbook and `.agent/AGENTS.md` §6.1 for the canonical example.
