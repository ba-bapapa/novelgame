#include"Include.h"

static int mImageHandle;    //画像ハンドル格納用変数

							//初期化
void Game_Initialize() {
	mImageHandle = LoadGraph("Res\\chapter0-1.png");//画像のロード
}

//終了処理
void Game_Finalize() {
	DeleteGraph(mImageHandle);//画像の解放
}

//更新
void Game_Update() {
	if (CheckHitKey(KEY_INPUT_3) != 0) {//Escキーが押されていたら
		SceneMgr_ChangeScene(eScene_Nakaniwa);//シーンをメニューに変更
	}
}

//描画
void Game_Draw() {
	DrawGraph(0, 0, mImageHandle, FALSE);
	DrawString(0, 0, "ニューゲーム。", GetColor(255, 255, 255));
	DrawString(0, 20, "3中庭へ。", GetColor(255, 255, 255));
}