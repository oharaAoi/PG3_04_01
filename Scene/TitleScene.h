#pragma once
#include "IScene.h"

class TitleScene : public IScene {
public:

	TitleScene();
	~TitleScene();

	void Init() override;
	void Update() override;
	void Draw() override;

private:

	int textureHandle_;

};

