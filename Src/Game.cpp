#include "Include.h"

static int mImageHandle;    //�摜�n���h���i�[�p�ϐ�
int MouseB;

							//������
void Game_Initialize() {
	mImageHandle = LoadGraph("Res\\B.jpg");    //�摜�̃��[�h
}

//�I������
void Game_Finalize() {
	DeleteGraph(mImageHandle);    //�摜�̉��
}

//�X�V
void Game_Update() {
	MouseB = GetMouseInput();

	if (MouseB & MOUSE_INPUT_RIGHT) { //Esc�L�[��������Ă�����
		SceneMgr_ChangeScene(eScene_Menu);//�V�[�������j���[�ɕύX
	}
}

//�`��
void Game_Draw() {
	DrawGraph(0, 0, mImageHandle, FALSE);
	DrawString(0, 0, "�Q�[����ʂł��B", GetColor(255, 255, 255));
	DrawString(0, 20, "Esc�L�[�������ƃ��j���[��ʂɖ߂�܂��B", GetColor(255, 255, 255));
}
