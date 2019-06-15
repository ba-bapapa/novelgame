/*
*テキストクラス
*/
#include"Include.h"

class TextClass {
private:
	//定数
	enum { SceneMax = 20, RowMax = 2048 };//シーン最大数、最大行数
	enum { Normal, EYECATCH, BACKLOG, NOTWINDOW, CHANGE, END, TITLE };//描画モードの数

	int Select;
	int MenuEnterFlag;
	int WriteMode;

	int TextCount;
	int SceneCount;
	int SerifCount;

	bool Selectflg = false;//選択肢出現
	bool TextGraphEndflg = false;//テキスト全文描画完了フラグ

	int LineNo[128][1024];//セリフの行数
	int LineMax[128][1024];//テキスト総行数

	std::string Name[64][1024];//キャラ名	
	std::string Text[64][1024];//セリフテキスト

							   //void InitGameCount(UserClass &user);
							   //struct SaveData_rec SaveData;
public:
	//初期化
	TextClass();
	void InitVar();
	void Load();
	int CutSpace(std::string&tmpText);
	//void CheckText(UserClass&User);
	std::vector<std::string>StringSplot(const std::string&Str, char Sep);

	void main(class UserClass &user);
	void modeChange(int &ModeFlag, int&ChangeFlg, UserClass&user);

	void NormalWrite(UserClass&user);
	void WriteText(UserClass&user);
	void WriteName();

	void ReadUpdate(UserClass&user);

	void SetGameData(UserClass&user);

	void CheckControlCode(UserClass&user);
	void BackCheckControlCode(UserClass&user);


};