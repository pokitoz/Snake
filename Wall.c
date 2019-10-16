#ifdef __cplusplus
#include <cstdlib>
#else
#include <stdlib.h>
#endif

#include <SDL/SDL.h>

#define MAP_PIXEL_WALL 20
#define MAP_NUMBER_CASE 20

typedef struct Component Component;
struct Component
{

    SDL_Surface *rectangle;
    int x, y;
    Component* next;
};

typedef struct Wall
{

    Component* start;
    Uint32 color;

} Wall;


Wall* WALL_create(int x, int y, Uint32 color)
{

    Wall* wall = malloc(sizeof(Wall));
    wall->color = color;

    wall->start = malloc(sizeof(Component));
    wall->start->x = x;
    wall->start->y = y;
    wall->start->rectangle = SDL_CreateRGBSurface(SDL_HWSURFACE, MAP_PIXEL_WALL, MAP_PIXEL_WALL, 32, 0, 0,0, 0);
    SDL_FillRect(wall->start->rectangle, NULL, color);
    wall->start->next = NULL;

    return wall;
}

void WALL_addLine(Wall* wall, int line, int column)
{
    Component* component = wall->start;

    while(component != NULL)
    {
        component=component->next;
    }

    int i = 0;
    while(i < MAP_NUMBER_CASE)
    {
        component = malloc(sizeof(Component));
        component->rectangle = SDL_CreateRGBSurface(SDL_HWSURFACE, MAP_PIXEL_WALL, MAP_PIXEL_WALL, 32, 0, 0,0, 0);
        SDL_FillRect(component->rectangle, NULL, wall->color);
        component->x = line;
        component->y = column + i;
        i++;
    }

}

void WALL_free(Wall* wall)
{

}

void WALL_addColumn(Wall* wall, int line, int column)
{

    Component* component = wall->start;
    while(component != NULL)
    {
        component=component->next;
    }

    int i = 0;
    while(i < MAP_NUMBER_CASE)
    {
        component = malloc(sizeof(Component));
        component->rectangle = SDL_CreateRGBSurface(SDL_HWSURFACE, MAP_PIXEL_WALL, MAP_PIXEL_WALL, 32, 0, 0,0, 0);
        SDL_FillRect(component->rectangle, NULL, wall->color);
        component->x = line + i;
        component->y = column;
        i++;
    }

}

void WALL_addComponent(Wall* wall, int x, int y)
{

    Component* component = wall->start;
    while(component != NULL)
    {
        component=component->next;
    }

    component = malloc(sizeof(Component));
    component->rectangle = SDL_CreateRGBSurface(SDL_HWSURFACE, MAP_PIXEL_WALL, MAP_PIXEL_WALL, 32, 0, 0,0, 0);
    SDL_FillRect(component->rectangle, NULL, wall->color);
    component->x = x;
    component->y = y;

}
