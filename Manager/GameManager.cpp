#include "GameManager.h"
#include <Novice.h>
#include "Scene/TitleScene.h"
#include "Scene/StageScene.h"
#include "Scene/ClearScene.h"

GameManager::GameManager() {
	sceneArray[TITLE] = std::make_unique<TitleScene>();
	sceneArray[STAGE] = std::make_unique<StageScene>();
	sceneArray[CLEAR] = std::make_unique<ClearScene>();

	IScene::SetSceneNo(TITLE);

	input_ = InputManager::GetInstance();
}

GameManager::~GameManager() {
}

void GameManager::Run() {
	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		input_->Update();

		///
		/// ↓更新処理ここから
		///
		sceneArray[currentSceneNo_]->Update();
		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		sceneArray[currentSceneNo_]->Draw();
		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (InputManager::IsTriggerKey(DIK_ESCAPE)) {
			break;
		}
	}
}

void GameManager::CheackNextScene() {
	preSceneNo_ = currentSceneNo_;
	preSceneNo_ = currentSceneNo_;
	currentSceneNo_ = sceneArray[currentSceneNo_]->GetSceneNo();

	// 変更チェック
	if (preSceneNo_ != currentSceneNo_) {
		sceneArray[currentSceneNo_]->Init();
	}
}
