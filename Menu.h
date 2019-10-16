#ifndef MENU_HEADER
#define MENU_HEADER

#include <SDL/SDL.h>

#include "Game.h"
typedef struct Menu
{
    SDL_Surface* title;
    SDL_Surface* start;
    SDL_Surface* option;
    SDL_Surface* maps;
    SDL_Surface* exit;
    int selection;
    SDL_Surface* rectangle_selection;

} Menu;

#define MENU_X 10
#define MENU_Y 20
#define MENU_PIXEL_X 400
#define MENU_PIXEL_TITLE 120
#define MENU_PIXEL_MENU 60
#define MENU_GAP 15


#include "Apple.h"
#include "Option.h"
#include "Snake.h"

void MENU_initImages(Menu* menu);
void MENU_buildScreen(struct GameState* gameState);
void MENU_key(SDLKey selection, struct GameState* gameState);

void MENU_free(Menu* menu);



#endif
