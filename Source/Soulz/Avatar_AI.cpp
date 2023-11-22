// Fill out your copyright notice in the Description page of Project Settings.


#include "Avatar_AI.h"
#include "NavigationSystem.h"
#include "AIController.h"
#include "GameFramework/CharacterMovementComponent.h"

void AAvatar_AI::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	switch (CurrentSate)
	{
	case EAIState::AI_Idle:
		UpdateIdleState(DeltaTime);
		break;
	case EAIState::AI_Wander:
		UpdateWanderState();
		break;
	case EAIState::AI_Chase:
		break;
	case EAIState::AI_Attack:
		break;
	case EAIState::AI_Return:
		break;
	case EAIState::AI_Dead:
		break;
	default:
		break;
	}
	if (bIsDebug) {
		UWorld* world = GetWorld();
		DrawDebugSphere(world, SpawnLocation, MaxWanderRange, 12, FColor::Yellow);
		DrawDebugSphere(world, WanderDestination, StoppingDistance, 12, FColor::White);
		DrawDebugLine(world, GetActorLocation(), WanderDestination, FColor::Red);
	}	
}

void AAvatar_AI::EnterIdleState()
{
	UE_LOG(LogTemp, Log, TEXT("Entered Idle State"))
	CurrentSate = EAIState::AI_Idle;
	CurrentIdleTime = FMath::RandRange(MinIdleTime, MaxIdleTime);

	AAIController* AiController = Cast<AAIController>(GetController());
	if (AiController) {
		AiController->StopMovement();
	}
}

void AAvatar_AI::EnterWonderState()
{
	UE_LOG(LogTemp, Log ,TEXT("Entered Wonder State"))
	CurrentSate = EAIState::AI_Wander;
	AAIController* AiController = Cast<AAIController>(GetController());
	if (AiController) {

		WanderDestination = PickRandomDestination(SpawnLocation, MaxWanderRange);
		AiController->MoveToLocation(WanderDestination);
		SetWalkSpeed();
	}
	else {
		EnterIdleState();
	}
}

void AAvatar_AI::EnterChaseState()
{
}

void AAvatar_AI::EnterAttackState()
{
}

void AAvatar_AI::EnterReturnState()
{
}

void AAvatar_AI::EnterDeadState()
{
}

void AAvatar_AI::UpdateIdleState(float DeltaTime)
{
	CurrentIdleTime -= DeltaTime;
	if (CurrentIdleTime <= 0.0f) {
		EnterWonderState();
	}
}

void AAvatar_AI::UpdateWanderState()
{
	const float Distance = FVector::Distance(GetActorLocation(), WanderDestination);
	if (Distance <= StoppingDistance) {
		EnterIdleState();
	}
}

FVector AAvatar_AI::PickRandomDestination(const FVector& center, const float Range)
{
	const UNavigationSystemV1* NavSystem = FNavigationSystem::GetCurrent<UNavigationSystemV1>(GetWorld());

	FNavLocation RandomLocation;

	if (NavSystem->GetRandomPointInNavigableRadius(center, Range, RandomLocation)) {
		return RandomLocation.Location;
	}
	
	return center;
}

void AAvatar_AI::SetWalkSpeed()
{
	GetCharacterMovement()->MaxWalkSpeed = WalkSpeed;
}

void AAvatar_AI::SetRunSpeed()
{
	GetCharacterMovement()->MaxWalkSpeed = RunSpeed;
}

void AAvatar_AI::BeginPlay()
{
	Super::BeginPlay();
	EnterIdleState();
	SpawnLocation = GetActorLocation();
}
