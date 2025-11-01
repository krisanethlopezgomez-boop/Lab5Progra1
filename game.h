#pragma once
#include "raylib.h"
#include "Car.h"
#include "Player.h"
class Game {
private:
	Car enemy;
	Player player;
	int level;
	int attempts;
	bool gameOver;
	Sound music;
	Font font;
public:
	void Init();
	void Run();
	void DrawInstructions();
	void ResetRound();
	void NextLevel();
	void Close();
};
