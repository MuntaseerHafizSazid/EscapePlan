// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/InputComponent.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "DrawDebugHelpers.h"
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Grabber1.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FGreenUpRequest);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FGreenDownRequest);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FGreenLeftRequest);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FGreenRightRequest);

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FRedUpRequest);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FRedDownRequest);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FRedLeftRequest);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FRedRightRequest);

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FYellowUpRequest);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FYellowDownRequest);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FYellowLeftRequest);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FYellowRightRequest);

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FGrabRequest);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FBlankRequest);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FFullyRequest);

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FPushButtonDoor1Request);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FPushButtonDoor2Request);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FPushButtonDoor3Request);

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FPlayButtonRequest);

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FInteractButtonRequest);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FPostponeButtonRequest);



UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TESTGAME_API UGrabber1 : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber1();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	FVector Location = FVector(0, 0, 0);
	FRotator Rotation = FRotator(0, 0, 0);
	FVector Location_KeyFrame1 = FVector(0, 0, 0);
	FRotator Rotation_KeyFrame1 = FRotator(0, 0, 0);
	FVector Location_KeyFrame2 = FVector(0, 0, 0);
	FRotator Rotation_KeyFrame2 = FRotator(0, 0, 0);
	FVector Location_KeyFrame3 = FVector(0, 0, 0);
	FRotator Rotation_KeyFrame3 = FRotator(0, 0, 0);
	FVector Location_KeyFrame4 = FVector(0, 0, 0);
	FRotator Rotation_KeyFrame4 = FRotator(0, 0, 0);
	FVector Location_KeyFrame5 = FVector(0, 0, 0);
	FRotator Rotation_KeyFrame5 = FRotator(0, 0, 0);
	FVector Location_KeyFrame6 = FVector(0, 0, 0);
	FRotator Rotation_KeyFrame6 = FRotator(0, 0, 0);
	FVector Location_KeyFrame7 = FVector(0, 0, 0);
	FRotator Rotation_KeyFrame7 = FRotator(0, 0, 0);
	FVector Location_KeyFrame8 = FVector(0, 0, 0);
	FRotator Rotation_KeyFrame8 = FRotator(0, 0, 0);
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Switch")
		AActor* GrabbedThing = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Switch")
		bool GreenUp = false;

	AActor* MyCharacter = nullptr;

private:
	float Reach = 540.0f;
	FString name;
	///for saving the pointer of the shift key pressed
	UInputComponent* InputComponent = nullptr;
	///for saving the pointer of the physics body which the is now connected to
	UPhysicsHandleComponent* PhysicsHandle = nullptr;
	void Push();
	void GettingPhysicsHandleComponent();
	void SetupInputComponent();
	FVector GetLineTraceEnd();
	FVector GetLineTraceBegin();
	const FHitResult GetFirstPhysicsBodyInReach();
	void SettingTheKey(AActor* ActorHit);
	void TakingTheKey(AActor* ActorHit, UPrimitiveComponent* ComponentToGrab);
public:
	UPROPERTY(BlueprintAssignable)
		FGreenUpRequest FGreenUpRequest;
	UPROPERTY(BlueprintAssignable)
		FGreenDownRequest FGreenDownRequest;
	UPROPERTY(BlueprintAssignable)
		FGreenRightRequest FGreenRightRequest;
	UPROPERTY(BlueprintAssignable)
		FGreenLeftRequest FGreenLeftRequest;

	UPROPERTY(BlueprintAssignable)
		FRedUpRequest FRedUpRequest;
	UPROPERTY(BlueprintAssignable)
		FRedDownRequest FRedDownRequest;
	UPROPERTY(BlueprintAssignable)
		FRedRightRequest FRedRightRequest;
	UPROPERTY(BlueprintAssignable)
		FRedLeftRequest FRedLeftRequest;

	UPROPERTY(BlueprintAssignable)
		FYellowUpRequest FYellowUpRequest;
	UPROPERTY(BlueprintAssignable)
		FYellowDownRequest FYellowDownRequest;
	UPROPERTY(BlueprintAssignable)
		FYellowRightRequest FYellowRightRequest;
	UPROPERTY(BlueprintAssignable)
		FYellowLeftRequest FYellowLeftRequest;
	UPROPERTY(BlueprintAssignable)
		FGrabRequest FGrabRequest;
	UPROPERTY(BlueprintAssignable)
		FBlankRequest FBlankRequest;
	UPROPERTY(BlueprintAssignable)
		FFullyRequest FFullyRequest;
	UPROPERTY(BlueprintAssignable)
		FPushButtonDoor1Request FPushButtonDoor1Request;
	UPROPERTY(BlueprintAssignable)
		FPushButtonDoor2Request FPushButtonDoor2Request;
	UPROPERTY(BlueprintAssignable)
		FPushButtonDoor3Request FPushButtonDoor3Request;
	UPROPERTY(BlueprintAssignable)
		FPlayButtonRequest FPlayButtonRequest;
	UPROPERTY(BlueprintAssignable)
		FInteractButtonRequest FInteractButtonRequest;
	UPROPERTY(BlueprintAssignable)
		FPostponeButtonRequest FPostponeButtonRequest;
};
