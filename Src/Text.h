/*
*�e�L�X�g�N���X
*/
#include"Include.h"

class TextClass {
private:
	//�萔
	enum { SceneMax = 20, RowMax = 2048 };//�V�[���ő吔�A�ő�s��
	enum { Normal, EYECATCH, BACKLOG, NOTWINDOW, CHANGE, END, TITLE };//�`�惂�[�h�̐�

	int Select;
	int MenuEnterFlag;
	int WriteMode;

	int TextCount;
	int SceneCount;
	int SerifCount;

	bool Selectflg = false;//�I�����o��
	bool TextGraphEndflg = false;//�e�L�X�g�S���`�抮���t���O

	int LineNo[128][1024];//�Z���t�̍s��
	int LineMax[128][1024];//�e�L�X�g���s��

	std::string Name[64][1024];//�L������	
	std::string Text[64][1024];//�Z���t�e�L�X�g

							   //void InitGameCount(UserClass &user);
							   //struct SaveData_rec SaveData;
public:
	//������
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