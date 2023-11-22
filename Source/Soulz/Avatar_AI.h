// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Avatar.h"
#include "Avatar_AI.generated.h"

enum class EAIState : uint8 {
	AI_Idle,
	AI_Wander,
	AI_Chase,
	AI_Attack,
	AI_Return,
	AI_Dead
};

/**
 * 
 */
UCLASS()
class SOULZ_API AAvatar_AI : public AAvatar
{
	GENERATED_BODY()
public:
	virtual void Tick(float DeltaTime) override;
protected:
	EAIState CurrentSate;

	void EnterIdleState();
	void EnterWonderState();
	void EnterChaseState();
	void EnterAttackState();
	void EnterReturnState();
	void EnterDeadState();

	void UpdateIdleState(float DeltaTime);
	void UpdateWanderState();

	FVector PickRandomDestination(const FVector& center, const float Range);

	void SetWalkSpeed();
	void SetRunSpeed();

	UPROPERTY(EditAnywhere)
	float WalkSpeed;

	UPROPERTY(EditAnywhere)
	float RunSpeed;

	//Idle variables
	UPROPERTY(EditAnywhere)
	float MinIdleTime;

	UPROPERTY(EditAnywhere)
	float MaxIdleTime;

	float CurrentIdleTime;

	//Wonder variables
	FVector WanderDestination;

	UPROPERTY(EditAnywhere)
	float MaxWanderRange;

	UPROPERTY(EditAnywhere)
	float StoppingDistance;


	FVector SpawnLocation;

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	bool bIsDebug = false;
};
