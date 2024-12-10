#include <stdio.h>
#include <stdlib.h>

// estructura de un nodo
struct Nodo {
    int numero;
    struct Nodo *siguente;
};

/**
 * Tipo de dato estructura nodo de nombre lista
 * Evita escribir mas codigo
 * antes >> struct Nodo nodo = creaNodo(0);
 * despues >> nodo nodo = creaNodo(0);
 */
typedef struct Nodo *nodo;

// prototipos de funcion
nodo creaNodo(int dato);
int insertaInicio(nodo *li, int dato);
int insertaFinal(nodo *li, int dato);
int insertaEnXPos(nodo *li, int dato, int pos);
int cambiaValorXNodo(nodo *li, int nuevo, int pos);
int imprimeLista(nodo li);

// funcion principal
int main() {
    // primer puntero, no crea un nodo, apunta a null
    nodo apuntador_principal = NULL;

    // se le asigna al puntero el nuevo nodo para asi iniciar la lista
    apuntador_principal = creaNodo(0);

    // se usa el ampersand para pasar la direccion de memoria de la lista
    // esto es el paso de parametro por referencia
    insertaInicio(&apuntador_principal, 1);
    insertaFinal(&apuntador_principal, 2);
    insertaEnXPos(&apuntador_principal, 3, 2);
    
    // no se usa el ampersand por que se pasa el primer nodo el cual ya tiene asignada la direccion de memoria del anterior
    imprimeLista(apuntador_principal);
    return 0;
}

// crea una primer lista
nodo creaNodo(int dato) {
    // se crea un nuevo nodo
    nodo nodo_nuevo = (nodo)malloc(sizeof(struct Nodo));

    // se asigna el numero
    nodo_nuevo->numero = dato;

    /**
     * En esta parte se asigna null en el apuntador del nuevo nodo
     */
    nodo_nuevo->siguente = NULL;

    return nodo_nuevo;
}

// inserta al inicio de la lista
int insertaInicio(nodo *primer_nodo, int dato) {

    // crea un nuevo nodo
    nodo nodo_nuevo_auxiliar = creaNodo(dato);

    // al nuevo nodo le asigna la direccion de memoria de la lista
    nodo_nuevo_auxiliar->siguente = *primer_nodo;

    // cambia la lista para añadir el nuevo nodo entonces el apuntador principal apunta al nuevo nodo
    *primer_nodo = nodo_nuevo_auxiliar;
    return 0;
}

// inserta al final de la lista
int insertaFinal(nodo *primer_nodo, int dato) {

    // crea un nuevo nodo
    nodo nodo_nuevo_auxiliar = creaNodo(dato);

    // nodo temporal al que le asigna el primer nodo
    nodo nodo_actual = *primer_nodo;

    // si valida que la lista esta vacia
    if(*primer_nodo == NULL) {
        *primer_nodo = nodo_nuevo_auxiliar;
    } else {

        // recorre nodo por nodo mientras el apuntador siguente no sea NULL
        while(nodo_actual->siguente != NULL) {
            nodo_actual = nodo_actual->siguente;
        }

        // ya que recorrio todos al ultimo que era NULL le asigna el nuevo nodo auxiliar
        nodo_actual->siguente = nodo_nuevo_auxiliar;
    }
    return 0;
}

// inserta en una posicion cuales quiera el usuario de la lista
int insertaEnXPos(nodo *primer_nodo, int dato, int pos) {

    // crea un nuevo nodo
    nodo nodo_nuevo_auxiliar = creaNodo(dato);

    // crea un nodo temporal al que le asigna el primer nodo
    nodo nodo_actual = *primer_nodo;

    // esto solo es un incremento del bucle
    int i;

    if(pos < 0) return 0;

    // si la lista esta vacia asigna el nodo creado sin importar la posicion
    if(*primer_nodo == NULL) {
        *primer_nodo = nodo_nuevo_auxiliar;
        return 0;
    }

    // si la posicion es 0 inserta al inicio
    if(pos == 0) {
        insertaInicio(primer_nodo, dato);
        return 0;
    }

    i = 0;
    while(i < (pos - 1)) {

        // si la posicion es invalida libera la memoria asignada al nuevo nodo
        if(nodo_actual == NULL) {
            free(nodo_nuevo_auxiliar);
            printf("posicion invalida\n");
            return 0;
        }

        // recorre los nodos por medio de las direcciones
        nodo_actual = nodo_actual->siguente;
        i++;
    }
    
    // al nodo nuevo auxiliar le asigna la direccion de memoria que tiene el nodo actual
    nodo_nuevo_auxiliar->siguente = nodo_actual->siguente;

    // asi mismo al nodo actual le asigna la lista con el nuevo nodo
    nodo_actual->siguente = nodo_nuevo_auxiliar;

    return 0;
}

// cambiar el valor en cualquier nodo que quiera el usuario
int cambiaValorXNodo(nodo *li, int nuevo, int pos) {
    nodo temp = *li;
    int i = 0;

    while(i < (pos - 1)) {
        if(temp == NULL) {
            printf("posicion invalida\n");
            return 0;
        }
        temp = temp->siguente;
        i++;
    }
    temp->numero = nuevo;
    return 0;
}

// imprime la nodo total;
int imprimeLista(nodo li) {
    while (li != NULL) {
        printf("%d -> ", li->numero);
        li = li->siguente;
    }
    printf("NULL\n");
    return 0;
}

// funcion para liberar la memoria
int liberaMemoria(nodo *li)
{
    // crea un puntero que contiene la direccion de memoria del primer nodo
    nodo nodo_actual = *li;
    // crea un puntero temporal
    nodo nodo_siguiente;

    // bucle que recorre los nodos mientras no sea igual a null el siguente de nodo actual
    while (nodo_actual != NULL)
    {
        nodo_siguiente = nodo_actual->siguente;
        // se va liberando la memoria con free
        free(nodo_actual);
        nodo_actual = nodo_siguiente;
    }

    // el puntero principal se iguala a null
    *li = NULL;

    return 0;
}