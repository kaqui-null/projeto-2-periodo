#include <curses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
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
*/
/*
int main(){
    draw_room_map2();
}*/
