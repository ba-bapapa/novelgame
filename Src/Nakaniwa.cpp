#include "Include.h"


static int mImageHandle, mImageText, mImageText2;    //�摜�n���h���i�[�p�ϐ�

int MouseD;



//������
void Nakaniwa_Initialize() {
	mImageHandle = LoadGraph("Res\\D.jpg");    //�摜�̃��[�h
	mImageText = LoadGraph("Res\\03.png"); // 
	mImageText2 = LoadGraph("Res\\03.png"); // 
}

//�I������
void Nakaniwa_Finalize() {
	DeleteGraph(mImageHandle);    //�摜�̉��
	DeleteGraph(mImageText);    //�摜�̉��
	DeleteGraph(mImageText2);    //�摜�̉��
}

//�X�V
void Nakaniwa_Update() {
	MouseD = GetMouseInput();                //�}�E�X�̓��͏�Ԏ擾
	if (CheckHitKey(KEY_INPUT_B) != 0) {//���N���b�N������Ă���

		SceneMgr_ChangeScene(eScene_Game);//�V�[�����Q�[����ʂɕύX
	}

	if (CheckHitKey(KEY_INPUT_C) != 0) {//A�L�[��������Ă�����
		SceneMgr_ChangeScene(eScene_Config);//�V�[����ݒ��ʂɕύX
	}
}

//�`��
void Nakaniwa_Draw() {
	DrawGraph(0, 0, mImageHandle, FALSE);
	DrawGraph(600, 200, mImageText, FALSE);
	DrawGraph(600, 232, mImageText2, FALSE);
	DrawString(250, 200, "�`����`", GetColor(255, 255, 255));
	DrawString(600, 200, "Seve", GetColor(255, 255, 255));
	DrawString(600, 232, "Lode ", GetColor(255, 255, 255));
}