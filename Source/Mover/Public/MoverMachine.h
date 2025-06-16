// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MoverMachine.generated.h"

UCLASS()
class MOVER_API AMoverMachine : public AActor
{
	GENERATED_BODY()
	
public:	
	AMoverMachine();
	virtual void Tick(float DeltaTime) override;
	
protected:
	virtual void BeginPlay() override;

private:
	/* 랜덤 확률 (에디터 수정 가능) */
	UPROPERTY(EditAnywhere)
	int32 RandomPercent = 50;
	
	/* 현재위치 */
	FVector CurrentPosition;

	
	/* 이동 이력 저장용 배열 */
	TArray<FVector> MoveHistory;
	
	/* 0 또는 1을 반환 */
	int32 Step();

	/* 10회 이동 */
	void Move();

	/* 움직인 거리 계산 */
	float MoveDistance;

	/* 랜덤 확률 계산 */
	bool IsProbabilitySuccess();

	/* 특정확률 여부 */
	bool bSuccess;
};
