// Copyright Epic Games, Inc. All Rights Reserved.

#include "MoverGameMode.h"

void AMoverGameMode::BeginPlay()
{
	Super::BeginPlay();

	if (ActorToSpawn)
	{
		FVector SpawnLocation(0.f, 0.f, 0.f);
		FRotator SpawnRotation = FRotator::ZeroRotator;
		UE_LOG(LogTemp, Warning, TEXT("자동 스폰 완료!"));

		GetWorld()->SpawnActor<AActor>(ActorToSpawn, SpawnLocation, SpawnRotation);
	}
}

AMoverGameMode::AMoverGameMode()
{
	
}
