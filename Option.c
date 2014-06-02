#include "Option.h"

void OPTION_initImages(Option* option){
    option->title = SDL_LoadBMP("img/menu_options.bmp");
    option->speed =  SDL_LoadBMP("img/speed.bmp");
    option->color =  SDL_LoadBMP("img/color.bmp");
    option->return_to_menu = SDL_LoadBMP("img/return.bmp");
    option->selection = 0;
    option->colorSelection = 0;
    option->snake_color = COLOR_WHITE;
}

void OPTION_key(SDLKey selection, GameState* gameState){
    switch(selection){
        case SDLK_SPACE:
            if(gameState->option->selection == 2){
            //RETURN
                gameState->isOption = 0;
                SNAKE_changeColor(gameState->snake, gameState->option->snake_color);
                MENU_buildScreen(gameState);
                return;

            }
        break;

        case SDLK_DOWN:
            gameState->option->selection = (gameState->option->selection+1)%3;
            OPTION_buildScreen(gameState);
            break;

        case SDLK_UP:
            if(gameState->option->selection == 0){
                gameState->option->selection = 3;
            }
            gameState->option->selection = gameState->option->selection - 1;

            OPTION_buildScreen(gameState);
            break;

        case SDLK_RIGHT:
            // Selection 0 -> Speed
            if(gameState->option->selection == 0 ){
                 if(gameState->speed == 20){
                    return;
                }
                gameState->speed -= 10;
                OPTION_buildScreen(gameState);

            }
            //COLOR
            else if(gameState->option->selection == 1){

                gameState->option->snake_color = gameState->option->snake_color + 0xfff;
                OPTION_buildScreen(gameState);

            }


            break;

        case SDLK_LEFT:
            if(gameState->option->selection == 0 ){
                 if(gameState->speed == 380){
                    return;
                }
                gameState->speed += 10;
                OPTION_buildScreen(gameState);

            }
           else if(gameState->option->selection == 1){
                gameState->option->snake_color =  gameState->option->snake_color - 0xfff;
                OPTION_buildScreen(gameState);

            }

            break;

        default: ;
    }

}


void OPTION_buildScreen(GameState* gameState){

    SDL_FillRect(gameState->game_screen, NULL, COLOR_BLACK);

    SDL_Rect position;
    position.x = MENU_X;
    position.y = MENU_Y;
    SDL_BlitSurface(gameState->option->title, NULL, gameState->game_screen, &position);

    position.y += MENU_PIXEL_TITLE + MENU_GAP;

    SDL_Rect selection_position;
    selection_position.x = position.x-8;
    selection_position.y = position.y + (MENU_PIXEL_MENU+OPTION_GAP)*gameState->option->selection;

    gameState->option->rectangle_selection = SDL_CreateRGBSurface(SDL_HWSURFACE, 400+16, MENU_PIXEL_MENU , 32, 0, 0, 0, 0);
    SDL_FillRect(gameState->option->rectangle_selection, NULL, COLOR_WHITE);
    SDL_BlitSurface(gameState->option->rectangle_selection, NULL, gameState->game_screen, &selection_position);

    SDL_BlitSurface(gameState->option->speed, NULL, gameState->game_screen, &position);

    position.y += MENU_PIXEL_MENU;

    gameState->option->speed_rectangle = SDL_CreateRGBSurface(SDL_HWSURFACE, 400-gameState->speed, 10 , 32, 0, 0, 0, 0);
    SDL_FillRect(gameState->option->speed_rectangle, NULL, COLOR_RED);
    SDL_BlitSurface(gameState->option->speed_rectangle, NULL, gameState->game_screen, &position);

    position.y += OPTION_GAP;
    SDL_BlitSurface(gameState->option->color, NULL, gameState->game_screen, &position);

    position.y += MENU_PIXEL_MENU;
    gameState->option->color_rectangle = SDL_CreateRGBSurface(SDL_HWSURFACE, 400, 20 , 32, 0, 0, 0, 0);
    SDL_FillRect(gameState->option->color_rectangle, NULL, gameState->option->snake_color);
    SDL_BlitSurface(gameState->option->color_rectangle, NULL, gameState->game_screen, &position);

    position.y += OPTION_GAP;
    SDL_BlitSurface(gameState->option->return_to_menu, NULL, gameState->game_screen, &position);

    SDL_Flip(gameState->game_screen);

}

