#pragma once
#include <Novice.h>

class InputManager {
public:

	InputManager();
	~InputManager() = default;

	InputManager(const InputManager&) = delete;
	const InputManager& operator=(const InputManager&) = delete;

	static InputManager* GetInstance();

	void Update();

public:

	static bool IsTriggerKey(int DIK_key);
	static bool IsPressKeys(int DIK_key);
	static bool IsReleseKeys(int DIK_Key);

private:

	char* GetKeys() { return keys_; }
	char* GetPreKeys() { return preKeys_; }

private:


	// キーの入力状況
	char keys_[256] = { 0 };
	char preKeys_[256] = { 0 };
};

