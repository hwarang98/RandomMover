// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MoverGameMode.generated.h"

UCLASS(abstract)
class AMoverGameMode : public AGameModeBase
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

public:
	AMoverGameMode();

	UPROPERTY(EditDefaultsOnly, Category = "스폰")
	TSubclassOf<AActor> ActorToSpawn;
};