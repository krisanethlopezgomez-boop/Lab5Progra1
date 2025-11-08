#pragma once
#include "raylib.h"

class Game {
private:
    Sound carSound{};   // Sonido del carro
    int level{};        // Nivel actual
    bool gameOver{};    // Indicador de fin del juego
    bool win{};         // Indicador de victoria
    bool soundPlayed{}; // Si el sonido ya fue reproducido
    bool avoided{};     // Si el jugador evit� el carro
    float timer{};      // Temporizador de reacci�n

public:
    Game();
    ~Game();

    void Init();
    void Update();
    void Draw();
    bool ShouldClose() const; // Se marca como const porque no modifica atributos
};