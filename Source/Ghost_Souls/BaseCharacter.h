// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BaseCharacter.generated.h"

UCLASS()
class GHOST_SOULS_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:

	UPROPERTY(EditAnywhere,Category = "MySettings||inpuet")
	class UInputMappingContext* imc_Player;

	UPROPERTY(EditAnywhere,Category="MySettings||inpuet")
	TArray<class UInputAction*> inputActions;

	UPROPERTY(EditAnywhere,Category="MySettings||Camera")
	class UCameraComponent* cameraCam;
	UPROPERTY(EditAnywhere,Category="MySettings||Camera")
	class USpringArmComponent * springComp;

	UPROPERTY(EditAnywhere,Category="MySettings||Components")
	class UMoveComponent * moveComp;

	class APlayerController* pc;
};
