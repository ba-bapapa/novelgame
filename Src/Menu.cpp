#include "Include.h"




static int mImageHandle,mImageText, mImageText2;    //画像ハンドル格納用変数

int MouseA;

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


//初期化
void Menu_Initialize() {
	mImageHandle = LoadGraph("Res\\A.jpg");    //画像のロード
	mImageText = LoadGraph("Res\\03.png"); // 
	mImageText2 = LoadGraph("Res\\03.png"); // 
}

//終了処理
void Menu_Finalize() {
	DeleteGraph(mImageHandle);    //画像の解放
	DeleteGraph(mImageText);    //画像の解放
	DeleteGraph(mImageText2);    //画像の解放
}

//更新
void Menu_Update() {
	MouseA = GetMouseInput();                //マウスの入力状態取得
	if (MouseA&MOUSE_INPUT_LEFT) {//左クリック押されていた

		SceneMgr_ChangeScene(eScene_Game);//シーンをゲーム画面に変更
	}
	
	if (CheckHitKey(KEY_INPUT_A) != 0) {//Aキーが押されていたら
		SceneMgr_ChangeScene(eScene_Config);//シーンを設定画面に変更
	}
}

//描画
void Menu_Draw() {
	DrawGraph(0, 0, mImageHandle, FALSE);
	DrawGraph(540, 200, mImageText, FALSE);
	DrawGraph(540, 232, mImageText2, FALSE);
	DrawString(250, 200, "～タイトル～", GetColor(255, 255, 255));
	DrawString(540, 200, "Now Game", GetColor(255, 255, 255));
	DrawString(540, 232, "Lode Game", GetColor(255, 255, 255));
}