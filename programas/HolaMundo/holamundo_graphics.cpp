#include <stdio.h>
#include <graphics.h>

#define WIDTH 600
#define HEIGHT 400 

int main() {
    char texto[20];
    sprintf(texto, "Hola mundo");

    initwindow(WIDTH, HEIGHT);
    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2);
    outtextxy(WIDTH*.4, HEIGHT*.4, texto);
    
    getch();
}