#include "Snake.h"

Snake* SNAKE_create(Uint32 color)
{

    Snake* snake = (Snake*) malloc(sizeof(Snake));
    snake->head = (Point*) malloc(sizeof(Point));
    snake->head->x = SNAKE_BEGIN_X;
    snake->head->y = SNAKE_BEGIN_Y;
    snake->head->last_move = 'U';
    snake->head->next_move = 'U';

    snake->color = color;
    snake->head->rectangle = SDL_CreateRGBSurface(SDL_HWSURFACE, MAP_PIXEL_SNAKE, MAP_PIXEL_SNAKE, 32, 0, 0,0, 0);
    SDL_FillRect(snake->head->rectangle, NULL, color);

    snake->head->next=NULL;
    snake->length = 0;


    int i;
    for(i =1; i < SNAKE_INIT_LENGTH; i++)
    {
        SNAKE_add(snake, SNAKE_BEGIN_X, SNAKE_BEGIN_Y+i);
    }

    Point* point = snake->head->next;
    while(point != NULL)
    {
        point->last_move = 'U';
        point->next_move = 'U';
        point = point->next;
    }

    return snake;
}

void SNAKE_addEnd(Snake* snake)
{

    Point* next = snake->head;
    while(next->next != NULL)
    {
        next = next->next;
    }

    SNAKE_add(snake, next->x, next->y);


}

void SNAKE_add(Snake* snake, int x, int y)
{

    snake->length += 1;

    Point* tail = snake->head;
    while(tail->next != NULL)
    {
        tail = tail->next;
    }

    tail->next = (Point*) malloc(sizeof(Point));
    tail->next->x = x;
    tail->next->y = y;

    tail->next->rectangle = SDL_CreateRGBSurface(SDL_HWSURFACE, MAP_PIXEL_SNAKE, MAP_PIXEL_SNAKE, 32, 0, 0, 0, 0);
    SDL_FillRect(tail->next->rectangle, NULL, snake->color);

    tail->next->next = NULL;

}

void SNAKE_changeColor(Snake* snake, Uint32 color)
{
    snake->color = color;
    Point* current = snake->head;

    while(current != NULL)
    {
        SDL_FillRect(current->rectangle, NULL, snake->color);
        current = current->next;
    }

}

void POINT_move(Point* point, char move_letter)
{
    switch (move_letter)
    {
    case 'U':
        point->y += -1;
        break;
    case 'D':
        point->y += 1;
        break;
    case 'R':
        point->x += 1;
        break;
    case 'L':
        point->x += -1;
        break;
    default:
        break;
    }

    point->last_move = move_letter;
}

void SNAKE_move(Snake* snake)
{
    if(snake == NULL)
    {
        printf("Snake NULL");
        return;
    }

    Point* previous = snake->head;
    Point* next = snake->head->next;

    POINT_move(previous, previous->next_move);
    previous->last_move = previous->next_move;


    while(next != NULL)
    {
        POINT_move(next, next->next_move); //Change in case of key pushed.
        next->next_move = previous->last_move;
        previous = next;
        next = next->next;
    }

}

void SNAKE_free(Snake* snake)
{
    Point* current = snake->head;
    Point* next = snake->head->next;

    while(next != NULL)
    {
        free(current->rectangle);
        free(current);

        current = next;
        next = next->next;
    }
}


