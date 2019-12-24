// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SequencePuzzle.generated.h"

class ASequencePuzzlebutton;

UCLASS()
class CPPTUTORIAL_API ASequencePuzzle : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASequencePuzzle();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<ASequencePuzzlebutton> ButtonClass;
//public:	
//	// Called every frame
//	virtual void Tick(float DeltaTime) override;

};
