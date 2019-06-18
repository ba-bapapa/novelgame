#include "Include.h"


int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK); //�E�B���h�E���[�h�ύX�Ə������Ɨ���ʐݒ�

	SceneMgr_Initialize();
	double size = 1.0;
	int Handle, Count = 0;
	Handle = LoadSoundMem("Res\\073.mp3"); // �T�E���h/1up.wav�����[�h���A���ʔԍ���Handle�Ɋi�[
	int x, y, Mouse, Wheel, Image;

	Image = LoadGraph("Res\\A.png");//�摜���[�h

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {//��ʍX�V & ���b�Z�[�W���� & ��ʏ���

		if (Count % 120 == 0) { // 2�b�Ɉ�x
			PlaySoundMem(Handle, DX_PLAYTYPE_BACK); // ���ʉ����Đ�����
		}
		Count++;

		Mouse = GetMouseInput();                //�}�E�X�̓��͏�Ԏ擾
		Wheel = GetMouseWheelRotVol();  //�z�C�[���̉�]�ʎ擾
		GetMousePoint(&x, &y);                //�}�E�X�̍��W�擾
		if (Mouse & MOUSE_INPUT_LEFT) { //�}�E�X�̍��{�^����������Ă�����
			//DrawString(0, 0, "���{�^����������Ă��܂�", GetColor(255, 255, 255));
		}
		if (Wheel > 0) {        //�z�C�[����+�����ɉ�]���Ă�����
			size += 0.1;
		}
		if (Wheel < 0) {        //�z�C�[�����|�����ɉ�]���Ă�����
			size -= 0.1;
		}
		SceneMgr_Update();  //�X�V
		SceneMgr_Draw();    //�`��

		DrawRotaGraph(x, y,size,0.0,Image,TRUE);  //�摜��x,y�̈ʒu�ɃT�C�Y�ŕ`��
	}

	SceneMgr_Finalize();

	WaitKey();     // �L�[���͂�����܂őҋ@
	DxLib_End(); // DX���C�u�����I������
	return 0;
}