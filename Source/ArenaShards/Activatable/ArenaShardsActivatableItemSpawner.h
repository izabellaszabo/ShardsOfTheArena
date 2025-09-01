// Copyright (c) 2025, Izabella Szabo. All rights reserved.

#pragma once

#include "ArenaShardsActivatableBase.h"
#include "ArenaShardsActivatableItemSpawner.generated.h"

/**
 * 
 */
UCLASS()
class ARENASHARDS_API AArenaShardsActivatableItemSpawner : public AArenaShardsActivatableBase
{
	GENERATED_BODY()
	
public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	class UStaticMeshComponent* SpawnTransform;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class AArenaShardsPickupBase> ActorClassToSpawn;

	UPROPERTY(EditAnywhere)
	bool ShouldRespawn = false;

	UPROPERTY(EditAnywhere)
	float RespawnSecInterval = 1;

	AArenaShardsActivatableItemSpawner();

protected:
	virtual void BeginPlay();
	virtual void OnActivated() override;
	virtual void OnDeactivated() override;

private:
	UPROPERTY() 
	AArenaShardsPickupBase* SpawnedActor = nullptr;

	FTimerHandle RespawnTimerHandle;

	UFUNCTION()
	void SpawnItem();
	UFUNCTION()
	void ItemPickedUp();

};
