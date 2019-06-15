#include "DxLib.h"
#include"Include.h"

#define GRAPHIC_BACKGROUND_FILENAME "Res\\A.jpg"
#define GRAPHIC_SELECTBOX_FILENAME "Res\\01.png"

#define SELECT_BOX_X 700
#define SELECT_BOX_Y 300

#define SELECT_BOX_WIDTH 700
#define SELECT_BOX_HEIGHT 50

#define SELECT_BOX_MESSAGE_Y 20

#define FONT_SIZE 16

#define SELECT_BOX_MESSAGE_MAX_LENGTH 100
#define SELECT_BOX_HIDE 0
#define SELECT_BOX_SHOW 1


static int mImageHandle;    //�摜�n���h���i�[�p�ϐ�


//�I�����{�b�N�X�֌W
//��
int g_whiteColor;
//�w�i�̓ǂݍ���
int g_backgroundGraphic;
//�I���{�b�N�X�̓ǂݍ���
int g_selectBoxGraphicHandle;
//�I���{�b�N�X�ɕ\�����郁�b�Z�[�W
char g_selectBoxMessage[2][SELECT_BOX_MESSAGE_MAX_LENGTH];
//�I���{�b�N�X��\�����邩�ǂ��� 0: �� �\ �� 1: �\ ��
int g_selectBoxVisibleFlag;


//�I���{�b�N�X�̏�����
void initSelectBox()
{
	//��
	g_whiteColor = GetColor(255, 255, 255);
	//�I���{�b�N�X�̓ǂݍ���
	g_selectBoxGraphicHandle = LoadGraph(GRAPHIC_SELECTBOX_FILENAME);
	//�I���{�b�N�X�̃��b�Z�[�W������
	memset(g_selectBoxMessage[0], 0, SELECT_BOX_MESSAGE_MAX_LENGTH);
	memset(g_selectBoxMessage[1], 0, SELECT_BOX_MESSAGE_MAX_LENGTH);
	//�I���{�b�N�X��\�����Ȃ�
	g_selectBoxVisibleFlag = SELECT_BOX_HIDE;
}


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
 
 //�X�V
/*void Menu_Update() {
	 if (CheckHitKey(KEY_INPUT_1) != 0) {//1�L�[��������Ă�����
		 SceneMgr_ChangeScene(eScene_Game);//�V�[�����Q�[����ʂɕύX
	 }
	 if (CheckHitKey(KEY_INPUT_2) != 0) {//2�L�[��������Ă�����
		 SceneMgr_ChangeScene(eScene_Config);//�V�[�������[�h��ʂɕύX
	 }

 }*/


 void Menu_Draw() {
	 DrawGraph(0, 0, mImageHandle, FALSE);
	 DrawString(0, 0, "���j���[��ʂł��B", GetColor(255, 255, 255));
 }


//�I���{�b�N�X�Ƀ��b�Z�[�W���Z�b�g����
/*void setSelectBoxMessage(const char* message1, const char* message2)
{
	//���b�Z�[�W�Z�b�g
	strncpy(g_selectBoxMessage[0], message1, SELECT_BOX_MESSAGE_MAX_LENGTH);
	strncpy(g_selectBoxMessage[1], message2, SELECT_BOX_MESSAGE_MAX_LENGTH);
	//�I���{�b�N�X��\��
	g_selectBoxVisibleFlag = SELECT_BOX_SHOW;
}
*/

 //�I�����{�b�N�X��`�悷��
 void drawSelectBox()
 {
 //�I�����{�b�N�X1�� �} �E �X �| �C �� �^ �� �� �� �� �� �� �� ��
	 if (isContainMousePointer(SELECT_BOX_X, SELECT_BOX_Y,
	 SELECT_BOX_WIDTH, SELECT_BOX_HEIGHT)) {
 //�����x0�� �� �� ��
	 SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);

	 } else {
	 //�����x50% �� �� ��
	 SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);

 }
 //�I���{�b�N�X�̕`��
	 DrawGraph(SELECT_BOX_X, SELECT_BOX_Y, g_selectBoxGraphicHandle, TRUE);

	 //�I�����{�b�N�X2�� �} �E �X �| �C �� �^ �� �� �� �� �� �� �� ��
 if (isContainMousePointer(SELECT_BOX_X, SELECT_BOX_Y + SELECT_BOX_HEIGHT,
	 SELECT_BOX_WIDTH, SELECT_BOX_HEIGHT)) {
	 //�����x0�� �� �� ��
	 SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);

 } else {
	 //�����x50% �� �� ��
 SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);
	
 }
 //�I���{�b�N�X2�� �� �� �` ��
 DrawGraph(SELECT_BOX_X, SELECT_BOX_Y + SELECT_BOX_HEIGHT,
 g_selectBoxGraphicHandle, TRUE);

 //�A���t�@�u�����h�����ɖ߂�
 SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

 //�K���ɕ�����\������
 DrawString(SELECT_BOX_X + 20, SELECT_BOX_Y + SELECT_BOX_MESSAGE_Y,
	 "Now Game", g_whiteColor);
	 DrawString(SELECT_BOX_X + 20, SELECT_BOX_Y + SELECT_BOX_HEIGHT + SELECT_BOX_MESSAGE_Y,
	 "Lord Game", g_whiteColor);
 }


