#include "Sprite.h"

#include<DirectXMath.h>

using namespace Microsoft::WRL;
using namespace DirectX;

void Sprite::Initialize(DirectXCommon* dxCommon, SpriteCommon* common)
{
	dxCommon_ = dxCommon;
	common_ = common;

	D3D12_HEAP_PROPERTIES uploadHeapProjecties{};
	uploadHeapProjecties.Type = D3D12_HEAP_TYPE_UPLOAD;
	D3D12_RESOURCE_DESC vertexResourceDesc{};
	vertexResourceDesc.Dimension = D3D12_RESOURCE_DIMENSION_BUFFER;
	vertexResourceDesc.Width = sizeof(XMFLOAT4) * 3;
	vertexResourceDesc.Height = 1;
	vertexResourceDesc.DepthOrArraySize = 1;
	vertexResourceDesc.MipLevels = 1;
	vertexResourceDesc.SampleDesc.Count = 1;
	vertexResourceDesc.Layout = D3D12_TEXTURE_LAYOUT_ROW_MAJOR;

	HRESULT result = dxCommon_->Getdevice()->CreateCommittedResource(&uploadHeapProjecties, D3D12_HEAP_FLAG_NONE, &vertexResourceDesc, D3D12_RESOURCE_STATE_GENERIC_READ, nullptr, IID_PPV_ARGS(&vertexResource));
	assert(SUCCEEDED(result));


	vertexBufferView.BufferLocation = vertexResource->GetGPUVirtualAddress();
	vertexBufferView.SizeInBytes = sizeof(DirectX::XMFLOAT4) * 3;
	vertexBufferView.StrideInBytes = sizeof(DirectX::XMFLOAT4);

}

void Sprite::Draw()
{
	XMFLOAT4* vertexData = nullptr;
	vertexResource->Map(0, nullptr,reinterpret_cast<void**>(&vertexData));

	vertexData[0] = { -0.5f,-0.5f,0.0f,1.0f };
	vertexData[1] = { 0.0f,0.5f,0.0f,1.0f };
	vertexData[2] = { 0.5f,-0.5f,0.0f,1.0f };

	dxCommon_->GetCommmandList()->SetGraphicsRootSignature(common_->GetRootSignature());
	dxCommon_->GetCommmandList()->SetPipelineState(common_->GetPipelineState());

	dxCommon_->GetCommmandList()->IASetVertexBuffers(0, 1, &vertexBufferView);

	dxCommon_->GetCommmandList()->IASetPrimitiveTopology(D3D10_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

	dxCommon_->GetCommmandList()->DrawInstanced(3, 1, 0, 0);

}
