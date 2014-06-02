#ifndef OPTION_HEADER
#define OPTION_HEADER

#define OPTION_GAP 25
#include <SDL/SDL.h>

typedef struct Option{
    SDL_Surface* title;
    SDL_Surface* speed;
    SDL_Surface* color;
    SDL_Surface* return_to_menu;
    int selection;
    int colorSelection;
    SDL_Surface* rectangle_selection;
    Uint32 snake_color;
    SDL_Surface* speed_rectangle;
    SDL_Surface* color_rectangle;

} Option;
#include "Game.h"
void OPTION_buildScreen(struct GameState* gameState);
void OPTION_initImages(Option* option);

#include "Menu.h"
#include "Snake.h"

#include "Color.h"

void OPTION_key(SDLKey selection, struct GameState* gameState);
#endif
