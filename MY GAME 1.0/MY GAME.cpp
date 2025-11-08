#include "Game.h"
#include <stdio.h>

Game::Game() {
    level = 1;
    gameOver = false;
    win = false;
    soundPlayed = false;
    avoided = false;
    timer = 0;
}

Game::~Game() {
    UnloadSound(carSound);
    CloseAudioDevice();
    CloseWindow();
}

void Game::Init() {
    InitWindow(800, 450, "Evita el Impacto");
    InitAudioDevice();
    carSound = LoadSound("car.wav");

    if (!IsSoundValid(carSound)) {
        printf("Error: no se pudo cargar el sonido car.wav\n");
    }

    SetTargetFPS(60);
}

void Game::Update() {
    // Evita procesar l�gica si el juego ya termin�
    if (gameOver || win) return;

    // Aumenta el temporizador seg�n el tiempo real entre frames
    timer += GetFrameTime();

    // Tiempo de espera antes del sonido (5s en el nivel 1, disminuye cada nivel)
    float waitTime = 5.0f - (level - 1) * 0.5f;
    if (waitTime < 1.0f) waitTime = 1.0f; // l�mite m�nimo

    // Reproduce el sonido del carro cuando llega el tiempo
    if (timer >= waitTime && !soundPlayed) {
        PlaySound(carSound);
        soundPlayed = true;
    }

    // Reacci�n del jugador
    if (soundPlayed && !avoided) {
        if (IsKeyPressed(KEY_SPACE)) {
            avoided = true; // El jugador evit� el impacto
        }
        else if (timer >= waitTime + 4.0f) {
            gameOver = true; // No reaccion� a tiempo
        }
    }

    // Si evit� el carro, pasa de nivel o gana
    if (avoided && level < 3) {
        level++;
        avoided = false;
        soundPlayed = false;
        timer = 0;
    }
    else if (avoided && level >= 3) {
        win = true;
    }
}

void Game::Draw() {
    BeginDrawing();
    ClearBackground(RAYWHITE);

    if (win) {
        DrawText("�GANASTE!", 300, 200, 40, GREEN);
        DrawText("Presiona ESC para salir", 250, 260, 20, DARKGRAY);
    }
    else if (gameOver) {
        DrawText("GAME OVER", 300, 200, 40, RED);
        DrawText("Presiona ESC para salir", 250, 260, 20, DARKGRAY);
    }
    else {
        DrawText(TextFormat("Nivel: %i", level), 10, 10, 30, BLACK);
        DrawText("Presiona ESPACIO cuando escuches el carro!", 100, 400, 20, DARKBLUE);
    }

    EndDrawing();
}

bool Game::ShouldClose() const {
    return WindowShouldClose();
}