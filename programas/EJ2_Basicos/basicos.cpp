/**
 * @file tiposysalidas.cpp
 * @author Kmz Kuro (https://www.nekoapi.work.gd/)
 * @version 0.1
 * @date 2024-10-20
 * Este ejemplo muestra todo lo basico de C
 * Desde tipos de datos hasta sentencias de control como los bucles
 *
 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    /**
     * tipos de datos simples
     */

    // enteros
    int edad; // formato en salida %d
    int radio;
    int numero;

    int incremento;
    int decremento;

    // decimales
    float peso;               // formato %f
    double altura, resultado; // formato %lf, soporta mas decimales que float
    // para declarar varias variables de un mismo tipo se puede dar una coma y escribir sobre la misma linea

    // texto y caracteres
    char letra;     // formato %c, unicamente soporta una letra entre comillas simples
    char texto[30]; // formato %s, soporta una cadena de caracteres en doble comilla, especificando la longitud [n-1] = 29 caracteres

    // constantes nota: se declaran antes de las variables pero primero hay que entender los tipos
    const double PI = 3.14;
    // nota: se usa la palabra clave const antes, este tipo de valores no pueden cambiar, otra forma de hacer constantes es con macros

    printf("Ingrese su nombre: "); // salidas, se manejan con prinft

    // leer texto y guardarlo en texto
    fgets(texto, sizeof(texto), stdin);
    // nota: no es recomendable usar gets, ya que puede causar desbordamiento de memoria, esta funcion te evita de ello

    printf("Ingrese su edad: ");
    scanf(" %d", &edad); // usamos el ampersand (o como se escriba) para especificar la direccion en donde se va a escribir el valor

    printf("\nEdad %d,  nombre: %s", edad, texto);
    // si queremos imprimir valores usamos su formato y en comas escribimos las variables
    // \n es una secuencia de escape que usamos para dar un enter, leer: https://learn.microsoft.com/es-es/cpp/c-language/escape-sequences?view=msvc-170
    // analiza lo siguente

    printf("\nIngrese su peso: ");
    scanf(" %f", &peso);

    printf("\nIngrese su altura: ");
    scanf(" %lf", &altura);

    letra = 'a';

    printf("\nTu altura es de %lf y tu peso es %f, letra: %c", altura, peso, letra);

    printf("\nIngresa el radio del circulo: ");
    scanf(" %d", &radio);

    // asignamos valor a una variable
    resultado = PI * pow(radio, 2); // pow, funcion de potencia incluida en la libreria math

    printf("\nArea del circulo: %lf", resultado);
    printf("\nEscriba un numero: ");
    scanf(" %d", &numero);

    // condicion simple, operadores de relacion y logicos
    if (numero != 0)
    {
        printf("\nEl numero es diferente de cero");
    }

    // condicion if else
    if (numero >= 0)
    {
        printf("\nel numero es positivo");
    }
    else
    {
        printf("\nel numero es negativo");
    }

    // condicion multiple
    if (numero < 0)
    {
        printf("\nel numero esta en el dominio (-infinito, 0)");
    }
    else if (numero == 0)
    {
        printf("\nel numero es exactamente igual a cero");
    }
    else
    {
        printf("\nel numero esta en el dominio (0, infinito)");
    }

    // operadores logicos

    // operador Y (and), requiere que las dos relaciones sean verdaderas
    if (numero > 0 && numero < 10)
    {
        printf("\nel numero cumple con el dominio (0, 10)");
    }

    // operador O (or), cualquiera puede ser verdadero para que se pueda cumplir la condicion
    if (numero <= 0 || numero > 10)
    {
        printf("\nel numero es menor o igual a 0 o mayor a 10");
    }

    printf("\nel numero es: %d\n", numero);

    system("pause"); // system funcion de la libreria stdlib, controla la consola, la instruccion system hace una pausa
    system("cls");   // cls limpia la consola

    // switch case, es otra forma de tener condiciones

    printf("selecciona entre 1 o 0\n");

    scanf(" %d", &numero); // funcion getchar dentro de la libreria stdio, obtiene una tecla

    switch (numero) // ponemos la variable que queremos validar
    {
    case 1:                        // encontramos un coincidente con case
        printf("Presionaste 1\n"); // colocamos el codigo
        break;                     // colocamos break al final de nuestro codigo para romper el switch
    case 0:
        printf("Presionaste 0\n");
        break;
    default:
        printf("presionaste %d\n", numero);
        break;
    }

    system("pause");
    system("cls");

    // acumuladores y bucles

    printf("Bucle for, numeros del 2 al 10\n");

    for (incremento = 2; incremento <= 10; incremento += 2)
    {
        // for, primero es desde donde comenzamos, despues hasta donde terminamos y finalmente incrementar dos valores (+=2)
        printf("%d\n", incremento);
    }

    system("pause");
    system("cls");

    printf("Escribe un numero: ");
    scanf(" %d", &numero);

    printf("\nTabla del %d\n", numero);

    // bucle while, fuera de la instruccion se asigna el valor desde donde comenzamos a la variable incremento
    // en los parentesis del while va hasta donde terminamos, y dentro del bucle va el incremento
    incremento = 1;
    while (incremento <= 10)
    {
        printf("%d x %d = %d\n", numero, incremento, (numero * incremento));
        incremento++;
    }

    system("pause");
    system("cls");

    // analiza el siguente bucle y encuentra las similitudes a los otros bucles

    printf("conteo del 10 al 0\n");

    decremento = 10;
    do
    {
        printf("%d\n", decremento);
        decremento--;
    } while (decremento >= 0);

    system("pause && cls");
    // bucle infinito
    incremento = 0;
    while (true)
    { // se escribe un true para que siempre se este ejecutando
        incremento++;
        printf("numero %d\n", incremento);

        if (incremento == 5)
        {

            printf("Llegaste al 5 deseas salir? presiona (1) para si o (0) para no\n");
            scanf(" %d", &numero);

            if (numero == 1)
            {
                break; // la instruccion break rompe el bucle y lo finaliza
            }
            else
            {
                system("cls");
                incremento = 0;
                continue; // la instruccion continue vuelve a iniciar el bucle desde el principio
            }
        }
    }
}