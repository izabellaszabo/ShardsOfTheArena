// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "ArenaShardsPlayerController.h"

#ifdef ARENASHARDS_ArenaShardsPlayerController_generated_h
#error "ArenaShardsPlayerController.generated.h already included, missing '#pragma once' in ArenaShardsPlayerController.h"
#endif
#define ARENASHARDS_ArenaShardsPlayerController_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class AArenaShardsPlayerController *********************************************
ARENASHARDS_API UClass* Z_Construct_UClass_AArenaShardsPlayerController_NoRegister();

#define FID_ArenaShards_Source_ArenaShards_ArenaShardsPlayerController_h_19_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAArenaShardsPlayerController(); \
	friend struct Z_Construct_UClass_AArenaShardsPlayerController_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend ARENASHARDS_API UClass* Z_Construct_UClass_AArenaShardsPlayerController_NoRegister(); \
public: \
	DECLARE_CLASS2(AArenaShardsPlayerController, APlayerController, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Config), CASTCLASS_None, TEXT("/Script/ArenaShards"), Z_Construct_UClass_AArenaShardsPlayerController_NoRegister) \
	DECLARE_SERIALIZER(AArenaShardsPlayerController)


#define FID_ArenaShards_Source_ArenaShards_ArenaShardsPlayerController_h_19_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AArenaShardsPlayerController(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	AArenaShardsPlayerController(AArenaShardsPlayerController&&) = delete; \
	AArenaShardsPlayerController(const AArenaShardsPlayerController&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AArenaShardsPlayerController); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AArenaShardsPlayerController); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AArenaShardsPlayerController) \
	NO_API virtual ~AArenaShardsPlayerController();


#define FID_ArenaShards_Source_ArenaShards_ArenaShardsPlayerController_h_16_PROLOG
#define FID_ArenaShards_Source_ArenaShards_ArenaShardsPlayerController_h_19_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_ArenaShards_Source_ArenaShards_ArenaShardsPlayerController_h_19_INCLASS_NO_PURE_DECLS \
	FID_ArenaShards_Source_ArenaShards_ArenaShardsPlayerController_h_19_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class AArenaShardsPlayerController;

// ********** End Class AArenaShardsPlayerController ***********************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_ArenaShards_Source_ArenaShards_ArenaShardsPlayerController_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
