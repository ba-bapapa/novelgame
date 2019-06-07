#include "TitleScene.h"
#include"MainGameScene.h"
#include"GLFWEW.h"


/**
*�V�[��������������
*/
bool TitleScene::Initialize() {
	spriteRenderer.Init(1000, "Res/Sprite.vert", "Res/Sprite.frag");
	sprites.reserve(100);
	Sprite spr(Texture::Image2D::Create("Res/title.tga"));
	Sprite spr2(Texture::Image2D::Create("Res/sta.tga"));
	spr.Scale(glm::vec2(2));
	sprites.push_back(spr);
	sprites.push_back(spr2);
	fontRenderer.Init(1000);
	fontRenderer.LoadFromFile("Res/font.fnt");

	
	return true;
}

void TitleScene::ProcessInput() {
	GLFWEW::Window&window = GLFWEW::Window::Instance();
	if (window.GetGamePad().buttonDown&GamePad::START) {
		SceneStack::Instance().Replace(std::make_shared<MainGameScene>());
	}
	//if (!isFinish && timer <= 0.0f) {
		//if (window.IsKeyPressed(GLFW_KEY_ENTER)) {
			//NextScene("MainGameScene");
			//isFinish = true;
		//}
	//}
}

/**
*�V�[�����X�V����
*/
void TitleScene::Update(float deltaTime) {
	spriteRenderer.BeginUpdate();
	for (const Sprite&e : sprites) {
		spriteRenderer.AddVertices(e);
	}
	spriteRenderer.EndUpdate();
		const GLFWEW::Window& window = GLFWEW::Window::Instance();
		const float w = window.Width();
		const float h = window.Height();
		const float lineHeight = fontRenderer.LineHeight();
		fontRenderer.BeginUpdate();
		fontRenderer.AddString(glm::vec2(-w * 0.5f + 32, h * 0.5f - lineHeight), L"�^�C�g�����");
		fontRenderer.AddString(glm::vec2(-128, 0), L"�M�����Q�[");
		fontRenderer.AddString(glm::vec2(500, 0), L"�͂��߂�");
		fontRenderer.AddString(glm::vec2(500, -50), L"�߂�");
		fontRenderer.EndUpdate();
	
}
/**
*�V�[����`�悷��
*/

void TitleScene::Render()
{
	const GLFWEW::Window& window = GLFWEW::Window::Instance();
	const glm::vec2 screenSize(window.Width(), window.Height());
	spriteRenderer.Draw(screenSize);
	fontRenderer.Draw(screenSize);

}