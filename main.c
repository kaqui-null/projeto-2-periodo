#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curses.h>
#include <math.h>

// TODO:

/// Inicialize variáveis globais aqui

/// Inicialize funções aqui e defina após main */

// player
void player_draw(int y, int x, int direction);

void player_walk(int direction_array[], int key);

int* player_use(int* direction);

// MENU
char menu(char escolha);

// SPLASH_SCREEN
void splash_screen();

// MAPAS
void draw_room_map1();
void draw_room_map2();

// GAME_OVER
void game_over();

int main(int argc, char** argv){
    int key = 0;

    int enemies_m1[4][2] = {{5, 7}, {21, 8}, {16, 116}, {23, 82}};
    int enemies_m2[3][2] = {{25, 51}, {23, 21}, {8, 11}};

    int player_direction[3];
    player_direction[0] = 5; // y
    player_direction[1] = 5; // x
    player_direction[2] = 1; // orientação

    int y_max, x_max;
    char* texto = "CUSTOMIZAR";
    y_max = (int) floor(LINES/2);
    x_max = (int) floor(COLS/2 - sizeof(texto));


    initscr();
    curs_set(0);
    keypad(stdscr, 1);
    clear();

    napms(500);
    char escolha_menu = 0;
    escolha_menu = menu(escolha_menu);
    //usar escolha_menu para decidir mapa

    //skip colors
    splash_screen();
    draw_room_map1();
    draw_room_map2();

    while (1) {
        key = getch();
        // desenhar mapa escolhido, etc.
        if (key == 'g') {
            game_over();
        }
        clear();
    }
    getch();
    endwin();
    return 0;
}


/* Utils */


/* funções Player */

void player_draw(int y, int x, int direction) {
    /// DIREÇÕES:
    ///Siga o sentido horário para o valor do index da direção;
    ///
    ///0 -> up, 1 -> right, 2 -> down, 3 -> left
    ///E -> DIRECTION_ERROR

    switch (direction){
        case (0):
            mvaddch(y, x, '^');
            break;
        case (1):
            mvaddch(y, x, '>');
            break;
        case (2):
            mvaddch(y, x, 'v');
            break;
        case (3):
            mvaddch(y, x, '<');
            break;
        default:
            mvaddch(y,x, 'E');
    }

}


void player_walk(int direction_array[], int key){
    if (key == KEY_LEFT){
        direction_array[1] -= 1;
        direction_array[2] = 3;
    } else if (key == KEY_RIGHT) {
        direction_array[1] += 1;
        direction_array[2] = 1;
    } else if (key == KEY_UP) {
        direction_array[0] -= 1;
        direction_array[2] = 0;
    } else if (key == KEY_DOWN) {
        direction_array[0] += 1;
        direction_array[2] = 2;
    }
}


int* player_use(int* direction) {
    int y, x, orientation, coord_y, coord_x;
    char vis_vertical;
    char vis_horizontal;

    y = direction[0];
    x = direction[1];
    orientation = direction[2];

    switch (orientation) {
        case (0):
            coord_y = y - 1;
            break;
        case (1):
            coord_x = x + 1;
            break;
        case (2):
            coord_y = y + 1;
            break;
        case (3):
            coord_x = x - 1;
            break;
        default:
            ;
    }

    int vis_vertical_coord[2] = {coord_y, x};
    int vis_horizontal_coord[2] = {y, coord_x};
    int vis_error[2] = {-1, -1}; /// ERROR VECTOR FOR : player_use()

    vis_horizontal = mvinch(y, coord_x);
    vis_vertical = mvinch(coord_y, x);

    if (vis_horizontal == ACS_DIAMOND){
        return vis_horizontal_coord;
    } else if (vis_vertical == ACS_DIAMOND) {
        return vis_vertical_coord;
    } else {
        return vis_error;
    }
}

/* MENU */
char menu(char escolha){
    char* arraymenu[] = {"DIGITE O NUMERO", "CORRESPONDENTE", " ", "1. facil", "2. dificil", "3. sair"};
    int i, j, x, y, x1, y1;

    char* string[] ={" __ __ __ __","|   |   |    __|    |  |   |   |","|       |    |       |   |   |","||||_||__|___|"};

    clear();
    getmaxyx(stdscr, y, x);
    getmaxyx(stdscr, y1, x1);
    x = (x - 10) / 2;
    y = (y - 3) / 2;
    x1 = (x1 - 26) / 2;
    y1 = (y1 - 15) / 2;

    for (j = 0; j < 4; j++){
        mvprintw(y1 + j, x1, "%s", string[j]);
    }

    for(i = 0; i < 6; i++){
        refresh();
        mvprintw(y + i, x, "%s", arraymenu[i]);
    }

    printw("s\n");
    escolha = getch();

    if (escolha == '1'){
        printw("voce selecionou facil");
    } else if(escolha == '2') {
        printw("voce selecionou dificil");
    } else if(escolha == '3'){
        printw("voce selecionou sair");
    } else {
        printw("ERROR 404");
    }

    return escolha;
}

