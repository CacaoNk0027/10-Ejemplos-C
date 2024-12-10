/**
 * @file torresdehanoi_graphics.cpp
 * @author Kmz Kuro (https://www.nekoapi.work.gd/)
 * @version 0.1
 * @date 2024-10-20
 * Ejemplo sobre el juego de las torres de hanoi, haciendo uso de 3 dicos
 * 
 * RECOMIENDO ESPERAR A QUE ESTE DOCUMENTO SE EDITE CON COMENTARIOS PARA NO CONFUNDIRSE
 */


#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>

#define WIDTH 800
#define HEIGHT 600

const int rows = WIDTH / 4;
struct disco
{
    int num;
    int width;
    int height;
    int posX;
    int posY;
};
struct disco discos[3];
struct disco *punt;
int size = sizeof(discos) / sizeof(discos[0]);
int incremento = 0;

int hanoi(int disco, char origen, char intermedio, char destino);

// FUNCIONES DEL GRAFICO
int igraph();
int pbars();
int assign();
int printrg();
int divwhile(int i);
int move(int disco, char destino);

int main()
{
    igraph();
    return 0;
}

int hanoi(int disco, char origen, char intermedio, char destino)
{
    if (disco == 1)
    {
        delay(1000);
        move(disco, destino);
    }
    else
    {
        hanoi(disco - 1, origen, destino, intermedio);
        delay(1000);
        move(disco, destino);
        hanoi(disco - 1, intermedio, origen, destino);
    }
    return 0;
}

// grafico

int pbars()
{
    int posX, posY, x, y;
    char texto[2], rotulo[17];

    posY = HEIGHT * .5;
    posX = 0;

    y = 0;

    sprintf(rotulo, "Torres de hanoi");
    
    setcolor(WHITE);
    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 4);
    outtextxy(WIDTH * .1, HEIGHT * .1, rotulo);
    
    if(incremento == 0) {
        sprintf(rotulo, "Paso inicial");
    } else {
        sprintf(rotulo, "Paso %d", incremento);
    }
    incremento++;

    setcolor(WHITE);
    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2);
    outtextxy(WIDTH * .1, HEIGHT * .3, rotulo);

    settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);

    while (y < 20)
    {
        x = 0;
        while (x < 3)
        {
            posX += rows;
            sprintf(texto, "|");
            outtextxy(posX - x, posY, texto);
            outtextxy(posX - x + 12, posY, texto);
            x++;
        }
        posX = 0;
        posY += 10;
        y++;
    }

    rectangle(rows - 50, posY, rows*3+70, posY+30);
    return 0;
}

int assign()
{
    int i, w = 100, posY = HEIGHT * .8 - 10, posX = rows - 40;
    punt = discos;

    i = 0;
    while (i < size)
    {
        punt->width = w;
        punt->height = 20;
        punt->num = i + 1;
        punt->posX = posX;
        punt->posY = posY;
        w -= 20;
        posY -= 25;
        posX += 10;
        punt++;
        i++;
    }

    punt -= size;
    return 0;
}

int divwhile(int in) {
    int i = 0;
    punt-=in;
    while(i < size) {
        printrg();
        punt++;
        i++;
    }
    punt-=size;
    punt+=in;
    return 0;
}

int move(int disco, char destino)
{
    int i;
    if(disco == 1) {
        punt+=2;
        if(destino == 'A') {
            punt->posX = rows - 20;
            cleardevice();
            pbars();
            divwhile(2);
            punt-=2;
        } else
        if(destino == 'B') {
            punt->posX = rows - 20;
            punt->posX += rows;
            cleardevice();
            pbars();
            divwhile(2);
            punt-=2;
        } else
        if(destino == 'C') {
            punt->posX = rows - 20;
            punt->posX += rows*2;
            cleardevice();
            pbars();
            divwhile(2);
            punt-=2;
        }
    }
    if(disco == 2) {
        punt++;
        if(destino == 'A') {
            punt->posX = rows - 10;
            cleardevice();
            pbars();
            divwhile(1);
            punt--;
        } else
        if(destino == 'B') {
            punt->posX = rows - 10;
            punt->posX += rows-20;
            cleardevice();
            pbars();
            divwhile(1);
            punt--;
        } else
        if(destino == 'C') {
            punt->posX = rows - 10;
            punt->posX += rows*2-20;
            cleardevice();
            pbars();
            divwhile(1);
            punt--;
        }
    }
    if(disco == 3) {
        if(destino == 'A') {
            punt->posX = rows;
            cleardevice();
            pbars();
            divwhile(0);
        } else
        if(destino == 'B') {
            punt->posX = rows;
            punt->posX += rows;
            cleardevice();
            pbars();
            divwhile(0);
        } else
        if(destino == 'C') {
            punt->posX = rows;
            punt->posX += rows*2-40;
            cleardevice();
            pbars();
            divwhile(0);
        }
    }
    return 0;
}

int printrg() {
    setfillstyle(SOLID_FILL, rand() % 15);
    bar(punt->posX, punt->posY, punt->posX + punt->width, punt->posY + punt->height);
    setcolor(WHITE);
    rectangle(punt->posX, punt->posY, punt->posX + punt->width, punt->posY + punt->height);
    return 0;
}

int igraph()
{
    char texto[10];
    int i;

    assign();

    initwindow(WIDTH, HEIGHT);
    pbars();

    i = 0;
    while (i < size)
    {
        printrg();
        punt++;
        i++;
    }

    punt-=size;

    hanoi(3, 'A', 'B', 'C');

    getch();
    exit(0);
    return 0;
}