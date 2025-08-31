// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Subsystems/WorldSubsystem.h"
#include "ArenaShardsPoolingSubsystem.generated.h"

UCLASS()
class ARENASHARDS_API UArenaShardsPoolingSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()
	
public:	
	template<typename T>
	T* GetPooledActor(TSubclassOf<T> ClassToSpawn, FTransform PlaceHere);

	void ReturnPooledActor(AActor* ActorToPool);

protected:
	TMap<UClass*, TArray<AActor*>> PooledActorsMap;

};
