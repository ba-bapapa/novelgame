#include "DxLib.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	ChangeWindowMode(TRUE); // ウィンドウモードに設定

	DxLib_Init();   // DXライブラリ初期化処理

	LoadGraphScreen(0, 0, "title.jpg", TRUE); // 画像を描画する


	WaitKey();      // キー入力待ち
	DxLib_End();    // DXライブラリ終了処理
	return 0;
}