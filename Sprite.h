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

	struct VertexData
	{
		DirectX::XMFLOAT4 position;
		DirectX::XMFLOAT2 texcoord;
	};

	struct MaterialData
	{
		DirectX::XMFLOAT4 color;
		DirectX::XMMATRIX uvTransform;
	};

public:
	void Initialize(DirectXCommon* dxCommon,SpriteCommon* common,std::wstring textureFilePath);

	void Update();

	void Draw();


	//getter /setter
	DirectX::XMFLOAT2 GetPosition() {return position;}
	float GetRotation() { return rotation; }
	DirectX::XMFLOAT4 Getcolor() { return color_; }
	DirectX::XMFLOAT2 GetSize() { return size; }

	void SetPosition(DirectX::XMFLOAT2 pos) { position = pos; }
	void SetRotation(float rot) { rotation = rot; }
	void SetColor(DirectX::XMFLOAT4 color) { color_ = color; }
	void SetSize(DirectX::XMFLOAT2 size) { this->size = size; }

	void SetTexture(std::wstring textureFilePath);
private:

	void CreateVertex();

	void CreateIndex();

	void CreateMaterial();

	void CreateWVP();



private:
	DirectXCommon* dxCommon_ = nullptr;

	SpriteCommon* common_ = nullptr;

	VertexData* vertexData = nullptr;

	Microsoft::WRL::ComPtr<ID3D12Resource> vertexResource;
	D3D12_VERTEX_BUFFER_VIEW vertexBufferView{};

	Microsoft::WRL::ComPtr<ID3D12Resource> indexResource;
	D3D12_INDEX_BUFFER_VIEW indexBufferView{};

	
	Microsoft::WRL::ComPtr<ID3D12Resource> materialResource;
	MaterialData* materialData = nullptr;

	Microsoft::WRL::ComPtr<ID3D12Resource> wvpResource;

	DirectX:: XMMATRIX* wvpData = nullptr;

	DirectX::XMFLOAT4 color_ = { 1.0f,1.0f,1.0f,1.0f };

	Transform uvTransform = { {1,1,1},{0,0,0} ,{0,0,0} };

	Transform transform = { {1,1,1},{0,0,0},{0,0,0} };
	DirectX::XMFLOAT2 position = { 0,0 };
	float rotation = 0;
	DirectX::XMFLOAT2 size = { 512,512 };

	uint32_t textureIndex_ = 0;




	Transform cameraTransform = { {1,1,1},{0,0,0},{0,0,-5} };
};

