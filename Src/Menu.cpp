#include "Include.h"




static int mImageHandle,mImageText, mImageText2;    //�摜�n���h���i�[�p�ϐ�

int MouseA;

//�v���g�^�C�v�錾
int isContainMousePointer(int x, int y, int width, int height);
void drawSelectBox();

//�w�肵���{�b�N�X���Ƀ}�E�X�����݂��邩�ǂ���
//�߂�l 1: �� �� �� �� 0: �� �� �� �� ��
int isContainMousePointer(int x, int y, int width, int height)
{
int mouseX, mouseY;
//�}�E�X�̍��W���擾
GetMousePoint(&mouseX, &mouseY);
//�{�b�N�X���Ƀ}�E�X���W�����݂��邩
if ((mouseX >= x && mouseX <= x + width) &&
	(mouseY >= y && mouseY <= y + height)) {
	return 1;
	
}
return 0;
}


//������
void Menu_Initialize() {
	mImageHandle = LoadGraph("Res\\A.jpg");    //�摜�̃��[�h
	mImageText = LoadGraph("Res\\03.png"); // 
	mImageText2 = LoadGraph("Res\\03.png"); // 
}

//�I������
void Menu_Finalize() {
	DeleteGraph(mImageHandle);    //�摜�̉��
	DeleteGraph(mImageText);    //�摜�̉��
	DeleteGraph(mImageText2);    //�摜�̉��
}

//�X�V
void Menu_Update() {
	MouseA = GetMouseInput();                //�}�E�X�̓��͏�Ԏ擾
	if (MouseA&MOUSE_INPUT_LEFT) {//���N���b�N������Ă���
		WaitTimer(1000);

		SceneMgr_ChangeScene(eScene_Game);//�V�[�����Q�[����ʂɕύX
	}
	
	if (MouseA&MOUSE_INPUT_RIGHT) {//�E�N���b�N��������Ă�����
		WaitTimer(1000);
		SceneMgr_ChangeScene(eScene_Config);//�V�[����ݒ��ʂɕύX
	}
}

//�`��
void Menu_Draw() {

	DrawGraph(0, 0, mImageHandle, FALSE);
	DrawGraph(540, 200, mImageText, FALSE);
	DrawGraph(540, 232, mImageText2, FALSE);
	DrawString(250, 200, "�`�^�C�g���`", GetColor(255, 255, 255));
	SetDrawBlendMode(DX_BLENDMODE_ADD, 255);             //�u�����h���[�h�����Z(255/255)�ɐݒ�
	DrawString(540, 200, "Now Game", GetColor(255, 255, 255));
	DrawString(540, 232, "Lode Game", GetColor(255, 255, 255));
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);           //�u�����h���[�h���I�t
}