#include "Include.h"


static int mImageHandle, mImageChara, mImageText, mImageText2, mImageText3;    //�摜�n���h���i�[�p�ϐ�

int MouseF,x,y;


//������
void ISceneChanger_Initialize() {
	mImageHandle = LoadGraph("Res\\F.jpg");    //�摜�̃��[�h
	mImageText = LoadGraph("Res\\03.png"); // 
	mImageText2 = LoadGraph("Res\\03.png");
	mImageChara = LoadGraph("Res\\D.png"); //
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
	
	if (CheckHitKey(KEY_INPUT_ESCAPE) != 0) {//Esc�L�[��������Ă�����
		SceneMgr_ChangeScene(eScene_Menu);//�V�[�������j���[�ɕύX
	}
	/*MouseF = GetMouseInput();                //�}�E�X�̓��͏�Ԏ擾
	GetMousePoint(&x, &y);                //�}�E�X�̍��W�擾
	if (MouseF&MOUSE_INPUT_LEFT) {//Esc������Ă���
		WaitTimer(1000);
		DrawString(0, 0, "���{�^����������Ă��܂�", GetColor(255, 255, 255));
		//SceneMgr_ChangeScene(eScene_Menu);//�V�[�����Q�[����ʂɕύX
	}*/

}

//�`��
void ISceneChanger_Draw() {
	DrawGraph(0, 0, mImageHandle, FALSE);
	DrawGraph(600, 200, mImageText, FALSE);
	DrawGraph(600, 232, mImageText2, FALSE);
	DrawGraph(200, 100, mImageChara, FALSE);
	
	MouseF = GetMouseInput();                //�}�E�X�̓��͏�Ԏ擾
	GetMousePoint(&x, &y);                //�}�E�X�̍��W�擾
	if (MouseF&MOUSE_INPUT_LEFT) {//Esc������Ă���
		WaitTimer(1000);
		DrawString(250, 380, "�R����\��\n�I�������Ă��������܂�", GetColor(255, 255, 255));
	}
	if (CheckHitKey(KEY_INPUT_RETURN) != 0) {//�G���^�[�L�[��������Ă�����
		
		WaitTimer(1000);
		DrawString(200, 400, "�R����\��\n�I�������Ă��������܂�", GetColor(0, 0, 0));
	}

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);   //���߂͂��܂�
	DrawGraph(0, 400, mImageText3, FALSE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);  //���߂����
	DrawString(100, 100, "�`�I���2�`", GetColor(300, 255, 255));
	DrawString(600, 200, "Seve", GetColor(255, 255, 255));
	DrawString(600, 232, "Lode ", GetColor(255, 255, 255));
}