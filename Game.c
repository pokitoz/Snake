#include "Game.h"

void GAME_Key(SDLKey selection, GameState* gameState){
    switch(selection){
        case SDLK_SPACE:
            gameState->pause = 1;
            GAME_pause(gameState);
        break;

        case SDLK_UP:
            if(gameState->snake->head->next_move != 'D' && gameState->snake->head->last_move != 'D')
            gameState->snake->head->next_move = 'U';
            break;

        case SDLK_DOWN:
            if(gameState->snake->head->next_move != 'U' && gameState->snake->head->last_move != 'U')
            gameState->snake->head->next_move = 'D';
            break;

        case SDLK_RIGHT:
            if(gameState->snake->head->next_move != 'L' && gameState->snake->head->last_move != 'L')
            gameState->snake->head->next_move = 'R';
        break;

        case SDLK_LEFT:
            if(gameState->snake->head->next_move != 'R' && gameState->snake->head->last_move != 'R')
            gameState->snake->head->next_move = 'L';
        break;

        default: ;
    }

}

Uint32 update(Uint32 intervalle, void *parametre){
    GameState* state = (GameState*) parametre;
    SNAKE_move(state->snake);
    GAME_refresh(state);
    return intervalle;
}


void GAME_start(GameState* gameState){
    if(gameState->timer == NULL){
        SDL_Flip(gameState->game_screen);
        gameState->timer = SDL_AddTimer(gameState->speed, update, gameState);
    }
}

void GAME_pause(GameState* gameState){
    if(gameState->timer != NULL){
        gameState->pause = 1;
        SDL_RemoveTimer(gameState->timer);
        gameState->timer = NULL;
        MENU_buildScreen(gameState);

    }
}

void GAME_free(GameState* gameState){

    SDL_RemoveTimer(gameState->timer);
    MENU_free(gameState->menu);
    SNAKE_free(gameState->snake);
}



void GAME_end(GameState* gameState, char message[100]){

    MessageBox(NULL, "End of the game", message, MB_OK);
    SDL_RemoveTimer(gameState->timer);
    gameState->pause = 1;
    gameState->snake = SNAKE_create(COLOR_WHITE);
    gameState->timer = NULL;
    MENU_buildScreen(gameState);
}

void GAME_refresh(GameState* gameState){

    Point* p = gameState->snake->head;
    if(p->x == -1 || p->x == MAP_SIZE_X+1 || p->y == -1 || p->y == MAP_SIZE_Y+1){
        GAME_end(gameState, "Out of border! You lost");
        return;
    }

    if(++apple.counter == APPLECOUNTER){
        APPLE_new(COLOR_RED);
    }

    if(p->x==apple.x && p->y ==apple.y ){
        SNAKE_addEnd(gameState->snake);
        APPLE_new(COLOR_RED);
    }

    SDL_Rect position;
    SDL_FillRect(gameState->game_screen, NULL, COLOR_BLACK);

    Point* head = p;
    while(p!=NULL){

        if(p->x == head->x && p->y == head->y && p!=head){
            GAME_end(gameState, "Yummy! you just ate yourself..");
                    return;

        }
        position.x = MAP_PIXEL_SNAKE*p->x;
        position.y = MAP_PIXEL_SNAKE*p->y;

        SDL_BlitSurface(p->rectangle, NULL, gameState->game_screen, &position);
        p = p->next;

    }

    position.x = MAP_PIXEL_SNAKE*apple.x + 5;
    position.y = MAP_PIXEL_SNAKE*apple.y + 5;
    SDL_BlitSurface(gameState->apple.rectangle, NULL, gameState->game_screen, &position);

    SDL_Flip(gameState->game_screen);

}


