#include <stdio.h>
#include <unistd.h>
#include "screen.h"

void screenInit(int clear) {
    if (clear) {
        printf("\033[H\033[J");
    }
    printf("\033[?25l"); 
    fflush(stdout);
}
// esconde o cursor

void screenDestroy() {
    printf("\033[?25h"); 
    fflush(stdout);
} 
// mostra o cursor

void screenClear() {
    printf("\033[H\033[J");
}

void screenDrawBorders() {
    for (int x = MINX; x <= MAXX; x++) {
        printf("\033[%d;%dH#", MINY, x);
        printf("\033[%d;%dH#", MAXY, x);
    }
    for (int y = MINY; y <= MAXY; y++) {
        printf("\033[%d;%dH#", y, MINX);
        printf("\033[%d;%dH#", y, MAXX);
    }
}

void screenGotoxy(int x, int y) {
    printf("\033[%d;%dH", y, x);
}
