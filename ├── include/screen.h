#ifndef SCREEN_H
#define SCREEN_H

#define MINX 1
#define MINY 1
#define MAXX 40
#define MAXY 20

void screenInit(int clear);
void screenDestroy();
void screenClear();
void screenDrawBorders();
void screenGotoxy(int x, int y);

#endif
