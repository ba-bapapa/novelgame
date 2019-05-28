#include "DxLib.h"

// サウンドノベル風文字列描画基本
#include "DxLib.h"

// 文字のサイズ
#define MOJI_SIZE 24

int DrawPointX, DrawPointY;	// 文字列描画の位置
int SP, CP;	// 参照する文字列番号と文字列中の文字ポインタ

char String[][256] =
{
	"　ゲームプログラムとは、いやプログラムとは" ,
	"ある事柄を実現するプログラムの方法を説明されても理解できないことがある。B" ,
	"@　なぜならそのプログラム技法も何かの基本的な技法の組み合わせで出来ているからだ。B",
	"@　これはその他の学問も基本がわからないと応用が利かないということと同じ現象で、",
	"別に特に珍しいことでもない。B" ,
	"C　しかしゲームプログラムとなると覚えなくてはならない基礎が沢山あり、" ,
	"さらにある程度クオリティの高いソフトを作ろうとすると色々なプログラム技法を",
	"習得しなくてはならない。B" ,
	"@　しかもある程度レベルが高くなると自分で技法を編み出すか、技術レベルの高い",
	"プログラマーに聞くなどするしか方法がなく大変厄介である。B"
	"というかそのせいでゲームプログラムの敷居は高くなっているといえる。BE"
};

// 改行関数
int Kaigyou(void)
{
	int TempGraph;

	// 描画行位置を一つ下げる
	DrawPointY++;

	// 描画列を最初に戻す
	DrawPointX = 0;

	// もし画面からはみ出るなら画面をスクロールさせる
	if (DrawPointY * MOJI_SIZE + MOJI_SIZE > 480)
	{
		// テンポラリグラフィックの作成
		TempGraph = MakeGraph(640, 480);

		// 画面の内容を丸々コピーする
		GetDrawScreenGraph(0, 0, 640, 480, TempGraph);

		// 一行分上に貼り付ける
		DrawGraph(0, -MOJI_SIZE, TempGraph, FALSE);

		// 一番下の行の部分を黒で埋める
		DrawBox(0, 480 - MOJI_SIZE, 640, 480, 0, TRUE);

		// 描画行位置を一つあげる
		DrawPointY--;

		// グラフィックを削除する
		DeleteGraph(TempGraph);
	}

	// 終了
	return 0;
}