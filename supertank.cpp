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

//#define N 50
//#define M 50
#define MAX_BULLETS 100

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

int checkDirection;
/////////////////
int arrow;
int checkRIGHT = 0;
int checkLEFT = 0;
int checkUP = 0;
int checkDOWN = 0;
int lastKey = 0;
//Bloques

struct BlockUnbreakable {
    int x;
    int y;
};

struct Block {
    int x;
    int y;
};
//Tank
struct Tanks {
    double x = 0;
    double y = 0;
};

struct Bullets {
    double posx;
    double posy;
    double dir ;
    int alive = 0;

};

Tanks positionInitial;
Bullets position = {5,5,0,0};
void printBullet(struct Tanks tbullet);

//Funciones de Curses
void iniciar_Curses();
void finalizar_Curses();

//Funciones del juego
void Map();
//int teclas(struct Tanks *move, struct Tanks tbullet);
void tank1(int y, int x);

int row,col;
struct Bullets *bullet[MAX_BULLETS] = {NULL};

/////////////////////////////////////////////////////////////////////////// Funciones para la bala
Tanks positionTank(struct Tanks atank){
    return atank;
}

int direction(){
    if(checkRIGHT == -1)
        return 0;

    if(checkLEFT == 1)
        return 1;

    if(checkUP == 1)
        return 2;

    if(checkDOWN == -1)
        return 3;

}
struct Bullets spawn[MAX_BULLETS];
int i = 0;

void printBullet(struct Tanks tbullet){

    //    arrow = getch();
    /*    if(getch() =='b'){
          positionInitial = positionTank(tbullet);
          position.posx = positionInitial.x;

          position.posy = positionInitial.y;
          checkDirection = direction();
          }*/
        mvprintw(position.posy,position.posx, "*");

    mvprintw(40,70, "La direccion a la que mira es %i",checkDirection);
    if(position.posx<40 && position.posx>1 && position.posy>1 && position.posy<25){



        if(checkDirection == 0)
            position.posx++;

        if(checkDirection == 1)
            position.posx--;

        if(checkDirection == 2)
            position.posy--;

        if(checkDirection == 3)
            position.posy++;
    }
    else{
        mvprintw(position.posy,position.posx, " ");
        //    bullet[MAX_BULLETS] = bullet[--bullet_count];
    }

    mvprintw(20,60,"La posicion Y = %lf,La posicion X = %lf",position.posy,position.posx);

    mvprintw(30,80," spawn Y=%i,  X= %i, e I = %i",spawn[i].posy,spawn[i].posx,i );
    mvprintw(21,60,"La posicionInicial Y = %lf,La posicionInicial X = %lf",positionInitial.y,positionInitial.x);
    //      }


    refresh();
    }
int bulletAlive(int maxbullets){

    // activa una bala cada vez que le das a la flecha abajo
    //    int i = 0;
    if(i < maxbullets){ //&& getch() == KEY_DOWN){ incluir esta condicion en la funcion teclas dentro de case 'b'
        // // fill in the data
        spawn[i].alive = 1;
        mvprintw(spawn[i].posy,spawn[i].posx, "*");

        i++;
        //     mvprintw(30,80," spawn Y=%i,  X= %i",spawn[i].posy,spawn[i].posx);

    }
    }

    ////////////////////////////////////////////////////////////////////////////////////////////
    int teclas(struct Tanks *move, struct Tanks tbullet){





        arrow = getch();
        if(arrow != -1)
            lastKey = arrow;

        //    check_collision();
        mvprintw(row-5,0,"arrow es %i, y lastkey es %i", arrow, lastKey);
        mvprintw(row-6,0,"checkRIGHT: %i, checkDOWN: %i, checkLEFT: %i, checkUP: %i", checkRIGHT, checkDOWN, checkLEFT, checkUP);

        switch(arrow){

            case KEY_UP:
                checkRIGHT = 0;
                checkDOWN  = 0;
                checkLEFT  = 0;

                if(checkUP != 0){
                    (*move).y -= 1;
                    if((*move).y < minf + 1 )//((minf-1) ))//Up limit 9
                        (*move).y += 1;

                }
                checkUP += 1;
                if(checkUP > 1)
                    checkUP -= 1;
                break;

            case KEY_LEFT:
                checkRIGHT = 0;
                checkDOWN  = 0;
                checkUP    = 0;
                if(checkLEFT != 0){
                    (*move).x -= 1;
                    if((*move).x < minc + 1 )//Left limit 9
                        (*move).x += 1;

                }

                checkLEFT += 1;
                if(checkLEFT > 1)
                    checkLEFT -= 1;
                break;

            case KEY_DOWN:

                checkRIGHT = 0;
                checkLEFT  = 0;
                checkUP    = 0;
                if(checkDOWN != 0){
                    (*move).y += 1;
                    if( (*move).y > maxf-1 ) // Down limit -15
                        (*move).y -= 1;
                }

                checkDOWN -= 1;
                if(checkDOWN < -1)
                    checkDOWN += 1;
                break;

            case KEY_RIGHT:

                checkDOWN  = 0;
                checkLEFT  = 0;
                checkUP    = 0;

                if(checkRIGHT != 0){
                    (*move).x += 1;
                    if( (*move).x > maxc-1 )// Right limit -30
                        (*move).x -= 1;
                }
                checkRIGHT -= 1;
                if(checkRIGHT < -1)
                    checkRIGHT += 1;
                break;
            case 'b':
                positionInitial = positionTank(tbullet);
                position.posx = positionInitial.x;
                position.posy = positionInitial.y;
                checkDirection = direction();

                bulletAlive(MAX_BULLETS);
                break;

        }
        refresh();
        return arrow;
    }



    int main() {
        //    struct BlockUnbreakable blockU[N];
        //    struct Block block[M];
        struct Tanks tank = {7,7};


        setlocale(LC_ALL,"");
        iniciar_Curses();


        //struct Bullets *bullet[MAX_BULLETS] = {NULL};
        getmaxyx(stdscr,row,col);

        while(teclas(&tank,tank) != KEY_BREAK){
            clear();
            Map();
            tank1( (int) tank.x, (int) tank.y);
            teclas(&tank,tank);


            printBullet(tank);


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
        //    cbreak();
        nodelay(stdscr,true);
        //    noecho();

    }

    void finalizar_Curses(){
        curs_set(1);
        endwin();
    }




    void tank1(int x, int y) {
        int algo;


        algo=mvprintw(y, x,"H");

        //    algo=mvprintw(yInicio - y, xInicio - x,"H");
        if(ERR == algo){
            mvprintw(row-2,0,"This screen has %d rows and %d columns\n",row,col);
            mvprintw(row-1,0,"errah, %i,%i no es una direccio valida\n", y, x);
            /*
               fprintf(stderr, "errah, %i,%i no es una direccio valida\n", yInicio - y, xInicio - x);
               if((xInicio - x)<0)
               tank1(x+1, y);
               if((yInicio - y)<0)
               tank1(x, y+1);*/
        }
        mvprintw(row-1,0,"tank 1 está en, %i,%i", y, x);
        mvprintw(row-2,0,"tank 1 está en, %i,%i", y, x);
        //    mvprintw(row-3,0,"bala está en, %i,%i", pos.posy, pos.posx);

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
                    const wchar_t* block = L"\u2588"; // caracter utf-8
                    addwstr(block);    //necesitas ncursesw para caracteres largos tipo unicode
                    //                printw("X");
                }
            }
            printw("\n");
        }
        refresh();
    }

