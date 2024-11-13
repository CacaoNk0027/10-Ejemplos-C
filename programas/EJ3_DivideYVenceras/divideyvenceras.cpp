/**
 * @file divideyvenceras.cpp
 * @author Kmz Kuro (https://www.nekoapi.line.pm/)
 * @version 0.1
 * @date 2024-10-23
 * En este ejemplo vamos a aprender a usar las funciones, desde declararlas, definirlas y el paso de parametros
 * Asi mismo mostrare como limpiar el buffer de entrada
 */

#include <stdio.h>
#include <string.h>

void bflush();

int main() {
    // programa no iniciado
    return 0;
}

void bflush() {
    int c;
    do {
        c = getchar();
    } while(c != EOF && c != '\n');
}