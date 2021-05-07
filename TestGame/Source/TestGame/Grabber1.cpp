// Fill out your copyright notice in the Description page of Project Settings.


#include "Grabber1.h"
#include "GameFramework/Actor.h"
#include "CollisionQueryParams.h"
#include "Gameframework/Actor.h"
#include "Components/PrimitiveComponent.h"
#include "Kismet/GameplayStatics.h"
#define OUT

// Sets default values for this component's properties
UGrabber1::UGrabber1()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrabber1::BeginPlay()
{
	Super::BeginPlay();

	// ...
	///Beacause we want to use grab on physicalbody only.
	GettingPhysicsHandleComponent();
	///Because we want to grab when a button is pressed.
	SetupInputComponent();
	//TSubclassOf<ACharacter 
	//UGameplayStatics::GetAllActorsOfClass(GetWorld(),)
	MyCharacter = (AActor*)UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
}


// Called every frame
void UGrabber1::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
	/*DrawDebugLine(
		GetWorld(),
		GetLineTraceBegin(),
		GetLineTraceEnd(),
		FColor(255, 0, 0),
		false,
		0.0f,
		0.0f,
		10.0f
	);*/
	if (PhysicsHandle) {
		if (PhysicsHandle->GrabbedComponent)
		{
			PhysicsHandle->SetTargetLocation(GetLineTraceEnd());
		}
		///We get the Object which has been hitted.
		auto HitResult = GetFirstPhysicsBodyInReach();
		///We get the component.
		auto ComponentToGrab = HitResult.GetComponent();
		///We get the actor.
		auto ActorHit = HitResult.GetActor();
		if (ActorHit)
		{
			name = ActorHit->GetName();
			if (name == "Door_Level1_4")
			{

			}
			else if (name == "Door_Level2_2")
			{

			}
			else if (name == "Maze_Door2_2")
			{

			}
			else if (name == "Maze_Door_2")
			{

			}
			else {
				FInteractButtonRequest.Broadcast();
			}
		}
		else {
			FPostponeButtonRequest.Broadcast();
		}
	}
	else
		UE_LOG(LogTemp, Warning, TEXT("Physics Handle is missing."));
}

