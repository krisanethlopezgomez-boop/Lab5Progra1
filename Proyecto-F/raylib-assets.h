#pragma once
#include "raylib.h"
#include <string>
#include <map>

namespace raylib_assets {
    Texture2D GetTexture(const std::string& name);
    Sound GetSound(const std::string& name);
    void UnloadAll();
}