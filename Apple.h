#ifndef APPLE_HEADER
#define APPLE_HEADER

#include <SDL/SDL.h>
#include <time.h>

#define MAP_SIZE_X 20
#define MAP_SIZE_Y 20

#define APPLECOUNTER (15+(MAP_SIZE_X+MAP_SIZE_Y)%15)
#define APPLE_SIZE_X 10
#define APPLE_SIZE_Y 10

typedef struct Apple
{
    SDL_Surface *rectangle;
    int x, y;
    int counter;
} Apple;

Apple apple;

void APPLE_new(Uint32 color);


#endif
