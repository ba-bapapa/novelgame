#define _CRT_SECURE_NO_WARNINGS

#include"Include.h"


//テキストクラス

  /*初期化処理*/
TextClass::TextClass() {
	Initialze();		//変数初期化
	Load();	//ストーリ読み込み
}

/*変数初期化*/
void TextClass::Initialze () {
	//メンバ変数初期化
	SelectFlag = 1;
	Select = -1;
	AutoFlag = -1;
	TextCount = 0;
	SceneCount = 0;
	SerifCount = 0;
	SelectFlag = 0;
	WriteMode = NORMAL;
	TextGraphEndflg	= false;
	memset(LineMax, 0, sizeof(LineMax));
	memset(LineNo, 0, sizeof(LineNo));
	memset(Text, '\0', sizeof(Text));
	memset(Name, '\0', sizeof(Name));
}

/*ストーリーロード*/
void TextClass::Load() {
	//真の変数
	int							FileHandle;			//ファイルハンドル
	char						TmpBuf[128];		//テキスト取得用一時変数
	char						FileName[64];		//ファイル名格納
	std::string					TmpText;			//テキスト取得後操作用一時オブジェクト 
	std::vector<std::string>	SplitTextArray;		//分割された文字を格納する配列

	//カウンタ
	int	Count = 0;									//カウンタ
	int	Scene = 0;									//シーンカウンタ

	//行数管理
	int SerifNo = -1;								//セリフのナンバーを格納(最初は必ず加算されるので、初期値は負の数にしておく)

	//定数
	const int LoadTextLen = 128;					//読み込むテキストの文字数
	const int NAME = 0;						//分割された文字列を格納する配列に関するもの
	const int TEXT = 1;						//分割された文字列を格納する配列に関するもの


	//SceneMax(定数)までロード
	while (Scene <= SceneMax) {

		//ファイル名を取得
		sprintf(FileName, "Res\\test.txt");

		//ファイルオープン
		FileHandle = FileRead_open(FileName);

		//ファイル終端までループ
		while (FileRead_eof(FileHandle) == 0) {
			//ファイルから一行取得
			FileRead_gets(TmpBuf, LoadTextLen, FileHandle);

			//一文字目が '\0' なら空行と判断しスキップ
			if (TmpBuf[0] == '\0') continue;

			//char型配列のTmpBufをStringオブジェクトのTmpTextに変換
			TmpText = TmpBuf;

			//TmpTextの一文字目が'\0'ならば空行と判断しスキップ
			if (TmpText[0] == NULL) continue;

			//全角･半角スペースを除去
			CutSpace(TmpText);

			//TmpTextの一文字目が'\0'ならば空行と判断しスキップ
			if (TmpText[0] == '\0') continue;

			//TmpTextをNameとTextに分割
			SplitTextArray = StringSplit(TmpText, ':');

			//分割された文字列をNameとTextに代入
			Name[Scene][Count] = SplitTextArray[NAME];
			Text[Scene][Count] = SplitTextArray[TEXT];

			//Nameが"コメント"ならコメントと判断しスキップ
			if (Name[Scene][Count] == "コメント") continue;

			
			//Textが'\0'なら前のテキストの続きと判断し、Nameに続きと代入し、TextにName(一行全て入ってる)の内容をコピー ＆ 行数加算
			//それ以外ならば次のテキストと判断し、SerifNoを加算し、行数加算
			if (Text[Scene][Count] == "\0") {
				Text[Scene][Count] = Name[Scene][Count];
				Name[Scene][Count] = "続き";
				LineNo[Scene][SerifNo]++;
			}
			else {
				SerifNo++;
				LineNo[Scene][SerifNo]++;
			}

			//最大行数加算
			LineMax[Scene]++;

			//カウントを進める
			Count++;
		}

		//シーンカウントを進める
		Scene++;

		//カウント初期化
		Count = 0;
		SerifNo = -1;

	}

}

