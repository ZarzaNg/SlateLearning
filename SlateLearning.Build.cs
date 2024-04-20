// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class SlateLearning : ModuleRules
{
	public SlateLearning(ReadOnlyTargetRules Target) : base(Target)
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
