#include "Include.h"


int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK); //ウィンドウモード変更と初期化と裏画面設定

	SceneMgr_Initialize();


	int Handle, Count = 0;
	Handle = LoadSoundMem("Res/073.mp3"); // サウンド/1up.wavをロードし、識別番号をHandleに格納

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {//画面更新 & メッセージ処理 & 画面消去

		
		SceneMgr_Update();  //更新
		SceneMgr_Draw();    //描画
		if (Count % 120 == 0) { // 2秒に一度
			PlaySoundMem(Handle, DX_PLAYTYPE_BACK); // 効果音を再生する
		}
		Count++;

	}

	SceneMgr_Finalize();

	DxLib_End(); // DXライブラリ終了処理
	return 0;
}