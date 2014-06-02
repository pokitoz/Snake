#ifndef GAME_HEADER
#define GAME_HEADER

#include <stdlib.h>
#include <SDL/SDL.h>

#include "Apple.h"
#include "Option.h"
#include "Snake.h"
#include "Menu.h"

typedef struct GameState{
    SDL_Surface *game_screen;

    Snake* snake;
    struct Menu* menu;
    Option* option;
    Apple apple;

    int speed;
    char on;
    char pause;
    char isOption;
    SDL_TimerID timer;

} GameState;

void GAME_Key(SDLKey selection, GameState* gameState);

void GAME_start(GameState* gameState);
void GAME_refresh(GameState* GameState);
void GAME_end(GameState* gameState, char message[100]);
void GAME_free(GameState* gameState);
void GAME_pause(GameState* gameState);


#endif // GAME_HEADER
