void Menu_Initialize();//初期化
void Menu_Finalize();//終了処理
void Menu_Update();//更新
void Menu_Draw();//描画

				 //プロトタイプ宣言
void initSelectBox();
int isContainMousePointer(int x, int y, int width, int height);
void drawSelectBox();
void setSelectBoxMessage(const char* message1, const char* message2);
int isClickedSelectBox();

