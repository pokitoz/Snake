#include "Menu.h"

void MENU_initImages(Menu* menu)
{
    menu->title =  SDL_LoadBMP("img/title.bmp");
    menu->start =  SDL_LoadBMP("img/start.bmp");
    menu->option = SDL_LoadBMP("img/option.bmp");
    menu->maps = SDL_LoadBMP("img/maps.bmp");
    menu->exit = SDL_LoadBMP("img/exit.bmp");
    menu->selection = 0;
}

void MENU_key(SDLKey selection, GameState* gameState)
{
    switch(selection)
    {
    case SDLK_SPACE:
        switch(gameState->menu->selection)
        {
        //Play
        case 0:
            gameState->pause = 0;
            GAME_start(gameState);
            return;
            break;
        //Option
        case 1:
            gameState->isOption = 1;
            OPTION_buildScreen(gameState);
            break;
        //Map
        case 2:
            break;
        //Exit
        case 3:
            gameState->on = 0;
            break;

        }
        break;

    case SDLK_DOWN:
        gameState->menu->selection = (gameState->menu->selection+1)%4;
        MENU_buildScreen(gameState);
        break;

    case SDLK_UP:
        if(gameState->menu->selection == 0)
        {
            gameState->menu->selection = 4;
        }
        gameState->menu->selection = gameState->menu->selection - 1;

        MENU_buildScreen(gameState);
        break;

    case SDLK_RIGHT:
        break;

    case SDLK_LEFT:
        break;

    default:
        ;
    }

}


void MENU_buildScreen(GameState* gameState)
{

    SDL_FillRect(gameState->game_screen, NULL, COLOR_BLACK);

    SDL_Rect position;
    position.x = MENU_X;
    position.y = MENU_Y;
    SDL_BlitSurface(gameState->menu->title, NULL, gameState->game_screen, &position);

    position.y += MENU_PIXEL_TITLE + MENU_GAP;

    SDL_Rect selection_position;
    selection_position.x = position.x-8;
    selection_position.y = position.y + MENU_PIXEL_MENU*gameState->menu->selection;

    gameState->menu->rectangle_selection = SDL_CreateRGBSurface(SDL_HWSURFACE, 400+16, MENU_PIXEL_MENU, 32, 0, 0, 0, 0);
    SDL_FillRect(gameState->menu->rectangle_selection, NULL, COLOR_WHITE);
    SDL_BlitSurface(gameState->menu->rectangle_selection, NULL, gameState->game_screen, &selection_position);


    SDL_BlitSurface(gameState->menu->start, NULL, gameState->game_screen, &position);

    position.y += MENU_PIXEL_MENU;
    SDL_BlitSurface(gameState->menu->option, NULL, gameState->game_screen, &position);

    position.y += MENU_PIXEL_MENU;
    SDL_BlitSurface(gameState->menu->maps, NULL, gameState->game_screen, &position);

    position.y += MENU_PIXEL_MENU;
    SDL_BlitSurface(gameState->menu->exit, NULL, gameState->game_screen, &position);

    SDL_Flip(gameState->game_screen);

}

void MENU_free(Menu* menu)
{
    free(menu->title);
    free(menu->start);
    free(menu->option);
    free(menu->exit);
    free(menu->maps);
}
