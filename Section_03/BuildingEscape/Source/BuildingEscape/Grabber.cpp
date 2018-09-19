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
		InputComponent->BindAction("Release", IE_Pressed, this, &UGrabber::Release);
		InputComponent->BindAction("Increase", IE_Pressed, this, &UGrabber::ReachIncrease);
		InputComponent->BindAction("Decrease", IE_Pressed, this, &UGrabber::ReachDecrease);

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

	auto HitResult = GetFirstPhysicsBodyInReach();
	auto ComponentToGrab = HitResult.GetComponent();
	auto ActorHit = HitResult.GetActor();

	if (ActorHit) {

		PhysicsHandle->GrabComponent(ComponentToGrab, NAME_None, ComponentToGrab->GetOwner()->GetActorLocation(), true);

	}
}

void UGrabber::Release() 
{
	UE_LOG(LogTemp, Warning, TEXT("Grab Key Released!"));
	PhysicsHandle -> ReleaseComponent();
}

// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (!PhysicsHandle) { return; }

	if (PhysicsHandle->GetGrabbedComponent()) {

		PhysicsHandle->SetTargetLocation(GetLineTracePoints().v2);

	}

}

void UGrabber::ReachIncrease()
{

	if (Reach <= 600.0f) {

		Reach = Reach + 20.0f;

	}

}

void UGrabber::ReachDecrease()
{
	if (200.f <= Reach) {

		Reach = Reach - 20.0f;

	}
}

const FHitResult UGrabber::GetFirstPhysicsBodyInReach()
{

	//Raycast

	FHitResult HitResult;

	FCollisionQueryParams TraceParameters = (FName(TEXT("")), false, GetOwner());

	FTwoVectors TracePoints = GetLineTracePoints();

	GetWorld()->LineTraceSingleByObjectType(
		OUT HitResult,
		TracePoints.v1,
		TracePoints.v2,
		FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody),
		TraceParameters
	);

	//Print What we hit

	AActor* ActorHit = HitResult.GetActor();

	if (ActorHit) {

		UE_LOG(LogTemp, Warning, TEXT("Line trace hit: %s"), *(ActorHit->GetName()));
	}

	return HitResult;

}

const FTwoVectors UGrabber::GetLineTracePoints()
{

	FVector StartLocation;
	FRotator PlayerViewPointRotation;

	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
		OUT StartLocation,
		OUT PlayerViewPointRotation
	);

	FVector EndLocation = StartLocation + PlayerViewPointRotation.Vector() * Reach;

	return FTwoVectors(StartLocation, EndLocation);
}