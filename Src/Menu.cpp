#include "Menu.h"
#include "SceneMgr.h"
#include "DxLib.h"

static int mImageHandle;    //�摜�n���h���i�[�p�ϐ�

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
	if (CheckHitKey(KEY_INPUT_1) != 0) {//1�L�[��������Ă�����
		SceneMgr_ChangeScene(eScene_Game);//�V�[�����Q�[����ʂɕύX
	}
	if (CheckHitKey(KEY_INPUT_2) != 0) {//2�L�[��������Ă�����
		SceneMgr_ChangeScene(eScene_Config);//�V�[�������[�h��ʂɕύX
	}
//	if (CheckHitKey(KEY_INPUT_3) != 0) {//3�L�[��������Ă�����
	//	SceneMgr_ChangeScene(eScene_Config);//�V�[����ݒ��ʂɕύX
	//}
}

//�`��
void Menu_Draw() {
	DrawGraph(0, 0, mImageHandle, FALSE);
	DrawString(0, 0, "�^�C�g����ʁB", GetColor(255, 255, 255));
	DrawString(500, 20, "1NewGame", GetColor(255, 255, 255));
	DrawString(500, 40, "2LordGame", GetColor(255, 255, 255));
	//DrawString(500, 60, "3�ݒ�", GetColor(255, 255, 255));
}
