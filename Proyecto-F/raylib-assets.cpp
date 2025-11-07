#include "raylib-assets.h"
#include "raylib.h"

static std::map<std::string, Texture2D> textures;
static std::map<std::string, Sound> sounds;

Texture2D raylib_assets::GetTexture(const std::string& name) {
    if (textures.count(name) == 0) {
        if (name == "car") textures[name] = LoadTexture("assets/car.png");
        else if (name == "car-blue") textures[name] = LoadTexture("assets/car-blue.png");
    }
    return textures[name];
}

Sound raylib_assets::GetSound(const std::string& name) {
    if (sounds.count(name) == 0) {
        if (name == "engine") sounds[name] = LoadSound("assets/engine.wav");
    }
    return sounds[name];
}

void raylib_assets::UnloadAll() {
    for (auto& t : textures) UnloadTexture(t.second);
    textures.clear();
    for (auto& s : sounds) UnloadSound(s.second);
    sounds.clear();
}