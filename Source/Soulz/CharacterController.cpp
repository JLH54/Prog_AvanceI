// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterController.h"

void ACharacterController::SetupInputComponent()
{
	Super::SetupInputComponent();

	if (InputComponent) {
		InputComponent->BindAxis("HorizontalAxis", this, &ACharacterController::MoveHorizontal);
		InputComponent->BindAxis("VerticalAxis", this, &ACharacterController::MoveVertical);

		InputComponent->BindAction("Crouch", IE_Pressed, this, &ACharacterController::BeginCrouch);
		InputComponent->BindAction("Crouch", IE_Released, this, &ACharacterController::EndCrouch);

		InputComponent->BindAxis("Look_Horizontal", this, &ACharacterController::LookHorizontal);
		InputComponent->BindAxis("Look_Vertical", this, &ACharacterController::LookVertical);
	}
}

void ACharacterController::MoveHorizontal(float AxisValue)
{
	if (Dying) return;
	APawn* controlledPawn = GetPawn();
	if (!controlledPawn) return;
	FVector right = controlledPawn->GetActorForwardVector();
	controlledPawn->AddMovementInput(right, AxisValue);
}

void ACharacterController::MoveVertical(float AxisValue)
{
	if (Dying) return;
	APawn* controlledPawn = GetPawn();
	if (!controlledPawn) return;
	FVector forward = controlledPawn->GetActorRightVector();
	controlledPawn->AddMovementInput(forward, AxisValue);
}

void ACharacterController::LookHorizontal(float LookValue)
{
	if (Dying) return;
	APawn* controlledPawn = GetPawn();
	if (!controlledPawn) return;

	UWorld* world = GetWorld();
	float dt = world->GetDeltaSeconds();

	controlledPawn->AddControllerYawInput(dt * LookValue * RotationSpeed);
}

void ACharacterController::LookVertical(float LookValue)
{
	if (Dying) return;
	APawn* controlledPawn = GetPawn();
	if (!controlledPawn) return;

	UWorld* world = GetWorld();
	float dt = world->GetDeltaSeconds();

	controlledPawn->AddControllerPitchInput(dt * LookValue * RotationSpeed);
}

void ACharacterController::BeginCrouch()
{
	if (Dying) return;
	APawn* controlledPawn = GetPawn();
	if (!controlledPawn) return;

	/*ACharacter* MyCharacter = Cast<ACharacter>(controlledPawn);
	if (!MyCharacter) return;
	MyCharacter->Crouch();
	Crouched = true;*/
}

void ACharacterController::EndCrouch()
{
	if (Dying) return;
	APawn* controlledPawn = GetPawn();
	if (!controlledPawn) return;

	/*ACharacter* MyCharacter = Cast<ACharacter>(controlledPawn);
	if (!MyCharacter) return;
	MyCharacter->UnCrouch();
	Crouched = false;*/
}