/*文字列分割*/
std::vector<std::string> TextClass::StringSplit(const std::string &Str, char Sep) {
	//いろいろ宣言
	std::vector<std::string> V;
	std::stringstream Ss(Str);
	std::string Buffer;

	const std::string EndOfText = "\0";

	//文字列分割
	while (std::getline(Ss, Buffer, Sep)) V.push_back(Buffer);

	//終端文字 '\0' を挿入
	V.push_back(EndOfText);

	return V;
}

/*テキストからスペースを取り除く*/
int TextClass::CutSpace(std::string &TmpText) {
	//変数宣言
	int  i = 0;				//空白除去処理に使うカウンタ
	char TmpStr[3];		   	//空白除去処理につかう一時変数

	const int BigSpaceSize = 2; //全角スペースのサイズ

	//全角空白を取り除く処理
	if (TmpText.length() >= BigSpaceSize) {
		do {
			if (TmpText.length() <= i) {
				TmpText[0] = '\0';
				return 0;
			}
			TmpStr[0] = TmpText[i];
			TmpStr[1] = TmpText[i + 1];
			TmpStr[2] = '\0';
			i += 2;
		} while (strcmp(TmpStr, "　") == 0);
		TmpText = &TmpText[i - 2];
	}

	//半角スペースを取り除く処理
	i = 0;
	while (TmpText[i] == ' ') {
		//文字数を超えないようなコーディングをしろ(上参照)

		i++;
		if (TmpText.length() <= i) {
			TmpText[0] = '\0';
			return 0;
		}
	}
	TmpText = &TmpText[i];

}

/*メイン関数*/
void TextClass::Main(UserClass &User) {
	//メニューパラメータセット
	
	//定数
	const int OtherSelect = 6;


	//ゲームカウントの初期化
	InitGameCount(User);

	//テキストチェック
	CheckText(User);

	//制御コードチェック
	if (WriteMode != EYECATCH) CheckCotrolCode(User);

	
	//テキスト描画
	if (WriteMode == NORMAL) NormalWrite(User);	//通常テキスト描画

}

/*モードチェンジ*/
void TextClass::ModeChange(int &ModeFlag, int &ChangeFlag, UserClass &User) {
	//インスタンス化
	/*MouseClass* Mouse = MouseClass::GetInstance();
	AnimeClass Anime;*/

	static int Count = 0;

	const int AtherSelect = -1;

	//タイマー
	static int Timer = 0;
	if (WriteMode != NOTWINDOW) Timer++;

	//モードチェンジ
	

	

	//バックログ
	//if (Mouse->GetWheel() > 0 && WriteMode == NORMAL) WriteMode = BACKLOG;

	//エンディングモードへ
	if (WriteMode == END) { //&& Mouse->GetState(MOUSE::LEFT) > 10 ){
		Select = AtherSelect;
		WriteMode = NORMAL;
		//ModeFlag = MODE::END;
		//ModeFlag = MODE::OTHER;
		//User.SetPage( PAGE::TITLE );
	}

	//タイトル画面へ
	if (WriteMode == TITLE) {
		

	}
}

/*ゲームカウント初期化*/
void TextClass::InitGameCount(UserClass& User) {
	//ゲームカウント取得
	/*SaveData = User.GetSaveData();
	SceneCount = SaveData.SceneCount;
	TextCount = SaveData.TextCount;
	SerifCount = SaveData.SerifCount;
	User.SetBGMCode(SaveData.BGMCode);
	User.SetBackCode(SaveData.BackCode);
	User.SetCharacterCode(SaveData.CharCode);*/
}

