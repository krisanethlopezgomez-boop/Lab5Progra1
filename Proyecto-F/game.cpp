#include "Game.h"
#include "raylib-assets.h"

void Game::Init() {
    InitWindow(800, 600, "Mi Juego");
    InitAudioDevice();
    level = 1;
    attempts = 3;
    gameOver = false;
    player.Load();
    enemy.Load();
    music = LoadSound("assets/engine.wav");
    font = GetFontDefault();
}

void Game::Run() {
    while (!WindowShouldClose() && !gameOver) {
        enemy.Update(level);
        player.Update();

        if (enemy.CheckCollision(player)) {
            attempts--;
            if (attempts <= 0) gameOver = true;
            else ResetRound();
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);
        player.Draw();
        enemy.Draw();
        DrawTextEx(font, "Presiona ESPACIO para esquivar", { 20, 20 }, 20, 2, BLACK);
        EndDrawing();
    }
}

void Game::DrawInstructions() {
    DrawText("Instrucciones: esquiva el carro con ESPACIO", 20, 50, 20, DARKGRAY);
}

void Game::ResetRound() {
    player.Reset();
    enemy.Reset();
}

void Game::NextLevel() {
    level++;
    ResetRound();
}

void Game::Close() {
    player.Unload();
    enemy.Unload();
    UnloadSound(music);
    raylib_assets::UnloadAll();
    CloseAudioDevice();
    CloseWindow();
}