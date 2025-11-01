#pragma once
#include "raylib.h"
class Car {
private:
	Vector2 pos;
	Texture2D sprite;
	Sound engine;
	bool playing;
public:
	void Load();
	void Update(int level);
	void Draw();
	void Reset();
	void Unload();
	bool CheckCollision(const class Player& player);
};