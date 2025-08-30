// Fill out your copyright notice in the Description page of Project Settings.
#include "Activatable/Act_ItemSpawner.h"
#include "../Gameplay/Pickup/ArenaShardsPickupBase.h"

AAct_ItemSpawner::AAct_ItemSpawner()
{
	SpawnTransform = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Spawn Transform"));
	SpawnTransform->SetupAttachment(RootComponent);
	SpawnTransform->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	SpawnTransform->SetHiddenInGame(true);
}

void AAct_ItemSpawner::BeginPlay()
{
	Super::BeginPlay();
}

void AAct_ItemSpawner::OnActivated()
{
	Super::OnActivated();

	SpawnItem();
}

void AAct_ItemSpawner::OnDeactivated()
{
	Super::OnDeactivated();

	if (RespawnTimerHandle.IsValid())
		RespawnTimerHandle.Invalidate();
}

void AAct_ItemSpawner::SpawnItem()
{
	FActorSpawnParameters SpawnParams;
	SpawnParams.Owner = this;
	SpawnParams.Instigator = GetInstigator();

	SpawnedActor = GetWorld()->SpawnActor<AArenaShardsPickupBase>(ActorClassToSpawn, SpawnTransform->GetComponentTransform(), SpawnParams);
	if(SpawnedActor)
		SpawnedActor->OnPickedUp.AddDynamic(this, &AAct_ItemSpawner::ItemPickedUp);
}

void AAct_ItemSpawner::ItemPickedUp()
{
	if (SpawnedActor)
		SpawnedActor->OnPickedUp.RemoveDynamic(this, &AAct_ItemSpawner::ItemPickedUp); 
	SpawnedActor = nullptr;

	if (ShouldRespawn)
		GetWorld()->GetTimerManager().SetTimer(RespawnTimerHandle, this, &AAct_ItemSpawner::SpawnItem, RespawnSecInterval, false);
}

