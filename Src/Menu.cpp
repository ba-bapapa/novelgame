#include "Menu.h"
#include "SceneMgr.h"
#include "DxLib.h"

static int mImageHandle;    //画像ハンドル格納用変数

							//初期化
void Menu_Initialize() {
	mImageHandle = LoadGraph("Res\\A.jpg");    //画像のロード
}

//終了処理
void Menu_Finalize() {
	DeleteGraph(mImageHandle);    //画像の解放
}

//更新
void Menu_Update() {
	if (CheckHitKey(KEY_INPUT_1) != 0) {//1キーが押されていたら
		SceneMgr_ChangeScene(eScene_Game);//シーンをゲーム画面に変更
	}
	if (CheckHitKey(KEY_INPUT_2) != 0) {//2キーが押されていたら
		SceneMgr_ChangeScene(eScene_Config);//シーンをロード画面に変更
	}
//	if (CheckHitKey(KEY_INPUT_3) != 0) {//3キーが押されていたら
	//	SceneMgr_ChangeScene(eScene_Config);//シーンを設定画面に変更
	//}
}

//描画
void Menu_Draw() {
	DrawGraph(0, 0, mImageHandle, FALSE);
	DrawString(0, 0, "タイトル画面。", GetColor(255, 255, 255));
	DrawString(500, 20, "1NewGame", GetColor(255, 255, 255));
	DrawString(500, 40, "2LordGame", GetColor(255, 255, 255));
	//DrawString(500, 60, "3設定", GetColor(255, 255, 255));
}
