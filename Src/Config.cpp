#include "Include.h"

static int mImageHandle;    //�摜�n���h���i�[�p�ϐ�

//������
void Config_Initialize() {
	mImageHandle = LoadGraph("Res\\C.jpg");//�摜�̃��[�h
}

//�I������
void Config_Finalize() {
	DeleteGraph(mImageHandle);//�摜�̉��
}

//�X�V
void Config_Update() {
	if (CheckHitKey(KEY_INPUT_ESCAPE) != 0) {//Esc�L�[��������Ă�����
		SceneMgr_ChangeScene(eScene_Menu);//�V�[�������j���[�ɕύX
	}
}

//�`��
void Config_Draw() {
	DrawGraph(0, 0, mImageHandle, FALSE);
	DrawString(0, 0, "����B", GetColor(255, 255, 255));//�F
	DrawString(0, 20, "Esc�L�[�������ƃ��j���[��ʂɖ߂�܂��B", GetColor(255, 255, 255));
}
