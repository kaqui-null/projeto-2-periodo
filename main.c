#include <stdio.h>
#include <stdlib.h>
#include <curses.h>

// TODO:

/// Inicialize variáveis globais aqui

/// Inicialize funções aqui e defina após main */

// player
void player_draw(int y, int x, int direction);

void player_walk(int direction_array[], int key);

// util

int main(int argc, char** argv){

    int key = 0;

    int player_direction[3];
    player_direction[0] = 5; // y
    player_direction[1] = 5; // x
    player_direction[2] = 1; // orientação

    initscr();
    curs_set(0);
    keypad(stdscr, 1);
    clear();


    player_draw(player_direction[0], player_direction[1], player_direction[2]);
    refresh();
    key = getch();
    clear();
    player_walk(player_direction, key);
    player_draw(player_direction[0], player_direction[1], player_direction[2]);
    refresh();
    napms(1000);

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

/* (end) funções Player */
