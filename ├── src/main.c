#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "keyboard.h"
#include "screen.h"
#include "timer.h"

#define MAX_SNAKE_LENGTH 100

typedef struct {
    int x, y;
} Point;

typedef enum {
    UP, DOWN, LEFT, RIGHT
} Direction;

Point snake[MAX_SNAKE_LENGTH];
int snake_length;
Direction dir;
Point food;
int game_over = 0;

void init_game() {
    screenInit(1);
    keyboardInit();
    srand(time(NULL));

    snake_length = 5;
    int start_x = (MINX + MAXX) / 2;
    int start_y = (MINY + MAXY) / 2;
    for (int i = 0; i < snake_length; i++) {
        snake[i].x = start_x - i;
        snake[i].y = start_y;
    }

    dir = RIGHT;

    food.x = rand() % (MAXX - MINX - 2) + MINX + 1;
    food.y = rand() % (MAXY - MINY - 2) + MINY + 1;
}

void end_game() {
    keyboardDestroy();
    screenDestroy();
}

void handle_input() {
    if (keyhit()) {
        int key = readch();
        switch (key) {
            case 'w':
            case 'W':
                if (dir != DOWN) dir = UP;
                break;
            case 's':
            case 'S':
                if (dir != UP) dir = DOWN;
                break;
            case 'a':
            case 'A':
                if (dir != RIGHT) dir = LEFT;
                break;
            case 'd':
            case 'D':
                if (dir != LEFT) dir = RIGHT;
                break;
            case 'q':
            case 'Q':
                game_over = 1;
                break;
        }
    }
}

void update_snake() {
    for (int i = snake_length - 1; i > 0; i--) {
        snake[i] = snake[i - 1];
    }

    switch (dir) {
        case UP:
            snake[0].y--;
            break;
        case DOWN:
            snake[0].y++;
            break;
        case LEFT:
            snake[0].x--;
            break;
        case RIGHT:
            snake[0].x++;
            break;
    }

    if (snake[0].x <= MINX || snake[0].x >= MAXX ||
        snake[0].y <= MINY || snake[0].y >= MAXY) {
        game_over = 1;
    }

    for (int i = 1; i < snake_length; i++) {
        if (snake[0].x == snake[i].x && snake[0].y == snake[i].y) {
            game_over = 1;
            break;
        }
    }

    if (snake[0].x == food.x && snake[0].y == food.y) {
        if (snake_length < MAX_SNAKE_LENGTH) {
            snake[snake_length] = snake[snake_length - 1];
            snake_length++;
        }
        food.x = rand() % (MAXX - MINX - 2) + MINX + 1;
        food.y = rand() % (MAXY - MINY - 2) + MINY + 1;
    }
}

void draw_screen() {
    screenClear();
    screenDrawBorders();

    screenGotoxy(food.x, food.y);
    printf("O");

    for (int i = 0; i < snake_length; i++) {
        screenGotoxy(snake[i].x, snake[i].y);
        if (i == 0) {
            printf("X");
        } else {
            printf("o");
        }
    }

    fflush(stdout);
}

int main() {
    init_game();

    int game_tick = 100;
    timerInit(game_tick);

    while (!game_over) {
        handle_input();
        update_snake();
        draw_screen();

        while (!timerTimeOver()) {
            usleep(1000);
        }
        timerDestroy();
        timerInit(game_tick);
    }

    screenClear();
    screenGotoxy((MINX + MAXX) / 2 - 5, (MINY + MAXY) / 2);
    printf("Game Over!");
    fflush(stdout);

    timerInit(2000);
    while (!timerTimeOver()) {
        usleep(1000);
    }
    timerDestroy();

    end_game();
    return 0;
}
