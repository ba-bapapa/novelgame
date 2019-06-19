#include "Include.h"


static int mImageHandle, mImageChara, mImageText, mImageText2, mImageText3;    //画像ハンドル格納用変数

int MouseF,x,y;


//初期化
void ISceneChanger_Initialize() {
	mImageHandle = LoadGraph("Res\\F.jpg");    //画像のロード
	mImageText = LoadGraph("Res\\03.png"); // 
	mImageText2 = LoadGraph("Res\\03.png");
	mImageChara = LoadGraph("Res\\D.png"); //
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
	
	if (CheckHitKey(KEY_INPUT_ESCAPE) != 0) {//Escキーが押されていたら
		SceneMgr_ChangeScene(eScene_Menu);//シーンをメニューに変更
	}
	/*MouseF = GetMouseInput();                //マウスの入力状態取得
	GetMousePoint(&x, &y);                //マウスの座標取得
	if (MouseF&MOUSE_INPUT_LEFT) {//Esc押されていた
		WaitTimer(1000);
		DrawString(0, 0, "左ボタンが押されています", GetColor(255, 255, 255));
		//SceneMgr_ChangeScene(eScene_Menu);//シーンをゲーム画面に変更
	}*/

}

//描画
void ISceneChanger_Draw() {
	DrawGraph(0, 0, mImageHandle, FALSE);
	DrawGraph(600, 200, mImageText, FALSE);
	DrawGraph(600, 232, mImageText2, FALSE);
	DrawGraph(200, 100, mImageChara, FALSE);
	
	MouseF = GetMouseInput();                //マウスの入力状態取得
	GetMousePoint(&x, &y);                //マウスの座標取得
	if (MouseF&MOUSE_INPUT_LEFT) {//Esc押されていた
		WaitTimer(1000);
		DrawString(250, 380, "審査会発表を\n終了させていただきます", GetColor(255, 255, 255));
	}
	if (CheckHitKey(KEY_INPUT_RETURN) != 0) {//エンターキーが押されていたら
		
		WaitTimer(1000);
		DrawString(200, 400, "審査会発表を\n終了させていただきます", GetColor(0, 0, 0));
	}

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);   //透過はじまり
	DrawGraph(0, 400, mImageText3, FALSE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);  //透過おわり
	DrawString(100, 100, "～終わり2～", GetColor(300, 255, 255));
	DrawString(600, 200, "Seve", GetColor(255, 255, 255));
	DrawString(600, 232, "Lode ", GetColor(255, 255, 255));
}