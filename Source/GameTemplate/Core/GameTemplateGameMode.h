#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GameTemplateGameMode.generated.h"

class AGameTemplateCharacter;

/**
 * Phase 0 prototype game mode (Docs/Docs/Moon/ROADMAP.md Phase 0): spawns a flat
 * ground plane and a small number of placeholder actors so movement and
 * collision math can be validated before any Content/ assets exist.
 *
 * Deliberately free of art/animation — see Docs/Moon/Roadmaps/physics_collision.md
 * §1 for why this phase must be validated on bare geometry before any
 * Content/ assets are introduced.
 */
UCLASS()
class GAMETEMPLATE_API AGameTemplateGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AGameTemplateGameMode();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = "GameTemplate|Spawning")
	TSubclassOf<AGameTemplateCharacter> DefaultCharacterClass;

	/** How many placeholder actors to spawn for Phase 0 validation. */
	UPROPERTY(EditDefaultsOnly, Category = "GameTemplate|Spawning")
	int32 PlaceholderActorCount = 8;

private:
	void SpawnGroundPlane() const;
	void SpawnPlaceholderActors() const;
};
