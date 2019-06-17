#include"Include.h"
//ユーザクラス
struct SaveData_rec {
	short int   SceneCount;	//シーンカウント
	short int   TextCount;	//テキストカウント
	short int   SerifCount;	//セリフカウント
	int         BGMCode;	//BGMコード
	int         BackCode;	//背景コード
	int			CharCode;	//キャラクターコード
	int			Year;		//年
	int			Mon;		//月
	int			Day;		//日
	int         TextLength;	//テキストの文字数(バイト数)
	char		Text[61];	//テキスト1行(これは100%ﾊﾞｯﾌｧｵｰﾊﾞｰﾌﾛｰの元になるから、std::stringにしておくこと！)
};

class UserClass {
private:

	int PageFlag;//今のページ
//	struct SaveData_rec SaveData;//セーブデータ
	//struct ConfigData_rec ConfigData;//コンフィグ
	int BGM;
	int BackGround;
	int Char;
	bool SecretFlag;

public:
	UserClass();
	void SetPage(int Page);//関数初期化
	int GetPage();
	void SetSaveData(SaveData_rec&SaveData);
	SaveData_rec GetSaveData();
	void LoadConfigData();
	void SaveConfigData();
//	void SetConfigData(ConfigData_rec&ConfigDatya);
	//ConfigData_rec SetConfigData();

	//各コンフィグデータを返す
	int  GetTextSpeed();
	int  GetAutoTextSpeed();
	int  GetSkipFlag();
	int  GetBGMVol();
	int  GetSEVol();

	//既読関係
	void ReadUpdate();

	//サウンドコード
	void SetBGMCode(int Code);
	int  GetBGMCode();

	//背景コード
	void SetBackCode(int Code);
	int  GetBackCode();

	//キャラクタコード
	void SetCharacterCode(int Code);
	int  GetCharacterCode();

	//シークレットフラグ
	void SetSecretFlag();
	bool GetSecretFlag();

};

