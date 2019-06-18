#include "Include.h"


static int mImageHandle, mImageChara, mImageText, mImageText2, mImageText3;    //画像ハンドル格納用変数

int MouseF;



//初期化
void ISceneChanger_Initialize() {
	mImageHandle = LoadGraph("Res\\F.jpg");    //画像のロード
	mImageText = LoadGraph("Res\\03.png"); // 
	mImageText2 = LoadGraph("Res\\03.png");
	mImageChara = LoadGraph("Res\\D.png"); // // 
	mImageText3 = LoadGraph("Res\\02.png"); // 
}

//終了処理
void ISceneChanger_Finalize() {
	DeleteGraph(mImageHandle);    //画像の解放
	DeleteGraph(mImageText);    //画像の解放
	DeleteGraph(mImageText2);    //画像の解放
	DeleteGraph(mImageChara);    //画像の解放
	DeleteGraph(mImageText3);    //画像の解放
}

//更新
void ISceneChanger_Update() {
	MouseF = GetMouseInput();                //マウスの入力状態取得
	if (CheckHitKey(KEY_INPUT_ESCAPE) != 0) {//Esc押されていた

		SceneMgr_ChangeScene(eScene_Menu);//シーンをゲーム画面に変更
	}

}

//描画
void ISceneChanger_Draw() {
	DrawGraph(0, 0, mImageHandle, FALSE);
	DrawGraph(600, 200, mImageText, FALSE);
	DrawGraph(600, 232, mImageText2, FALSE);
	DrawGraph(200, 100, mImageChara, FALSE);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);   //透過はじまり
	DrawGraph(0, 400, mImageText3, FALSE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);  //透過おわり
	DrawString(250, 0, "～終わり2～", GetColor(300, 255, 255));
	DrawString(600, 200, "Seve", GetColor(255, 255, 255));
	DrawString(600, 232, "Lode ", GetColor(255, 255, 255));
}