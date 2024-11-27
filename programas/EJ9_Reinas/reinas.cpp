#include <stdio.h> 
// #include <graphics.h>
#include <math.h>

#define WIDTH 600
#define HEIGHT 400

// numero total de reinas y filas x columnas
const int n_reinas = 8;
int soluciones_t = 0;

// declaracion de funciones
void colocar_reina(int *reinas, int reinas_totales);
void imprime_tablon(int *reinas);
int validar(int *reinas, int reinas_totales);
// int igraph();

// funcion inicial
int main() {
    int reinas_totales = 0; // conteo de reinas colocadas
    int array[n_reinas]; // arreglo de reinas en columnas
    int i;

    // llenado del arreglo
    for(i = 0; i < n_reinas; i++) {
        array[i] = -1;
    }

    // llamada a la funcion recursiva, parametros (array[n], 0)
    colocar_reina(array, reinas_totales);
    printf("soluciones totales: %d\n", soluciones_t);
    // igraph();
    return 0;
}

// funcion recursiva
void colocar_reina(int *reinas, int c) {
    // caso base
    // prinmer condicion al ejecutarse (0 = 4)
    if(c == n_reinas) {
        imprime_tablon(reinas);
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

// int igraph() {
//     initwindow(WIDTH, HEIGHT);
//     readimagefile("corona.png", 10, 10, 100, 100);
//     getch();
//     return 0;
// }