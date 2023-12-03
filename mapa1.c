#include <curses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
int draw_room_map1(){

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
*/
/*
int main(){
    draw_room_map1();
}*/
