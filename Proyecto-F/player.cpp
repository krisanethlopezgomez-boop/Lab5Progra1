#include "Player.h"
#include "raylib-assets.h"

void Player::Load() {
    sprite = raylib_assets::GetTexture("car-blue");
    Reset();
}

void Player::Reset() {
    pos = { 600, 200 };
    dodged = false;
}

void Player::Update() {
    if (IsKeyPressed(KEY_SPACE)) dodged = true;
}

void Player::Draw() const {
    DrawTexture(sprite, (int)pos.x, (int)pos.y, dodged ? GREEN : WHITE);
}

Rectangle Player::GetRect() const {
    return { pos.x, pos.y, (float)sprite.width, (float)sprite.height };
}

void Player::Unload() {
    UnloadTexture(sprite);
}

bool Player::HasDodged() const {
    return dodged;
}