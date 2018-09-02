// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TriggerVolume.h"
#include "OpenDoor.generated.h"



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

	void OpenDoor();

	void CloseDoor();

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:

	UPROPERTY(VisibleAnywhere)
		float OpenAngle = 30.0f;
	
	UPROPERTY(VisibleAnywhere)
		float ClosedAngle = 90.0f;

	UPROPERTY(EditAnywhere)
		ATriggerVolume* OpenPressurePlate;

	UPROPERTY(EditAnywhere)
		ATriggerVolume* ClosePressurePlate;

	AActor* ActorThatOpens;

	AActor* Owner;
	
};
