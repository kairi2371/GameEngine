#pragma once
#define DIRECTINPUT_VERSION     0x0800   // DirectInput�̃o�[�W�����w��
#include <dinput.h>

#pragma comment(lib, "dinput8.lib")
#pragma comment(lib, "dxguid.lib")
#include<wrl.h>
//using namespace Microsoft::WRL;
#include<Windows.h>

class Input
{
public:
	//������
	void Initialize(HINSTANCE hInstance, HWND hwnd);
	//�X�V
	void Update();
	//�C�Ӄ{�^����������Ă���
	bool PushKey(BYTE keyNumber);
	//�C�ӂ̃{�^���������ꂽ�u��
	bool TriggerKey(BYTE keyNumber);
private:
	// DirectInput�̏�����
	Microsoft::WRL::ComPtr<IDirectInput8> directInput;
	Microsoft::WRL::ComPtr<IDirectInputDevice8> keyboard;
	BYTE key[256] = {};
	BYTE keyPre[256] = {};
};

