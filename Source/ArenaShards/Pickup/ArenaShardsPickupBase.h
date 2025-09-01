// Copyright (c) 2025, Izabella Szabo. All rights reserved.

#pragma once

#include "GameFramework/Actor.h"
#include "../Interfaces/ArenaShardsPoolableInterface.h"
#include "ArenaShardsPickupBase.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPickedUp);

UCLASS()
class ARENASHARDS_API AArenaShardsPickupBase : public AActor, public IArenaShardsPoolableInterface
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USceneComponent* Root;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* BaseMesh;

	UPROPERTY(BlueprintAssignable, Category = "Pickup")
	FOnPickedUp OnPickedUp;
	
	AArenaShardsPickupBase();
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintImplementableEvent)
	void BP_OnPickedUp(AActor* PickedUpBy);

	// Pooling
	virtual void OnTakenFromPool(FTransform PlaceHere);
	virtual void OnReturnedToPool();
	virtual bool IsPooled();

protected:
	virtual void BeginPlay() override;

	UFUNCTION()
	void OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	virtual void HandlePickup(AActor* PickedUpBy);


private:
	bool IsInPool = false;

};
