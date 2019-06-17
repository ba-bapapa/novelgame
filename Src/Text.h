/*
*�e�L�X�g�N���X
*/
#include"Include.h"
#include"UserData.h"

class TextClass {
private:
	//�萔
	enum { SceneMax = 20, RowMax = 2048 };//�V�[���ő吔�A�ő�s��
	enum { NORMAL, EYECATCH, BACKLOG, NOTWINDOW, CHANGE, END, TITLE };//�`�惂�[�h�̐�

	int Select;
	int MenuEnterFlag;
	int WriteMode;

	int SelectFlag;
	int TextCount;
	int SceneCount;
	int SerifCount;

	bool Selectflg = false;//�I�����o��
	int TextGraphEndflg;//�e�L�X�g�S���`�抮���t���O

	int LineNo[128][1024];//�Z���t�̍s��
	int LineMax[1024];//�e�L�X�g���s��

	std::string Name[64][1024];//�L������	
	std::string Text[64][1024];//�Z���t�e�L�X�g

	void InitGameCount(UserClass &User);
	struct SaveData_rec SaveData;
public:
	//������
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