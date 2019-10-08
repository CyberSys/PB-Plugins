// Copyright 2018 fpwong, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/EngineTypes.h"
#include "AutoSizeCommentsSettings.generated.h"

UENUM()
enum ECommentCollisionMethod
{
	ASC_Collision_Point UMETA(DisplayName = "Point"),
	ASC_Collision_Intersect UMETA(DisplayName = "Overlap"),
	ASC_Collision_Contained UMETA(DisplayName = "Contained"),
	ASC_Collision_Default UMETA(DisplayName = "Default (Don't use this!)"),
};


USTRUCT()
struct FPresetCommentStyle
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, config, Category = Default)
	FLinearColor Color = FLinearColor::White;

	UPROPERTY(EditAnywhere, config, Category = Default)
	int FontSize = 18;
};

UCLASS(config = EditorSettings)
class AUTOSIZECOMMENTS_API UAutoSizeCommentsSettings : public UObject
{
	GENERATED_BODY()

public:
	UAutoSizeCommentsSettings(const FObjectInitializer& ObjectInitializer);

	/** The default font size for comment boxes */
	UPROPERTY(EditAnywhere, config, Category = FontSize)
	int DefaultFontSize;

	/** If enabled, all nodes will be changed to the default font size (unless they are a preset or floating node) */
	UPROPERTY(EditAnywhere, config, Category = FontSize)
	bool bUseDefaultFontSize;

	/** If Use Random Color is not enabled, comment boxes will spawn with this default color */
	UPROPERTY(EditAnywhere, config, Category = Color)
	FLinearColor DefaultCommentColor;

	/** If enabled, comment boxes will spawn with a random color. If disabled, use default color */
	UPROPERTY(EditAnywhere, config, Category = Color)
	bool bUseRandomColor;

	/** Opacity used for the random color */
	UPROPERTY(EditAnywhere, config, Category = Color)
	float RandomColorOpacity;
	
	/** Set all nodes in the graph to the default color */
	UPROPERTY(EditAnywhere, config, Category = Color)
	bool bAggressivelyUseDefaultColor;

	/** Style for header comment boxes */
	UPROPERTY(EditAnywhere, config, Category = Styles)
	FPresetCommentStyle HeaderStyle;

	/** Preset styles (each style will have its own button on the comment box) */
	UPROPERTY(EditAnywhere, config, Category = Styles)
	TArray<FPresetCommentStyle> PresetStyles;

	/** Amount of padding for around the contents of a comment node */
	UPROPERTY(EditAnywhere, config, Category = Misc)
	FVector2D CommentNodePadding;

	/** If enabled, empty comment boxes will move out of the way of other comment boxes */
	UPROPERTY(EditAnywhere, config, Category = Misc)
	bool bMoveEmptyCommentBoxes;

	/** The speed at which empty comment boxes move */
	UPROPERTY(EditAnywhere, config, Category = Misc)
	float EmptyCommentBoxSpeed;

	/** Globally set "Color Bubble" for every comment box that is created or loaded */
	UPROPERTY(EditAnywhere, config, Category = Misc)
	bool bGlobalColorBubble;

	/** Globally set "Show Bubble When Zoomed" for every comment box that is created or loaded */
	UPROPERTY(EditAnywhere, config, Category = Misc)
	bool bGlobalShowBubbleWhenZoomed;

	/** If enabled, nodes inside comments will be saved to a cache file */
	UPROPERTY(EditAnywhere, config, Category = Misc)
	bool bSaveCommentNodeDataToFile;

	/** If enabled, nodes inside comments will be saved to a cache file */
	UPROPERTY(EditAnywhere, config, Category = Misc)
	bool bDetectNodesContainedForNewComments;

	/** Collision method to use when resizing comment nodes */
	UPROPERTY(EditAnywhere, config, Category = Misc)
	TEnumAsByte<ECommentCollisionMethod> ResizeCollisionMethod;

	/** Collision method to use when releasing alt */
	UPROPERTY(EditAnywhere, config, Category = Misc)
	TEnumAsByte<ECommentCollisionMethod> AltCollisionMethod;

	/** Don't add knot nodes to comment boxes */
	UPROPERTY(EditAnywhere, config, Category = Misc)
	bool bIgnoreKnotNodes;

	/** Hide the header button */
	UPROPERTY(EditAnywhere, config, Category = Controls)
	bool bHideHeaderButton;

	/** Hide the preset buttons */
	UPROPERTY(EditAnywhere, config, Category = Controls)
	bool bHidePresets;

	/** Hide the randomize color button */
	UPROPERTY(EditAnywhere, config, Category = Controls)
	bool bHideRandomizeButton;

	/** Hide controls at the bottom of the comment box */
	UPROPERTY(EditAnywhere, config, Category = Controls)
	bool bHideCommentBoxControls;

	/** Hide the comment bubble */
	UPROPERTY(EditAnywhere, config, Category = Controls)
	bool bHideCommentBubble;
};
