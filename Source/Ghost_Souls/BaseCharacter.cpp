// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseCharacter.h"
#include <../Plugins/EnhancedInput/Source/EnhancedInput/Public/EnhancedInputComponent.h>
#include "MoveComponent.h"
#include <../Plugins/EnhancedInput/Source/EnhancedInput/Public/EnhancedInputSubsystems.h>
#include <Camera/CameraComponent.h>
#include <GameFramework/SpringArmComponent.h>
#include <GameFramework/CharacterMovementComponent.h>

// Sets default values
ABaseCharacter::ABaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	moveComp = CreateDefaultSubobject<UMoveComponent>(TEXT("Move Component"));

	springComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm Component"));
	springComp->SetupAttachment(RootComponent);
	
	cameraCam = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera Compoent"));
	cameraCam->SetupAttachment(springComp);
	
	GetCharacterMovement()->bOrientRotationToMovement = true;
	
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	springComp->bUsePawnControlRotation = true;
	cameraCam->bUsePawnControlRotation = false;
}

// Called when the game starts or when spawned
void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	pc = GetController<APlayerController>();
	if (pc != nullptr)
	{
		UEnhancedInputLocalPlayerSubsystem* subSys = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(pc->GetLocalPlayer());
		if (subSys != nullptr)
			subSys->AddMappingContext(imc_Player, 0);
	}
}

// Called every frame
void ABaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	UEnhancedInputComponent * enhcedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	if (enhcedInputComponent != nullptr)
	{
		moveComp->SetupPlayerInputComponent(enhcedInputComponent,inputActions);
	}
}

