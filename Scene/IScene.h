#pragma once

enum SCENE {
	TITLE,
	STAGE,
	CLEAR,
};

/// <summary>
/// Sceneの基底クラス
/// </summary>
class IScene {
public:

	IScene() = default;
	virtual ~IScene() = default;

	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;

	int GetSceneNo() { return sceneNo_; }
	static void SetSceneNo(int sceneNo) { sceneNo_ = sceneNo; }

protected:

	static int sceneNo_;

};

