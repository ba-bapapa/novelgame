#include "Include.h"

static int mImageHandle,mImageChara,mImageText;    //画像ハンドル格納用変数
int MouseB;

							//初期化
void Game_Initialize() {
	mImageHandle = LoadGraph("Res\\B.jpg");//画像のロード
	mImageChara = LoadGraph("Res\\C.png"); // 
	mImageText = LoadGraph("Res\\02.png"); // 
}

//終了処理
void Game_Finalize() {
	DeleteGraph(mImageHandle);    //画像の解放
	DeleteGraph(mImageChara);    //画像の解放
	DeleteGraph(mImageText);    //画像の解放
}

//更新
void Game_Update() {
	MouseB = GetMouseInput();
	if (MouseB &MOUSE_INPUT_RIGHT) { //Escキーが押されていたら
		SceneMgr_ChangeScene(eScene_Nakaniwa);//シーンをメニューに変更
	}
}

//描画
void Game_Draw() {
	DrawGraph(0, 0, mImageHandle, FALSE);
	DrawGraph(200, 100, mImageChara, FALSE);
	DrawGraph(0, 400, mImageText, FALSE);
	DrawString(0, 0, "～プロローグ～", GetColor(300, 255, 255));
	DrawString(0, 400, "テキスト読み込み予定", GetColor(255, 255, 255));
}
