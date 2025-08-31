// Fill out your copyright notice in the Description page of Project Settings.
#include "Activatable/ActivatableItemSpawner.h"
#include "../Pickup/ArenaShardsPickupBase.h"
#include "../ArenaShardsPoolingSubsystem.h"

AActivatableItemSpawner::AActivatableItemSpawner()
{
	SpawnTransform = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Spawn Transform"));
	SpawnTransform->SetupAttachment(RootComponent);
	SpawnTransform->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	SpawnTransform->SetHiddenInGame(true);
}

void AActivatableItemSpawner::BeginPlay()
{
	Super::BeginPlay();
}

void AActivatableItemSpawner::OnActivated()
{
	Super::OnActivated();

	SpawnItem();
}

void AActivatableItemSpawner::OnDeactivated()
{
	Super::OnDeactivated();

	if (RespawnTimerHandle.IsValid())
		RespawnTimerHandle.Invalidate();
}

void AActivatableItemSpawner::SpawnItem()
{
	FActorSpawnParameters SpawnParams;
	SpawnParams.Owner = this;
	SpawnParams.Instigator = GetInstigator();

	auto PoolManager = GetWorld()->GetSubsystem<UArenaShardsPoolingSubsystem>();
	SpawnedActor = PoolManager->GetPooledActor(ActorClassToSpawn, SpawnTransform->GetComponentTransform());

	if(SpawnedActor)
		SpawnedActor->OnPickedUp.AddDynamic(this, &AActivatableItemSpawner::ItemPickedUp);
}

void AActivatableItemSpawner::ItemPickedUp()
{
	if (SpawnedActor)
		SpawnedActor->OnPickedUp.RemoveDynamic(this, &AActivatableItemSpawner::ItemPickedUp); 
	SpawnedActor = nullptr;

	if (ShouldRespawn)
		GetWorld()->GetTimerManager().SetTimer(RespawnTimerHandle, this, &AActivatableItemSpawner::SpawnItem, RespawnSecInterval, false);
}
