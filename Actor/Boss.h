#pragma once
#include "Lib/Vector2.h"

class Boss {
public:

	Boss();
	~Boss();

	void Init();
	void Update();
	void Draw();

	void DecreaseHp();

public:

	void SetIsDead(bool isDead) { isDead_ = isDead; }
	const bool GetIsDead() { return isDead_; }

	const float GetRadius() const { return radius_; }

	const Vector2 GetPos() const { return pos_; }

private:

	Vector2 pos_;
	float radius_;

	Vector2 velocity_;
	float speed_;

	float hp_;

	bool isDead_;
};

