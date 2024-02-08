#include "imGuiManager.h"
#include"External/imgui/imgui.h"
#include"External/imgui/imgui_impl_dx12.h"
#include"External/imgui/imgui_impl_win32.h"

void imGuiManager::Initialize(HWND hwnd, DirectXCommon* dxCommon)
{
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGui::StyleColorsDark();
	ImGui_ImplWin32_Init(hwnd);
	ImGui_ImplDX12_Init(

		dxCommon->Getdevice(),
		dxCommon->GetswapChainDesc().BufferCount,
		dxCommon->GetRtvDesc().Format,
		dxCommon->GetSrvDescriptorHeap(),
		dxCommon->GetSrvDescriptorHeap()->GetCPUDescriptorHandleForHeapStart(),
		dxCommon->GetSrvDescriptorHeap()->GetGPUDescriptorHandleForHeapStart()

	);
}

void imGuiManager::NewFrame()
{
	ImGui_ImplDX12_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();
}

void imGuiManager::CreateCommand()
{
	ImGui::Render();
}

void imGuiManager::CommandsExcute(ID3D12GraphicsCommandList* commandList)
{
	ImGui_ImplDX12_RenderDrawData(ImGui::GetDrawData(),commandList);
}

imGuiManager* imGuiManager::Create()
{
	imGuiManager* instance = new imGuiManager();

	return instance;
}

imGuiManager::~imGuiManager()
{
	ImGui_ImplDX12_Shutdown();
	ImGui_ImplWin32_Shutdown();
	ImGui::DestroyContext();
}

void imGuiManager::ShowDemo()
{
	ImGui::ShowDemoWindow();
}
