// Copyright (c) 2025, Izabella Szabo. All rights reserved.

#include "Activatable/ArenaShardsActivatableItemSpawner.h"
#include "../Pickup/ArenaShardsPickupBase.h"
#include "../ArenaShardsPoolingSubsystem.h"

AArenaShardsActivatableItemSpawner::AArenaShardsActivatableItemSpawner()
{
	SpawnTransform = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Spawn Transform"));
	SpawnTransform->SetupAttachment(RootComponent);
	SpawnTransform->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	SpawnTransform->SetHiddenInGame(true);
}

void AArenaShardsActivatableItemSpawner::BeginPlay()
{
	Super::BeginPlay();
}

void AArenaShardsActivatableItemSpawner::OnActivated()
{
	Super::OnActivated();

	SpawnItem();
}

void AArenaShardsActivatableItemSpawner::OnDeactivated()
{
	Super::OnDeactivated();

	if (RespawnTimerHandle.IsValid())
		RespawnTimerHandle.Invalidate();
}

void AArenaShardsActivatableItemSpawner::SpawnItem()
{
	FActorSpawnParameters SpawnParams;
	SpawnParams.Owner = this;
	SpawnParams.Instigator = GetInstigator();

	auto PoolManager = GetWorld()->GetSubsystem<UArenaShardsPoolingSubsystem>();
	SpawnedActor = PoolManager->GetPooledActor(ActorClassToSpawn, SpawnTransform->GetComponentTransform());

	if(SpawnedActor)
		SpawnedActor->OnPickedUp.AddDynamic(this, &AArenaShardsActivatableItemSpawner::ItemPickedUp);
	else
		UE_LOG(LogTemp, Warning, TEXT("Failed To Spawn Item"))
}

void AArenaShardsActivatableItemSpawner::ItemPickedUp()
{
	if (SpawnedActor)
		SpawnedActor->OnPickedUp.RemoveDynamic(this, &AArenaShardsActivatableItemSpawner::ItemPickedUp); 
	SpawnedActor = nullptr;

	if (ShouldRespawn)
		GetWorld()->GetTimerManager().SetTimer(RespawnTimerHandle, this, &AArenaShardsActivatableItemSpawner::SpawnItem, RespawnSecInterval, false);
}
