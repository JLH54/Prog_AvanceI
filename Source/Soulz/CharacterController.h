// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "CharacterController.generated.h"

/**
 * 
 */
UCLASS()
class SOULZ_API ACharacterController : public APlayerController
{
	GENERATED_BODY()
	
public:
	virtual void SetupInputComponent() override;

	UPROPERTY(EditAnywhere)
	float RotationSpeed;

	UPROPERTY(EditAnywhere, Category = "Crouch")
	bool Crouched;

	bool Dying;

private:
	void MoveHorizontal(float AxisValue);
	void MoveVertical(float AxisValue);
	void LookHorizontal(float LookValue);
	void LookVertical(float LookValue);

	void BeginCrouch();
	void EndCrouch();
};
