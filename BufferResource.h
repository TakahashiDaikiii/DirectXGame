#pragma once
#include <d3d12.h>
include

ID3D12Resource* CreateBufferResource(ID3D12Device* device, size_t sizeInByte)
{
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
}