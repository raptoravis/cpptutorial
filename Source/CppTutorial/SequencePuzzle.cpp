// Fill out your copyright notice in the Description page of Project Settings.


#include "SequencePuzzle.h"
#include "SequencePuzzlebutton.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ASequencePuzzle::ASequencePuzzle() : NumberOfOptions(4), DistanceFromOrigin(100), SequenceIndex(0)
{
	// disable tick events
	PrimaryActorTick.bCanEverTick = false;

	//for (int32 i = 0; i < NumberOfOptions; ++i)
	//{
	//	Sequence.Add(i);
	//}
	ExtendSequence();
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
			Button->Index = i;
			Button->Puzzle = this;

			Buttons.Add(Button);

			UGameplayStatics::FinishSpawningActor(Button, Transform);

			OffsetVector = Rotator.RotateVector(OffsetVector);

			//ASequencePuzzlebutton* Button = World->SpawnActor<ASequencePuzzlebutton>(ButtonClass, GetTransform());
		}
	}
}

void ASequencePuzzle::Guess(int32 Guess)
{
	//UE_LOG(LogTemp, Warning, TEXT("ASequencePuzzle::Guess"));
	int32 Actual = Sequence[SequenceIndex];
	if (Guess == Actual)
	{
		UE_LOG(LogTemp, Warning, TEXT("correct Guess %d"), Guess);
		SequenceIndex++;
		if (SequenceIndex == Sequence.Num())
		{
			SequenceIndex = 0;
			ExtendSequence();
			PlaySequence();
		}
		else
		{
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("incorrect Guess %d"), Guess);

		SequenceIndex = 0;
		Sequence.Empty();
		ExtendSequence();
		PlaySequence();
	}
}

void ASequencePuzzle::ExtendSequence()
{
	int32 ToAdd = FMath::RandRange(0, NumberOfOptions - 1);

	Sequence.Add(ToAdd);
}

//// Called every frame
//void ASequencePuzzle::Tick(float DeltaTime)
//{
//	Super::Tick(DeltaTime);
//
//}
//
