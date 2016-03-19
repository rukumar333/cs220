#include <stdio.h>
#include <math.h>

void func(int x){
    if(x > 100) x++;
    else x--;
}

int main(){
    enum strikers { Giroux, Bony, Rooney, Hazard, Aguero, Costa, Kane } player;
    enum teams { Arsenal, ManCity, ManU, Chelsea, Tottenham } team;
    /* team = Arsenal; */
    /* player = Rooney; */
    if (player==Giroux) team=Arsenal;
    else if (player==Bony) team=ManCity;
    else if (player==Rooney) team=ManU;
    return 1;
}
