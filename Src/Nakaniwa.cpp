#include "Include.h"


static int mImageHandle, mImageChara, mImageText, mImageText2, mImageText3;    //�摜�n���h���i�[�p�ϐ�

int MouseD;



//������
void Nakaniwa_Initialize() {
	mImageHandle = LoadGraph("Res\\D.jpg");    //�摜�̃��[�h
	mImageText = LoadGraph("Res\\03.png"); // 
	mImageText2 = LoadGraph("Res\\03.png");
	mImageChara = LoadGraph("Res\\D.png"); // // 
	mImageText3 = LoadGraph("Res\\02.png"); // 
}

//�I������
void Nakaniwa_Finalize() {
	DeleteGraph(mImageHandle);    //�摜�̉��
	DeleteGraph(mImageText);    //�摜�̉��
	DeleteGraph(mImageText2);    //�摜�̉��
	DeleteGraph(mImageChara);    //�摜�̉��
	DeleteGraph(mImageText3);    //�摜�̉��
}

//�X�V
void Nakaniwa_Update() {
	MouseD = GetMouseInput();                //�}�E�X�̓��͏�Ԏ擾
	if (MouseD&MOUSE_INPUT_LEFT) {//���N���b�N������Ă���
		WaitTimer(1000);
		SceneMgr_ChangeScene(eScene_BaseScene);//�V�[�����Q�[����ʂɕύX
	}

	if (MouseD &MOUSE_INPUT_RIGHT) {//�E�N���b�N��������Ă�����
		WaitTimer(1000);
		SceneMgr_ChangeScene(eScene_ISceneChanger);//�V�[����ݒ��ʂɕύX
	}
}

//�`��
void Nakaniwa_Draw() {
	DrawGraph(0, 0, mImageHandle, FALSE);
	DrawGraph(600, 200, mImageText, FALSE);
	DrawGraph(600, 232, mImageText2, FALSE);
	DrawGraph(200, 100, mImageChara, FALSE);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);   //���߂͂���
	DrawGraph(0, 400, mImageText3, FALSE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);  //���߂����
	DrawString(250, 0, "�`����`", GetColor(255, 300, 255));
	DrawString(600, 200, "Seve", GetColor(255, 255, 255));
	DrawString(600, 232, "Lode ", GetColor(255, 255, 255));
	DrawString(0, 400, "�e�L�X�g�ǂݍ��ݗ\��\n1�I����\n2�I����", GetColor(255, 255, 255));
}