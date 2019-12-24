// Fill out your copyright notice in the Description page of Project Settings.


#include "SequencePuzzle.h"
#include "SequencePuzzlebutton.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ASequencePuzzle::ASequencePuzzle()
{
	// disable tick events
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void ASequencePuzzle::BeginPlay()
{
	Super::BeginPlay();
	
	UWorld* World = GetWorld();
	if (World)
	{
		ASequencePuzzlebutton* Button = Cast<ASequencePuzzlebutton>(UGameplayStatics::BeginDeferredActorSpawnFromClass(this, ButtonClass, GetTransform()));
		Button->Color = FLinearColor(1, 0, 0, 0);
		UGameplayStatics::FinishSpawningActor(Button, GetTransform());

		//ASequencePuzzlebutton* Button = World->SpawnActor<ASequencePuzzlebutton>(ButtonClass, GetTransform());
	}
}

//// Called every frame
//void ASequencePuzzle::Tick(float DeltaTime)
//{
//	Super::Tick(DeltaTime);
//
//}
//
