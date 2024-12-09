#include "InputManager.h"

InputManager::InputManager() {
}

InputManager* InputManager::GetInstance() {
	static InputManager instance;
	return &instance;
}

void InputManager::Update() {
	memcpy(preKeys_, keys_, 256);
	Novice::GetHitKeyStateAll(keys_);
}

bool InputManager::IsTriggerKey(int DIK_key) {
	return GetInstance()->GetKeys()[DIK_key] && !GetInstance()->GetPreKeys()[DIK_key];
}

bool InputManager::IsPressKeys(int DIK_key) {
	return GetInstance()->GetKeys()[DIK_key];
}

bool InputManager::IsReleseKeys(int DIK_Key) {
	return  !GetInstance()->GetKeys()[DIK_Key] && GetInstance()->GetPreKeys()[DIK_Key];
}
