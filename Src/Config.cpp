#include"Include.h"

static int mImageHandle;    //�摜�n���h���i�[�p�ϐ�

							//������
void Config_Initialize() {
	mImageHandle = LoadGraph("Res\\title.jpg");//�摜�̃��[�h
}

//�I������
void Config_Finalize() {
	DeleteGraph(mImageHandle);//�摜�̉��
}

