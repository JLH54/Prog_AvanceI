// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Avatar.h"
#include "Avatar_Player.generated.h"

class UPotion;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnInteract);

/**
 * 
 */
UCLASS()
class SOULZ_API AAvatar_Player : public AAvatar
{
	GENERATED_BODY()
public:
	UPROPERTY()
	FOnInteract OnInteractionEvent;

	virtual float TakeDamage(float Damage,
		struct FDamageEvent
		const& DamageEvent,
		AController* EventInstigator
		, AActor* DamageCauser) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void Take(UPotion* PotionItem);

	UPROPERTY(VisibleAnywhere)
	TArray<UPotion*> Inventory;

	UFUNCTION(BlueprintCallable)
	void Drink();

	UFUNCTION(BlueprintCallable)
	void Interact();

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	//virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
