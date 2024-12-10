#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <math.h>

const int width = 1000;
const int height = 700;

// estructura de un nodo
struct Nodo
{
    int numero;
    struct Nodo *siguente;
};
// alias a la estructura
typedef struct Nodo *nodo;

// prototipos de funcion
nodo creaNodo(int dato);

int insertaInicio(nodo *li, int dato);
int insertaFinal(nodo *li, int dato);
int insertaEnXPos(nodo *li, int dato, int pos);
int cambiaValorXNodo(nodo *li, int nuevo, int pos);
int imprimeLista(nodo li);
int liberaMemoria(nodo *li);
int insert_i(nodo *li);
int insert_f(nodo *li);
int insert_e(nodo *li);
int cam_val(nodo *li);
int igraph(nodo *li);

void menu();
void rot_ins(char numB[4], const char caso[15]);
void rot_ens(char numB[4], const char texto[60]);
void rot_cam(char numB[4], const char texto[60]);
void arrow(int x1, int y1, int x2, int y2);

// funcion principal
int main()
{
    nodo apuntador_principal = NULL;

    igraph(&apuntador_principal);
    liberaMemoria(&apuntador_principal);

    return 0;
}

nodo creaNodo(int dato)
{
    nodo nodo_nuevo = (nodo)malloc(sizeof(struct Nodo));

    nodo_nuevo->numero = dato;
    nodo_nuevo->siguente = NULL;

    return nodo_nuevo;
}

int insertaInicio(nodo *primer_nodo, int dato)
{
    nodo nodo_nuevo_auxiliar = creaNodo(dato);

    nodo_nuevo_auxiliar->siguente = *primer_nodo;
    *primer_nodo = nodo_nuevo_auxiliar;
    
    return 0;
}

int insertaFinal(nodo *primer_nodo, int dato)
{
    nodo nodo_nuevo_auxiliar = creaNodo(dato);
    nodo nodo_actual = *primer_nodo;

    if (*primer_nodo == NULL)
    {
        *primer_nodo = nodo_nuevo_auxiliar;
    }
    else
    {
        while (nodo_actual->siguente != NULL)
        {
            nodo_actual = nodo_actual->siguente;
        }
        nodo_actual->siguente = nodo_nuevo_auxiliar;
    }

    return 0;
}

int insertaEnXPos(nodo *primer_nodo, int dato, int pos)
{
    nodo nodo_nuevo_auxiliar = creaNodo(dato);
    nodo nodo_actual = *primer_nodo;
    int i;

    if (pos < 0)
        return 0;
    if (*primer_nodo == NULL)
    {
        *primer_nodo = nodo_nuevo_auxiliar;
        return 0;
    }
    if (pos == 0)
    {
        insertaInicio(primer_nodo, dato);
        return 0;
    }

    i = 0;
    while (i < (pos - 1))
    {
        if (nodo_actual == NULL)
        {
            free(nodo_nuevo_auxiliar);
            return 1;
        }
        nodo_actual = nodo_actual->siguente;
        i++;
    }
    nodo_nuevo_auxiliar->siguente = nodo_actual->siguente;
    nodo_actual->siguente = nodo_nuevo_auxiliar;

    return 0;
}

int cambiaValorXNodo(nodo *li, int nuevo, int pos)
{
    nodo temp = *li;
    int i = 0;

    while (i < pos)
    {
        if (temp == NULL)
        {
            return 1;
        }
        temp = temp->siguente;
        i++;
    }
    temp->numero = nuevo;

    return 0;
}

