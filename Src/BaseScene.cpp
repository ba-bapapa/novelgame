#include "Include.h"


static int mImageHandle, mImageChara, mImageText, mImageText2, mImageText3;    //�摜�n���h���i�[�p�ϐ�

int MouseE;



//������
void BaseScene_Initialize() {
	mImageHandle = LoadGraph("Res\\E.jpg");    //�摜�̃��[�h
	mImageText = LoadGraph("Res\\03.png"); // 
	mImageText2 = LoadGraph("Res\\03.png");
	mImageChara = LoadGraph("Res\\D.png"); // // 
	mImageText3 = LoadGraph("Res\\02.png"); // 
}

//�I������
void BaseScene_Finalize() {
	DeleteGraph(mImageHandle);    //�摜�̉��
	DeleteGraph(mImageText);    //�摜�̉��
	DeleteGraph(mImageText2);    //�摜�̉��
	DeleteGraph(mImageChara);    //�摜�̉��
	DeleteGraph(mImageText3);    //�摜�̉��
}

//�X�V
void BaseScene_Update() {
	MouseE = GetMouseInput();                //�}�E�X�̓��͏�Ԏ擾
	if (MouseE&MOUSE_INPUT_RIGHT) {//���N���b�N������Ă���

		SceneMgr_ChangeScene(eScene_Menu);//�V�[�����Q�[����ʂɕύX
	}

	if (CheckHitKey(KEY_INPUT_C) != 0) {//A�L�[��������Ă�����
		SceneMgr_ChangeScene(eScene_Config);//�V�[����ݒ��ʂɕύX
	}
}

//�`��
void BaseScene_Draw() {
	DrawGraph(0, 0, mImageHandle, FALSE);
	DrawGraph(600, 200, mImageText, FALSE);
	DrawGraph(600, 232, mImageText2, FALSE);
	DrawGraph(200, 100, mImageChara, FALSE);
	DrawGraph(0, 400, mImageText3, FALSE);
	DrawString(250, 0, "�`�����`", GetColor(255, 255, 300));
	DrawString(600, 200, "Seve", GetColor(255, 255, 255));
	DrawString(600, 232, "Lode ", GetColor(255, 255, 255));
}