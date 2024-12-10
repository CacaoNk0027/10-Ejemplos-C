/**
 * @file torresdehanoi.cpp
 * @author Kmz Kuro (https://www.nekoapi.work.gd/)
 * @version 0.1
 * @date 2024-10-20
 * Ejemplo sobre las torres de hanoi ingresando el concepto de recursividad
 */

#include <stdio.h>

// constante con el numero de discos
#define DISCOS 3

// prototipos de funcion
int hanoi(int discos, char inicio, char intermedio, char destino);

int main() {
    // llamamos la funcion recursiva
    hanoi(DISCOS, 'A', 'B', 'C');
}

// definicion de la funcion hanoi
int hanoi(int discos, char inicio, char intermedio, char destino) {
    // caso base
    if(discos == 1) {
        // si el numero de discos es 1 entonces termina la funcion recursiva en el caso no recursivo
        printf("Disco %d: %c -> %c\n", discos, inicio, destino);
    } else {
        // llamamos a la funcion recursiva restando un numero y jugando con el paso de parametros
        hanoi(discos-1, inicio, destino, intermedio);
        printf("Disco %d: %c -> %c\n", discos, inicio, destino);
        hanoi(discos-1, intermedio, inicio, destino);
    }
    return 0;
}