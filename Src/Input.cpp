#include"Include.h"

//�L�[�N���X
KeyClass*KeyClass::GetInstance() {
	static KeyClass i;
	return &i;
}

//�L�[���
void KeyClass::SetHitKey(){
	char Tmpkey[256];

	GetHitKeyStateAll(Tmpkey);
	for (int i = 0; i < 256; ++i) {
		if (Tmpkey[i] == 1) {
			KeyState[i]++;
		}
		else {
			KeyState[i] = 0;
		}
	}
}

//�w�肳�ꂽ�L�[��Ԃ�Ԃ�
int KeyClass::GetState(int KeyCode) {
	return KeyState[KeyCode];
}

//�}�E�X�N���X
MouseClass*MouseClass::GetInstance() {
	static MouseClass i;
	return &i;
}

//�}�E�X�̏��
void MouseClass::SetHitMouse() {
	if (GetMouseInput()&MOUSE_INPUT_LEFT) {
		MouseState[LeftClick]++;
	}
	else {
		MouseState[LeftClick] = 0;
	}
	if (GetMouseInput()&MOUSE_INPUT_RIGHT) {
		MouseState[RightClick]++;
	}
	else {
		MouseState[RightClick] = 0;
	}
	
	GetMousePoint(&MouseX, &MouseY);
	MouseWheel = GetMouseWheelRotVol();
}

void MouseClass::GetPoint(int*x, int*y) {

	*x = MouseX;
	*y = MouseY;
}

void MouseClass::GetPointX(int &x) {
	x = MouseX;
}

void MouseClass::GetPointY(int&y) {
	y = MouseY;
}

int MouseClass::GetWheel() {
	return MouseWheel;
}

int MouseClass::GetState(int MouseCode) {
	return MouseState[MouseCode];
}

