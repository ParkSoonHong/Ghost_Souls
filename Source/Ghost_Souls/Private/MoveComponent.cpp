// Fill out your copyright notice in the Description page of Project Settings.


#include "MoveComponent.h"
#include <EnhancedInputComponent.h>
#include <InputAction.h>
#include "../BaseCharacter.h"

// Sets default values for this component's properties
UMoveComponent::UMoveComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UMoveComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	player = GetOwner<ABaseCharacter>();
}


// Called every frame
void UMoveComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UMoveComponent::SetupPlayerInputComponent(class UEnhancedInputComponent* enhancedInputComponent, TArray<class UInputAction*> inputActtions)
{
	enhancedInputComponent->BindAction(inputActtions[0],ETriggerEvent::Triggered, this , &UMoveComponent::Move);
	enhancedInputComponent->BindAction(inputActtions[0],ETriggerEvent::Completed, this , &UMoveComponent::Move);
	enhancedInputComponent->BindAction(inputActtions[1],ETriggerEvent::Triggered, this , &UMoveComponent::Rotate);
	enhancedInputComponent->BindAction(inputActtions[1],ETriggerEvent::Completed, this , &UMoveComponent::Rotate);
}

void UMoveComponent::Move(const struct FInputActionValue& value)
{
	FVector2D controllerInput = value.Get<FVector2D>();
	if (player != nullptr)
	{
	FVector forwardVerctor = FRotationMatrix(player->GetController()->GetControlRotation()).GetUnitAxis(EAxis::X);
	FVector rightVector = FRotationMatrix(player->GetController()->GetControlRotation()).GetUnitAxis(EAxis::Y);

	player->AddMovementInput(forwardVerctor,controllerInput.X);
	player->AddMovementInput(rightVector,controllerInput.Y);
	}
}

void UMoveComponent::Rotate(const struct FInputActionValue& value)
{
	FVector2D rightControolerinput = value.Get<FVector2D>();

	if (player->pc != nullptr)
	{
		player->pc->AddYawInput(rightControolerinput.X);
		player->pc->AddPitchInput(rightControolerinput.Y);
	}
	
}

