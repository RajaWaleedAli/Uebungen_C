/*
Autor: Raja Waleed Ali
Datum: 6.12.23
Beschreibung: Galton-Brett.
*/

#include<stdio.h>
#include<time.h>
#include<limits.h>
#include<stdlib.h>
#include<math.h>

int main(){
    srand(time(NULL));
    int kugel, ebene, box, i, j, x;
    int loop=0;
    printf("Wieviele Kugeln sollen fallen? ");
    scanf("%d", &kugel);
    printf("Wieviele Ebenen soll es geben? ");
    scanf("%d", &ebene);
    box = ebene+1;
    j=ebene;
    for(i=ebene-1; i>0; i--){
        j=j+i;
    }
    int nail1[j];

    while(loop==0){
        x=rand()%2;
    }

    return 0;
}
