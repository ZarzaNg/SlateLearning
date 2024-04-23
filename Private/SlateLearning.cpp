// Copyright Epic Games, Inc. All Rights Reserved.

#include "SlateLearning.h"
#include "Developer/StandaloneRenderer/Public/StandaloneRenderer.h"
#include "Runtime/Slate/Public/Framework/Application/SlateApplication.h"
#include "Runtime/SlateCore/Public/Widgets/DeclarativeSyntaxSupport.h"
#include "Runtime/SlateCore/Public/Widgets/SWindow.h"
#include "RequiredProgramMainCPPInclude.h"

DEFINE_LOG_CATEGORY_STATIC(LogSlateLearning, Log, All);

IMPLEMENT_APPLICATION(SlateLearning, "SlateLearning");

INT32_MAIN_INT32_ARGC_TCHAR_ARGV()
{
	GEngineLoop.PreInit(ArgC, ArgV);

	FSlateApplication::InitializeAsStandaloneApplication(GetStandardStandaloneRenderer());
	FSlateApplication::InitHighDPI(true);

	SOverlay::FOverlaySlot* Slot;
	SHorizontalBox::FSlot* BoxPtr;

	const TSharedPtr<SWindow> MainWindow = SNew(SWindow).ClientSize(FVector2D(800, 600))
	[
		SNew(SOverlay) + SOverlay::Slot().VAlign(EVerticalAlignment::VAlign_Top).HAlign(EHorizontalAlignment::HAlign_Left).Expose(Slot)
		[
			SNew(SHorizontalBox) + SHorizontalBox::Slot().AutoWidth().Expose(BoxPtr)
			[
				SNew(SButton).Text(NSLOCTEXT("L10N", "Key", "Add a button")).OnClicked_Lambda([=]()
				{
					SWidget& SlotWidget = Slot->GetWidget().Get();
					SHorizontalBox& HorizontalBox = static_cast<SHorizontalBox&>(SlotWidget);
					HorizontalBox.AddSlot()
					[
						SNew(SButton).Text(NSLOCTEXT("L10N", "Key", "Button Content"))
					];
					return FReply::Handled();
				})
			]
		]
	];

	SWidget& SlotWidget = Slot->GetWidget().Get();
	SHorizontalBox& HorizontalBox = static_cast<SHorizontalBox&>(SlotWidget);
	// Failed to get the pointer in this way.
	// SHorizontalBox& HorizontalBox = static_cast<SHorizontalBox&>(BoxPtr->GetWidget().Get());
	for(uint8 i = 0; i < 5; i++)
	{
		HorizontalBox.AddSlot()
		[
			SNew(SButton).Text(NSLOCTEXT("L10N", "Key", "Button Content"))
		];
	}

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
