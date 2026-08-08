#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameTemplateCharacter.generated.h"

class UStaticMeshComponent;
class UPrimitiveComponent;
class UCameraComponent;
class USpringArmComponent;

/**
 * Base playable/AI character.
 *
 * Phase 0 prototype (Docs/Docs/Moon/ROADMAP.md Phase 0): a Character (capsule
 * collision + movement component) with an engine basic-shape placeholder
 * mesh, so no custom Content/ assets are required. See
 * Docs/Moon/Roadmaps/physics_collision.md §3 for the planned upgrade to a
 * subdivided per-region Physics Asset if per-region hit detection is needed,
 * and .agent/workflows/animation_rigging.md for eventual IK/ragdoll work.
 */
UCLASS()
class GAMETEMPLATE_API AGameTemplateCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AGameTemplateCharacter();

protected:
	virtual void BeginPlay() override;
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

	UFUNCTION()
	void HandleCapsuleHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent,
		FVector NormalImpulse, const FHitResult& Hit);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "GameTemplate|Visual")
	TObjectPtr<UStaticMeshComponent> VisualComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "GameTemplate|Camera")
	TObjectPtr<USpringArmComponent> CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "GameTemplate|Camera")
	TObjectPtr<UCameraComponent> FollowCamera;
};
