// Fill out your copyright notice in the Description page of Project Settings.
#include "Pickup/ArenaShardsPickupBase.h"
#include "Components/StaticMeshComponent.h"
#include "ArenaShardsPoolingSubsystem.h"

// Sets default values
AArenaShardsPickupBase::AArenaShardsPickupBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	bReplicates = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	BaseMesh->SetupAttachment(RootComponent);
	BaseMesh->SetCollisionProfileName(FName("OverlapAllDynamic"));
	BaseMesh->OnComponentBeginOverlap.AddDynamic(this, &AArenaShardsPickupBase::OnOverlap);
}

// Called when the game starts or when spawned
void AArenaShardsPickupBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AArenaShardsPickupBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AArenaShardsPickupBase::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	HandlePickup(OtherActor);
}

void AArenaShardsPickupBase::HandlePickup(AActor* PickedUpBy)
{
	BP_OnPickedUp(PickedUpBy);
	OnPickedUp.Broadcast();

	auto PoolManager = GetWorld()->GetSubsystem<UArenaShardsPoolingSubsystem>();
	PoolManager->ReturnPooledActor(this);
}

void AArenaShardsPickupBase::OnTakenFromPool(FTransform PlaceHere)
{
	IsInPool = false;
	BaseMesh->SetVisibility(true);
	BaseMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	SetActorTransform(PlaceHere);
}

void AArenaShardsPickupBase::OnReturnedToPool()
{
	IsInPool = true;
	BaseMesh->SetVisibility(false);
	BaseMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	SetActorTransform(FTransform::Identity);
}

bool AArenaShardsPickupBase::IsPooled()
{
	return IsInPool;
}