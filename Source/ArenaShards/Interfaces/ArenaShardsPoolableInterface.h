// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "ArenaShardsPoolableInterface.generated.h"

UINTERFACE(Blueprintable)
class UArenaShardsPoolableInterface : public UInterface
{
    GENERATED_BODY()
};

class IArenaShardsPoolableInterface
{
    GENERATED_BODY()

public:
    virtual void OnTakenFromPool(FTransform PlaceHere) = 0;
    virtual void OnReturnedToPool() = 0;
    virtual bool IsPooled() = 0;
};