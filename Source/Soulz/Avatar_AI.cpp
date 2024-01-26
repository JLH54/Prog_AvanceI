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
		UpdateChaseState();
		break;
	case EAIState::AI_Attack:
		UpdateAttackState();
		break;
	case EAIState::AI_Return:
		UpdateReturnState();
		break;
	case EAIState::AI_Dead:
		UpdateReturnState();
		break;
	default:
		CurrentSate = EAIState::AI_Idle;
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
	UE_LOG(LogTemp, Log, TEXT("Entered Chase State"))
	CurrentSate = EAIState::AI_Chase;
	AAIController* AiController = Cast<AAIController>(GetController());
	AiController->MoveToLocation(target->GetActorLocation());
}

void AAvatar_AI::EnterAttackState()
{
	UE_LOG(LogTemp, Log, TEXT("Entered Attack State"))
	CurrentSate = EAIState::AI_Attack;
}

void AAvatar_AI::EnterReturnState()
{
	UE_LOG(LogTemp, Log, TEXT("Entered Return State"))
	CurrentSate = EAIState::AI_Return;

	AAIController* AiController = Cast<AAIController>(GetController());
	AiController->MoveToLocation(SpawnLocation);
}

void AAvatar_AI::EnterDeadState()
{
	UE_LOG(LogTemp, Log, TEXT("Entered Dead State"))
	CurrentSate = EAIState::AI_Dead;
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
	if (target != nullptr) {
		EnterChaseState();
	}
	const float Distance = FVector::Distance(GetActorLocation(), WanderDestination);
	if (Distance <= StoppingDistance) {
		EnterIdleState();
	}
}

void AAvatar_AI::UpdateChaseState()
{
	if (target == nullptr) EnterReturnState();
	AAIController* AiController = Cast<AAIController>(GetController());
	AiController->MoveToLocation(target->GetActorLocation());
	
	const float Distance = FVector::Distance(GetActorLocation(), target->GetActorLocation());
	if (Distance <= StoppingDistance) {
		EnterAttackState();
	}
}

void AAvatar_AI::UpdateAttackState()
{
	if (target == nullptr) EnterReturnState();
	UAnimInstance* anim = GetMesh()->GetAnimInstance();
	if (!anim) return;
	if (!AttackMontage)return;
	anim->Montage_Play(AttackMontage);
}

void AAvatar_AI::UpdateReturnState()
{
	if (target != nullptr) EnterChaseState();

	AAIController* AiController = Cast<AAIController>(GetController());
	AiController->MoveToLocation(target->GetActorLocation());

	const float Distance = FVector::Distance(GetActorLocation(), target->GetActorLocation());
	if (Distance <= StoppingDistance) {
		EnterAttackState();
	}

}

void AAvatar_AI::UpdateDeadState()
{

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

void AAvatar_AI::SetTarget(AAvatar_Player* player)
{
	target = player;
}

void AAvatar_AI::RemoveTarget()
{
	target = nullptr;
}
