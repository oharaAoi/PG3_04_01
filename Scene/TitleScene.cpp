#include "TitleScene.h"
#include "Novice.h"
#include "Manager/InputManager.h"

TitleScene::TitleScene() {
}

TitleScene::~TitleScene() {
}

void TitleScene::Init() {
	textureHandle_ = Novice::LoadTexture("./Resources/title.png");
}

void TitleScene::Update() {
	if (InputManager::IsTriggerKey(DIK_SPACE)) {
		sceneNo_ = SCENE::STAGE;
	}
}

void TitleScene::Draw() {
	Novice::DrawSprite(0, 0, textureHandle_, 1.0f, 1.0f, 0.0f, WHITE);
}
