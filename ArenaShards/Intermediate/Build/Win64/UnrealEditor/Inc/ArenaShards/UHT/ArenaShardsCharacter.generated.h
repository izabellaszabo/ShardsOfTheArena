// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "ArenaShardsCharacter.h"

#ifdef ARENASHARDS_ArenaShardsCharacter_generated_h
#error "ArenaShardsCharacter.generated.h already included, missing '#pragma once' in ArenaShardsCharacter.h"
#endif
#define ARENASHARDS_ArenaShardsCharacter_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class AArenaShardsCharacter ****************************************************
#define FID_ArenaShards_Source_ArenaShards_ArenaShardsCharacter_h_24_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execDoJumpEnd); \
	DECLARE_FUNCTION(execDoJumpStart); \
	DECLARE_FUNCTION(execDoLook); \
	DECLARE_FUNCTION(execDoMove);


ARENASHARDS_API UClass* Z_Construct_UClass_AArenaShardsCharacter_NoRegister();

#define FID_ArenaShards_Source_ArenaShards_ArenaShardsCharacter_h_24_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAArenaShardsCharacter(); \
	friend struct Z_Construct_UClass_AArenaShardsCharacter_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend ARENASHARDS_API UClass* Z_Construct_UClass_AArenaShardsCharacter_NoRegister(); \
public: \
	DECLARE_CLASS2(AArenaShardsCharacter, ACharacter, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Config), CASTCLASS_None, TEXT("/Script/ArenaShards"), Z_Construct_UClass_AArenaShardsCharacter_NoRegister) \
	DECLARE_SERIALIZER(AArenaShardsCharacter)


#define FID_ArenaShards_Source_ArenaShards_ArenaShardsCharacter_h_24_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	AArenaShardsCharacter(AArenaShardsCharacter&&) = delete; \
	AArenaShardsCharacter(const AArenaShardsCharacter&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AArenaShardsCharacter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AArenaShardsCharacter); \
	DEFINE_ABSTRACT_DEFAULT_CONSTRUCTOR_CALL(AArenaShardsCharacter) \
	NO_API virtual ~AArenaShardsCharacter();


#define FID_ArenaShards_Source_ArenaShards_ArenaShardsCharacter_h_21_PROLOG
#define FID_ArenaShards_Source_ArenaShards_ArenaShardsCharacter_h_24_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_ArenaShards_Source_ArenaShards_ArenaShardsCharacter_h_24_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_ArenaShards_Source_ArenaShards_ArenaShardsCharacter_h_24_INCLASS_NO_PURE_DECLS \
	FID_ArenaShards_Source_ArenaShards_ArenaShardsCharacter_h_24_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class AArenaShardsCharacter;

// ********** End Class AArenaShardsCharacter ******************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_ArenaShards_Source_ArenaShards_ArenaShardsCharacter_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
