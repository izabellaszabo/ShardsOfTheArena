// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeArenaShards_init() {}
	ARENASHARDS_API UFunction* Z_Construct_UDelegateFunction_ArenaShards_OnEnemyDied__DelegateSignature();
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_ArenaShards;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_ArenaShards()
	{
		if (!Z_Registration_Info_UPackage__Script_ArenaShards.OuterSingleton)
		{
			static UObject* (*const SingletonFuncArray[])() = {
				(UObject* (*)())Z_Construct_UDelegateFunction_ArenaShards_OnEnemyDied__DelegateSignature,
			};
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/ArenaShards",
				SingletonFuncArray,
				UE_ARRAY_COUNT(SingletonFuncArray),
				PKG_CompiledIn | 0x00000000,
				0xCB46D6A4,
				0xEE714C9E,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_ArenaShards.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_ArenaShards.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_ArenaShards(Z_Construct_UPackage__Script_ArenaShards, TEXT("/Script/ArenaShards"), Z_Registration_Info_UPackage__Script_ArenaShards, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0xCB46D6A4, 0xEE714C9E));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
