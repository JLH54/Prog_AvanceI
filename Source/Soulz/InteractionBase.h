// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InteractionBase.generated.h"

class AAvatar_Player;

UCLASS()
class SOULZ_API AInteractionBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AInteractionBase();
	
protected:
	UFUNCTION(BlueprintCallable)
	void OnEnterInteractionZone(AAvatar_Player* other);

	UFUNCTION(BlueprintCallable)
	void OnExitInteractionZone(AAvatar_Player* other);

	UFUNCTION(BlueprintImplementableEvent)
	void Activate();

	UFUNCTION()
	void OnInteractActivated();

	UFUNCTION(BlueprintCallable)
	bool hasBeenPressed();

	UFUNCTION(BlueprintCallable)
	void pressed();

	bool isPressed;
};
