// Copyright Epic Games, Inc. All Rights Reserved.


#include "AcronicGameModeBase.h"
#include "Acronic.h"


AAcronicGameModeBase::AAcronicGameModeBase()
{
}

void AAcronicGameModeBase::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)
{
	Super::InitGame(MapName, Options, ErrorMessage);
	UE_LOG(LogAcronic, Log, TEXT("Game is running: %s %s"), *MapName, *Options);
}