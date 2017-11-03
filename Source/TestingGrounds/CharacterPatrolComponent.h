// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "CharacterPatrolComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TESTINGGROUNDS_API UCharacterPatrolComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCharacterPatrolComponent();

	TArray<AActor*> GetPatrolPoints();

private:
	// An array of waypoints along the controlled character's patrol route
	UPROPERTY(EditInstanceOnly, Category = Patrol)
	TArray<AActor*> PatrolPoints;
};
