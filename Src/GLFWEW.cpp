/**
*@ file GLFWEW.cpp
*/
#include "GLFWEW.h"
#include<iostream>
namespace GLFWEW {
/**
*GLFWからのエラー報告を処理する
*/
	void ErrorCallback(int error, const char*desc) {
		std::cerr << "ERROR:" << desc << std::endl;
	}

/**
*シングルトンインスタンスを取得する
*/
	Window&Window::Instance() {
		static Window instance;
		return instance;
	}


	/**
	*コンストラクタ
	*/
	Window::Window() {

	}
	/**
	*デストラクタ
	*/
	Window::~Window() {
		if (isGLFWInitialized) {
			glfwTerminate();
		}
	}

	/**
	*GLFW/GLEWの初期化
	*/
	bool Window::Init(int w, int h, const char*title) {
		if (isInitialized) {
			std::cerr << "ERROR:GLFWEWは既に初期化されています." << std::endl;
			return false;
		}
		if (!isGLFWInitialized) {
			glfwSetErrorCallback(ErrorCallback);
			if (glfwInit() != GL_TRUE) {
				return false;
			}
			isGLFWInitialized = true;
		}
		if (!window) {
			window = glfwCreateWindow(w, h, title, nullptr, nullptr);
			if (!window) {
				return false;
			}
			glfwMakeContextCurrent(window);
		}
		if (glewInit() != GLEW_OK) {
			std::cerr << "ERROR:GLEWの初期化に失敗しました." << std::endl;
			return false;
		}

		width = w;
		height = h;
		//OpenGLの情報をコンソールウィンドウへ出力する
		const GLubyte*renderer = glGetString(GL_RENDERER);
		std::cout << "Renderer:" << renderer << std::endl;
		const GLubyte*version = glGetString(GL_VERSION);
		std::cout << "Version:" << version << std::endl;

		isInitialized = true;
		return true;
	}
	/**
	*ウィンドウを閉じるべきか調べる
	*/
	bool Window::ShouoldClose() const {
		return glfwWindowShouldClose(window) != 0;
	}
	/**
	*フロントバッファとバックバッファを切り替える
	*/
	void Window::SwapBuffers()const {
		glfwPollEvents();
		
		glfwSwapBuffers(window);
	}
	bool Window::IsKeyPressed(int key)const {
		return glfwGetKey(window, key) == GLFW_PRESS;
	}

	void Window::InitTimer() {
		glfwSetTime(0.0);
		previousTime = 0.0;
		deltaTime = 0.0;
	}
	void Window::UpdateTimer() {
		const double currentTime = glfwGetTime();
		deltaTime = currentTime - previousTime;
		previousTime = currentTime;
		const float upperLimit = 0.25f;
		if (deltaTime > upperLimit) {
			deltaTime = 1.0f / 60.0f;
		}
		UpdateGamePad();
	}

	double Window::DeltaTime()const {
		return deltaTime;
	}

	/**
	*ゲームパッドの状態を取得する
	*/
	const GamePad&Window::GetGamePad() const {
		return gamepad;
	}

	/**
	*ゲームパッドのアナログ入力装置ID
	*/
	enum GAMEPAD_AXES {
		GAMEPAD_AXES_LEFT_X,
		GAMEPAD_AXES_LEFT_Y,
		GAMEPAD_AXES_TRIGGER,
		GAMEPAD_AXES_RIGHT_Y,
		GAMEPAD_AXES_RIGHT_X,
	};

	/**
	*ゲームパッドのデジタル入力装置ID
	*/
	enum GAMEPAD_BUTTON {
		GAMEPAD_BUTTON_A,
		GAMEPAD_BUTTON_B,
		GAMEPAD_BUTTON_X,
		GAMEPAD_BUTTON_Y,
		GAMEPAD_BUTTON_L,
		GAMEPAD_BUTTON_R,
		GAMEPAD_BUTTON_BACK,
		GAMEPAD_BUTTON_START,
		GAMEPAD_BUTTON_L_THUMB,
		GAMEPAD_BUTTON_R_THUMB,
		GAMEPAD_BUTTON_UP,
		GAMEPAD_BUTTON_RIGHT,
		GAMEPAD_BUTTON_DOWN,
		GAMEPAD_BUTTON_LEFT,

	};

