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


static int mImageHandle;    //画像ハンドル格納用変数


//選択肢ボックス関係
//白
int g_whiteColor;
//背景の読み込み
int g_backgroundGraphic;
//選択ボックスの読み込み
int g_selectBoxGraphicHandle;
//選択ボックスに表示するメッセージ
char g_selectBoxMessage[2][SELECT_BOX_MESSAGE_MAX_LENGTH];
//選択ボックスを表示するかどうか 0: 非 表 示 1: 表 示
int g_selectBoxVisibleFlag;


//選択ボックスの初期化
void initSelectBox()
{
	//白
	g_whiteColor = GetColor(255, 255, 255);
	//選択ボックスの読み込み
	g_selectBoxGraphicHandle = LoadGraph(GRAPHIC_SELECTBOX_FILENAME);
	//選択ボックスのメッセージ初期化
	memset(g_selectBoxMessage[0], 0, SELECT_BOX_MESSAGE_MAX_LENGTH);
	memset(g_selectBoxMessage[1], 0, SELECT_BOX_MESSAGE_MAX_LENGTH);
	//選択ボックスを表示しない
	g_selectBoxVisibleFlag = SELECT_BOX_HIDE;
}


//指定したボックス内にマウスが存在するかどうか
//戻り値 1: 存 在 す る 0: 存 在 し な い
 int isContainMousePointer(int x, int y, int width, int height)
 {
	 int mouseX, mouseY;
	
 //マウスの座標を取得
 GetMousePoint(&mouseX, &mouseY);

 //ボックス内にマウス座標が存在するか
 if ((mouseX >= x && mouseX <= x + width) &&
	 (mouseY >= y && mouseY <= y + height)) {
	return 1;
 }
  return 0;
 
 }
 
 //更新
/*void Menu_Update() {
	 if (CheckHitKey(KEY_INPUT_1) != 0) {//1キーが押されていたら
		 SceneMgr_ChangeScene(eScene_Game);//シーンをゲーム画面に変更
	 }
	 if (CheckHitKey(KEY_INPUT_2) != 0) {//2キーが押されていたら
		 SceneMgr_ChangeScene(eScene_Config);//シーンをロード画面に変更
	 }

 }*/


 void Menu_Draw() {
	 DrawGraph(0, 0, mImageHandle, FALSE);
	 DrawString(0, 0, "メニュー画面です。", GetColor(255, 255, 255));
 }


//選択ボックスにメッセージをセットする
/*void setSelectBoxMessage(const char* message1, const char* message2)
{
	//メッセージセット
	strncpy(g_selectBoxMessage[0], message1, SELECT_BOX_MESSAGE_MAX_LENGTH);
	strncpy(g_selectBoxMessage[1], message2, SELECT_BOX_MESSAGE_MAX_LENGTH);
	//選択ボックスを表示
	g_selectBoxVisibleFlag = SELECT_BOX_SHOW;
}
*/

 //選択肢ボックスを描画する
 void drawSelectBox()
 {
 //選択肢ボックス1が マ ウ ス ポ イ ン タ を 含 ん で い た 場 合
	 if (isContainMousePointer(SELECT_BOX_X, SELECT_BOX_Y,
	 SELECT_BOX_WIDTH, SELECT_BOX_HEIGHT)) {
 //透明度0％ と す る
	 SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);

	 } else {
	 //透明度50% と す る
	 SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);

 }
 //選択ボックスの描画
	 DrawGraph(SELECT_BOX_X, SELECT_BOX_Y, g_selectBoxGraphicHandle, TRUE);

	 //選択肢ボックス2が マ ウ ス ポ イ ン タ を 含 ん で い た 場 合
 if (isContainMousePointer(SELECT_BOX_X, SELECT_BOX_Y + SELECT_BOX_HEIGHT,
	 SELECT_BOX_WIDTH, SELECT_BOX_HEIGHT)) {
	 //透明度0％ と す る
	 SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);

 } else {
	 //透明度50% と す る
 SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);
	
 }
 //選択ボックス2つ 目 の 描 画
 DrawGraph(SELECT_BOX_X, SELECT_BOX_Y + SELECT_BOX_HEIGHT,
 g_selectBoxGraphicHandle, TRUE);

 //アルファブレンドを元に戻す
 SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

 //適当に文字を表示する
 DrawString(SELECT_BOX_X + 20, SELECT_BOX_Y + SELECT_BOX_MESSAGE_Y,
	 "Now Game", g_whiteColor);
	 DrawString(SELECT_BOX_X + 20, SELECT_BOX_Y + SELECT_BOX_HEIGHT + SELECT_BOX_MESSAGE_Y,
	 "Lord Game", g_whiteColor);
 }


