#include "Apple.h"


void APPLE_new(Uint32 color){
    srand(time(NULL));
    apple.rectangle=SDL_CreateRGBSurface(SDL_HWSURFACE, APPLE_SIZE_X, APPLE_SIZE_Y, 32, 0, 0,0, 0);
    SDL_FillRect(apple.rectangle, NULL, color);

    apple.x = rand() % MAP_SIZE_X;
    apple.y = rand() % MAP_SIZE_Y;
    apple.counter = 0;
}
