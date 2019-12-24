// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SequencePuzzlebutton.generated.h"

UCLASS()
class CPPTUTORIAL_API ASequencePuzzlebutton : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASequencePuzzlebutton();

	UPROPERTY(BlueprintReadOnly)
	FLinearColor Color;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void Highlight(bool bIsHightlight);
};
