#include "Include.h"


static int mImageHandle, mImageChara, mImageText, mImageText2, mImageText3;    //�摜�n���h���i�[�p�ϐ�

int MouseF;



//������
void ISceneChanger_Initialize() {
	mImageHandle = LoadGraph("Res\\F.jpg");    //�摜�̃��[�h
	mImageText = LoadGraph("Res\\03.png"); // 
	mImageText2 = LoadGraph("Res\\03.png");
	mImageChara = LoadGraph("Res\\D.png"); // // 
	mImageText3 = LoadGraph("Res\\02.png"); // 
}

//�I������
void ISceneChanger_Finalize() {
	DeleteGraph(mImageHandle);    //�摜�̉��
	DeleteGraph(mImageText);    //�摜�̉��
	DeleteGraph(mImageText2);    //�摜�̉��
	DeleteGraph(mImageChara);    //�摜�̉��
	DeleteGraph(mImageText3);    //�摜�̉��
}

//�X�V
void ISceneChanger_Update() {
	MouseF = GetMouseInput();                //�}�E�X�̓��͏�Ԏ擾
	if (CheckHitKey(KEY_INPUT_ESCAPE) != 0) {//Esc������Ă���

		SceneMgr_ChangeScene(eScene_Menu);//�V�[�����Q�[����ʂɕύX
	}

}

//�`��
void ISceneChanger_Draw() {
	DrawGraph(0, 0, mImageHandle, FALSE);
	DrawGraph(600, 200, mImageText, FALSE);
	DrawGraph(600, 232, mImageText2, FALSE);
	DrawGraph(200, 100, mImageChara, FALSE);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);   //���߂͂��܂�
	DrawGraph(0, 400, mImageText3, FALSE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);  //���߂����
	DrawString(250, 0, "�`�I���2�`", GetColor(300, 255, 255));
	DrawString(600, 200, "Seve", GetColor(255, 255, 255));
	DrawString(600, 232, "Lode ", GetColor(255, 255, 255));
}