/* SPLASH_SCREEN */
void splash_screen(){
    clear();
    refresh();
    start_color();

    init_pair(1,COLOR_WHITE, COLOR_WHITE);

    int y, y2, x, x2, i, j;

    char text[17][98] = {

        {' ',' ',' ',' ',' ','*','*','*','*','*',' ','*','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ','*','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ','*','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*','*','*','*',' ','*',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*','*','*','*',' ','*','*',' ',' ',' ',' '},
        {' ',' ','*','*','*','*','*','*',' ',' ','*',' ','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','*','*','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','*','*','*','*',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ','*','*','*','*','*','*',' ',' ','*',' ',' ','*','*','*','*','*',' ',' ',' ',' ',' ',' ',' ',' ','*','*','*','*','*','*',' ',' ','*','*','*','*',' ','*',' '},
        {' ','*','*',' ',' ',' ','*',' ',' ','*',' ',' ','*','*',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','*',' ',' ','*','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','*',' ',' ','*','*','*','*',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ','*',' ',' ','*',' ',' ',' ',' ',' ','*','*','*','*','*',' ',' ',' ',' ',' ','*','*',' ',' ',' ','*',' ',' ','*',' ','*','*','*','*',' ',' '},
        {'*',' ',' ',' ',' ','*',' ',' ','*',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','*','*',' ',' ',' ','*','*','*',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','*','*',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ','*',' ',' ','*','*',' ',' ',' ',' ',' ','*',' ','*','*',' ',' ',' ',' ',' ','*',' ',' ',' ',' ','*',' ',' ','*',' ',' ',' ','*','*',' ',' ',' '},
        {' ',' ',' ',' ','*',' ',' ','*',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','*','*','*',' ',' ',' ',' ','*','*','*',' ',' ',' ',' ',' ','*',' ',' ','*','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','*','*','*',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ','*','*',' ','*','*',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ','*','*',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ','*','*',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ','*','*',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ','*','*',' ','*','*',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ','*','*',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ','*','*',' ',' ',' ','*','*',' ',' ',' ','*','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ','*','*',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ','*','*',' ','*','*','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ','*','*',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ','*','*',' ',' ',' ','*','*',' ',' ','*','*','*','*',' ',' ','*',' ',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ','*','*',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ','*','*','*','*','*','*',' ',' ',' ',' ',' '},
        {' ',' ',' ','*','*',' ','*','*',' ',' ','*','*','*',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ','*','*',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ','*','*',' ',' ',' ','*','*',' ','*',' ',' ','*','*','*','*',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ','*','*',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ','*','*','*','*','*',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ','*','*',' ','*','*',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ','*','*',' ',' ',' ','*','*',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ','*','*',' ',' ',' ','*','*','*',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ','*','*',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ','*',' ',' ','*','*',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ','*','*',' ',' ','*','*',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ','*','*',' ',' ','*','*',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ',' ','*','*',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ',' ','*','*',' ','*',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ','*','*',' ','*',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ','*',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ','*','*','*','*',' ',' ',' ',' ',' ',' ','*','*','*',' ',' ',' ',' ',' ',' ',' ','*','*','*',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*','*',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*','*',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' '},
        {' ','*',' ',' ','*','*','*','*',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*','*','*','*','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*','*','*','*','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*','*','*','*','*','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','*','*','*','*','*','*','*','*','*','*','*',' ',' '},
        {'*',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ','*','*','*','*','*','*',' ',' ',' ',' ',' '},
        {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
        {' ','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    };

    char text2[] = "PRESSIONE QUALQUER TECLA PARA CONTINUAR >>>";

    int length = sizeof(text)/sizeof(text[0]);
    getmaxyx(stdscr,y,x);
    y = (y-length)/2;
    x = (x-98)/2;


    for(i=0;i<17;i++){
        for(j=0;j<98;j++){

            mvprintw(y+i,x+j, "%c",text[i][j]);
            refresh();
        }
        napms(20);
        printw("\n");
    }

    int length2 = sizeof(text2)/sizeof(text2[0]);
    getmaxyx(stdscr, y2,x2);
    x2=x2-length2;

    napms(1000);

    mvprintw(y2-2,x2-2, "%s", text2);

    getch();
}

/* MAPA1 */
void draw_room_map1(){
 clear();
    initscr();
    refresh();

    int i,j,k,l,m,y,x;
    int numero_salas = 7;
    int dimensoes_salas[7][2] = {{8,16}, {9,13}, {10,15}, {6,30}, {15,15},{8,23},{8,24}};

    int coordenadas_salas[7][2] = {{3,5}, {22,35}, {19,5},{3,65},{13,110}, {9,30},{18,68}};

    for(i=0;i<numero_salas;i++){
        int altura = dimensoes_salas[i][0];
        int comprimento = dimensoes_salas[i][1];
        y = coordenadas_salas[i][0];
        x = coordenadas_salas[i][1];

        for(j=0;j<comprimento;j++){
            for(k=0;k<altura;k++){
                mvprintw(y,x+j, "*");
                mvprintw(y+k,x, "*");
                mvprintw(y+altura,x+j, "*");
                mvprintw(y+k,x+comprimento, "*");
            }
        }
    }

    int corredor_vertical = 10;
    int dimensoes_vertical[] = {7,3,4,9,2,4,4,2,7,3};
    int coordenadas_vertical[10][2] = {{10,6},{17,18},{28,6},{23,27},{29,78},{26,124},{10,111},{8,105},{4,30},{16,69}};

    for(i=0;i<corredor_vertical;i++){
        int vertical = dimensoes_vertical[i];
        int y_vertical = coordenadas_vertical[i][0];
        int x_vertical = coordenadas_vertical[i][1];
        for(j=y_vertical;j<y_vertical+vertical;j++){
            mvprintw(j,x_vertical,"||");
        }
    }

    int corredor_horizontal = 9;
    int dimensoes_horizontal[] = {12,20,11,33,45,6,13,38,19};
    int coordenadas_horizontal[9][2] = {{16,7},{31,7},{22,27},{30,45},{29,79},{10,105},{8,92},{3,30},{16,50}};

    for(m=0;m<corredor_horizontal;m++){
        int horizontal = dimensoes_horizontal[m];
        int y_horizontal = coordenadas_horizontal[m][0];
        int x_horizontal = coordenadas_horizontal[m][1];
        for(l=x_horizontal; l<x_horizontal+horizontal;l++){
            mvprintw(y_horizontal,l,"=");
        }
    }

    getch();
}

/* MAPA2 */
void draw_room_map2(){

    clear();
    initscr();

    int i,j,k,l,m,y,x;
    int numero_salas = 5;
    int dimensoes_salas[5][2] = {{8,16}, {10,15},{6,30},{15,15},{8,24}};

    int coordenadas_salas[5][2] = {{4,10},{19,10},{3,65},{13,110},{20,50}};

    for(i=0;i<numero_salas;i++){
        int altura = dimensoes_salas[i][0];
        int comprimento = dimensoes_salas[i][1];
        y = coordenadas_salas[i][0];
        x = coordenadas_salas[i][1];

        for(j=0;j<comprimento;j++){
            for(k=0;k<altura;k++){
                mvprintw(y,x+j,"*");
                mvprintw(y+k,x,"*");
                mvprintw(y+altura,x+j,"*");
                mvprintw(y+k,x+comprimento, "*");
            }
        }


    }

    int corredor_vertical = 9;
    int dimensoes_vertical[] = {8,4,10,4,4,5,2,5,5};
    int coordenadas_vertical[9][2] = {{9,6},{16,18},{22,27},{28,12},{26,124},{10,111},{8,105},{4,30},{25,79}};

    for(i=0;i<corredor_vertical;i++){
        int vertical = dimensoes_vertical[i];
        int y_vertical = coordenadas_vertical[i][0];
        int x_vertical = coordenadas_vertical[i][1];
        for(j=y_vertical;j<y_vertical+vertical;j++){
            mvprintw(j,x_vertical,"||");
        }
    }

    int corredor_horizontal = 10;
    int dimensoes_horizontal[] = {12,15,24,5,6,45,6,13,38,7};
    int coordenadas_horizontal[10][2] = {{16,7},{31,13},{22,27},{9,7},{8,25},{29,79},{10,105},{8,92},{3,30},{24,73}};

    for(m=0;m<corredor_horizontal;m++){
        int horizontal = dimensoes_horizontal[m];
        int y_horizontal = coordenadas_horizontal[m][0];
        int x_horizontal = coordenadas_horizontal[m][1];
        for(l=x_horizontal; l<x_horizontal+horizontal;l++){
            mvprintw(y_horizontal,l,"=");
        }
    }

    getch();
}

/* GAME OVER */
void game_over(){

    start_color();
    init_pair(1, COLOR_BLACK, COLOR_RED);
    curs_set(0);

    int i = 0;
    int y, x;

    char gameOver[] = "GAME OVER!!";
    int length = sizeof(gameOver) / sizeof(gameOver[0]);

    getmaxyx(stdscr,y,x);
    y = y/2;
    x = (x-length)/2;

    do {

        refresh();
        clear();
        napms(1000);

        attron(COLOR_PAIR(1));
        mvprintw(y,x, "%s", gameOver);
        attroff(COLOR_PAIR(1));

        refresh();
        clear();
        napms(1000);
        i++;
    }while(i<5);

}
