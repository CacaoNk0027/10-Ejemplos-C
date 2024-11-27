#include <stdio.h> 
#include <graphics.h>
#include <math.h>

#define WIDTH 700
#define HEIGHT 600

// numero total de reinas y filas x columnas
const int n_reinas = 8;
int soluciones_t = 0;

// declaracion de funciones
void colocar_reina(int *reinas, int reinas_totales);
void imprime_tablon(int *reinas);
int validar(int *reinas, int reinas_totales);
int igraph();
int g_sol(int *reinas);
void corona(int posX, int posY);
// funcion inicial
int main() {
    igraph();
    return 0;
}

// funcion recursiva
void colocar_reina(int *reinas, int c) {
    // caso base
    // prinmer condicion al ejecutarse (0 = 4)
    if(c == n_reinas) {
        imprime_tablon(reinas);
        g_sol(reinas);
        printf("\n\n");
    } else {
        // incremento en la reina (cambio de posicion)
        for(reinas[c] = 0; reinas[c] < n_reinas; reinas[c]++) {
            // validacion en la funcion (array[n], 0)
            if(validar(reinas, c)) {
                // llamada a funcion recursiva (array[n], 1)
                colocar_reina(reinas, c+1);
            }
        }
    }
}

// validacion
int validar(int *reinas, int c) {
    int i;
    // incremento con respecto a la posicion de la reina
    for(i = 0; i < c; i++) {
        // la primer condicion es para validar sobre la misma columna o fila, no se
        // la segunda, despues de la o, es para validar sobre diagonales
        if(reinas[i] == reinas[c] || abs(c-i) == abs(reinas[c] - reinas[i])) {
            return 0;
        }
    }
    return 1;
}

void imprime_tablon(int *reinas) {
    int filas, columnas;
    soluciones_t++;
    for(filas = 0; filas < n_reinas; filas++) {
        for(columnas = 0; columnas < n_reinas; columnas++) {
            if(reinas[filas] == columnas) {
                printf("Q ");
            } else {
                printf(".  ");
            }
        }
        printf("\n");
    }
}

int g_sol(int *reinas) {
    int i, posX = WIDTH * 0.05, posY = HEIGHT * 0.01, x = 0;
    char rotulo[50];

    sprintf(rotulo, "Reinas que no atacan");
    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 4);
    outtextxy(posX+50, posY, rotulo);

    sprintf(rotulo, "Solucion %d", soluciones_t);
    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 3);
    outtextxy(WIDTH * .75, HEIGHT * .2, rotulo);
    
    sprintf(rotulo, "reinas[%d] = { %d, %d, %d, %d, %d, %d, %d, %d }", n_reinas, 
        reinas[0], reinas[1], reinas[2], reinas[3], reinas[4], reinas[5], reinas[6], reinas[7]
    );
    outtextxy(posX+50, HEIGHT * .8, rotulo);

    for(i = 0; i < (n_reinas * n_reinas); i++) {
        if((i % 8) == 0) {
            posY += 50;
            posX = WIDTH * 0.05;
            x++;
        }
        posX += 50;
        if(((i + x) % 2) == 0) {
            setfillstyle(SOLID_FILL, LIGHTGRAY);
        } else {
            setfillstyle(SOLID_FILL, DARKGRAY);
        }
        bar(posX, posY, posX + 45, posY + 45);
    }
    posX = WIDTH * 0.05 + 73; 
    posY = HEIGHT * 0.01 + 73;
    for(i = 0; i < n_reinas; i++) {
        for(x = 0; x < reinas[i]; x++) {
            posY += 50;
        }
        corona(posX-12, posY-10);
        posY = HEIGHT * 0.01 + 73;
        posX += 50;
    }

    if(soluciones_t == 92) {
        while(!kbhit()) {
            sprintf(rotulo, "Soluciones totales: %d", soluciones_t);
            settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2);
            outtextxy(WIDTH*.7, HEIGHT * .5, rotulo);

            sprintf(rotulo, "Presione cualquier tecla para continuar");
            settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2);
            outtextxy(WIDTH*.05 + 50, HEIGHT * .9, rotulo);
        }
    } else {
        sprintf(rotulo, "Espere a que finalice de mostrar las soluciones");
        settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2);
        outtextxy(WIDTH*.05 + 50, HEIGHT * .9, rotulo);
    }

    delay(700);
    cleardevice();
    return 0;
}

int igraph() {
    
    int reinas_totales = 0; // conteo de reinas colocadas
    int array[n_reinas]; // arreglo de reinas en columnas
    int i;

    // llenado del arreglo
    for(i = 0; i < n_reinas; i++) {
        array[i] = -1;
    }
    // llamada a la funcion recursiva, parametros (array[n], 0)
    
    initwindow(WIDTH, HEIGHT);
    colocar_reina(array, reinas_totales);
    while(!kbhit());
    closegraph();
    return 0;
}

void corona(int posX, int posY) {
    int x1, x2, x3; 
    int y1, y2, y3;
    int i;

    x1 = posX; 
    x2 = posX + 5; 
    x3 = posX - 10;
    y1 = posY + 10; 
    y2 = posY + 10; 
    y3 = posY;

    i = 0;
    while(i < 5) {

        line(x1, y1, x2, y2);
        line(x2, y2, x3, y3);
        line(x3, y3, x1, y1);

        setfillstyle(SOLID_FILL, YELLOW);
        floodfill((x1 + x2 + x3) / 3, (y1 + y2 + y3) / 3, WHITE);

        x1+=5;
        x2+=5;
        x3+=11;

        i++;
    }

    setfillstyle(SOLID_FILL, YELLOW);
    bar(posX, y1+5, x2-5, y1+10);

    setfillstyle(SOLID_FILL, YELLOW);
    bar(posX-2, y1+12, x2-3, y1+14);
}