int imprimeLista(nodo li)
{
    int posX = width * 0.2 + 40;
    int posY = height * 0.2;
    int i_mod = 0;
    char rotulo[44];

    cleardevice();

    sprintf(rotulo, "Principal");
    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 3);
    outtextxy(width * 0.1, posY + 10, rotulo);

    arrow(width * 0.2, posY + 25, width * 0.2 + 40, posY + 25);

    while (li != NULL)
    {
        sprintf(rotulo, "%d", li->numero);
        rectangle(posX, posY, posX + 80, posY + 50);
        line(posX + 60, posY, posX + 60, posY + 50);
        settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2);
        outtextxy(posX + 20, posY + 10, rotulo);
        li = li->siguente;
        posX += 100;
        arrow(posX - 30, posY + 25, posX, posY + 25);
    }

    sprintf(rotulo, "NULL");
    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 3);
    outtextxy(posX + 10, posY + 10, rotulo);

    while (true)
    {
        if (kbhit())
        {
            break;
        }
    }

    return 0;
}

int liberaMemoria(nodo *li)
{
    nodo nodo_actual = *li;
    nodo nodo_siguiente;

    while (nodo_actual != NULL)
    {
        nodo_siguiente = nodo_actual->siguente;
        free(nodo_actual);
        nodo_actual = nodo_siguiente;
    }

    *li = NULL;

    return 0;
}

int insert_i(nodo *li)
{
    char ch = '\0';
    char numB[4] = "";
    int i = 0;
    char rotulo[26];

    rot_ins(numB, "inicio");

    while (true)
    {
        if (kbhit())
        {
            ch = getch();

            rot_ins(numB, "inicio");

            if (ch == 13)
            {
                if (i > 0)
                {
                    break;
                }
                else
                {
                    sprintf(rotulo, "Debes ingresar un numero");
                    setcolor(RED);
                    outtextxy(width * 0.05, height * 0.4, rotulo);
                }
            }

            if (ch == 8)
            {
                if (i > 0)
                {
                    i--;
                    numB[i] = '\0';
                    rot_ins(numB, "inicio");
                }
            }

            if (ch >= '0' && ch <= '9')
            {
                if (i < sizeof(numB) - 1)
                {
                    numB[i] = ch;
                    i++;
                    rot_ins(numB, "inicio");
                }
            }
        }
        delay(100);
    }
    insertaInicio(li, atoi(numB));

    return 0;
}

int insert_f(nodo *li)
{
    char ch = '\0';
    char numB[4] = "";
    int i = 0;
    char rotulo[26];

    rot_ins(numB, "final");

    while (true)
    {
        if (kbhit())
        {
            ch = getch();

            rot_ins(numB, "final");

            if (ch == 13)
            {
                if (i > 0)
                {
                    break;
                }
                else
                {
                    sprintf(rotulo, "Debes ingresar un numero");
                    setcolor(RED);
                    outtextxy(width * 0.05, height * 0.4, rotulo);
                }
            }
            if (ch == 8)
            {
                if (i > 0)
                {
                    i--;
                    numB[i] = '\0';
                    rot_ins(numB, "final");
                }
            }

            if (ch >= '0' && ch <= '9')
            {
                if (i < sizeof(numB) - 1)
                {
                    numB[i] = ch;
                    i++;
                    rot_ins(numB, "final");
                }
            }
        }
        delay(100);
    }
    insertaFinal(li, atoi(numB));

    return 0;
}