/*様々なテキストチェック*/
void TextClass::CheckText(UserClass &User) {
	//メニュー決定フラグを折っておく
	MenuEnterFlag = 0;

	const int AtherSelect = -1;

	//一回目フラグ
	static bool FirstFlag = FALSE;

	//シーンの終わりなら、次のシーンへ(カウント更新)
	if (TextCount >= LineMax[SceneCount]) {
		SceneCount++;
		TextCount = 0;
		SerifCount = 0;

		//ユーザークラスに渡す
		SaveData.SceneCount = SceneCount;
		SaveData.TextCount = TextCount;
		SaveData.SerifCount = SerifCount;
	//	User.SetSaveData(SaveData);

		//アイキャッチを動作させる
		WriteMode = EYECATCH;
	}

	//シーンのはじめにアイキャッチを動作させる
	/*if (SceneCount == 0 && TextCount == 0 && FirstFlag == FALSE) {
		Select = AtherSelect;
		WriteMode = EYECATCH;
		FirstFlag = TRUE;
	}
	if (TextCount > 0) FirstFlag = FALSE;

	*/
}

/*テキスト通常描画*/
void TextClass::NormalWrite(UserClass &User) {
	//インスタンス取得
	KeyClass* Key = KeyClass::GetInstance();
	MouseClass* Mouse = MouseClass::GetInstance();

	//テキスト描画
	WriteText(User);

	//名前描画
	WriteName();

	//ゲームカウント更新
	//User.SetSaveData(SceneCount,TextCount,SerifCount);
}

/*テキスト描画*/
void TextClass::WriteText(UserClass &User) {
	//変数宣言
	static int  WriteCount = 0;					//書き込み時カウント
	static int  WriteIndex[3] = { 0,0,0 };			//現在何文字目か
	static int  WriteX = 0;							//書き込みX軸座標
	static int  WriteY = 0;							//書き込みY座標
	static int  OldTextCount;						//前のテキストカウントを取得
	static int  WriteLine;							//描画する行
	int  Length;									//文字数
	int  TmpCount = 0;								//一時カウンタ
	int  LoopCount = 0;								//ループ用カウンタ
	char WriteText[3];								//書き込み文字

	//定数定義	
	const int DrawX = 250;							//描画基準Ｘ座標						
	const int DrawY =600 - 600 / 3 + 50;	//描画基準Ｙ座標
	const int TextSpace = 14;							//文字と文字の間隔
	const int LineSpace = 40;							//行と行の間隔
	const int FontSize = 28;							//フォントサイズ
	int DrawSpeed ;										//文字の描画速度
	

	
	//文字の描画速度を取得
	DrawSpeed = User.GetTextSpeed();


	//テキストが進んだら変数初期化
	if (TextCount != OldTextCount) {
		memset(WriteIndex, 0, sizeof(WriteIndex));
		WriteCount = 0;
		WriteX = 0;
		WriteY = 0;
		WriteLine = 0;
	}
	//前のテキストカウントを取得(上の初期化のため)
	OldTextCount = TextCount;

	//フォントサイズ
	//SetFontSize(FontSize);

	//現在表示されている文字数だけ表示する(Lineは行数を示し、最大行数分ループする)
	for (int Line = 0; Line < LineNo[SceneCount][SerifCount]; Line++) {

		//描画が完了している行まで描画
		if (Line <= WriteLine) {
			LoopCount = 0;																								//ループカウンタ初期化
			while (LoopCount <= WriteIndex[Line]) {																		//書き込み可能文字数以下なら
				WriteX = LoopCount * TextSpace;																			//描画X座標更新
				WriteText[0] = Text[SceneCount][TextCount + Line][LoopCount];												//1byte目代入
				WriteText[1] = Text[SceneCount][TextCount + Line][LoopCount + 1];											//2byte目代入
				WriteText[2] = '\0';																					//ヌル文字を代入
				//DrawStringToHandle(DrawX+WriteX,DrawY + ( LineSpace * Line ),WriteText,GetColor(200,200,200),TextFontHandle);	//一文字描画
				//DrawStringShadow(DrawX + WriteX, DrawY + (LineSpace * Line), WriteText, GetColor(233, 233, 233), GetColor(5, 5, 5));
				LoopCount += 2;																							//一文字分カウントアップ
			}

			Length = Text[SceneCount][TextCount + Line].length() - 2;

			//文字列の終端ならば、書き込み行数を更新
			if (Length <= WriteIndex[Line]) {
				WriteLine = Line + 1;					//文字列の終端ならば、書き込み行数を更新
			}
			else if (WriteCount % DrawSpeed == 0) WriteIndex[Line] += 2;


			//もしも全文描画終了フラグが立っているならば,描画カウントを最大にする(文字数を代入)
			if (TextGraphEndflg == 1) {
				WriteIndex[Line] = Length;
			}
		}
	}

	//描画タイミング動機用
	WriteCount++;

	//テキストが全て描画されたら、全文描画終了フラグを立てる
	if (WriteLine == LineNo[SceneCount][SerifCount]) TextGraphEndflg = 1;

}

