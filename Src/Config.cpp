#include"Include.h"

static int mImageHandle;    //画像ハンドル格納用変数

							//初期化
void Config_Initialize() {
	mImageHandle = LoadGraph("Res\\title.jpg");//画像のロード
}

//終了処理
void Config_Finalize() {
	DeleteGraph(mImageHandle);//画像の解放
}

