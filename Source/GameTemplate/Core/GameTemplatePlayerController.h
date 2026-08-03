#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GameTemplatePlayerController.generated.h"

class UInputMappingContext;

/**
 * Base player controller. Owns the Enhanced Input mapping context binding
 * once Content/Input/ Data Assets exist (Moon/Roadmaps/ui_ux.md).
 */
UCLASS()
class GAMETEMPLATE_API AGameTemplatePlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AGameTemplatePlayerController();

protected:
	virtual void BeginPlay() override;

	/** Assign a Content/ Enhanced Input Mapping Context asset here once one exists. */
	UPROPERTY(EditDefaultsOnly, Category = "GameTemplate|Input")
	TObjectPtr<UInputMappingContext> DefaultMappingContext;
};
