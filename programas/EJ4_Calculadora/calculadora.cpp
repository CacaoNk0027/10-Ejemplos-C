/**
 * @file calculadora.cpp
 * @author your name (https://www.nekoapi.work.gd/)
 * @version 0.1
 * @date 2024-12-10
 * En este ejemplo haremos uso de la practica divide y venceras para hacer una calculadora
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// prototipos de funcion
double operar(int opcion);
void menu();
void bflush();

// funcion principal
int main()
{
    menu();
    return 0;
}

// definicion de la funcion menu
void menu()
{
    int opcion;
    double resultado;

    // bucle infinito para repetir el menu
    while (true)
    {
        printf("Menu de operaciones\n");
        printf("selecciona una opcion con respecto a su numero\n");
        printf("\n[1] Suma\n[2] Resta\n[3] Multiplicacion\n[4] Division\n[5] Potencia\n[6] Raiz\n[7] Salir\n\nEscribe la opcion: ");
        scanf("%d", &opcion);
        bflush();
        if (opcion < 1 || opcion > 7)
        {
            printf("Opcion invalida, vuelve a intentarlo\n");
            system("pause && cls");
            continue;
        }

        system("cls");

        // llamada a la funcion operar
        resultado = operar(opcion);

        printf("\n\nResultado: %.2lf\n", resultado);

        system("pause && cls");
    }
}

// definicion de la funcion operar con parametro opcion
double operar(int opcion)
{
    double numero1, numero2, resultado;

    if(opcion != 6) {
        if(opcion == 7) {
            exit(0);
        }
        printf("Ingresa el numero [1]: ");
        scanf("%lf", &numero1);
        bflush();

        printf("Ingresa el numero [2]: ");
        scanf("%lf", &numero2);
        bflush();
    } else {
        printf("Ingresa el numero: ");
        scanf("%lf", &numero1);
        bflush();
    }

    switch (opcion)
    {
    case 1:
        resultado = numero1 + numero2;
        break;
    case 2:
        resultado = numero1 - numero2;        
        break;
    case 3:
        resultado = numero1 * numero2;
        break;
    case 4:
        if(numero2 == 0) {
            printf("no se puede operar una division con 0 de denominador\n");
            resultado = 0;
            break;
        }
        resultado = numero1 / numero2;
        break;
    case 5:
        resultado = pow(numero1, numero2);
        break;
    case 6:
        if(numero1 < 0) {
            printf("no se puede operar una raiz con numero negativo de base\n");
            resultado = 0;
            break;
        }
        resultado = sqrt(numero1);
        break;
    }
    // devuelve el resultado de las operaciones dependiendo el caso que se haya dado
    return resultado;
}

void bflush()
{
    int c;
    do
    {
        c = getchar();
    } while (c != EOF && c != '\n');
}