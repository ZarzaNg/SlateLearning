// Copyright Epic Games, Inc. All Rights Reserved.

#include "LearnSlate.h"
#include "Developer/StandaloneRenderer/Public/StandaloneRenderer.h"
#include "Runtime/Slate/Public/Framework/Application/SlateApplication.h"
#include "Runtime/SlateCore/Public/Widgets/DeclarativeSyntaxSupport.h"
#include "Runtime/SlateCore/Public/Widgets/SWindow.h"
#include "RequiredProgramMainCPPInclude.h"

DEFINE_LOG_CATEGORY_STATIC(LogLearnSlate, Log, All);

IMPLEMENT_APPLICATION(LearnSlate, "LearnSlate");

INT32_MAIN_INT32_ARGC_TCHAR_ARGV()
{
	GEngineLoop.PreInit(ArgC, ArgV);

	FSlateApplication::InitializeAsStandaloneApplication(GetStandardStandaloneRenderer());
	FSlateApplication::InitHighDPI(true);

	const TSharedPtr<SWindow> MainWindow = SNew(SWindow).ClientSize(FVector2D(800, 600));

	FSlateApplication::Get().AddWindow(MainWindow.ToSharedRef());

	while (!IsEngineExitRequested())
	{
		BeginExitIfRequested();
		FSlateApplication::Get().PumpMessages();
		FSlateApplication::Get().Tick();
	}
	
	FEngineLoop::AppExit();
	return 0;
}
