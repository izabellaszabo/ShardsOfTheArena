// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "ArenaShardsGameMode.h"

#ifdef ARENASHARDS_ArenaShardsGameMode_generated_h
#error "ArenaShardsGameMode.generated.h already included, missing '#pragma once' in ArenaShardsGameMode.h"
#endif
#define ARENASHARDS_ArenaShardsGameMode_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class AArenaShardsGameMode *****************************************************
ARENASHARDS_API UClass* Z_Construct_UClass_AArenaShardsGameMode_NoRegister();

#define FID_ArenaShards_Source_ArenaShards_ArenaShardsGameMode_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAArenaShardsGameMode(); \
	friend struct Z_Construct_UClass_AArenaShardsGameMode_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend ARENASHARDS_API UClass* Z_Construct_UClass_AArenaShardsGameMode_NoRegister(); \
public: \
	DECLARE_CLASS2(AArenaShardsGameMode, AGameModeBase, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/ArenaShards"), Z_Construct_UClass_AArenaShardsGameMode_NoRegister) \
	DECLARE_SERIALIZER(AArenaShardsGameMode)


#define FID_ArenaShards_Source_ArenaShards_ArenaShardsGameMode_h_15_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	AArenaShardsGameMode(AArenaShardsGameMode&&) = delete; \
	AArenaShardsGameMode(const AArenaShardsGameMode&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AArenaShardsGameMode); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AArenaShardsGameMode); \
	DEFINE_ABSTRACT_DEFAULT_CONSTRUCTOR_CALL(AArenaShardsGameMode) \
	NO_API virtual ~AArenaShardsGameMode();


#define FID_ArenaShards_Source_ArenaShards_ArenaShardsGameMode_h_12_PROLOG
#define FID_ArenaShards_Source_ArenaShards_ArenaShardsGameMode_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_ArenaShards_Source_ArenaShards_ArenaShardsGameMode_h_15_INCLASS_NO_PURE_DECLS \
	FID_ArenaShards_Source_ArenaShards_ArenaShardsGameMode_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class AArenaShardsGameMode;

// ********** End Class AArenaShardsGameMode *******************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_ArenaShards_Source_ArenaShards_ArenaShardsGameMode_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