int insert_e(nodo *li)
{
    char ch = '\0';
    char numB[4] = "";
    char posB[3] = "";
    int i = 0;
    int val;
    char rotulo[26];

    rot_ens(numB, "Escribe el numero para el nodo");

    while (true)
    {
        if (kbhit())
        {
            ch = getch();

            rot_ens(numB, "Escribe el numero para el nodo");

            if (ch == 13)
            {
                if (i > 0)
                {
                    break;
                }
                else
                {
                    sprintf(rotulo, "Debes ingresar un numero");
                    setcolor(RED);
                    outtextxy(width * 0.05, height * 0.4, rotulo);
                }
            }
            if (ch == 8)
            {
                if (i > 0)
                {
                    i--;
                    numB[i] = '\0';
                    rot_ens(numB, "Escribe el numero para el nodo");
                }
            }

            if (ch >= '0' && ch <= '9')
            {
                if (i < sizeof(numB) - 1)
                {
                    numB[i] = ch;
                    i++;
                    rot_ens(numB, "Escribe el numero para el nodo");
                }
            }
        }
        delay(100);
    }

    i = 0;
    rot_ens(posB, "ingresa la posicion en la cual deseas ingresar el nodo");

    while (true)
    {
        if (kbhit())
        {
            ch = getch();

            rot_ens(posB, "ingresa la posicion en la cual deseas ingresar el nodo");

            if (ch == 13)
            {
                if (i > 0)
                {
                    val = insertaEnXPos(li, atoi(numB), atoi(posB) - 1);
                    if (val)
                    {
                        sprintf(rotulo, "Posicion invalida");
                        setcolor(RED);
                        outtextxy(width * 0.05, height * 0.4, rotulo);
                    }
                    else
                    {
                        break;
                    }
                }
                else
                {
                    sprintf(rotulo, "Debes ingresar un numero");
                    setcolor(RED);
                    outtextxy(width * 0.05, height * 0.4, rotulo);
                }
            }
            if (ch == 8)
            {
                if (i > 0)
                {
                    i--;
                    posB[i] = '\0';
                    rot_ens(posB, "ingresa la posicion en la cual deseas ingresar el nodo");
                }
            }

            if (ch >= '0' && ch <= '9')
            {
                if (i < sizeof(posB) - 1)
                {
                    posB[i] = ch;
                    i++;
                    rot_ens(posB, "ingresa la posicion en la cual deseas ingresar el nodo");
                }
            }
        }
        delay(100);
    }

    return 0;
}

int cam_val(nodo *li)
{
    char ch = '0';
    char numB[4] = "";
    char posB[3] = "";
    int i = 0;
    int val;
    char rotulo[26];

    rot_cam(numB, "Escribe el numero para el nodo");

    while (true)
    {
        if (kbhit())
        {
            ch = getch();

            rot_cam(numB, "Escribe el numero para el nodo");

            if (ch == 13)
            {
                if (i > 0)
                {
                    break;
                }
                else
                {
                    sprintf(rotulo, "Debes ingresar un numero");
                    setcolor(RED);
                    outtextxy(width * 0.05, height * 0.4, rotulo);
                }
            }
            if (ch == 8)
            {
                if (i > 0)
                {
                    i--;
                    numB[i] = '\0';
                    rot_cam(numB, "Escribe el numero para el nodo");
                }
            }

            if (ch >= '0' && ch <= '9')
            {
                if (i < sizeof(numB) - 1)
                {
                    numB[i] = ch;
                    i++;
                    rot_cam(numB, "Escribe el numero para el nodo");
                }
            }
        }
        delay(100);
    }

    i = 0;
    rot_cam(posB, "ingresa la posicion del nodo a modificar");

    while (true)
    {
        if (kbhit())
        {
            ch = getch();

            rot_cam(posB, "ingresa la posicion del nodo a modificar");

            if (ch == 13)
            {
                if (i > 0)
                {
                    val = cambiaValorXNodo(li, atoi(numB), atoi(posB) - 1);
                    if (val)
                    {
                        sprintf(rotulo, "Posicion invalida");
                        setcolor(RED);
                        outtextxy(width * 0.05, height * 0.4, rotulo);
                    }
                    else
                    {
                        break;
                    }
                }
                else
                {
                    sprintf(rotulo, "Debes ingresar un numero");
                    setcolor(RED);
                    outtextxy(width * 0.05, height * 0.4, rotulo);
                }
            }
            if (ch == 8)
            {
                if (i > 0)
                {
                    i--;
                    posB[i] = '\0';
                    rot_cam(posB, "ingresa la posicion del nodo a modificar");
                }
            }

            if (ch >= '0' && ch <= '9')
            {
                if (i < sizeof(posB) - 1)
                {
                    posB[i] = ch;
                    i++;
                    rot_cam(posB, "ingresa la posicion del nodo a modificar");
                }
            }
        }
        delay(100);
    }
    
    return 0;
}