//�I�����{�b�N�X���N���b�N���ꂽ���ǂ���
//0: �N �� �b �N �� �� �� �� �� �� 1: �I �� ��1 �� �N �� �b �N �� �� �� 2: �I �� ��2 �� �N �� �b �N �� �� ��
 int isClickedSelectBox()
 {
	 //�I�����{�b�N�X���\������Ă���Ƃ�
	 if (g_selectBoxVisibleFlag) {
		 //�}�E�X�̏�Ԃ𒲂ׂ�
		 //���N���b�N���ꂽ�Ƃ�
		 if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) {

			 if (isContainMousePointer(SELECT_BOX_X, SELECT_BOX_Y,
				 SELECT_BOX_WIDTH, SELECT_BOX_HEIGHT)) {
				 //�I�����{�b�N�X1�� �} �E �X �| �C �� �^ �� �� �� �� �� �� �� ��
				//�I���{�b�N�X�̃��b�Z�[�W������
				 memset(g_selectBoxMessage[0], 0, SELECT_BOX_MESSAGE_MAX_LENGTH);
				 memset(g_selectBoxMessage[1], 0, SELECT_BOX_MESSAGE_MAX_LENGTH);
				 //�I���{�b�N�X��\�����Ȃ�
				 g_selectBoxVisibleFlag = SELECT_BOX_HIDE;
				 //�I����1�� �N �� �b �N �� �� �� �� �� �� �� �� �� �m
				 return 1;

			 }
			 else if (isContainMousePointer(SELECT_BOX_X,
				 SELECT_BOX_Y + SELECT_BOX_HEIGHT,
				 SELECT_BOX_WIDTH, SELECT_BOX_HEIGHT)) {
				 //�I�����{�b�N�X2�� �} �E �X �| �C �� �^ �� �� �� �� �� �� �� ��
				 //�I���{�b�N�X�̃��b�Z�[�W������
				 memset(g_selectBoxMessage[0], 0, SELECT_BOX_MESSAGE_MAX_LENGTH);
				 memset(g_selectBoxMessage[1], 0, SELECT_BOX_MESSAGE_MAX_LENGTH);
				 //�I���{�b�N�X��\�����Ȃ�
				 g_selectBoxVisibleFlag = SELECT_BOX_HIDE;
				 //�I����2�� �N �� �b �N �� �� �� �� �� �� �� �� �� �m
				 return 2;

			 }
		 }
	 }
	 return 0;
 }


 int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	 LPSTR lpCmdLine, int nCmdShow)
 {
	 int Handle, Count = 0;
	 Handle = LoadSoundMem("073.mp3"); // �T�E���h/1up.wav�����[�h���A���ʔԍ���Handle�Ɋi�[

	  //�E�B���h�E���[�h�ŋN��
	 ChangeWindowMode(TRUE);
	 //��ʂ̑傫����800 * 600
	 SetGraphMode(800, 600, 16);
	 // D x L i b������
	 if (DxLib_Init() == -1) {
		 return -1;

	 }



	 // �` �� �� �� �� �� �� �� �Z �b �g
	 SetDrawScreen(DX_SCREEN_BACK);

	 //�t�H���g�̑傫�����Z�b�g
	 SetFontSize(FONT_SIZE);
	 // �} �E �X �� �\ �� �� �� �� �� ��
	 SetMouseDispFlag(TRUE);

	 //�I���{�b�N�X�̏�����
	 initSelectBox();
	 //��
	 //g_whiteColor = GetColor(255, 255, 255);
	 //�w�i�̓ǂݍ���
	 g_backgroundGraphic = LoadGraph(GRAPHIC_BACKGROUND_FILENAME);
	 //�I���{�b�N�X�̓ǂݍ���
	// g_selectBoxGraphicHandle = LoadGraph(GRAPHIC_SELECTBOX_FILENAME);

	 int tmpClicked = 0; //�e�X�g�p


	//���C�����[�v
	 while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {

		 if (Count % 120 == 0) { // 2�b�Ɉ�x
			 PlaySoundMem(Handle, DX_PLAYTYPE_BACK); // ���ʉ����Đ�����
		 }
		 Count++;

		 // F 1 �� �� �� �� �I �� �{ �b �N �X �� �\ ��
		 /*if (CheckHitKey(KEY_INPUT_F1)) {
			 setSelectBoxMessage(" F 1 �� �� �� �� �� �� �I �� �� 1 ", "�I����2");
		 }*/

		 //��ʃN���A
		 ClearDrawScreen();

		 //�w�i��`��
		 DrawGraph(0, 0, g_backgroundGraphic, FALSE);

		 //�I�����{�b�N�X�̕`��
		 drawSelectBox();

		 //�ǂ̑I�������N���b�N���ꂽ�����ׂ�
		/* tmpClicked = isClickedSelectBox();
		 if (tmpClicked == 1) {
			 DrawString(50, 50, "�I����1�� �N �� �b �N �� �� �� �� ��", g_whiteColor);

		 }
		 else if (tmpClicked == 2) {
			 DrawString(50, 50, "�I����2�� �N �� �b �N �� �� �� �� ��", g_whiteColor);

		 }*/


		 ScreenFlip();

		 //�N���b�N���ꂽ���Ƃ�������悤�ɂ��Ă���
		 /*if (tmpClicked != 0) {
			 Sleep(1000);

		 }*/


	 }

	 DxLib_End();
	 return 0;

 }