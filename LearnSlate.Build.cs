// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class LearnSlate : ModuleRules
{
	public LearnSlate(ReadOnlyTargetRules Target) : base(Target)
	{
		PublicIncludePaths.Add("Runtime/Launch/Public");
		
		PrivateIncludePaths.Add("Runtime/Launch/Private");
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"AppFramework",
				"Core",
				"ApplicationCore",
				"Projects",
				"Slate",
				"SlateCore",
				"StandaloneRenderer", 
			});
	}
}
