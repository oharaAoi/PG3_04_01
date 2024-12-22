#pragma once
#include "IScene.h"

class ClearScene : public IScene {
public:

	ClearScene();
	~ClearScene();

	void Init() override;
	void Update() override;
	void Draw() override;

private:

	int textureHandle_;

};