void UGrabber1::Push()
{
	///We get the Object which has been hitted.
	auto HitResult = GetFirstPhysicsBodyInReach();
	///We get the component.
	auto ComponentToGrab = HitResult.GetComponent();
	///We get the actor.
	auto ActorHit = HitResult.GetActor();
	if (ActorHit) {
		FPlayButtonRequest.Broadcast();
		name = ActorHit->GetName();
		UE_LOG(LogTemp, Warning, TEXT("%s"), *name);
		if (name == "SwitchGreenUp")
		{
			FGreenUpRequest.Broadcast();

		}
		else if (name == "SwitchGreenDown")
		{
			FGreenDownRequest.Broadcast();
		}
		else if (name == "SwitchGreenRight")
		{
			FGreenRightRequest.Broadcast();
		}
		else if (name == "SwitchGreenLeft")
		{
			FGreenLeftRequest.Broadcast();
		}
		else if (name == "SwitchRedUp")
		{
			FRedUpRequest.Broadcast();
		}
		else if (name == "SwitchRedDown")
		{
			FRedDownRequest.Broadcast();
		}
		else if (name == "SwitchRedRight")
		{
			FRedRightRequest.Broadcast();
		}
		else if (name == "SwitchRedLeft")
		{
			FRedLeftRequest.Broadcast();
		}
		else if (name == "SwitchYellowUp")
		{
			FYellowUpRequest.Broadcast();
		}
		else if (name == "SwitchYellowDown")
		{
			FYellowDownRequest.Broadcast();
		}
		else if (name == "SwitchYellowRight")
		{
			FYellowRightRequest.Broadcast();
		}
		else if (name == "SwitchYellowLeft")
		{
			FYellowLeftRequest.Broadcast();
		}
		else if (name == "KeyFrame_2") ///KeyFrame_1
		{
			TArray<AActor*> Actors = { nullptr };
			ActorHit->GetAttachedActors(Actors, true);
			if (GrabbedThing != nullptr && !Actors.IsValidIndex(0))
			{
				const FAttachmentTransformRules a(EAttachmentRule::SnapToTarget, EAttachmentRule::SnapToTarget, EAttachmentRule::SnapToTarget, true);
				GrabbedThing->AttachToActor(ActorHit, a, "socket");
				GrabbedThing = nullptr;
				Location_KeyFrame1 = Location;
				Rotation_KeyFrame1 = Rotation;
				Location = FVector(0, 0, 0);
				Rotation = FRotator(0, 0, 0);
			}
			else if (GrabbedThing == nullptr && !Actors.IsValidIndex(0))
			{
				FBlankRequest.Broadcast();
			}
			else if (GrabbedThing == nullptr && Actors.IsValidIndex(0))
			{
				Actors[0]->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
				Actors[0]->SetActorLocation(Location, false, 0, ETeleportType::TeleportPhysics);
				Actors[0]->SetActorRotation(Rotation, ETeleportType::TeleportPhysics);
				GrabbedThing = Actors[0];
				Location = Location_KeyFrame1;
				Rotation = Rotation_KeyFrame1;
				Location_KeyFrame1 = FVector(0, 0, 0);
				Rotation_KeyFrame1 = FRotator(0, 0, 0);
			}
			else {
				FFullyRequest.Broadcast();
			}
		}
		else if (name == "KeyFrame_3") ///KeyFrame_2
		{
			TArray<AActor*> Actors = { nullptr };
			ActorHit->GetAttachedActors(Actors, true);
			if (GrabbedThing != nullptr && !Actors.IsValidIndex(0))
			{
				const FAttachmentTransformRules a(EAttachmentRule::SnapToTarget, EAttachmentRule::SnapToTarget, EAttachmentRule::SnapToTarget, true);
				GrabbedThing->AttachToActor(ActorHit, a, "socket");
				GrabbedThing = nullptr;
				Location_KeyFrame2 = Location;
				Rotation_KeyFrame2 = Rotation;
				Location = FVector(0, 0, 0);
				Rotation = FRotator(0, 0, 0);
			}
			else if (GrabbedThing == nullptr && !Actors.IsValidIndex(0))
			{
				FBlankRequest.Broadcast();
			}
			else if (GrabbedThing == nullptr && Actors.IsValidIndex(0))
			{
				Actors[0]->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
				Actors[0]->SetActorLocation(Location, false, 0, ETeleportType::TeleportPhysics);
				Actors[0]->SetActorRotation(Rotation, ETeleportType::TeleportPhysics);
				GrabbedThing = Actors[0];
				Location = Location_KeyFrame2;
				Rotation = Rotation_KeyFrame2;
				Location_KeyFrame2 = FVector(0, 0, 0);
				Rotation_KeyFrame2 = FRotator(0, 0, 0);
			}
			else {
				FFullyRequest.Broadcast();
			}
		}
		else if (name == "KeyFrame_6") ///KeyFrame_3
		{
			TArray<AActor*> Actors = { nullptr };
			ActorHit->GetAttachedActors(Actors, true);
			if (GrabbedThing != nullptr && !Actors.IsValidIndex(0))
			{
				const FAttachmentTransformRules a(EAttachmentRule::SnapToTarget, EAttachmentRule::SnapToTarget, EAttachmentRule::SnapToTarget, true);
				GrabbedThing->AttachToActor(ActorHit, a, "socket");
				GrabbedThing = nullptr;
				Location_KeyFrame3 = Location;
				Rotation_KeyFrame3 = Rotation;
				Location = FVector(0, 0, 0);
				Rotation = FRotator(0, 0, 0);
			}
			else if (GrabbedThing == nullptr && !Actors.IsValidIndex(0))
			{
				FBlankRequest.Broadcast();
			}
			else if (GrabbedThing == nullptr && Actors.IsValidIndex(0))
			{
				Actors[0]->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
				Actors[0]->SetActorLocation(Location, false, 0, ETeleportType::TeleportPhysics);
				Actors[0]->SetActorRotation(Rotation, ETeleportType::TeleportPhysics);
				GrabbedThing = Actors[0];
				Location = Location_KeyFrame3;
				Rotation = Rotation_KeyFrame3;
				Location_KeyFrame3 = FVector(0, 0, 0);
				Rotation_KeyFrame3 = FRotator(0, 0, 0);
			}
			else {
				FFullyRequest.Broadcast();
			}
		}
		else if (name == "KeyFrame_7") ///KeyFrame_4
		{
			TArray<AActor*> Actors = { nullptr };
			ActorHit->GetAttachedActors(Actors, true);
			if (GrabbedThing != nullptr && !Actors.IsValidIndex(0))
			{
				const FAttachmentTransformRules a(EAttachmentRule::SnapToTarget, EAttachmentRule::SnapToTarget, EAttachmentRule::SnapToTarget, true);
				GrabbedThing->AttachToActor(ActorHit, a, "socket");
				GrabbedThing = nullptr;
				Location_KeyFrame4 = Location;
				Rotation_KeyFrame4 = Rotation;
				Location = FVector(0, 0, 0);
				Rotation = FRotator(0, 0, 0);
			}
			else if (GrabbedThing == nullptr && !Actors.IsValidIndex(0))
			{
				FBlankRequest.Broadcast();
			}
			else if (GrabbedThing == nullptr && Actors.IsValidIndex(0))
			{
				Actors[0]->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
				Actors[0]->SetActorLocation(Location, false, 0, ETeleportType::TeleportPhysics);
				Actors[0]->SetActorRotation(Rotation, ETeleportType::TeleportPhysics);
				GrabbedThing = Actors[0];
				Location = Location_KeyFrame4;
				Rotation = Rotation_KeyFrame4;
				Location_KeyFrame4 = FVector(0, 0, 0);
				Rotation_KeyFrame4 = FRotator(0, 0, 0);
			}
			else {
				FFullyRequest.Broadcast();
			}
		}
		else if (name == "KeyFrame_10") ///KeyFrame_5
		{
			TArray<AActor*> Actors = { nullptr };
			ActorHit->GetAttachedActors(Actors, true);
			if (GrabbedThing != nullptr && !Actors.IsValidIndex(0))
			{
				const FAttachmentTransformRules a(EAttachmentRule::SnapToTarget, EAttachmentRule::SnapToTarget, EAttachmentRule::SnapToTarget, true);
				GrabbedThing->AttachToActor(ActorHit, a, "socket");
				GrabbedThing = nullptr;
				Location_KeyFrame5 = Location;
				Rotation_KeyFrame5 = Rotation;
				Location = FVector(0, 0, 0);
				Rotation = FRotator(0, 0, 0);
			}
			else if (GrabbedThing == nullptr && !Actors.IsValidIndex(0))
			{
				FBlankRequest.Broadcast();
			}
			else if (GrabbedThing == nullptr && Actors.IsValidIndex(0))
			{
				Actors[0]->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
				Actors[0]->SetActorLocation(Location, false, 0, ETeleportType::TeleportPhysics);
				Actors[0]->SetActorRotation(Rotation, ETeleportType::TeleportPhysics);
				GrabbedThing = Actors[0];
				Location = Location_KeyFrame5;
				Rotation = Rotation_KeyFrame5;
				Location_KeyFrame5 = FVector(0, 0, 0);
				Rotation_KeyFrame5 = FRotator(0, 0, 0);
			}
			else {
				FFullyRequest.Broadcast();
			}
		}
		else if (name == "KeyFrame_11") ///KeyFrame_6
		{
			TArray<AActor*> Actors = { nullptr };
			ActorHit->GetAttachedActors(Actors, true);
			if (GrabbedThing != nullptr && !Actors.IsValidIndex(0))
			{
				const FAttachmentTransformRules a(EAttachmentRule::SnapToTarget, EAttachmentRule::SnapToTarget, EAttachmentRule::SnapToTarget, true);
				GrabbedThing->AttachToActor(ActorHit, a, "socket");
				GrabbedThing = nullptr;
				Location_KeyFrame6 = Location;
				Rotation_KeyFrame6 = Rotation;
				Location = FVector(0, 0, 0);
				Rotation = FRotator(0, 0, 0);
			}
			else if (GrabbedThing == nullptr && !Actors.IsValidIndex(0))
			{
				FBlankRequest.Broadcast();
			}
			else if (GrabbedThing == nullptr && Actors.IsValidIndex(0))
			{
				Actors[0]->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
				Actors[0]->SetActorLocation(Location, false, 0, ETeleportType::TeleportPhysics);
				Actors[0]->SetActorRotation(Rotation, ETeleportType::TeleportPhysics);
				GrabbedThing = Actors[0];
				Location = Location_KeyFrame6;
				Rotation = Rotation_KeyFrame6;
				Location_KeyFrame6 = FVector(0, 0, 0);
				Rotation_KeyFrame6 = FRotator(0, 0, 0);
			}
			else {
				FFullyRequest.Broadcast();
			}
		}
		else if (name == "KeyFrame_14") ///KeyFrame_7
		{
			TArray<AActor*> Actors = { nullptr };
			ActorHit->GetAttachedActors(Actors, true);
			if (GrabbedThing != nullptr && !Actors.IsValidIndex(0))
			{
				UE_LOG(LogTemp, Warning, TEXT("Success."));
				const FAttachmentTransformRules a(EAttachmentRule::SnapToTarget, EAttachmentRule::SnapToTarget, EAttachmentRule::SnapToTarget, true);
				GrabbedThing->AttachToActor(ActorHit, a, "socket");
				GrabbedThing = nullptr;
				Location_KeyFrame7 = Location;
				Rotation_KeyFrame7 = Rotation;
				Location = FVector(0, 0, 0);
				Rotation = FRotator(0, 0, 0);
			}
			else if (GrabbedThing == nullptr && !Actors.IsValidIndex(0))
			{
				FBlankRequest.Broadcast();
			}
			else if (GrabbedThing == nullptr && Actors.IsValidIndex(0))
			{
				Actors[0]->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
				Actors[0]->SetActorLocation(Location, false, 0, ETeleportType::TeleportPhysics);
				Actors[0]->SetActorRotation(Rotation, ETeleportType::TeleportPhysics);
				GrabbedThing = Actors[0];
				Location = Location_KeyFrame7;
				Rotation = Rotation_KeyFrame7;
				Location_KeyFrame7 = FVector(0, 0, 0);
				Rotation_KeyFrame7 = FRotator(0, 0, 0);
			}
			else {
				FFullyRequest.Broadcast();
			}
		}
		else if (name == "KeyFrame_15") ///KeyFrame_8
		{
			TArray<AActor*> Actors = { nullptr };
			ActorHit->GetAttachedActors(Actors, true);
			if (GrabbedThing != nullptr && !Actors.IsValidIndex(0))
			{
				const FAttachmentTransformRules a(EAttachmentRule::SnapToTarget, EAttachmentRule::SnapToTarget, EAttachmentRule::SnapToTarget, true);
				GrabbedThing->AttachToActor(ActorHit, a, "socket");
				GrabbedThing = nullptr;
				Location_KeyFrame8 = Location;
				Rotation_KeyFrame8 = Rotation;
				Location = FVector(0, 0, 0);
				Rotation = FRotator(0, 0, 0);
			}
			else if (GrabbedThing == nullptr && !Actors.IsValidIndex(0))
			{
				FBlankRequest.Broadcast();
			}
			else if (GrabbedThing == nullptr && Actors.IsValidIndex(0))
			{
				Actors[0]->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
				Actors[0]->SetActorLocation(Location, false, 0, ETeleportType::TeleportPhysics);
				Actors[0]->SetActorRotation(Rotation, ETeleportType::TeleportPhysics);
				GrabbedThing = Actors[0];
				Location = Location_KeyFrame8;
				Rotation = Rotation_KeyFrame8;
				Location_KeyFrame8 = FVector(0, 0, 0);
				Rotation_KeyFrame8 = FRotator(0, 0, 0);
			}
			else {
				FFullyRequest.Broadcast();
			}
		}
		else if (name == "Button_Level1_2")
		{
			FPushButtonDoor1Request.Broadcast();
		}
		else if (name == "Button_Level2_2")
		{
			FPushButtonDoor2Request.Broadcast();
		}
		else if (name == "BookFrame1_2")
		{
			TArray<AActor*> Actors = { nullptr };
			ActorHit->GetAttachedActors(Actors, true);
			if (GrabbedThing != nullptr && !Actors.IsValidIndex(0))
			{
				const FAttachmentTransformRules a(EAttachmentRule::SnapToTarget, EAttachmentRule::SnapToTarget, EAttachmentRule::SnapToTarget, true);
				GrabbedThing->AttachToActor(ActorHit, a, "socket");
				GrabbedThing = nullptr;
				Location_KeyFrame8 = Location;
				Rotation_KeyFrame8 = Rotation;
				Location = FVector(0, 0, 0);
				Rotation = FRotator(0, 0, 0);
			}
			else if (GrabbedThing == nullptr && !Actors.IsValidIndex(0))
			{
				FBlankRequest.Broadcast();
			}
			else if (GrabbedThing == nullptr && Actors.IsValidIndex(0))
			{
				Actors[0]->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
				Actors[0]->SetActorLocation(Location, false, 0, ETeleportType::TeleportPhysics);
				Actors[0]->SetActorRotation(Rotation, ETeleportType::TeleportPhysics);
				GrabbedThing = Actors[0];
				Location = Location_KeyFrame8;
				Rotation = Rotation_KeyFrame8;
				Location_KeyFrame8 = FVector(0, 0, 0);
				Rotation_KeyFrame8 = FRotator(0, 0, 0);
			}
			else {
				FFullyRequest.Broadcast();
			}
		}
		else if (name == "BookFrame2_2")
		{
			TArray<AActor*> Actors = { nullptr };
			ActorHit->GetAttachedActors(Actors, true);
			if (GrabbedThing != nullptr && !Actors.IsValidIndex(0))
			{
				const FAttachmentTransformRules a(EAttachmentRule::SnapToTarget, EAttachmentRule::SnapToTarget, EAttachmentRule::SnapToTarget, true);
				GrabbedThing->AttachToActor(ActorHit, a, "socket");
				GrabbedThing = nullptr;
				Location_KeyFrame7 = Location;
				Rotation_KeyFrame7 = Rotation;
				Location = FVector(0, 0, 0);
				Rotation = FRotator(0, 0, 0);
			}
			else if (GrabbedThing == nullptr && !Actors.IsValidIndex(0))
			{
				FBlankRequest.Broadcast();
			}
			else if (GrabbedThing == nullptr && Actors.IsValidIndex(0))
			{
				Actors[0]->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
				Actors[0]->SetActorLocation(Location, false, 0, ETeleportType::TeleportPhysics);
				Actors[0]->SetActorRotation(Rotation, ETeleportType::TeleportPhysics);
				GrabbedThing = Actors[0];
				Location = Location_KeyFrame7;
				Rotation = Rotation_KeyFrame7;
				Location_KeyFrame7 = FVector(0, 0, 0);
				Rotation_KeyFrame7 = FRotator(0, 0, 0);
			}
			else {
				FFullyRequest.Broadcast();
			}
		}
		else if (name == "BookFrame3_2")
		{
			TArray<AActor*> Actors = { nullptr };
			ActorHit->GetAttachedActors(Actors, true);
			if (GrabbedThing != nullptr && !Actors.IsValidIndex(0))
			{
				const FAttachmentTransformRules a(EAttachmentRule::SnapToTarget, EAttachmentRule::SnapToTarget, EAttachmentRule::SnapToTarget, true);
				GrabbedThing->AttachToActor(ActorHit, a, "socket");
				GrabbedThing = nullptr;
				Location_KeyFrame6 = Location;
				Rotation_KeyFrame6 = Rotation;
				Location = FVector(0, 0, 0);
				Rotation = FRotator(0, 0, 0);
			}
			else if (GrabbedThing == nullptr && !Actors.IsValidIndex(0))
			{
				FBlankRequest.Broadcast();
			}
			else if (GrabbedThing == nullptr && Actors.IsValidIndex(0))
			{
				Actors[0]->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
				Actors[0]->SetActorLocation(Location, false, 0, ETeleportType::TeleportPhysics);
				Actors[0]->SetActorRotation(Rotation, ETeleportType::TeleportPhysics);
				GrabbedThing = Actors[0];
				Location = Location_KeyFrame6;
				Rotation = Rotation_KeyFrame6;
				Location_KeyFrame6 = FVector(0, 0, 0);
				Rotation_KeyFrame6 = FRotator(0, 0, 0);
			}
			else {
				FFullyRequest.Broadcast();
			}
		}
		else if (name == "BookFrame4_2")
		{
			TArray<AActor*> Actors = { nullptr };
			ActorHit->GetAttachedActors(Actors, true);
			if (GrabbedThing != nullptr && !Actors.IsValidIndex(0))
			{
				const FAttachmentTransformRules a(EAttachmentRule::SnapToTarget, EAttachmentRule::SnapToTarget, EAttachmentRule::SnapToTarget, true);
				GrabbedThing->AttachToActor(ActorHit, a, "socket");
				GrabbedThing = nullptr;
				Location_KeyFrame5 = Location;
				Rotation_KeyFrame5 = Rotation;
				Location = FVector(0, 0, 0);
				Rotation = FRotator(0, 0, 0);
			}
			else if (GrabbedThing == nullptr && !Actors.IsValidIndex(0))
			{
				FBlankRequest.Broadcast();
			}
			else if (GrabbedThing == nullptr && Actors.IsValidIndex(0))
			{
				Actors[0]->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
				Actors[0]->SetActorLocation(Location, false, 0, ETeleportType::TeleportPhysics);
				Actors[0]->SetActorRotation(Rotation, ETeleportType::TeleportPhysics);
				GrabbedThing = Actors[0];
				Location = Location_KeyFrame5;
				Rotation = Rotation_KeyFrame5;
				Location_KeyFrame5 = FVector(0, 0, 0);
				Rotation_KeyFrame5 = FRotator(0, 0, 0);
			}
			else {
				FFullyRequest.Broadcast();
			}
		}
		else if (name == "Button_Level3_3")
		{
			FPushButtonDoor3Request.Broadcast();
		}
		else if (name == "Door_Level1_4")
		{

		}
		else if (name == "Door_Level2_2")
		{

		}
		else if (name == "Maze_Door2_2")
		{

		}
		else if (name == "Maze_Door_2")
		{

		}
		else {
			TakingTheKey(ActorHit,ComponentToGrab);
		}
	}
	else
	{
		if (GrabbedThing != nullptr)
		{
			GrabbedThing->SetActorLocation(Location, false, 0, ETeleportType::TeleportPhysics);
			GrabbedThing->SetActorRotation(Rotation, ETeleportType::TeleportPhysics);
			GrabbedThing = nullptr;
			Location = FVector(0, 0, 0);
			Rotation = FRotator(0, 0, 0);
		}
		else {
			
		}
	}

}

