#include "Car.h"
#include "Player.h"
#include "raylib-assets.h"

void Car::Load() {
	sprite = raylib_assets::GetTexture("car");
	engine = raylib_assets::GetSound("engine");
	Reset();
}
void Car::Reset() {
	pos = { -200, 200 };
	playing = false;
}
void Car::Update(int level) {
	pos.x += 5 * level;
	if (!playing) {
		PlaySound(engine);
		playing = true;
	}
	float volume = 1.0f - (pos.x / 800.0f);
	SetSoundVolume(engine, volume);
	if (pos.x > 800) Reset();
}
void Car::Draw() {
	DrawTexture(sprite, (int)pos.x, (int)pos.y, WHITE);
}
bool Car::CheckCollision(const Player& player) {
	Rectangle r1 = { pos.x, pos.y, (float)sprite.width,
   (float)sprite.height };
	Rectangle r2 = player.GetRect();
	return CheckCollisionRecs(r1, r2);
}
void Car::Unload() {
	UnloadTexture(sprite);
	UnloadSound(engine);
}