//選択肢ボックスがクリックされたかどうか
//0: ク リ ッ ク さ れ て い な い 1: 選 択 肢1 が ク リ ッ ク さ れ た 2: 選 択 肢2 が ク リ ッ ク さ れ た
 int isClickedSelectBox()
 {
	 //選択肢ボックスが表示されているとき
	 if (g_selectBoxVisibleFlag) {
		 //マウスの状態を調べる
		 //左クリックされたとき
		 if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) {

			 if (isContainMousePointer(SELECT_BOX_X, SELECT_BOX_Y,
				 SELECT_BOX_WIDTH, SELECT_BOX_HEIGHT)) {
				 //選択肢ボックス1が マ ウ ス ポ イ ン タ を 含 ん で い た 場 合
				//選択ボックスのメッセージ初期化
				 memset(g_selectBoxMessage[0], 0, SELECT_BOX_MESSAGE_MAX_LENGTH);
				 memset(g_selectBoxMessage[1], 0, SELECT_BOX_MESSAGE_MAX_LENGTH);
				 //選択ボックスを表示しない
				 g_selectBoxVisibleFlag = SELECT_BOX_HIDE;
				 //選択肢1が ク リ ッ ク さ れ て い る こ と を 通 知
				 return 1;

			 }
			 else if (isContainMousePointer(SELECT_BOX_X,
				 SELECT_BOX_Y + SELECT_BOX_HEIGHT,
				 SELECT_BOX_WIDTH, SELECT_BOX_HEIGHT)) {
				 //選択肢ボックス2が マ ウ ス ポ イ ン タ を 含 ん で い た 場 合
				 //選択ボックスのメッセージ初期化
				 memset(g_selectBoxMessage[0], 0, SELECT_BOX_MESSAGE_MAX_LENGTH);
				 memset(g_selectBoxMessage[1], 0, SELECT_BOX_MESSAGE_MAX_LENGTH);
				 //選択ボックスを表示しない
				 g_selectBoxVisibleFlag = SELECT_BOX_HIDE;
				 //選択肢2が ク リ ッ ク さ れ て い る こ と を 通 知
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
	 Handle = LoadSoundMem("073.mp3"); // サウンド/1up.wavをロードし、識別番号をHandleに格納

	  //ウィンドウモードで起動
	 ChangeWindowMode(TRUE);
	 //画面の大きさは800 * 600
	 SetGraphMode(800, 600, 16);
	 // D x L i b初期化
	 if (DxLib_Init() == -1) {
		 return -1;

	 }



	 // 描 画 先 を 裏 画 面 に セ ッ ト
	 SetDrawScreen(DX_SCREEN_BACK);

	 //フォントの大きさをセット
	 SetFontSize(FONT_SIZE);
	 // マ ウ ス を 表 示 状 態 に す る
	 SetMouseDispFlag(TRUE);

	 //選択ボックスの初期化
	 initSelectBox();
	 //白
	 //g_whiteColor = GetColor(255, 255, 255);
	 //背景の読み込み
	 g_backgroundGraphic = LoadGraph(GRAPHIC_BACKGROUND_FILENAME);
	 //選択ボックスの読み込み
	// g_selectBoxGraphicHandle = LoadGraph(GRAPHIC_SELECTBOX_FILENAME);

	 int tmpClicked = 0; //テスト用


	//メインループ
	 while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {

		 if (Count % 120 == 0) { // 2秒に一度
			 PlaySoundMem(Handle, DX_PLAYTYPE_BACK); // 効果音を再生する
		 }
		 Count++;

		 // F 1 を 押 す と 選 択 ボ ッ ク ス を 表 示
		 /*if (CheckHitKey(KEY_INPUT_F1)) {
			 setSelectBoxMessage(" F 1 を 押 し た 時 の 選 択 肢 1 ", "選択肢2");
		 }*/

		 //画面クリア
		 ClearDrawScreen();

		 //背景を描画
		 DrawGraph(0, 0, g_backgroundGraphic, FALSE);

		 //選択肢ボックスの描画
		 drawSelectBox();

		 //どの選択肢がクリックされたか調べる
		/* tmpClicked = isClickedSelectBox();
		 if (tmpClicked == 1) {
			 DrawString(50, 50, "選択肢1が ク リ ッ ク さ れ ま し た", g_whiteColor);

		 }
		 else if (tmpClicked == 2) {
			 DrawString(50, 50, "選択肢2が ク リ ッ ク さ れ ま し た", g_whiteColor);

		 }*/


		 ScreenFlip();

		 //クリックされたことが分かるようにしておく
		 /*if (tmpClicked != 0) {
			 Sleep(1000);

		 }*/


	 }

	 DxLib_End();
	 return 0;

 }