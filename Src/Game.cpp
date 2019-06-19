#include "Include.h"

static int mImageHandle,mImageChara,mImageText;    //�摜�n���h���i�[�p�ϐ�
int MouseB;

							//������
void Game_Initialize() {
	mImageHandle = LoadGraph("Res\\B.jpg");//�摜�̃��[�h
	mImageChara = LoadGraph("Res\\C.png"); // 
	mImageText = LoadGraph("Res\\02.png"); // 
}

//�I������
void Game_Finalize() {
	DeleteGraph(mImageHandle);    //�摜�̉��
	DeleteGraph(mImageChara);    //�摜�̉��
	DeleteGraph(mImageText);    //�摜�̉��
}

//�X�V
void Game_Update() {
	MouseB = GetMouseInput();
	if (MouseB &MOUSE_INPUT_LEFT) { //���N���b�N�L�[��������Ă�����
		WaitTimer(1000);
		SceneMgr_ChangeScene(eScene_Nakaniwa);//�V�[�������j���[�ɕύX
	}
	if (CheckHitKey(KEY_INPUT_RETURN) != 0) {//�G���^�[�L�[��������Ă�����
		SceneMgr_ChangeScene(eScene_Nakaniwa);//�V�[�������j���[�ɕύX
		WaitTimer(1000);
	}
}

//�`��
void Game_Draw() {
	DrawGraph(0, 0, mImageHandle, FALSE);
	DrawGraph(200, 100, mImageChara, FALSE);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);   //���߂͂��܂�
	DrawGraph(0, 400, mImageText, FALSE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);  //���߂����
	DrawString(0, 0, "�`�v�����[�O�`", GetColor(300, 255, 255));
	DrawString(0, 400, "�e�L�X�g�ǂݍ��ݗ\��\n�N���b�N�Ŏ��̃V�[����", GetColor(255, 255, 255));
	}
