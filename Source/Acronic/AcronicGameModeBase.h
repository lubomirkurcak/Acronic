// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "AcronicGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class ACRONIC_API AAcronicGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	AAcronicGameModeBase();
	virtual void InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage);
};
