#pragma once

#include"DirectXCommon.h"

class imGuiManager
{
public:

	static void Initialize(HWND hwnd, DirectXCommon* dxCommon);

	static void NewFrame();

	static void CreateCommand();

	static void CommandsExcute(ID3D12GraphicsCommandList* commandList);

	static imGuiManager* Create();

public:

	~imGuiManager();

public:
	void ShowDemo();
};

