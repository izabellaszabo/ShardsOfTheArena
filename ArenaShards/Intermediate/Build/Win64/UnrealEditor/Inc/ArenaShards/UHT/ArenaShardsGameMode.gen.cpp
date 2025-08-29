// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ArenaShardsGameMode.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeArenaShardsGameMode() {}

// ********** Begin Cross Module References ********************************************************
ARENASHARDS_API UClass* Z_Construct_UClass_AArenaShardsGameMode();
ARENASHARDS_API UClass* Z_Construct_UClass_AArenaShardsGameMode_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
UPackage* Z_Construct_UPackage__Script_ArenaShards();
// ********** End Cross Module References **********************************************************

// ********** Begin Class AArenaShardsGameMode *****************************************************
void AArenaShardsGameMode::StaticRegisterNativesAArenaShardsGameMode()
{
}
FClassRegistrationInfo Z_Registration_Info_UClass_AArenaShardsGameMode;
UClass* AArenaShardsGameMode::GetPrivateStaticClass()
{
	using TClass = AArenaShardsGameMode;
	if (!Z_Registration_Info_UClass_AArenaShardsGameMode.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("ArenaShardsGameMode"),
			Z_Registration_Info_UClass_AArenaShardsGameMode.InnerSingleton,
			StaticRegisterNativesAArenaShardsGameMode,
			sizeof(TClass),
			alignof(TClass),
			TClass::StaticClassFlags,
			TClass::StaticClassCastFlags(),
			TClass::StaticConfigName(),
			(UClass::ClassConstructorType)InternalConstructor<TClass>,
			(UClass::ClassVTableHelperCtorCallerType)InternalVTableHelperCtorCaller<TClass>,
			UOBJECT_CPPCLASS_STATICFUNCTIONS_FORCLASS(TClass),
			&TClass::Super::StaticClass,
			&TClass::WithinClass::StaticClass
		);
	}
	return Z_Registration_Info_UClass_AArenaShardsGameMode.InnerSingleton;
}
UClass* Z_Construct_UClass_AArenaShardsGameMode_NoRegister()
{
	return AArenaShardsGameMode::GetPrivateStaticClass();
}
struct Z_Construct_UClass_AArenaShardsGameMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n *  Simple GameMode for a third person game\n */" },
#endif
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "ArenaShardsGameMode.h" },
		{ "ModuleRelativePath", "ArenaShardsGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Simple GameMode for a third person game" },
#endif
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AArenaShardsGameMode>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_AArenaShardsGameMode_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AGameModeBase,
	(UObject* (*)())Z_Construct_UPackage__Script_ArenaShards,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AArenaShardsGameMode_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AArenaShardsGameMode_Statics::ClassParams = {
	&AArenaShardsGameMode::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x008003ADu,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AArenaShardsGameMode_Statics::Class_MetaDataParams), Z_Construct_UClass_AArenaShardsGameMode_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AArenaShardsGameMode()
{
	if (!Z_Registration_Info_UClass_AArenaShardsGameMode.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AArenaShardsGameMode.OuterSingleton, Z_Construct_UClass_AArenaShardsGameMode_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AArenaShardsGameMode.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AArenaShardsGameMode);
AArenaShardsGameMode::~AArenaShardsGameMode() {}
// ********** End Class AArenaShardsGameMode *******************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_ArenaShards_Source_ArenaShards_ArenaShardsGameMode_h__Script_ArenaShards_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AArenaShardsGameMode, AArenaShardsGameMode::StaticClass, TEXT("AArenaShardsGameMode"), &Z_Registration_Info_UClass_AArenaShardsGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AArenaShardsGameMode), 1299024316U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ArenaShards_Source_ArenaShards_ArenaShardsGameMode_h__Script_ArenaShards_1500588148(TEXT("/Script/ArenaShards"),
	Z_CompiledInDeferFile_FID_ArenaShards_Source_ArenaShards_ArenaShardsGameMode_h__Script_ArenaShards_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_ArenaShards_Source_ArenaShards_ArenaShardsGameMode_h__Script_ArenaShards_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
