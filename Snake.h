#ifndef SNAKE_HEADER
#define SNAKE_HEADER

#include <stdlib.h>

#include <SDL/SDL.h>
#include <unistd.h>
#include <windows.h>

#define MAP_SIZE_X 20
#define MAP_SIZE_Y 20
#define MAP_PIXEL_SNAKE 20

#define SNAKE_BEGIN_X 7
#define SNAKE_BEGIN_Y 7
#define SNAKE_INIT_LENGTH 3

typedef struct Point Point;
struct Point
{
    //Add a color for each block
    SDL_Surface *rectangle;
    int x;
    int y;
    char last_move;
    char next_move;
    Point* next;

};

typedef struct Snake
{
    Uint32 color;
    Point* head;
    int length;
} Snake;

Snake* SNAKE_create(Uint32 color);
void SNAKE_add(Snake* snake, int x, int y);
void SNAKE_move(Snake* snake);
void SNAKE_addEnd(Snake* snake);
void SNAKE_free(Snake* snake);
void POINT_move(Point* point, char move_letter);
void SNAKE_changeColor(Snake* snake, Uint32 color);

#endif
