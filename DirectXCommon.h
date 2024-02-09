#pragma once

#include <wrl.h>
#include<dxgi1_6.h>
#include <d3d12.h>

#include<vector>
#include<chrono>
#include"WinApp.h"
class DirectXCommon
{
public:

	void Initialize(WinApp* winApp);

	void PreDraw();

	void PosDraw();

	//Getter

	ID3D12Device* Getdevice() const { return device.Get(); }
	ID3D12GraphicsCommandList* GetCommmandList() const { return commandList.Get(); }

	DXGI_SWAP_CHAIN_DESC1 GetswapChainDesc() { return swapChainDesc; }

	D3D12_RENDER_TARGET_VIEW_DESC GetRtvDesc() { return rtvDesc; }

	ID3D12DescriptorHeap* GetSrvDescriptorHeap() { return srvDescriptorHeap.Get(); }


private:
	//デバイス
	void DeviceInitialize();
	//コマンド
	void CommandInitialize();
	//スワップチェーン
	void SwapChainInitialize();
	//レンダーターゲット
	void RenderTargerInitialize();
	//深度バッファ
	void DepthBufferInitialize();
	//フェンス
	void FenceInitialize();
	//ディスクリプターヒープ作成
	ID3D12DescriptorHeap* CreateDescriptorHeap(D3D12_DESCRIPTOR_HEAP_TYPE heapType, UINT numDescripots, bool shaderVisible);

	void InitializeFixFPS();

	void UpdateFixFPS();

public:
	static const uint32_t kMaxSRVCount;


private:

	WinApp* winApp = nullptr;

	Microsoft::WRL::ComPtr<ID3D12Device> device;
	Microsoft::WRL::ComPtr<IDXGIFactory7> dxgiFactory;

	Microsoft::WRL::ComPtr<ID3D12CommandAllocator> commandAllocator;
	Microsoft::WRL::ComPtr<ID3D12GraphicsCommandList> commandList;
	Microsoft::WRL::ComPtr<ID3D12CommandQueue> commandQueue;

	Microsoft::WRL::ComPtr<IDXGISwapChain4> swapChain;
	DXGI_SWAP_CHAIN_DESC1 swapChainDesc{};

	Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> rtvHeap;
	D3D12_DESCRIPTOR_HEAP_DESC rtvHeapDesc{};
	std::vector<Microsoft::WRL::ComPtr<ID3D12Resource>> backBuffers;

	Microsoft::WRL::ComPtr<ID3D12Resource> depthBuff;
	D3D12_DESCRIPTOR_HEAP_DESC dsvHeapDesc{};
	Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> dsvHeap;

	Microsoft::WRL::ComPtr<ID3D12Fence> fence;
	UINT64 fenceVal = 0;

	D3D12_RESOURCE_BARRIER barrierDesc{};

	D3D12_RENDER_TARGET_VIEW_DESC rtvDesc{};

	std::chrono::steady_clock::time_point reference_;

	Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> rtvDescriptorHeap;

	Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> srvDescriptorHeap;


};