#include "PlayerBullet.h"
#include "Novice.h"

PlayerBullet::PlayerBullet() {
}

PlayerBullet::~PlayerBullet() {
}

void PlayerBullet::Init(const Vector2& pos) {
	pos_ = pos;
	radius_ = 10.0f;
	isDead_ = false;
}

void PlayerBullet::Update() {
	pos_ += velocity_ * speed_;

	if (pos_.x < -10.0f || pos_.x > 1300.0f) {
		isDead_ = true;
	}

	if (pos_.y< -10.0f || pos_.y > 750.0f) {
		isDead_ = true;
	}
}

void PlayerBullet::Draw() {
	Novice::DrawEllipse(
		static_cast<int>(pos_.x),
		static_cast<int>(pos_.y),
		10,
		10,
		0.0f,
		GREEN,
		kFillModeSolid
	);
}

