#pragma once
#include "raylib.h"

class Player {
private:
    Vector2 pos;
    Texture2D sprite;
    bool dodged;
public:
    void Load();
    void Update();
    void Draw() const;
    void Reset();
    void Unload();
    Rectangle GetRect() const;
    bool HasDodged() const;
};