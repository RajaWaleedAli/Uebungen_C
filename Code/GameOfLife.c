/*
Autor: Raja Waleed Ali
Datum: 7.12.23
Beschreibung: Game of life.
*/

#include<stdio.h>
#include<time.h>
#include<limits.h>
#include<stdlib.h>
#include<math.h>

int nachbar(){

}

void spielfeld(int spalten, int zeilen, char* feld[zeilen][spalten], char* mensch[zeilen][spalten]){
    int i, j;
    for(i=0;i<zeilen, i++){
        for(j=0; j<spalten; j++){
            feld[i][j]="- ";
            if(mensch[i][j]=="X "){
                feld[i][j]="X ";
            }
            printf("%s")
        }
    }

}

int main(){
    int i, j, life, zeilen, spalten;
    printf("Gib die Zeilenanzahl an! ");
    scanf("%d", &zeilen);
    printf("Gib die Spaltenanzahl an! ");
    scanf("%d", &spalten);
    char feld[zeilen][spalten];

    return 0;
}