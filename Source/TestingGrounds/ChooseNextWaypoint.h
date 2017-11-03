// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BehaviorTree/BTTaskNode.h"
#include "ChooseNextWaypoint.generated.h"

/**
 * 
 */
UCLASS()
class TESTINGGROUNDS_API UChooseNextWaypoint : public UBTTaskNode
{
	GENERATED_BODY()
	
public:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

protected:
	UPROPERTY(EditAnywhere, Category = Blackboard)
	struct FBlackboardKeySelector NextWaypointIndexKey;

	UPROPERTY(EditAnywhere, Category = Blackboard)
	struct FBlackboardKeySelector NextWaypointKey;

private:
	// An array of waypoints along the controlled character's patrol route
	TArray<AActor*> PatrolPoints;

	void GetPatrolPoints(UBehaviorTreeComponent& OwnerComp);
	void SetNextWaypoint(UBlackboardComponent* BlackboardComponent);
	void CycleNextWaypointIndex(UBlackboardComponent* BlackboardComponent);
};
