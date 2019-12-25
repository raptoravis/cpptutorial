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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<ASequencePuzzlebutton> ButtonClass;

	int32 NumberOfOptions;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float DistanceFromOrigin;

	UPROPERTY(BlueprintReadOnly)
	TArray<ASequencePuzzlebutton*> Buttons;

	UPROPERTY(BlueprintReadOnly)
	TArray<int32> Sequence;

public:
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void PlaySequence();

	UFUNCTION(BlueprintCallable)
	void Guess(int32 Guess);
private:
	// Add one to the sequence
	void ExtendSequence();

	int32 SequenceIndex;
};