	/**
	*ゲームパッドの状態を更新する
	*/
	void Window::UpdateGamePad() {
		const uint32_t prevButtons = gamepad.buttons;

		//アナログ入力とボタン入力を取得
		int axesCount, buttonCount;
		const float*axes = glfwGetJoystickAxes(GLFW_JOYSTICK_1, &axesCount);
		const uint8_t*buttons = glfwGetJoystickButtons(GLFW_JOYSTICK_1,&buttonCount);

		//両方の配列がnullptrでなく、最低限必要なデータ数を満たしていれば勇尾樹奈ゲームパッドが接続される
		if (axes&&buttons&&axesCount >= 2 && buttonCount >= 8) {
			//有効なゲームパッドが接続されている場合
			gamepad.buttons &= ~(GamePad::DPAD_UP | GamePad::DPAD_DOWN | GamePad::DPAD_LEFT | GamePad::DPAD_RIGHT);
			static const float digitalThreshold = 0.3f;
			if (axes[GAMEPAD_AXES_LEFT_Y] >= digitalThreshold) {
				gamepad.buttons |= GamePad::DPAD_UP;
			}
			else if (axes[GAMEPAD_AXES_LEFT_Y] <= -digitalThreshold) {
				gamepad.buttons |= GamePad::DPAD_DOWN;
			}
			if (axes[GAMEPAD_AXES_LEFT_X] >= digitalThreshold) {
				gamepad.buttons |= GamePad::DPAD_LEFT;
			}
			else if (axes[GAMEPAD_AXES_LEFT_X] <= -digitalThreshold) {
				gamepad.buttons |= GamePad::DPAD_RIGHT;
			}

			//配列インデックスとGamePadキーの対応表
			static const struct {
				int dataIndex;
				uint32_t gamepadBit;
			}keyMap[]={
				{GAMEPAD_BUTTON_A,GamePad::A},
				{GAMEPAD_BUTTON_B,GamePad::B},
			{ GAMEPAD_BUTTON_X,GamePad::X },
			{ GAMEPAD_BUTTON_Y,GamePad::Y },
			{ GAMEPAD_BUTTON_L,GamePad::L },
			{ GAMEPAD_BUTTON_R,GamePad::R },
			{ GAMEPAD_BUTTON_START,GamePad::START },
			{ GAMEPAD_BUTTON_UP,GamePad::DPAD_UP },
			{ GAMEPAD_BUTTON_DOWN,GamePad::DPAD_DOWN },
			{ GAMEPAD_BUTTON_LEFT,GamePad::DPAD_LEFT },
			{ GAMEPAD_BUTTON_RIGHT,GamePad::DPAD_RIGHT },
		};
			for (const auto&e : keyMap) {
				if (buttons[e.dataIndex] == GLFW_PRESS) {
					gamepad.buttons |= e.gamepadBit;
				}
				else if (buttons[e.dataIndex] == GLFW_RELEASE) {
					gamepad.buttons &= ~e.gamepadBit;
				}
			}
		}
		else {
			//有効なゲームパッドが接続されていないのでキーボードで入力

			//配列インデックスとgamePadキーの対応表
			static const struct {
				int keyCode;
				uint32_t gamepadBit;
			}keyMap[]{
				{GLFW_KEY_J,GamePad::A},
			{ GLFW_KEY_K,GamePad::B },
			{ GLFW_KEY_U,GamePad::X },
			{ GLFW_KEY_I,GamePad::Y },
			{ GLFW_KEY_O,GamePad::L },
			{ GLFW_KEY_L,GamePad::R },
			{ GLFW_KEY_ENTER,GamePad::START },
			{ GLFW_KEY_W,GamePad::DPAD_UP },
			{ GLFW_KEY_A,GamePad::DPAD_LEFT },
			{ GLFW_KEY_S,GamePad::DPAD_DOWN},
			{ GLFW_KEY_D,GamePad::DPAD_RIGHT },
		};
			for (const auto&e : keyMap) {
				const int key = glfwGetKey(window, e.keyCode);
				if (key == GLFW_PRESS) {
					gamepad.buttons |= e.gamepadBit;
				}
				else if (key == GLFW_RELEASE) {
					gamepad.buttons &= ~e.gamepadBit;
				}
			}
		}
		//前回の更新で押されていなくて今回押されているキーの情報をbuttonDownに格納
		gamepad.buttonDown = gamepad.buttons&~prevButtons;
	}
}//namespace GLFWEW
