#include"Include.h"
//���[�U�N���X

class UserClass {
private:

	int PageFlag;//���̃y�[�W
	struct SaveData_rec SaveData;//�Z�[�u�f�[�^
	struct ConfigData_rec ConfigData;//�R���t�B�O
	int BGM;
	int BackGround;
	int Char;
	bool SecretFlag;

public:
	UserClass();
	void SetPage(int Page);//�֐�������
	int GetPage();
	void SetSaveData(SaveData_rec&SaveData);
	SaveData_rec GetSaveData();
	void LoadConfigData();
	void SaveConfigData();
	void SetConfigData(ConfigData_rec&ConfigDatya);
	ConfigData_rec SetConfigData();

	//�e�R���t�B�O�f�[�^��Ԃ�
	int  GetTextSpeed();
	int  GetAutoTextSpeed();
	int  GetSkipFlag();
	int  GetBGMVol();
	int  GetSEVol();

	//���Ǌ֌W
	void ReadUpdate();

	//�T�E���h�R�[�h
	void SetBGMCode(int Code);
	int  GetBGMCode();

	//�w�i�R�[�h
	void SetBackCode(int Code);
	int  GetBackCode();

	//�L�����N�^�R�[�h
	void SetCharacterCode(int Code);
	int  GetCharacterCode();

	//�V�[�N���b�g�t���O
	void SetSecretFlag();
	bool GetSecretFlag();

};

