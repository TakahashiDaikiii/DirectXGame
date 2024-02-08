#pragma once

#include <string>
#include<wrl.h>
#include<dxcapi.h>
#include<d3d12.h>

#include"DirectXCommon.h"

class SpriteCommon
{
public:

	void Initialize(DirectXCommon*dxCommon);

	ID3D12RootSignature* GetRootSignature() { return rootSignature. Get(); }
	ID3D12PipelineState* GetPipelineState() { return pipelineState.Get(); }
private:
	static IDxcBlob* CompileShader(
		const std::wstring& filePath,
		const wchar_t* profile,
		IDxcUtils* dxUtils,
		IDxcCompiler3* dxcCompiler,
		IDxcIncludeHandler* includeHandler);

private:
	DirectXCommon* dxCommon_ = nullptr;

	Microsoft::WRL::ComPtr<ID3D12RootSignature> rootSignature;

	Microsoft::WRL::ComPtr<ID3D12PipelineState> pipelineState;
};

