#include"Include.h"
//���[�U�N���X
struct SaveData_rec {
	short int   SceneCount;	//�V�[���J�E���g
	short int   TextCount;	//�e�L�X�g�J�E���g
	short int   SerifCount;	//�Z���t�J�E���g
	int         BGMCode;	//BGM�R�[�h
	int         BackCode;	//�w�i�R�[�h
	int			CharCode;	//�L�����N�^�[�R�[�h
	int			Year;		//�N
	int			Mon;		//��
	int			Day;		//��
	int         TextLength;	//�e�L�X�g�̕�����(�o�C�g��)
	char		Text[61];	//�e�L�X�g1�s(�����100%�ޯ̧���ް�۰�̌��ɂȂ邩��Astd::string�ɂ��Ă������ƁI)
};

class UserClass {
private:

	int PageFlag;//���̃y�[�W
//	struct SaveData_rec SaveData;//�Z�[�u�f�[�^
	//struct ConfigData_rec ConfigData;//�R���t�B�O
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
//	void SetConfigData(ConfigData_rec&ConfigDatya);
	//ConfigData_rec SetConfigData();

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

