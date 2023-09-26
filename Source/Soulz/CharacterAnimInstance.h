// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "CharacterAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class SOULZ_API UCharacterAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (BlueprintThreadSafe))
	float GetPawnCurrentSpeed();

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (BlueprintThreadSafe))
	float GetPawnCurrentDirection();

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (BlueprintThreadSafe))
	float GetPawnCurrentDirectionForSpeed();

	UFUNCTION(BlueprintCallable, Category = "Crouch", BlueprintPure, meta = (BlueprintThreadSafe))
	bool IsCrouched();

	UPROPERTY(EditAnywhere, Category = "Crouch")
	bool Crouched;

	UFUNCTION(BlueprintCallable, Category = "Dying", BlueprintPure, meta = (BlueprintThreadSafe))
	bool IsDying();

	UPROPERTY(EditAnywhere, Category = "Dying")
	bool Dying;

	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
};
