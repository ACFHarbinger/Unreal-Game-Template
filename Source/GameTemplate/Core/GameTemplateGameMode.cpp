#include "Core/GameTemplateGameMode.h"

#include "Core/GameTemplateCharacter.h"
#include "Core/GameTemplatePlayerController.h"
#include "Engine/StaticMeshActor.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"

AGameTemplateGameMode::AGameTemplateGameMode()
{
	DefaultPawnClass = AGameTemplateCharacter::StaticClass();
	PlayerControllerClass = AGameTemplatePlayerController::StaticClass();
	DefaultCharacterClass = AGameTemplateCharacter::StaticClass();
}

void AGameTemplateGameMode::BeginPlay()
{
	Super::BeginPlay();

	SpawnGroundPlane();
	SpawnPlaceholderActors();
}

void AGameTemplateGameMode::SpawnGroundPlane() const
{
	UWorld* World = GetWorld();
	if (!World)
	{
		return;
	}

	AStaticMeshActor* Ground = World->SpawnActor<AStaticMeshActor>(FVector::ZeroVector, FRotator::ZeroRotator);
	if (!Ground)
	{
		return;
	}

	Ground->SetMobility(EComponentMobility::Static);
	UStaticMeshComponent* MeshComponent = Ground->GetStaticMeshComponent();

	static ConstructorHelpers::FObjectFinder<UStaticMesh> PlaneMeshAsset(TEXT("/Engine/BasicShapes/Plane.Plane"));
	if (PlaneMeshAsset.Succeeded())
	{
		MeshComponent->SetStaticMesh(PlaneMeshAsset.Object);
	}

	// Engine basic-shape Plane is 100x100uu at scale 1 (unverified against
	// the exact 5.5 asset — confirm visually in-editor); scale up to give a
	// reasonably sized test area.
	Ground->SetActorScale3D(FVector(50.0f, 50.0f, 1.0f));

	MeshComponent->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	MeshComponent->SetCollisionResponseToAllChannels(ECR_Block);
}

void AGameTemplateGameMode::SpawnPlaceholderActors() const
{
	UWorld* World = GetWorld();
	if (!World || !DefaultCharacterClass)
	{
		return;
	}

	for (int32 Index = 0; Index < PlaceholderActorCount; ++Index)
	{
		const FVector SpawnLocation(Index * 200.0f, 0.0f, 100.0f);

		FActorSpawnParameters SpawnParams;
		SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

		World->SpawnActor<AGameTemplateCharacter>(DefaultCharacterClass, SpawnLocation, FRotator::ZeroRotator, SpawnParams);
	}
}
