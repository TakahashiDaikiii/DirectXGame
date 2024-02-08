#pragma once

#include "DirectXCommon.h"

#include <d3d12.h>
#include<wrl.h>

#include"SpriteCommon.h"
#include<DirectXMath.h>

class Sprite
{
	struct Transform {
		DirectX::XMFLOAT3 scale;
		DirectX::XMFLOAT3 rotate;
		DirectX::XMFLOAT3 translate;
	};
public:
	void Initialize(DirectXCommon* dxCommon,SpriteCommon* common);

	void Draw();

private:

	void CreateVertex();

	void CreateMaterial();

	void CreateWVP();


private:
	DirectXCommon* dxCommon_ = nullptr;

	SpriteCommon* common_ = nullptr;


	Microsoft::WRL::ComPtr<ID3D12Resource> vertexResource;

	D3D12_VERTEX_BUFFER_VIEW vertexBufferView{};

	Microsoft::WRL::ComPtr<ID3D12Resource> materialResource;

	Microsoft::WRL::ComPtr<ID3D12Resource> wvpResource;

	DirectX:: XMMATRIX* wvpData = nullptr;

	DirectX::XMFLOAT4 color_ = { 1.0f,0.0f,0.0f,1.0f };

	Transform transform = { {1,1,1},{0,0,0},{0,0,0} };

	Transform cameraTransform = { {1,1,1},{0,0,0},{0,0,-5} };
};

