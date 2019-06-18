#include "Include.h"

static int mImageHandle;    //画像ハンドル格納用変数

//初期化
void Config_Initialize() {
	mImageHandle = LoadGraph("Res\\C.jpg");//画像のロード
}

//終了処理
void Config_Finalize() {
	DeleteGraph(mImageHandle);//画像の解放
}

//更新
void Config_Update() {
	if (CheckHitKey(KEY_INPUT_ESCAPE) != 0) {//Escキーが押されていたら
		SceneMgr_ChangeScene(eScene_Menu);//シーンをメニューに変更
	}
}

//描画
void Config_Draw() {
	DrawGraph(0, 0, mImageHandle, FALSE);
	DrawString(0, 0, "未定。", GetColor(255, 255, 255));//色
	DrawString(0, 20, "Escキーを押すとメニュー画面に戻ります。", GetColor(255, 255, 255));
}
