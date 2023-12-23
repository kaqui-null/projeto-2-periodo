/*
typedef struct {
    int hp;
    int forca;
    int origin_y;
    int origin_x;
    int direction;
    
    int *player_pos;
    int *player_y;
    int *player_x;
} Inimigo;


void inimigo(Inimigo *Inimigo, int hp, int forca, int *origin, int *player_pos) {
    Inimigo->hp = hp;
    Inimigo->forca = forca;
    Inimigo->origin_y = origin[0];
    Inimigo->origin_x = origin[1];
    Inimigo->direction = origin[2];

    Inimigo->player_pos = player_pos;
    Inimigo->player_y = player_pos[0];
    Inimigo->player_x = player_pos[1];
}

int check_surrounding(Inimigo *Inimigo) {
    for (int i = Inimigo->origin_y - 1; i <= Inimigo->origin_y + 2; i++) {
        for (int j = Inimigo->origin_x - 1; j <= Inimigo->origin_x + 2; j++) {
            if (Inimigo->player_pos[0] == i && Inimigo->player_pos[1] == j) {
                return 1;
            }
        }
    }
    return 0;
}
//verificar se o check surrounding funciona com +2 ou com +1

int morte(Inimigo *Inimigo) {
    if (Inimigo->hp > 0) {
        return 0;
    } else {
        return 1;
    }
}
*/
