#include "Include.h"


int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK); //�E�B���h�E���[�h�ύX�Ə������Ɨ���ʐݒ�

	SceneMgr_Initialize();


	int Handle, Count = 0;
	Handle = LoadSoundMem("Res/073.mp3"); // �T�E���h/1up.wav�����[�h���A���ʔԍ���Handle�Ɋi�[

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {//��ʍX�V & ���b�Z�[�W���� & ��ʏ���

		
		SceneMgr_Update();  //�X�V
		SceneMgr_Draw();    //�`��
		if (Count % 120 == 0) { // 2�b�Ɉ�x
			PlaySoundMem(Handle, DX_PLAYTYPE_BACK); // ���ʉ����Đ�����
		}
		Count++;

	}

	SceneMgr_Finalize();

	DxLib_End(); // DX���C�u�����I������
	return 0;
}