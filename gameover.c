//codigo duvida - cor nao funciona
#include <curses.h>
/*
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

} */

/*
int main(){
    game_over();
}*/
