#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//for mygetch
#include <unistd.h>
#include <ncurses.h>

//For UTF-8
#include <locale.h>

#define fila  27
#define columna 42

#define minf 0
#define minc 0
#define maxf (fila-1)
#define maxc (columna-1)
#define xInicio 10
#define yInicio 10

char tmp_map[fila][columna];
char map[fila][columna] = {
    {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
    {2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
    {2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
    {2,0,0,1,1,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
    {2,0,0,1,1,0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,2},
    {2,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,2},
    {2,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
    {2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
    {2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,2},
    {2,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,2},
    {2,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,2},
    {2,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,2},
    {2,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,2},
    {2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,2},
    {2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
    {2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
    {2,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,2},
    {2,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,2},
    {2,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,2},
    {2,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,2},
    {2,0,0,1,1,0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
    {2,0,0,1,1,0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
    {2,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,2},
    {2,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,2},
    {2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
    {2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
    {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2}
};

//Bloques

typedef struct blockUnbreakable {
    int x;
    int y;
} blockA;

typedef struct block {
    int x;
    int y;
} blockB;

//Tank
typedef struct tanks {
    double x = 0;
    double y = 0;
} Tanks;
Tanks tank;

//Funciones de Curses
void iniciar_Curses();
void finalizar_Curses();

//Funciones del juego
void Map();
int teclas(double *x, double *y);
void tank1(int y, int x);

int row,col;

int main() {
    blockB  B;
    blockA  A;
    setlocale(LC_ALL,"");
    iniciar_Curses();


    getmaxyx(stdscr,row,col);

    while(teclas(&tank.x,&tank.y) != KEY_BREAK){
     clear();
     Map();
     tank1( (int) tank.x, (int) tank.y);
     usleep(20000);

    }
    finalizar_Curses();
    return 0;
}

void iniciar_Curses(){
    initscr();
    curs_set(0);
    keypad(stdscr, TRUE);
    halfdelay(1);

}

void finalizar_Curses(){
    curs_set(1);
    endwin();
}


int teclas(double *x, double *y){

    int flecha;

    flecha = getch();
    //    check_collision();
    switch(flecha){

        case KEY_UP:
            *y += 1;
            if(*y > ((minf-1) + yInicio ))//Up limit 9
                *y -= 1;
            break;

        case KEY_LEFT:
            *x += 1;
            if(*x > ((minc-1) + xInicio ))//Left limit 9
                *x -= 1;
             break;

        case KEY_DOWN:
            *y -= 1;
            if( *y < ((yInicio)+ ( (-maxf)+1 )) )// Down limit -15
                *y += 1;
            break;

        case KEY_RIGHT:
            *x -= 1;
             if( *x < ((xInicio)+ ( (-maxc)+1 )) )// Right limit -30
                *x += 1;
            break;
    }
    return flecha;
}

void tank1(int x, int y) {
    int algo;

    algo=mvprintw(yInicio - y, xInicio - x,"H");
    if(ERR == algo){
        mvprintw(row-2,0,"This screen has %d rows and %d columns\n",row,col);
        mvprintw(row-1,0,"errah, %i,%i no es una direccio valida\n", yInicio - y, xInicio - x);
        /*
        fprintf(stderr, "errah, %i,%i no es una direccio valida\n", yInicio - y, xInicio - x);
        if((xInicio - x)<0)
              tank1(x+1, y);
        if((yInicio - y)<0)
            tank1(x, y+1);*/
    }
    mvprintw(row-1,0,"tank 1 está en, %i,%i", yInicio - y, xInicio - x);
    mvprintw(row-2,0,"tank 1 está en, %i,%i", y, x);
    refresh();
}

void Map(){
    for(int f = 0; f < fila; f++) {
        for (int c=0; c< columna; c++ ){

            if(map[f][c]==0)
                printw(" ");
            if(map[f][c]==1)
                printw("#");
            if(map[f][c]==2){
                const wchar_t* block = L"\u2588";
                addwstr(block);
            }
        }
        printw("\n");
    }
  refresh();
}
