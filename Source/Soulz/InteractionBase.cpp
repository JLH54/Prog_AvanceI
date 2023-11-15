// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractionBase.h"
#include "Avatar_Player.h"
// Sets default values
AInteractionBase::AInteractionBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	isPressed = false;
}

void AInteractionBase::OnEnterInteractionZone(AAvatar_Player* other)
{
	if (other) {
		other->OnInteractionEvent.AddDynamic(this, &AInteractionBase::OnInteractActivated);
	}
	
}

void AInteractionBase::OnExitInteractionZone(AAvatar_Player* other)
{
	if (other) {
		other->OnInteractionEvent.RemoveAll(this);
	}

}

void AInteractionBase::OnInteractActivated()
{
	Activate();
}

bool AInteractionBase::hasBeenPressed()
{
	return isPressed;
}

void AInteractionBase::pressed()
{
	isPressed = true;
}

