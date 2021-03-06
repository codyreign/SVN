// ©2017 Cody Serino

#pragma once
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "Engine/TriggerVolume.h"
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "OpenDoor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnOpenRequest);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnCloseRequest);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()
public:	
	// Sets default values for this component's properties
	UOpenDoor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	UPROPERTY(BlueprintAssignable)
		FOnOpenRequest OnOpenRequest;

	UPROPERTY(BlueprintAssignable)
		FOnCloseRequest OnCloseRequest;
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	//UPROPERTY(EditAnywhere)
		//ATriggerVolume* PressurePlate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		ATriggerVolume* PressurePlate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float TriggerMass=100;


	bool doorOpen = false;
};
