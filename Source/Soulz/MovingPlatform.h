// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class SOULZ_API AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float MaxDistance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector velocity;

	UPROPERTY(BlueprintReadWrite)
	bool InPause;

	UPROPERTY(BlueprintReadWrite)
	FVector startPosition;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
