#pragma once
#include <memory>
#include <list>
#include "IScene.h"
#include "Actor/Player.h"
#include "Actor/Boss.h"
#include "Actor/PlayerBullet.h"

class StageScene : public IScene {
public:

	StageScene();
	~StageScene();

	void Init() override;
	void Update() override;
	void Draw() override;

	void AddBullet(const Vector2& pos);

	void Collision();

private:

	// ----- actor ----- //
	std::unique_ptr<Player> player_;
	std::unique_ptr<Boss> boss_;
	std::list<std::unique_ptr<PlayerBullet>> playerBulletList_;

};

