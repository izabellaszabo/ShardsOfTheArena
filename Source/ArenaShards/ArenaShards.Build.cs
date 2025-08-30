// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ArenaShards : ModuleRules
{
	public ArenaShards(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"ArenaShards",
			"ArenaShards/Variant_Platforming",
			"ArenaShards/Variant_Platforming/Animation",
			"ArenaShards/Variant_Combat",
			"ArenaShards/Variant_Combat/AI",
			"ArenaShards/Variant_Combat/Animation",
			"ArenaShards/Variant_Combat/Gameplay",
			"ArenaShards/Variant_Combat/Interfaces",
			"ArenaShards/Variant_Combat/UI",
			"ArenaShards/Variant_SideScrolling",
			"ArenaShards/Variant_SideScrolling/AI",
			"ArenaShards/Variant_SideScrolling/Gameplay",
			"ArenaShards/Variant_SideScrolling/Interfaces",
			"ArenaShards/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
