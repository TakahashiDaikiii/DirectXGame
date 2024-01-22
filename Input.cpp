#include "Input.h"

void Input::Initialize()
{
	//DirectInputのインスタンス生成
	ComPtr<IDirectInput8> directInput = nullptr;

	ComPtr<IDirectInputDevice8> keyboard;
	result = directInput->CreateDevice(GUID_SysKeyboard, &keyboard, NULL);
	assert(SUCCEDED(result));

}

void Input::Update()
{

}
