#include "Include.h"


static int mImageHandle;    //�摜�n���h���i�[�p�ϐ�

int MouseA;
							//������
void Menu_Initialize() {
	mImageHandle = LoadGraph("Res\\A.jpg");    //�摜�̃��[�h

}

//�I������
void Menu_Finalize() {
	DeleteGraph(mImageHandle);    //�摜�̉��
}

//�X�V
void Menu_Update() {
	MouseA = GetMouseInput();                //�}�E�X�̓��͏�Ԏ擾
	if (MouseA&MOUSE_INPUT_LEFT) {//���N���b�N������Ă�����
		SceneMgr_ChangeScene(eScene_Game);//�V�[�����Q�[����ʂɕύX
	}
	
	if (MouseA & MOUSE_INPUT_RIGHT) {//C�L�[��������Ă�����
		SceneMgr_ChangeScene(eScene_Config);//�V�[����ݒ��ʂɕύX
	}
}

//�`��
void Menu_Draw() {
	DrawGraph(0, 0, mImageHandle, FALSE);
	DrawString(0, 0, "���j���[��ʂł��B", GetColor(255, 255, 255));
	DrawString(0, 20, "G�L�[�������ƃQ�[����ʂɐi�݂܂��B", GetColor(255, 255, 255));
	DrawString(0, 40, "C�L�[�������Ɓ@�ݒ��ʂɐi�݂܂��B", GetColor(255, 255, 255));
}