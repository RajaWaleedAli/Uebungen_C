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

int nachbar(zeilen, spalten, char mensch[zeilen][spalten], int posX, int posY){
    int neighbor = 0;
    if(mensch[posY][posX]=='X'){
        if(mensch[(posY+1+zeilen)%zeilen][posX]=='X'){
            neighbor++;
        }
        if(mensch[(posY-1+zeilen)%zeilen][posX]=='X'){
            neighbor++;
        }
        if(mensch[posY][(posX+1+spalten)%spalten]=='X'){
            neighbor++;
        }
        if(mensch[posY][(posX-1+spalten)%spalten]=='X'){
            neighbor++;
        }
        if(mensch[(posY+1+zeilen)%zeilen][(posX+1+spalten)%spalten]=='X'){
            neighbor++;
        }
        if(mensch[(posY-1+zeilen)%zeilen][(posX-1+spalten)%spalten]=='X'){
            neighbor++;
        }
        if(mensch[(posY-1+zeilen)%zeilen][(posX+1+spalten)%spalten]=='X'){
            neighbor++;
        }
        if(mensch[(posY+1+zeilen)%zeilen][(posX-1+spalten)%spalten]=='X'){
            neighbor++;
        }

        return neighbor;
    }
}

void spielfeld(int zeilen, int spalten, char mensch[zeilen][spalten]){
    int i, j;
    char feld[zeilen][spalten];
    system("cls");
        for(i=0;i<zeilen; i++){
            for(j=0; j<spalten; j++){
                feld[i][j]='-';
                if(mensch[i][j]=='X'){
                    feld[i][j]='X';
                }
            }
        }
        for(i=0;i<zeilen; i++){
            for(j=0; j<spalten; j++){
                printf("%c ", feld[i][j]);
            }
        printf("\n");
        } 
        for(i=0;i<zeilen; i++){
            for(j=0; j<spalten; j++){
                nachbar(zeilen, spalten, mensch, j, i);
            }
        } 
}

int main(){
    srand(time(NULL));
    int i, j, k, life, zeilen, spalten, count;
    char input;
    printf("Gib die Zeilenanzahl an! ");
    scanf("%d", &zeilen);
    printf("Gib die Spaltenanzahl an! ");
    scanf("%d", &spalten);
    printf("Gib die Anzahl der Menschen an! ");
    scanf("%d", &count);
    char mensch[zeilen][spalten];

    for(i=0;i<count; i++){
        j=rand()%zeilen;
        k=rand()%spalten;
        if(mensch[j][k]=='X'){
            i--;
        }else{
           mensch[j][k]='X'; 
        }
        
    }

    spielfeld(spalten, zeilen, mensch);
    while(input!='x'){

    }


    return 0;
}