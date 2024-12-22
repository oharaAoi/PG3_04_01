#pragma once
#include "Lib/Vector2.h"

class StageScene;

class Player {
public:

	Player();
	~Player();

	void Init();
	void Update();
	void Draw();

private:

	void Move();

	void Shot();

public:

	void SetStageScene(StageScene* stageScene) { stageScene_ = stageScene; }

	const float GetRadius() const { return radius_; }

private:

	// ----- pointer ----- //
	StageScene* stageScene_ = nullptr;

	Vector2 pos;
	float radius_;

	Vector2 velocity_;
	float speed_;
};

