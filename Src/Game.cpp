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
	if (MouseB &MOUSE_INPUT_RIGHT) { //Esc�L�[��������Ă�����
		SceneMgr_ChangeScene(eScene_Nakaniwa);//�V�[�������j���[�ɕύX
	}
}

//�`��
void Game_Draw() {
	DrawGraph(0, 0, mImageHandle, FALSE);
	DrawGraph(200, 100, mImageChara, FALSE);
	DrawGraph(0, 400, mImageText, FALSE);
	DrawString(0, 0, "�`�v�����[�O�`", GetColor(300, 255, 255));
	DrawString(0, 400, "�e�L�X�g�ǂݍ��ݗ\��", GetColor(255, 255, 255));
}
