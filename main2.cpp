#include <stdlib.h>
#include <SDL/SDL.h>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <windows.h>

#include "Menu.c"
#include "Snake.c"
#include "Game.c"
#include "Apple.c"
#include "Option.c"
#include "Color.h"



int main(int argc, char *argv[]){

    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) == -1){
        fprintf(stderr, "Erreur d'initialisation de la SDL : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    SDL_WM_SetCaption("Snake", NULL);

    game_screen = SDL_SetVideoMode(MAP_PIXEL_SNAKE*MAP_SIZE_X + MAP_PIXEL_SNAKE, MAP_PIXEL_SNAKE*MAP_SIZE_Y + MAP_PIXEL_SNAKE, 32, SDL_HWSURFACE);
    menu_screen = SDL_SetVideoMode(MAP_PIXEL_SNAKE*MAP_SIZE_X + MAP_PIXEL_SNAKE, MAP_PIXEL_SNAKE*MAP_SIZE_Y + MAP_PIXEL_SNAKE, 32, SDL_HWSURFACE);
    option_screen = SDL_SetVideoMode(MAP_PIXEL_SNAKE*MAP_SIZE_X + MAP_PIXEL_SNAKE, MAP_PIXEL_SNAKE*MAP_SIZE_Y + MAP_PIXEL_SNAKE, 32, SDL_HWSURFACE);

    TICK_SPEED = 200;

    Menu menu;
    MENU_initImages(&menu);

    Option option;
    OPTION_initImages(&option);

    Snake* snake = SNAKE_create(COLOR_WHITE);
    APPLE_new(COLOR_RED);

    timer = NULL;

    GameState gameState;
    gameState.snake = SNAKE_create(COLOR_WHITE);
    gameState.menu = menu;
    gameState.option = option;
    gameState.apple = apple;
    gameState.speed = 200;
    gameState.on = 1;
    gameState.pause = 1;
    gameState.isOption = 0;

    MENU_buildScreen(menu);
    SDL_Event event;

    int on = 1;
    int pause = 1;
    int isOption = 0;

    while (on){
        SDL_WaitEvent(&event);
        switch(event.type){
            case SDL_QUIT:
                on = 0;
                break;

            case SDL_KEYDOWN:
                if(!pause){
                    GAME_Key(event.key.keysym.sym, snake, menu, &on, &pause);
                }
                else{
                    if(isOption){
                        OPTION_key(event.key.keysym.sym, snake, &menu, &option, &isOption);
                    }
                    else{
                        MENU_key(event.key.keysym.sym, snake, &menu, option, &on, &pause, &isOption);
                    }
                }
                break;
            }
    }

    SDL_Quit();
    return 0;
}

