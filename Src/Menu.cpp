#include "Include.h"


static int mImageHandle;    //画像ハンドル格納用変数

int MouseA;
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
	MouseA = GetMouseInput();                //マウスの入力状態取得
	if (MouseA&MOUSE_INPUT_LEFT) {//左クリック押されていたら
		SceneMgr_ChangeScene(eScene_Game);//シーンをゲーム画面に変更
	}
	
	if (MouseA & MOUSE_INPUT_RIGHT) {//Cキーが押されていたら
		SceneMgr_ChangeScene(eScene_Config);//シーンを設定画面に変更
	}
}

//描画
void Menu_Draw() {
	DrawGraph(0, 0, mImageHandle, FALSE);
	DrawString(0, 0, "メニュー画面です。", GetColor(255, 255, 255));
	DrawString(0, 20, "Gキーを押すとゲーム画面に進みます。", GetColor(255, 255, 255));
	DrawString(0, 40, "Cキーを押すと　設定画面に進みます。", GetColor(255, 255, 255));
}