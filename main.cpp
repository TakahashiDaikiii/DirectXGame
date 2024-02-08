#include"Input.h"
#include"WinApp.h"
#include"DirectXCommon.h"
#include"Sprite.h"
#include"SpriteCommon.h"

#include "imGuiManager.h"
// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

    Input* input_ = nullptr;

    WinApp* winApp_ = nullptr;

    DirectXCommon* dxCommon_ = nullptr;



#pragma region WindowsAPI初期化処理

    winApp_ = new WinApp();
    winApp_->Initialize();

#pragma endregion

    // DirectX初期化処理　ここから
    
    dxCommon_ = new DirectXCommon();
    dxCommon_->Initialize(winApp_);
    // DirectX初期化処理　ここまで
#pragma endregion

    input_ = new Input();
    input_->Initialize(winApp_);

    imGuiManager* imgui = imGuiManager::Create();
    imGuiManager::Initialize(winApp_->GetHwnd(), dxCommon_);



    SpriteCommon* spriteCommon = new SpriteCommon();
    spriteCommon->Initialize(dxCommon_);

    Sprite* sprite = new Sprite();
    sprite->Initialize(dxCommon_,spriteCommon);


    // ゲームループ
    while (true) {
        if (winApp_->Update() == true)
        {
            break;
       }

        imGuiManager::NewFrame();
        imgui->ShowDemo();

        input_->Update();


        imGuiManager::CreateCommand();
        dxCommon_->PreDraw();

        sprite->Draw();
        imGuiManager::CommandsExcute(dxCommon_->GetCommmandList());
        dxCommon_->PosDraw();

    }

    delete sprite;

    delete spriteCommon;

    delete imgui;

    delete input_;

    winApp_->Finalize();

    delete winApp_;

    delete dxCommon_;

    return 0;
}
