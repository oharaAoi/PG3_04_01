#include "ClearScene.h"
#include "Novice.h"
#include "Manager/InputManager.h"

ClearScene::ClearScene() {
}

ClearScene::~ClearScene() {
}

void ClearScene::Init() {
	textureHandle_ = Novice::LoadTexture("./Resources/clear.png");
}

void ClearScene::Update() {
	if (InputManager::IsTriggerKey(DIK_SPACE)) {
		sceneNo_ = SCENE::TITLE;
	}
}

void ClearScene::Draw() {
	Novice::DrawSprite(0, 0, textureHandle_, 1.0f, 1.0f, 0.0f, WHITE);
}
