/*
*テキストクラス
*/
#include"Include.h"
#include"UserData.h"

class TextClass {
private:
	//定数
	enum { SceneMax = 20, RowMax = 2048 };//シーン最大数、最大行数
	enum { NORMAL, EYECATCH, BACKLOG, NOTWINDOW, CHANGE, END, TITLE };//描画モードの数

	int Select;
	int MenuEnterFlag;
	int WriteMode;

	int SelectFlag;
	int TextCount;
	int SceneCount;
	int SerifCount;

	bool Selectflg = false;//選択肢出現
	int TextGraphEndflg;//テキスト全文描画完了フラグ

	int LineNo[128][1024];//セリフの行数
	int LineMax[1024];//テキスト総行数

	std::string Name[64][1024];//キャラ名	
	std::string Text[64][1024];//セリフテキスト

	void InitGameCount(UserClass &User);
	struct SaveData_rec SaveData;
public:
	//初期化
	TextClass();
	void InitVar();
	void Load();
	int CutSpace(std::string&tmpText);
	void CheckText(UserClass&User);
	std::vector<std::string>StringSplit(const std::string&Str, char Sep);

	void Main(class UserClass &user);
	void ModeChange(int &ModeFlag, int&ChangeFlg, UserClass&user);

	void NormalWrite(UserClass&user);
	void WriteText(UserClass&user);
	void PutNextLine(UserClass &User);
	void WriteName();

	void CheckRead();
	void ControlRead();
	void ReadUpdate(UserClass&user);

	void SetGameData(UserClass&user);

	void CheckCotrolCode(UserClass &User);
	void BackCheckControlCode(UserClass&user);


};