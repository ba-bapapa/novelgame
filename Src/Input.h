
//キークラス
class KeyClass {
private:
	int KeyState[256];
	KeyClass(){}
public:
	static KeyClass*GetInstance();
	void SetHitKey();
	int GetState(int KeyCode);
};

//マウスクラス
class MouseClass {
	enum {
		LeftClick,RightClick
	};
private:
	int MouseX;
	int MouseY;
	int MouseState[2];
	int MouseWheel;
	MouseClass(){}

public:
	static MouseClass*GetInstance();
	void SetHitMouse();
	void GetPoint(int*x, int*y);
	void GetPointX(int&x);
	void GetPointY(int&y);
	int GetWheel();
	int GetState(int MouseCode);
};
