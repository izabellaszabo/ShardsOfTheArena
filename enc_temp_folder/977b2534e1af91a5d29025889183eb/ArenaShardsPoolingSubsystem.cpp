// Fill out your copyright notice in the Description page of Project Settings.
#include "ArenaShardsPoolingSubsystem.h"
#include "Interfaces/ArenaShardsPoolableInterface.h"

template<typename T>
T* UArenaShardsPoolingSubsystem::GetPooledActor(TSubclassOf<T> ClassToSpawn, FTransform PlaceHere)
{
    static_assert(TIsDerivedFrom<T, AActor>::IsDerived, "T must be an AActor");

    if (!ClassToSpawn)
    {
        return nullptr;
    }

    TArray<AActor*>& Pool = PooledActorsMap.FindOrAdd(*ClassToSpawn);

    for (AActor* Actor : Pool)
    {
        if (IArenaShardsPoolableInterface* Poolable = Cast<IArenaShardsPoolableInterface>(Actor))
        {
            if(Poolable->IsPooled())
            {
                Poolable->OnTakenFromPool(PlaceHere);
                return Cast<T>(Actor);
            }
        }
    }

    AActor* NewActor = GetWorld()->SpawnActor<AActor>(*ClassToSpawn);
    if (NewActor)
    {
        Pool.Add(NewActor);
        if (IArenaShardsPoolableInterface* Poolable = Cast<IArenaShardsPoolableInterface>(NewActor))
        {
            Poolable->OnTakenFromPool(PlaceHere);
        }
    }

    return Cast<T>(NewActor);
}

void UArenaShardsPoolingSubsystem::ReturnPooledActor(AActor* ActorToPool)
{
    if (IArenaShardsPoolableInterface* Poolable = Cast<IArenaShardsPoolableInterface>(ActorToPool))
    {
        Poolable->OnReturnedToPool();
    }
}