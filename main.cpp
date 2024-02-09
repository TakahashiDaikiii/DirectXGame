#include"Input.h"
#include"WinApp.h"
#include"DirectXCommon.h"
#include"Sprite.h"
#include"SpriteCommon.h"

#include "imGuiManager.h"
#include<vector>

#include"TextureManager.h"
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

    TextureManager::GetInstance()->Initialize(dxCommon_);
    TextureManager::GetInstance()->LoadTexture(L"Resources/mario.jpg");


    std::vector<Sprite*> sprite;

    for (int i = 0; i < 5; i++)
    {
        Sprite* temp = new Sprite();
        if (i % 2 == 0)  temp->Initialize(dxCommon_, spriteCommon, L"Resources/mario.jpg");
        else if (i % 2 == 1)  temp->Initialize(dxCommon_, spriteCommon, L"Resources/mario.jpg");
        temp->SetPosition({ (float)i * 120,0 });
        sprite.push_back(temp);
    }


    // ゲームループ
    while (true) {
        if (winApp_->Update() == true)
        {
            break;
       }

        imGuiManager::NewFrame();
        imgui->ShowDemo();

        input_->Update();

        ////移動

        DirectX::XMFLOAT2 pos = sprite[0]->GetPosition();
        pos.x += 0.01f;
        sprite[0]->SetPosition(pos);

        //回転
        float rot = sprite[0]->GetRotation();
        rot += 0.005f;
        sprite[0]->SetRotation(rot);

        //色
        DirectX::XMFLOAT4 color = sprite[0]->Getcolor();
        color.x -= 0.1f;
        if (color.x < 0)
        {
            color.x = 1.0f;
        }
        sprite[0]->SetColor(color);

        //サイズ
        DirectX::XMFLOAT2 size = sprite[0]->GetSize();
        size.y += 0.01f;
        sprite[0]->SetSize(size);

        for (int i = 0; i < 5; i++)
        {
            sprite[i]->Update();
        }

        imGuiManager::CreateCommand();
        dxCommon_->PreDraw();


        for (int i = 0; i < 5; i++)
        {
            sprite[i]->Draw();
        }


        imGuiManager::CommandsExcute(dxCommon_->GetCommmandList());
        dxCommon_->PosDraw();

    }
    for (int i = 0; i < 5; i++) 
    {
        delete sprite[i];
    }

    TextureManager::GetInstance()->Finalize();

    delete spriteCommon;

    delete imgui;

    delete input_;

    winApp_->Finalize();

    delete winApp_;

    delete dxCommon_;

    return 0;
}
