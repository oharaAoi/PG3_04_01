#pragma once
#include "Lib/Vector2.h"

class PlayerBullet {
public:

	PlayerBullet();
	~PlayerBullet();

	void Init(const Vector2& pos);
	void Update();
	void Draw();

public:

	void SetIsDead(bool isDead) { isDead_ = isDead; }
	const bool GetIsDead() const { return isDead_; }

	const float GetRadius() const { return radius_; }

	const Vector2 GetPos() const { return pos_; }

private:

	Vector2 pos_;
	float radius_;

	Vector2 velocity_ = {0.0f, -1.0f};
	float speed_ = 6.0f;

	bool isDead_;
};

