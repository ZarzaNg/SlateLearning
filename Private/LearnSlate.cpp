// Copyright Epic Games, Inc. All Rights Reserved.

#include "LearnSlate.h"

#include "RequiredProgramMainCPPInclude.h"

DEFINE_LOG_CATEGORY_STATIC(LogLearnSlate, Log, All);

IMPLEMENT_APPLICATION(LearnSlate, "LearnSlate");

INT32_MAIN_INT32_ARGC_TCHAR_ARGV()
{
	FTaskTagScope Scope(ETaskTag::EGameThread);
	ON_SCOPE_EXIT
	{ 
		LLM(FLowLevelMemTracker::Get().UpdateStatsPerFrame());
		RequestEngineExit(TEXT("Exiting"));
		FEngineLoop::AppPreExit();
		FModuleManager::Get().UnloadModulesAtShutdown();
		FEngineLoop::AppExit();
	};

	if (int32 Ret = GEngineLoop.PreInit(ArgC, ArgV))
	{
		return Ret;
	}

	// to run automation tests in LearnSlate:
	// * set `bForceCompileDevelopmentAutomationTests` to `true` in `LearnSlateTarget` constructor in "LearnSlate.Target.cs"
	// add `FAutomationTestFramework::Get().StartTestByName(TEXT("The name of the test class passed to IMPLEMENT_SIMPLE_AUTOMATION_TEST or TEST_CASE_NAMED"), 0);` right here

	// to link with "CoreUObject" module:
	// * uncomment `PrivateDependencyModuleNames.Add("CoreUObject");` in `LearnSlate` constructor in "LearnSlate.Build.cs"
	// * set `bCompileAgainstCoreUObject` to `true` in `LearnSlateTarget` constructor in "LearnSlate.Target.cs"

	// to enable tracing:
	// * uncomment `AppendStringToPublicDefinition("UE_TRACE_ENABLED", "1");` in `LearnSlate` constructor in "LearnSlate.Build.cs"
	// * uncomment `GlobalDefinitions.Add("UE_TRACE_ENABLED=1");` in `LearnSlateTarget` constructor in "LearnSlate.Target.cs"
	// you may need to enable compilation of a particular trace channel, e.g. for "task" traces:
	// * add `GlobalDefinitions.Add("UE_TASK_TRACE_ENABLED=1");` in `LearnSlateTarget` constructor in "LearnSlate.Target.cs"
	// you'll still need to enable this trace channel on cmd-line like `-trace=task,default`

	// to enable LLM tracing, uncomment the following in `LearnSlate` constructor in "LearnSlate.Build.cs":
	// GlobalDefinitions.Add("LLM_ENABLED_IN_CONFIG=1");
	// GlobalDefinitions.Add("UE_MEMORY_TAGS_TRACE_ENABLED=1");

	UE_LOG(LogLearnSlate, Display, TEXT("Hello World"));

	return 0;
}
