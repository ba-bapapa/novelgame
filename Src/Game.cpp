#include"Include.h"

static int mImageHandle;    //�摜�n���h���i�[�p�ϐ�

							//������
void Game_Initialize() {
	mImageHandle = LoadGraph("Res\\chapter0-1.png");//�摜�̃��[�h
}

//�I������
void Game_Finalize() {
	DeleteGraph(mImageHandle);//�摜�̉��
}

//�X�V
void Game_Update() {
	if (CheckHitKey(KEY_INPUT_3) != 0) {//Esc�L�[��������Ă�����
		SceneMgr_ChangeScene(eScene_Nakaniwa);//�V�[�������j���[�ɕύX
	}
}

//�`��
void Game_Draw() {
	DrawGraph(0, 0, mImageHandle, FALSE);
	DrawString(0, 0, "�j���[�Q�[���B", GetColor(255, 255, 255));
	DrawString(0, 20, "3����ցB", GetColor(255, 255, 255));
}