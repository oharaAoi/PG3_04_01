#pragma once
#include <memory>
#include "Scene/IScene.h"
#include "Manager/InputManager.h"

class GameManager {
public:

	GameManager();
	~GameManager();

	void Run();

	void CheackNextScene();

private:

	InputManager* input_;

	std::unique_ptr<IScene> sceneArray[3];

	int currentSceneNo_ = SCENE::TITLE;	// 今のScene
	int preSceneNo_;		// 前のscene

};

