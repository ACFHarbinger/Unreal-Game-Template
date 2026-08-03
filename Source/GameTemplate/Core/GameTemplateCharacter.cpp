#include "Core/GameTemplateCharacter.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/CapsuleComponent.h"
#include "UObject/ConstructorHelpers.h"

AGameTemplateCharacter::AGameTemplateCharacter()
{
	PrimaryActorTick.bCanEverTick = false;

	VisualComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualComponent"));
	VisualComponent->SetupAttachment(RootComponent);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> CapsuleMeshAsset(TEXT("/Engine/BasicShapes/Cylinder.Cylinder"));
	if (CapsuleMeshAsset.Succeeded())
	{
		VisualComponent->SetStaticMesh(CapsuleMeshAsset.Object);
	}
	VisualComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 400.0f;
	CameraBoom->bUsePawnControlRotation = true;

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;

	GetCapsuleComponent()->OnComponentHit.AddDynamic(this, &AGameTemplateCharacter::HandleCapsuleHit);
}

void AGameTemplateCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void AGameTemplateCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Enhanced Input mapping context binding goes here once
	// Content/Input/ Data Assets exist — see Config/DefaultInput.ini and
	// Moon/Roadmaps/ui_ux.md.
}

void AGameTemplateCharacter::HandleCapsuleHit(UPrimitiveComponent* HitComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
{
	// Placeholder hook for gameplay-event emission — see
	// .agent/rules/cpp_gameplay.md §6.3 for the "raise an event, don't
	// mutate state directly" pattern this should follow once a core
	// gameplay subsystem exists to consume it.
}
