void Menu_Initialize();//������
void Menu_Finalize();//�I������
void Menu_Update();//�X�V
void Menu_Draw();//�`��

				 //�v���g�^�C�v�錾
void initSelectBox();
int isContainMousePointer(int x, int y, int width, int height);
void drawSelectBox();
void setSelectBoxMessage(const char* message1, const char* message2);
int isClickedSelectBox();

