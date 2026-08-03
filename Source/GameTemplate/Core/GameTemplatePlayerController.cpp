#include "Core/GameTemplatePlayerController.h"

#include "EnhancedInputSubsystems.h"

AGameTemplatePlayerController::AGameTemplatePlayerController()
{
}

void AGameTemplatePlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (UEnhancedInputLocalPlayerSubsystem* Subsystem =
			ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		if (DefaultMappingContext)
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}
}
