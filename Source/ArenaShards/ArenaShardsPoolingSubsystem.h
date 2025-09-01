// Copyright (c) 2025, Izabella Szabo. All rights reserved.

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
