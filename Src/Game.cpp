#include"Include.h"


static int mImageHandle;    //�摜�n���h���i�[�p�ϐ�

							//������
void Game_Initialize() {
	mImageHandle = LoadGraph("Res\\chapter0-1.png");    //�摜�̃��[�h
}

//�I������
void Game_Finalize() {
	DeleteGraph(mImageHandle);    //�摜�̉��
}

//�X�V
void Game_Update() {
	if (CheckHitKey(KEY_INPUT_ESCAPE) != 0) { //Esc�L�[��������Ă�����
		SceneMgr_ChangeScene(eScene_Menu);//�V�[�������j���[�ɕύX
	}
}

//�`��
void Game_Draw() {
	DrawGraph(0, 0, mImageHandle, FALSE);
	DrawString(0, 0, "�j���[�Q�[����ʁB", GetColor(255, 255, 255));
	DrawString(0, 20, "Esc�L�[�������ƃ��j���[��ʂɖ߂�܂��B", GetColor(255, 255, 255));
}