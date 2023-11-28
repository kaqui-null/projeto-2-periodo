#include <stdio.h>
#include <stdlib.h>
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

    char escolha_menu = 0;
    escolha_menu = menu(escolha_menu);
    //usar escolha_menu para decidir mapa

    initscr();
    curs_set(0);
    keypad(stdscr, 1);
    clear();

    //skip colors

    while (1) {
        key = getch();
        // desenhar mapa escolhido, etc.
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
    initscr();
    curs_set(0);
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
