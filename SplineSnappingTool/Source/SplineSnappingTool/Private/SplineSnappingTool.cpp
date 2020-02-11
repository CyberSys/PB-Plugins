// Copyright 2015 Elhoussine Mehnik (Mhousse1247). All Rights Reserved.
//******************* http://ue4resources.com/ *********************//


#include "SplineSnappingTool.h"
#include "SplineSnappingToolEdMode.h"
#include "SplineSnappingToolStyle.h"

#define LOCTEXT_NAMESPACE "FSplineSnappingToolModule"

void FSplineSnappingToolModule::StartupModule()
{
	FSplineSnappingToolStyle::Initialize();

	FEditorModeRegistry::Get().RegisterMode<FSplineSnappingToolEdMode>(
		FSplineSnappingToolEdMode::EM_SplineSnappingToolEdModeId,
		LOCTEXT("SplineSnappingToolModeName", "Spline Snapping Tool"),
		FSlateIcon(FSplineSnappingToolStyle::Get()->GetStyleSetName(), TEXT("SplineSnappingToolMode")),
		true
		);
}

void FSplineSnappingToolModule::ShutdownModule()
{
	FSplineSnappingToolStyle::Shutdown();

	FEditorModeRegistry::Get().UnregisterMode(FSplineSnappingToolEdMode::EM_SplineSnappingToolEdModeId);
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FSplineSnappingToolModule, SplineSnappingTool)