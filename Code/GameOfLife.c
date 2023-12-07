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

void spielfeld(int spalten, int zeilen, char mensch[zeilen][spalten]){
    int i, j;
    int x=0;
    char feld[zeilen][spalten]
    for(i=0;i<zeilen, i++){
        for(j=0; j<spalten; j++){
            feld[i][j]="- ";
            if(mensch[i][j]=='X'){
                feld[i][j]='X';
            }
            x++;
            printf("%s ", feld[i][j]);
        }
        printf("\n");
    }
    if(x==zeilen*spalten){
        for(i=0;i<zeilen, i++){
            for(j=0; j<spalten; j++){
                printf("%s ", feld[i][j]);
            }
        printf("\n");
        }
        x=0;
    }
}

int main(){
    int i, j, life, zeilen, spalten, count;
    printf("Gib die Zeilenanzahl an! ");
    scanf("%d", &zeilen);
    printf("Gib die Spaltenanzahl an! ");
    scanf("%d", &spalten);
    printf("Gib die Anzahl der Menschen an! ");
    scanf("%d", &count);
    char mensch[zeilen][spalten];
    spielfeld(spalten, zeilen)

    return 0;
}