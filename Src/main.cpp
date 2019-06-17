#include "DxLib.h"
#include "SceneMgr.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK); //ウィンドウモード変更と初期化と裏画面設定

	SceneMgr_Initialize();
	double size = 1.0;
	int x, y, Mouse, Wheel,Image;

	Image = LoadGraph("Res\\A.png");//画像ロード

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {//画面更新 & メッセージ処理 & 画面消去

		Mouse = GetMouseInput();                //マウスの入力状態取得
		Wheel = GetMouseWheelRotVol();  //ホイールの回転量取得
		GetMousePoint(&x, &y);                //マウスの座標取得
		if (Mouse & MOUSE_INPUT_LEFT) { //マウスの左ボタンが押されていたら
			//DrawString(0, 0, "左ボタンが押されています", GetColor(255, 255, 255));
		}
		if (Wheel > 0) {        //ホイールが+方向に回転していたら
			size += 0.1;
		}
		if (Wheel < 0) {        //ホイールが－方向に回転していたら
			size -= 0.1;
		}
		SceneMgr_Update();  //更新
		SceneMgr_Draw();    //描画

		DrawRotaGraph(x, y,size,0.0,Image,TRUE);  //画像をx,yの位置にサイズで描画
	}

	SceneMgr_Finalize();

	DxLib_End(); // DXライブラリ終了処理
	return 0;
}