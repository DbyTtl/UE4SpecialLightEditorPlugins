// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Toolkits/BaseToolkit.h"


struct FPointBatchValue
{
	// ����ǿ�ȱ���
	float LightIntensityMultiple = 1.f;
	// ˥���뾶����
	float FalloffRadiusMultiple = 1.f;
	// ������ɫ
	FLinearColor LightColor = FLinearColor(255.f, 255.f, 255.f, 0.f);
};


class FLightBatchUpDataValueEdModeToolkit : public FModeToolkit
{
public:

	FLightBatchUpDataValueEdModeToolkit();
	
	/** FModeToolkit interface */
	virtual void Init(const TSharedPtr<IToolkitHost>& InitToolkitHost) override;

	/** IToolkit interface */
	virtual FName GetToolkitFName() const override;
	virtual FText GetBaseToolkitName() const override;
	virtual class FEdMode* GetEditorMode() const override;
	virtual TSharedPtr<class SWidget> GetInlineContent() const override { return ToolkitWidget; }

private:

	TSharedPtr<SWidget> ToolkitWidget;

	TSharedPtr<SVerticalBox> ParameterWidget;

	// ���Դ����
	FPointBatchValue PointBatchData;

	// ��СLOD�ƹ�����
	FPointBatchValue MinCurvePointBatchData;

	// ���LOD�ƹ�����
	FPointBatchValue MaxCurvePointBatchData;

protected:
	/** The true objects bound to the Slate combobox. */
	TArray< TSharedPtr<FString> > Options;

	/** A shared pointer to the current selected string */
	TSharedPtr<FString> CurrentOptionPtr;

	// ���ĵĵ��Դ����������
	TArray<FString> PointLightParametersTitle;

	// ���ĵ�LOD�ƹ����������
	TArray<FString> CurveRouteCreateParametersTitle;

protected:
	/** Called by slate when it needs to generate a new item for the combobox */
	virtual TSharedRef<SWidget> HandleGenerateWidget(TSharedPtr<FString> Item) const;

	/** Called by slate when the underlying combobox selection changes */
	virtual void HandleSelectionChanged(TSharedPtr<FString> Item, ESelectInfo::Type SelectionType);

	FText GetSelectedSubjectName() const;

	virtual TSharedRef<SWidget> CreateSSpinBoxWidget(FString Item, int ID) const;

	void HandleOnValueCommitted(float InValue, ETextCommit::Type CommitMethod, int ID);

	void CreateParametersSet();

	FReply OnButtonClick();

	// ���ĵ��Դ������
	void UpDataPointLightParameters(USelection* Value);

	// ���ĵ��Դ������
	void UpDataSpotLightParameters(USelection* Value);

	// ����LOD���Դ������
	void UpDataCurvePointLightParameters(USelection* Value);
};
