// Fill out your copyright notice in the Description page of Project Settings.


#include "Public/MoverMachine.h"

AMoverMachine::AMoverMachine()
{
	PrimaryActorTick.bCanEverTick = true;
	
	CurrentPosition = FVector(0, 0, 0);
}

void AMoverMachine::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("랜덤 이동 시작! 시작 좌표: (%.0f, %.0f)"), CurrentPosition.X, CurrentPosition.Y);
	UE_LOG(LogTemp, Warning, TEXT("======================================="));
	UE_LOG(LogTemp, Warning, TEXT(" "))

	Move();
}

int32 AMoverMachine::Step()
{
	return FMath::RandRange(0, 1);  // 0 또는 1 리턴
}

/**
 * @brief  현재 위치에서 10회에 걸쳐 랜덤으로 이동하고, 이동 경로와 거리 로그를 출력합니다.
 * 
 * - 매 스텝마다 X, Y 좌표를 0 또는 1만큼 랜덤하게 이동합니다.
 * - 이동 전 위치와 이동 후 위치를 비교하여 거리(이동 거리)를 계산합니다.
 * - 각 이동 단계마다 이전 위치, 현재 위치, 이동 거리를 로그로 출력합니다.
 * - 이동 시 Z축 값은 항상 0으로 고정되어 2D 평면 내 움직임만 고려합니다.
 *
 * @note  Step() 함수는 0 또는 1을 반환하는 것으로 가정합니다.
 */
void AMoverMachine::Move()
{
	MoveHistory.Empty(); // 혹시모를 이전 기록 삭제
	CurrentPosition = FVector::ZeroVector;
	MoveHistory.Add(CurrentPosition);
	
	for (int i = 0; i < 10; i++)
	{
		// 이전 좌표
		FVector PrevPosition = CurrentPosition;

		const int XStep = Step();
		const int YStep = Step();

		CurrentPosition.X += XStep;
		CurrentPosition.Y += YStep;

		MoveDistance = FVector::Distance(PrevPosition, CurrentPosition);

		bSuccess = IsProbabilitySuccess();
		
		if (bSuccess)
		{
			UE_LOG(LogTemp, Warning, TEXT("랜덤 이벤트 발생! HP가 10 회복됩니다!"));
		}

		UE_LOG(LogTemp, Warning, TEXT("[%d회차] 이전: (%.0f, %.0f) → 현재: (%.0f, %.0f) | 이동 거리: %.2f \n"),
			i + 1,
			PrevPosition.X, PrevPosition.Y,
			CurrentPosition.X, CurrentPosition.Y,
			MoveDistance
		);
		UE_LOG(LogTemp, Warning, TEXT(" "));
		UE_LOG(LogTemp, Warning, TEXT("======================================="));
		UE_LOG(LogTemp, Warning, TEXT(" "));
	}
}

/**
 * @brief 주어진 확률(퍼센트)로 랜덤 성공 여부를 결정합니다.
 * 
 * @param Percent 확률 값 (0~100) - 몇 % 확률로 성공할지 지정
 * @return int32 성공하면 1, 실패하면 0 반환 (또는 true/false 대신 int)
 */
bool AMoverMachine::IsProbabilitySuccess()
{
	int32 RandomValue = FMath::RandRange(1, 100);

	int32 Percent = (RandomPercent > 0) ? RandomPercent : 50;

	return RandomValue <= Percent;
}

// Called every frame
void AMoverMachine::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

