#include "Include.h"


static int mImageHandle, mImageChara, mImageText, mImageText2, mImageText3;    //画像ハンドル格納用変数

int MouseD;



//初期化
void Nakaniwa_Initialize() {
	mImageHandle = LoadGraph("Res\\D.jpg");    //画像のロード
	mImageText = LoadGraph("Res\\03.png"); // 
	mImageText2 = LoadGraph("Res\\03.png");
	mImageChara = LoadGraph("Res\\D.png"); // // 
	mImageText3 = LoadGraph("Res\\02.png"); // 
}

//終了処理
void Nakaniwa_Finalize() {
	DeleteGraph(mImageHandle);    //画像の解放
	DeleteGraph(mImageText);    //画像の解放
	DeleteGraph(mImageText2);    //画像の解放
	DeleteGraph(mImageChara);    //画像の解放
	DeleteGraph(mImageText3);    //画像の解放
}

//更新
void Nakaniwa_Update() {
	MouseD = GetMouseInput();                //マウスの入力状態取得
	if (MouseD&MOUSE_INPUT_LEFT) {//左クリック押されていた
		SceneMgr_ChangeScene(eScene_BaseScene);//シーンをゲーム画面に変更
	}

	if (CheckHitKey(KEY_INPUT_C) != 0) {//Aキーが押されていたら
		SceneMgr_ChangeScene(eScene_Config);//シーンを設定画面に変更
	}
}

//描画
void Nakaniwa_Draw() {
	DrawGraph(0, 0, mImageHandle, FALSE);
	DrawGraph(600, 200, mImageText, FALSE);
	DrawGraph(600, 232, mImageText2, FALSE);
	DrawGraph(200, 100, mImageChara, FALSE);
	DrawGraph(0, 400, mImageText3, FALSE);
	DrawString(250, 0, "〜中庭〜", GetColor(255, 300, 255));
	DrawString(600, 200, "Seve", GetColor(255, 255, 255));
	DrawString(600, 232, "Lode ", GetColor(255, 255, 255));
}