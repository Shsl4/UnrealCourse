// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TriggerVolume.h"
#include "Engine.h"
#include "Activator.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FSetMovable);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FReceive);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UActivator : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UActivator();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


private:

	//Define A TriggerVolume (Selected in editor)

	UPROPERTY(EditAnywhere)
		ATriggerVolume* Receiver = nullptr;

	//Create a BluePrint Assignable Event

	UPROPERTY(BlueprintAssignable)
		FReceive Receive;

	AActor* Owner = nullptr;	

};
