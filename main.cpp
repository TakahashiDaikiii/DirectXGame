#include"Input.h"
#include"WinApp.h"
#include"DirectXCommon.h"

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


    // ゲームループ
    while (true) {
        if (winApp_->Update() == true)
        {
            break;
       }

        input_->Update();

        dxCommon_->PreDraw();

        dxCommon_->PosDraw();

    }

    delete input_;

    winApp_->Finalize();

    delete winApp_;

    delete dxCommon_;

    return 0;
}
