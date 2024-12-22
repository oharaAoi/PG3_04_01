﻿#include "Player.h"
#include "Novice.h"
#include "Manager/InputManager.h"
#include "Scene/StageScene.h"

Player::Player() {}
Player::~Player() {}

//////////////////////////////////////////////////////////////////////////////////////////////////
// ↓　初期化処理
//////////////////////////////////////////////////////////////////////////////////////////////////

void Player::Init() {
	pos = { 640.0f, 400.0f };
	radius_ = 20.0f;
	velocity_ = { 0.0f, 0.0f };
	speed_ = 4.0f;
}

//////////////////////////////////////////////////////////////////////////////////////////////////
// ↓　更新処理
//////////////////////////////////////////////////////////////////////////////////////////////////

void Player::Update() {
	Move();
	Shot();

	pos += velocity_ * speed_;
}

//////////////////////////////////////////////////////////////////////////////////////////////////
// ↓　描画処理
/////////////////////////////////////////////////////////////////////////////////////////////////

void Player::Draw() {
	Novice::DrawEllipse(
		static_cast<int>(pos.x),
		static_cast<int>(pos.y),
		static_cast<int>(radius_),
		static_cast<int>(radius_),
		0.0f,
		WHITE,
		kFillModeSolid
	);
}

//////////////////////////////////////////////////////////////////////////////////////////////////
// ↓　移動処理
/////////////////////////////////////////////////////////////////////////////////////////////////

void Player::Move() {
	velocity_ = { 0.0f, 0.0f };

	if (InputManager::IsPressKeys(DIK_W)) {
		velocity_.y = -1.0f;
	}

	if (InputManager::IsPressKeys(DIK_S)) {
		velocity_.y = 1.0f;
	}

	if (InputManager::IsPressKeys(DIK_A)) {
		velocity_.x = -1.0f;
	}

	if (InputManager::IsPressKeys(DIK_D)) {
		velocity_.x = 1.0f;
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////
// ↓　攻撃処理
/////////////////////////////////////////////////////////////////////////////////////////////////

void Player::Shot() {
	if (InputManager::IsTriggerKey(DIK_SPACE)) {
		stageScene_->AddBullet(pos);
	}
}