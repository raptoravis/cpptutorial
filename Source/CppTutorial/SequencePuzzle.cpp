// Fill out your copyright notice in the Description page of Project Settings.


#include "SequencePuzzle.h"
#include "SequencePuzzlebutton.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ASequencePuzzle::ASequencePuzzle() : NumberOfOptions(4), DistanceFromOrigin(100)
{
	// disable tick events
	PrimaryActorTick.bCanEverTick = false;

	for (int32 i = 0; i < NumberOfOptions; ++i)
	{
		Sequence.Add(i);
	}
}

// Called when the game starts or when spawned
void ASequencePuzzle::BeginPlay()
{
	Super::BeginPlay();

	FLinearColor Colors[] = { FLinearColor(1, 0, 0, 0), FLinearColor(0, 1, 0, 0),FLinearColor(0, 0, 1, 0),FLinearColor(1, 1, 0, 0) };

	UWorld* World = GetWorld();
	if (World)
	{
		FVector OffsetVector(DistanceFromOrigin, 0, DistanceFromOrigin);
		FRotator Rotator(90, 0, 0);

		for (int32 i = 0; i < NumberOfOptions; ++i)
		{
			FTransform Transform = GetTransform();
			//Transform.SetLocation(OffsetVector);
			Transform.AddToTranslation(OffsetVector);

			ASequencePuzzlebutton* Button = Cast<ASequencePuzzlebutton>(UGameplayStatics::BeginDeferredActorSpawnFromClass(this, ButtonClass, Transform));
			Button->Color = Colors[i];//FLinearColor(1, 0, 0, 0);
			Buttons.Add(Button);

			UGameplayStatics::FinishSpawningActor(Button, Transform);

			OffsetVector = Rotator.RotateVector(OffsetVector);

			//ASequencePuzzlebutton* Button = World->SpawnActor<ASequencePuzzlebutton>(ButtonClass, GetTransform());
		}
	}
}

//// Called every frame
//void ASequencePuzzle::Tick(float DeltaTime)
//{
//	Super::Tick(DeltaTime);
//
//}
//
