#include "Game.h"
#include "raylib-assets.h"


void Game::Init() {
	InitWindow(800, 450, "Evita el Impacto");
	InitAudioDevice();
	SetTargetFPS(60);
	raylib_assets::Load(); // carga recursos predeterminados
	font = raylib_assets::GetFont("default");
	enemy.Load();
	player.Load();
	level = 1;
	attempts = 0;
	gameOver = false;
}
void Game::DrawInstructions() {
	BeginDrawing();
	ClearBackground(RAYWHITE);
	DrawTextEx(font,
		"Instrucciones:\n"
		"- Escucha el auto que se acerca.\n"
		"- Cuando este cerca, presiona ESPACIO para esquivarlo.\n"
		"- Tienes 5 intentos por nivel.\n"
		"Presiona ENTER para comenzar.",
		{ 80, 100 }, 20, 2, BLACK);
	EndDrawing();
	while (!IsKeyPressed(KEY_ENTER)) {}
}
void Game::Run() {
	DrawInstructions();
	while (!WindowShouldClose()) {
		if (gameOver) {
			BeginDrawing();
			ClearBackground(RAYWHITE);
			DrawTextEx(font, "Juego terminado.\nPresiona ENTER para reiniciar.",
				{ 200, 200 }, 24, 2, RED);
			EndDrawing();
			if (IsKeyPressed(KEY_ENTER)) {
				gameOver = false;
				level = 1;
				attempts = 0;
				ResetRound();
			}
			continue;
		}
		enemy.Update(level);
		player.Update();
		if (enemy.CheckCollision(player)) {
			if (!player.HasDodged()) {
				attempts++;
				if (attempts >= 5) {
					NextLevel();
				}
			}
			ResetRound();
		}
		BeginDrawing();
		ClearBackground(SKYBLUE);
		enemy.Draw();
		player.Draw();
		DrawTextEx(font, TextFormat("Nivel: %i Intentos: %i", level,
			attempts),
			{ 20, 20 }, 20, 2, BLACK);
		EndDrawing();
	}
	Close();
}
void Game::ResetRound() {
	enemy.Reset();
	player.Reset();
}
void Game::NextLevel() {
	level++;
	attempts = 0;
}
void Game::Close() {
	enemy.Unload();
	player.Unload();
	UnloadSound(music);
	UnloadFont(font);
	CloseAudioDevice();
	CloseWindow();
}