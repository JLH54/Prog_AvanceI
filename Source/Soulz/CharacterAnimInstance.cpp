// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterAnimInstance.h"
#include "CharacterController.h"

float UCharacterAnimInstance::GetPawnCurrentSpeed()
{
	const APawn* pawn = TryGetPawnOwner();
	if (pawn) {
		const FVector velocity = pawn->GetVelocity();
		return velocity.Size();
	}
	return 0.0f;
}

float UCharacterAnimInstance::GetPawnCurrentDirection()
{
	const APawn* pawn = TryGetPawnOwner();
	if (pawn) {
		const FVector velocity = pawn->GetVelocity();
		const FVector direction = velocity.GetSafeNormal();
		const float directionAngle = FMath::RadiansToDegrees(FMath::Atan2(direction.Y, direction.X));
		return directionAngle;
	}
	return 0.0f;
}

float UCharacterAnimInstance::GetPawnCurrentDirectionForSpeed()
{
	const APawn* pawn = TryGetPawnOwner();
	if (pawn) {
		const FVector velocity = pawn->GetVelocity();
		const FVector direction = velocity.GetSafeNormal();
		const float directionAngle = FMath::RadiansToDegrees(FMath::Atan2(direction.Y, direction.X));
		if (directionAngle < 0) {
			return 1;
		}
		else {
			return -1;
		}
	}
	return 1;
}

bool UCharacterAnimInstance::IsCrouched()
{
	return Crouched;
}

bool UCharacterAnimInstance::IsDying()
{
	return Dying;
}

void UCharacterAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
	const APawn* pawn = TryGetPawnOwner();
	if (pawn) {
		AController* MyController = pawn->GetController();
		ACharacterController* MyCharacterController = Cast<ACharacterController>(MyController);

		if (MyCharacterController) {
			Crouched = MyCharacterController->Crouched;
			Dying = MyCharacterController->Dying;
		}
	}
}
