#include"MainGameScene.h"
#include"StatusScene.h"
#include"GameOverScene.h"
#include"GLFWEW.h"


/**
*シーンを初期化する
*/
bool MainGameScene::Initialize() {
	spriteRenderer.Init(1000, "Res/Sprite.vert", "Res/Sprite.frag");
	sprites.reserve(100);
	Sprite spr(Texture::Image2D::Create("Res/tree.tga"));
	spr.Scale(glm::vec2(2));
	sprites.push_back(spr);
	return true;
}

void MainGameScene::ProcessInput() {
	if (!flag) {
		GLFWEW::Window&window = GLFWEW::Window::Instance();
		if (window.GetGamePad().buttonDown&GamePad::START) {
			flag = true;
			SceneStack::Instance().push(std::make_shared<StatusScene>());
		}
	}
	else {
		GLFWEW::Window&window = GLFWEW::Window::Instance();
		if (window.GetGamePad().buttonDown&GamePad::START) {
			SceneStack::Instance().Replace(std::make_shared<GameOverScene>());
		}
	}
}

/**
*シーンを更新する
*/
void MainGameScene::Update(float deltaTime) {
	spriteRenderer.BeginUpdate();
	for (const Sprite&e : sprites) {
		spriteRenderer.AddVertices(e);
	}
	spriteRenderer.EndUpdate();
}
/**
*シーンを描画する
*/

void MainGameScene::Render()
{
	const GLFWEW::Window& window = GLFWEW::Window::Instance();
	const glm::vec2 screenSize(window.Width(), window.Height());
	spriteRenderer.Draw(screenSize);
}