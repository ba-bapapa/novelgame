#include "Include.h"

static int mImageHandle;    //画像ハンドル格納用変数
int MouseB;

							//初期化
void Game_Initialize() {
	mImageHandle = LoadGraph("Res\\B.jpg");    //画像のロード
}

//終了処理
void Game_Finalize() {
	DeleteGraph(mImageHandle);    //画像の解放
}

//更新
void Game_Update() {
	MouseB = GetMouseInput();

	if (MouseB & MOUSE_INPUT_RIGHT) { //Escキーが押されていたら
		SceneMgr_ChangeScene(eScene_Menu);//シーンをメニューに変更
	}
}

//描画
void Game_Draw() {
	DrawGraph(0, 0, mImageHandle, FALSE);
	DrawString(0, 0, "ゲーム画面です。", GetColor(255, 255, 255));
	DrawString(0, 20, "Escキーを押すとメニュー画面に戻ります。", GetColor(255, 255, 255));
}
