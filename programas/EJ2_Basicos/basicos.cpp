/**
 * @file tiposysalidas.cpp
 * @author Kmz Kuro (https://www.nekoapi.line.pm/)
 * @version 0.1
 * @date 2024-10-20
 * Este ejemplo muestra todo lo basico de C
 * Desde tipos de datos hasta sentencias de control como los bucles
 * 
 */

#include <stdio.h>

int main() {
    /**
     * tipos de datos simples
     */

    // enteros
    int edad; // formato en salida %d
    int radio;

    // decimales
    float peso; // formato %f
    double altura; // formato %lf, soporta mas decimales que float

    // texto y caracteres
    char letra = 'A'; // formato %c, unicamente soporta una letra entre comillas simples
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

    printf("\nsu nombre es: %s y su edad %d", texto, edad); 
    // si queremos imprimir valores usamos su formato y en comas escribimos las variables
    // \n es una secuencia de escape que usamos para dar un enter, leer: https://learn.microsoft.com/es-es/cpp/c-language/escape-sequences?view=msvc-170 
    // analiza lo siguente 

    printf("\nIngrese su peso: ");
    scanf(" %f", &peso);

    printf("\nIngrese su altura: ");
    scanf(" %lf", &altura);    

    // ejemplo aun no terminado ... continuare despues
}