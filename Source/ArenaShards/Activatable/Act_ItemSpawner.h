// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Activatable/ActivatableBase.h"
#include "Act_ItemSpawner.generated.h"

/**
 * 
 */
UCLASS()
class ARENASHARDS_API AAct_ItemSpawner : public AActivatableBase
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

	AAct_ItemSpawner();

protected:
	virtual void BeginPlay();
	virtual void OnActivated();
	virtual void OnDeactivated();

private:
	UPROPERTY() 
	AArenaShardsPickupBase* SpawnedActor = nullptr;

	FTimerHandle RespawnTimerHandle;

	UFUNCTION()
	void SpawnItem();
	UFUNCTION()
	void ItemPickedUp();

};
