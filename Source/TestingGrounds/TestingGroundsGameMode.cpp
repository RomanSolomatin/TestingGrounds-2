// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "TestingGrounds.h"
#include "TestingGroundsGameMode.h"
#include "TestingGroundsHUD.h"
#include "TestingGroundsCharacter.h"

ATestingGroundsGameMode::ATestingGroundsGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = ATestingGroundsHUD::StaticClass();
}