int igraph(nodo *li)
{
    char opc = '\0';
    initwindow(width, height);
    menu();

    while (true)
    {
        if (kbhit())
        {
            opc = getch();

            if (opc == 27)
            {
                break;
            }

            if (opc == 'a' || opc == 'A')
            {
                insert_i(li);
                menu();
            }

            if (opc == 'b' || opc == 'B')
            {
                insert_f(li);
                menu();
            }

            if (opc == 'c' || opc == 'C')
            {
                insert_e(li);
                menu();
            }

            if (opc == 'd' || opc == 'D')
            {
                cam_val(li);
                menu();
            }

            if (opc == 'e' || opc == 'E')
            {
                imprimeLista(*li);
                menu();
            }
        }

        delay(100);
    }
    closegraph();

    return 0;
}

void menu()
{
    char rotulo[55];

    cleardevice();
    sprintf(rotulo, "Menu de listas");

    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 5);
    outtextxy(width * 0.05, height * 0.1, rotulo);

    sprintf(rotulo, "Presiona la tecla indicada para cada opcion");

    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 3);
    outtextxy(width * 0.05, height * 0.2, rotulo);

    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2);
    sprintf(rotulo, "[a] Inserta inicio");
    outtextxy(width * 0.05, height * 0.3, rotulo);
    sprintf(rotulo, "[b] Inserta fin");
    outtextxy(width * 0.05, height * 0.35, rotulo);
    sprintf(rotulo, "[c] Inserta x pos");
    outtextxy(width * 0.05, height * 0.4, rotulo);
    sprintf(rotulo, "[d] Cambiar valor");
    outtextxy(width * 0.05, height * 0.45, rotulo);
    sprintf(rotulo, "[e] Mostrar lista");
    outtextxy(width * 0.05, height * 0.50, rotulo);
    sprintf(rotulo, "[ESC] presiona ESC para salir");
    outtextxy(width * 0.05, height * 0.60, rotulo);
}

void rot_ins(char numB[4], const char caso[15])
{
    char rotulo[55];
    cleardevice();
    setcolor(WHITE);
    sprintf(rotulo, "Ingresa al %s", caso);

    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 5);
    outtextxy(width * 0.05, height * 0.1, rotulo);

    sprintf(rotulo, "Escribe el numero y presiona enter cuando finalices");

    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 3);
    outtextxy(width * 0.05, height * 0.2, rotulo);

    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2);
    sprintf(rotulo, "Numero: %s", numB);
    outtextxy(width * 0.05, height * 0.3, rotulo);
}

void rot_ens(char buffer[4], const char texto[60])
{
    char rotulo[60];
    cleardevice();
    setcolor(WHITE);
    sprintf(rotulo, "Ingresa en X posicion");

    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 5);
    outtextxy(width * 0.05, height * 0.1, rotulo);

    sprintf(rotulo, "%s", texto);

    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 3);
    outtextxy(width * 0.05, height * 0.2, rotulo);

    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2);
    sprintf(rotulo, "Numero: %s", buffer);
    outtextxy(width * 0.05, height * 0.3, rotulo);
}

void rot_cam(char buffer[4], const char texto[60])
{
    char rotulo[60];
    cleardevice();
    setcolor(WHITE);
    sprintf(rotulo, "Cambia un valor");

    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 5);
    outtextxy(width * 0.05, height * 0.1, rotulo);

    sprintf(rotulo, "%s", texto);

    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 3);
    outtextxy(width * 0.05, height * 0.2, rotulo);

    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2);
    sprintf(rotulo, "Numero: %s", buffer);
    outtextxy(width * 0.05, height * 0.3, rotulo);
}

void arrow(int x1, int y1, int x2, int y2)
{
    double angulo = atan2(y2 - y1, x2 - x1);
    int x3 = x2 - 10 * cos(angulo + 3.1415 / 6);
    int y3 = y2 - 10 * sin(angulo + 3.1415 / 6);
    int x4 = x2 - 10 * cos(angulo - 3.1415 / 6);
    int y4 = y2 - 10 * sin(angulo - 3.1415 / 6);

    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x2, y2, x4, y4);
}