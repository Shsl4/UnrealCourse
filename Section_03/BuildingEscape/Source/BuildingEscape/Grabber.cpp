#include "Grabber.h"

#define OUT

UGrabber::UGrabber()
{
	PrimaryComponentTick.bCanEverTick = true;

}

void UGrabber::BeginPlay()
{
	Super::BeginPlay();

	PhysicsHandleChecker();

	InputComponentChecker();
	
}

void UGrabber::InputComponentChecker()
{
	//Check for the InputComponent presence

	InputComponent = GetOwner()->FindComponentByClass<UInputComponent>();

	if (InputComponent) {

		//Handle is found

		UE_LOG(LogTemp, Warning, TEXT("InputComponent from %s found!"), *(GetOwner()->GetName()));

		InputComponent->BindAction("Grab", IE_Pressed, this, &UGrabber::Grab);
		InputComponent->BindAction("Grab", IE_Released, this, &UGrabber::Release);

	}
	else {

		UE_LOG(LogTemp, Error, TEXT("INPUTCOMPONENT FROM %s NOT FOUND!"), *(GetOwner()->GetName()));

	}
}

void UGrabber::PhysicsHandleChecker()
{
	//Check for the PhysicsHandle presence

	PhysicsHandle = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();

	if (PhysicsHandle) {

		//Handle is found

		UE_LOG(LogTemp, Warning, TEXT("PhysicsHandle from %s found!"), *(GetOwner()->GetName()));

	}
	else {

		UE_LOG(LogTemp, Error, TEXT("PHYSICSHANDLE FROM %s NOT FOUND!"), *(GetOwner()->GetName()));

	}
}

void UGrabber::Grab() 
{

	UE_LOG(LogTemp, Warning, TEXT("Grab Key Pressed!"));
	GetFirstPhysicsBodyInReach();

}

void UGrabber::Release() 
{
	UE_LOG(LogTemp, Warning, TEXT("Grab Key Released!"));
}

// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

const FHitResult UGrabber::GetFirstPhysicsBodyInReach()
{
	FVector PlayerViewPointLocation;
	FRotator PlayerViewPointRotation;

	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
		OUT PlayerViewPointLocation,
		OUT PlayerViewPointRotation
	);

	//UE_LOG(LogTemp, Warning, TEXT("Location : %s, Position : %s"), *PlayerViewPointLocation.ToString(), *PlayerViewPointRotation.ToString());

	//Draw a Line representing range

	FVector LineTraceEnd = PlayerViewPointLocation + PlayerViewPointRotation.Vector() * Reach;

	DrawDebugLine(GetWorld(), PlayerViewPointLocation, LineTraceEnd, FColor(255, 0, 0), false, 0.0f, 0.0f, 1.0f);

	//Raycast

	FHitResult Hit;

	FCollisionQueryParams TraceParameters = (FName(TEXT("")), false, GetOwner());

	GetWorld()->LineTraceSingleByObjectType(
		OUT Hit,
		PlayerViewPointLocation,
		LineTraceEnd,
		FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody),
		TraceParameters
	);

	//Print What we hit

	AActor* ActorHit = Hit.GetActor();

	if (ActorHit) {

		UE_LOG(LogTemp, Warning, TEXT("Line trace hit: %s"), *(ActorHit->GetName()));
	}

	return FHitResult();

}