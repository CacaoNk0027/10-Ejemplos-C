/**
 * @file holamundo_graphics.cpp
 * @author Kmz Kuro (https://www.nekoapi.work.gd/)
 * @version 0.1
 * @date 2024-10-20
 * Este ejemplo enseña a como iniciar el modo grafico y como imprimir un texto en el mismo
 * 
 */

// se importan la libreria estandar y la libreria graphics.h
#include <stdio.h>
#include <graphics.h>

// definimos macros 
#define WIDTH 600 // anchura de la ventana
#define HEIGHT 400 // altura

int main() {
    // las variables que declaremos siempre van hasta arriba del resto del codigo
    // no es recomendable hacer uso de definiciones intermedias
    char texto[20];

    // asigno "hola mundo" a la variable texto
    // lo hago asi y no inicializo para evitar advertencias en el uso de la funcion outtextxy
    sprintf(texto, "Hola mundo");

    // se inicia el modo grafico con la funcion initwindow, especificando la anchura y la altura
    initwindow(WIDTH, HEIGHT);

    // establecemos un estilo en el texto, fuente sans serif, direccion horizontal y de tamaño 2
    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2);

    // imprimimos el texto a un 40% de la altura y la anchura de la ventana
    outtextxy(WIDTH*.4, HEIGHT*.4, texto);
    
    // hacemos una pausa, es necesario hacerla con getch para evitar que se trabe la pantalla
    getch();

    // fin
    return 0;
}