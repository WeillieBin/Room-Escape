// Copyright Chris Weill 2019

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "Components/InputComponent.h"
#include "Grabber.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	float Reach = 100.f;

	UInputComponent *InputComponent = nullptr;
	UPhysicsHandleComponent *PhysicsHandle = nullptr;

	void Grab();
	void Released();
	void FindPhysicsComponent();
	void SetupInputComponent();
	FVector LineTraceEndPoint();
	FVector LineTraceStartPoint();
	const FHitResult GetFirstPhysicsBodyInReach();
};
