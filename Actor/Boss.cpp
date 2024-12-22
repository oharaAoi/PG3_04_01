#include "Boss.h"
#include "Novice.h"

Boss::Boss() {
}

Boss::~Boss() {
}

void Boss::Init() {
	pos_ = { 640.0f, 100.0f };
	radius_ = 40.0f;
	velocity_ = { 1.0f, 0.0f };
	speed_ = 2.0f;

	hp_ = 5.0f;
	isDead_ = false;
}

void Boss::Update() {
	pos_ += velocity_ * speed_;

	if (pos_.x - radius_ < 0.0f) {
		velocity_.x *= -1.0f;
	}

	if (pos_.x + radius_ > 1280.0f) {
		velocity_.x *= -1.0f;
	}
}

void Boss::Draw() {
	Novice::DrawEllipse(
		static_cast<int>(pos_.x),
		static_cast<int>(pos_.y),
		static_cast<int>(radius_),
		static_cast<int>(radius_),
		0.0f,
		RED,
		kFillModeSolid
	);

	Novice::DrawBox(
		static_cast<int>(pos_.x - 25.0f),
		static_cast<int>(pos_.y + 50.0f),
		static_cast<int>(50.0f * (hp_ / 5.0f)),
		10,
		0.0f,
		RED,
		kFillModeSolid
	);
}

void Boss::DecreaseHp() {
	--hp_;

	if (hp_ <= 0.0f) {
		isDead_ = true;
	}
}
