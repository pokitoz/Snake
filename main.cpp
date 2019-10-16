#include "Main.h"
// Multiscreen


int main(int argc, char *argv[])
{

    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) == -1)
    {
        fprintf(stderr, "Erreur d'initialisation de la SDL : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    SDL_WM_SetCaption("Snake", NULL);

    Menu menu;
    MENU_initImages(&menu);

    Option option;
    OPTION_initImages(&option);

    Snake* snake = SNAKE_create(COLOR_WHITE);
    APPLE_new(COLOR_RED);

    GameState gameState;
    gameState.game_screen = SDL_SetVideoMode(MAP_PIXEL_SNAKE*MAP_SIZE_X + MAP_PIXEL_SNAKE, MAP_PIXEL_SNAKE*MAP_SIZE_Y + MAP_PIXEL_SNAKE, 32, SDL_HWSURFACE);

    gameState.snake = SNAKE_create(COLOR_WHITE);
    gameState.menu = &menu;
    gameState.option = &option;
    gameState.apple = apple;
    gameState.speed = 200;

    gameState.on = 1;
    gameState.pause = 1;
    gameState.isOption = 0;

    gameState.timer = NULL;

    MENU_buildScreen(&gameState);
    SDL_Event event;

    while (gameState.on)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
        case SDL_QUIT:
            gameState.on = 0;
            break;

        case SDL_KEYDOWN:
            selection(event.key.keysym.sym, &gameState);
            break;
        }
    }

    SDL_Quit();
    return 0;
}


void selection(SDLKey key, GameState* gameState)
{

    if(!gameState->pause)
    {
        GAME_Key(key, gameState);
    }
    else
    {
        if(gameState->isOption)
        {
            OPTION_key(key, gameState);
        }
        else
        {
            MENU_key(key, gameState);
        }
    }

}