/*名前描画*/
void TextClass::WriteName() {
	//定数定義
	const int DrawX = 200;
	const int DrawY = 600 - 600 / 3 + 10;

	//Nameが主人公なら、空文字を代入(地の文なので名前を表示させない)
	if (Name[SceneCount][TextCount] == "主人公") {
		Name[SceneCount][TextCount][0] = '\0';
	}

	//名前描画
	//DrawStringShadow(DrawX, DrawY, Name[SceneCount][TextCount].c_str(), GetColor(233, 233, 233), GetColor(5, 5, 5));
}

/*次の行へ進める*/
void TextClass::PutNextLine(UserClass &User) {
	//インスタンス取得
	KeyClass*   Key = KeyClass::GetInstance();
	MouseClass* Mouse = MouseClass::GetInstance();

	//エンターが押されて、テキストが表示し終わって、メニューを選択していないなら、カウントを進める
	if ((Key->GetState(KEY_INPUT_RETURN) == 1 || /*Mouse->GetState(MOUSE::LEFT) == 1 ||*/ Mouse->GetWheel() < 0) && MenuEnterFlag != 1) {
		//テキスト表示完了フラグが立っていればカウントを進める
		if (TextGraphEndflg == 1) {

			//テキストカウントを現在の行数分進める
			//TextCount        += RowNo;
			TextCount += LineNo[SceneCount][SerifCount];

			//Graph.Draw();

			//セリフカウントを進める
			SerifCount++;

			//テキスト表示完了フラグ
			TextGraphEndflg = 0;

			//現在カウントを更新
			//User.SetSaveData(SceneCount,TextCount,SerifCount);

		}
		else {
			TextGraphEndflg = 1;
		}
	}
}

void TextClass::CheckRead() {

}

/*制御コードチェック*/
void TextClass::CheckCotrolCode(UserClass &User) {
	//各種コード受け取り変数
	std::string BGMCode;
	std::string BackCode;
	std::string EventCode;
	std::string CharacterCode;

	bool EventFlag = FALSE;

	do {

		EventFlag = FALSE;


		
		//時間経過
		if (Name[SceneCount][TextCount] == "イベント") {
			EventCode = Text[SceneCount][TextCount];
			//if (EventCode == "経過") OverTime(User);
			if (EventCode == "タイトルへ") {
				WriteMode = TITLE;
			}
		}

		//エンド
		if (Name[SceneCount][TextCount] == "エンド") {
			TextCount++;
			SerifCount++;
			WriteMode = END;
		}

	} while (EventFlag == TRUE);
}

/*バックログから戻ったときに前の制御コードを取得*/
void TextClass::BackCheckControlCode(UserClass &User) {
	int TmpSceneCount, TmpTextCount;
	bool BGMFlag = FALSE;
	bool BackFlag = FALSE;
	bool CharFlag = FALSE;
	std::string BGMCode;
	std::string BackCode;
	std::string CharacterCode;

	TmpSceneCount = SceneCount;
	TmpTextCount = TextCount;

	//曲をいったん停止
	//User.SetBGMCode(GAME_BGM::STOP);
	//User.SetCharacterCode(GAME_CHAR::NOT);

	while (TmpTextCount >= 0) {
		

		//カウントを下げる
		TmpTextCount--;

	

		//全てのコードが確認されたら処理を抜ける
		if (BGMFlag == TRUE && BackFlag == TRUE && CharFlag == TRUE) break;

	}
}