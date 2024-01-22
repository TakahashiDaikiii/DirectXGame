#pragma once
#include<Windows.h>
#define DIRECTINPUT_VERSION     0x0800   // DirectInputのバージョン指定
#include <dinput.h>

#pragma comment(lib, "dinput8.lib")

#pragma comment(lib, "dxguid.lib")

#include<wrl.h>


class Input
{
public:

	void Initialize(HINSTANCE hInstance,HWND hwnd);
	
	void Update();

	bool PushKey(BYTE keyNumber);

	bool TriggerKey(BYTE keyNumber);

private:
	Microsoft::WRL::ComPtr<IDirectInput8> directInput;
	Microsoft::WRL::ComPtr<IDirectInputDevice8> keyboard;

	BYTE key[256] = {};
	BYTE keyPre[256] = {};

};