void UGrabber1::GettingPhysicsHandleComponent()
{
	PhysicsHandle = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();
}

void UGrabber1::SetupInputComponent()
{
	InputComponent = GetOwner()->FindComponentByClass<UInputComponent>();
	///For Binding Action.
	if (InputComponent)
	{
		InputComponent->BindAction("Push", IE_Pressed, this, &UGrabber1::Push);
	}
}

FVector UGrabber1::GetLineTraceEnd()
{
	///For saving the player location at the moment
	FVector PlayerViewPointLocation;
	///For saving the player rotation at the moment
	FRotator PlayerViewPointRotation;
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
		OUT PlayerViewPointLocation,
		OUT PlayerViewPointRotation
	);

	return PlayerViewPointLocation + (PlayerViewPointRotation.Vector() * Reach);
}

FVector UGrabber1::GetLineTraceBegin()
{
	///For saving the player location at the moment
	FVector PlayerViewPointLocation;
	///For saving the player rotation at the moment
	FRotator PlayerViewPointRotation;
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
		OUT PlayerViewPointLocation,
		OUT PlayerViewPointRotation
	);

	return PlayerViewPointLocation;
}

const FHitResult UGrabber1::GetFirstPhysicsBodyInReach()
{
	///setup query parameters.
	///Third parameter is for the actor we want to ignore. in this case it is the owner.
	///Not doing anything complex. so 2nd parameter is set to false.
	FCollisionQueryParams TraceParameters(FName(TEXT("")), false, GetOwner());

	///Line trace (AKA ray-cast) out to reach distance
	FHitResult Hit;
	GetWorld()->LineTraceSingleByObjectType(
		OUT Hit,
		GetLineTraceBegin(),
		GetLineTraceEnd(),
		FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody),
		TraceParameters
	);
	return Hit;
}

void UGrabber1::SettingTheKey(AActor* ActorHit)
{

}

void UGrabber1::TakingTheKey(AActor* ActorHit, UPrimitiveComponent* ComponentToGrab)
{
	if (GrabbedThing == nullptr)
	{
		GrabbedThing = ActorHit;
		Location = ActorHit->GetActorLocation();
		Rotation = ActorHit->GetActorRotation();
		const FAttachmentTransformRules a(EAttachmentRule::SnapToTarget, EAttachmentRule::SnapToTarget, EAttachmentRule::SnapToTarget, true);
		ActorHit->SetActorLocation(FVector(0, 0, 0), false, 0, ETeleportType::TeleportPhysics);
		ActorHit->SetActorRotation(FRotator(0, 0, 0), ETeleportType::TeleportPhysics);
	}
	else {
		FGrabRequest.Broadcast();
	}
}

