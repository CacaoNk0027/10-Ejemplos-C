/**
 * @file divideyvenceras.cpp
 * @author Kmz Kuro (https://www.nekoapi.work.gd/)
 * @version 0.1
 * @date 2024-10-23
 * En este ejemplo vamos a aprender a usar las funciones, desde declararlas, definirlas y el paso de parametros
 * Asi mismo mostrare como limpiar el buffer de entrada
 */

#include <stdio.h>
#include <string.h>

// prototipo de funciones
// estas se forman para decir que funciones va a ocupar nuestro programa, de esta manera podemos definirlas despues de definir la funcion main
void bflush();
// esta funcion incluye dos parametros son "variables dentro de la funcion"
int potencia(int base, int exponente);

int main() {
    int base, exponente, resultado;
    printf("Escribe la base del exponente: ");
    scanf("%d", &base);
    bflush();
    printf("Escribe el exponente: ");
    scanf("%d", &exponente);
    resultado = potencia(base, exponente);
    printf("\n\nResultado de la operacion: %d", resultado);
    return 0;
}

// definicion de la funcion potencia
int potencia(int base, int exponente) {
    int i, resultado = 1;
    i = 0;
    while(i < exponente) {
        resultado = resultado * base;
        i++;
    }
    return resultado;
}

// definicion de la funcion bflush, esta funcion nos ayuda a limpiar el buffer, para evitar que el programa se salte entradas de la consola
void bflush() {
    int c;
    do {
        c = getchar();
    } while(c != EOF && c != '\n');
}

// el concepto de divide y venceras consiste en divivir un problema mas grande en otros mas pequeños, a modo de que este pueda ser resuelto de mejor manera
// esto lo aplicamos en crear funciones para cada cosa, a modo de no escribir todo nuestro codigo en una sola funcion (el main)
// divide y venceras es una buena practica en programacion, que nos ayudara a tener una mejor estructura de nuestro codigo