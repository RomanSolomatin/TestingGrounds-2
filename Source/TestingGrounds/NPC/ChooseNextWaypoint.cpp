// Fill out your copyright notice in the Description page of Project Settings.

#include "TestingGrounds.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "CharacterPatrolComponent.h"
#include "ChooseNextWaypoint.h"

EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UBlackboardComponent* BlackboardComponent = OwnerComp.GetBlackboardComponent();

	if (BlackboardComponent)
	{
		GetPatrolPoints(OwnerComp);
		SetNextWaypoint(BlackboardComponent);
		CycleNextWaypointIndex(BlackboardComponent);
	}

	return EBTNodeResult::Succeeded;
}

void UChooseNextWaypoint::GetPatrolPoints(UBehaviorTreeComponent& OwnerComp)
{
	// Get the controlled pawn
	APawn* Pawn = OwnerComp.GetAIOwner()->GetPawn();
	UCharacterPatrolComponent* CharacterPatrolComponent = nullptr;

	if (Pawn)
	{
		// Initialize the CharacterPatrolComponent
		CharacterPatrolComponent = Pawn->FindComponentByClass<UCharacterPatrolComponent>();
	}

	if (CharacterPatrolComponent)
	{
		// Get the patrol points
		PatrolPoints = CharacterPatrolComponent->GetPatrolPoints();
	}
}

void UChooseNextWaypoint::SetNextWaypoint(UBlackboardComponent* BlackboardComponent)
{
	// Get the current index of the NextWaypoint array
	int32 Index = BlackboardComponent->GetValueAsInt(NextWaypointIndexKey.SelectedKeyName);
	AActor* NextWaypoint = nullptr;

	if (PatrolPoints.Num() > 0)
	{
		// Get the next waypoint
		NextWaypoint = PatrolPoints[Index];
	}

	if (NextWaypoint)
	{
		// Set the next waypoint
		BlackboardComponent->SetValueAsObject(NextWaypointKey.SelectedKeyName, NextWaypoint);
	}
}

void UChooseNextWaypoint::CycleNextWaypointIndex(UBlackboardComponent* BlackboardComponent)
{
	// Get the current index of the NextWaypoint array
	int32 Index = BlackboardComponent->GetValueAsInt(NextWaypointIndexKey.SelectedKeyName);
	
	if (PatrolPoints.Num() > 0)
	{
		// Cycle o the new index
		Index = ++Index % PatrolPoints.Num();

		// Set the new current index
		BlackboardComponent->SetValueAsInt(NextWaypointIndexKey.SelectedKeyName, Index);
	}
}