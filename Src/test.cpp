#include "DxLib.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	ChangeWindowMode(TRUE); // �E�B���h�E���[�h�ɐݒ�

	DxLib_Init();   // DX���C�u��������������

	LoadGraphScreen(0, 0, "title.jpg", TRUE); // �摜��`�悷��


	WaitKey();      // �L�[���͑҂�
	DxLib_End();    // DX���C�u�����I������
	return 0;
}