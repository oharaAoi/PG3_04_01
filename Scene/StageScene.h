#pragma once
#include "IScene.h"

class StageScene : public IScene {
public:

	StageScene();
	~StageScene();

	void Init() override;
	void Update() override;
	void Draw() override;

private:


};

