/*
Autor: Raja Waleed Ali
Datum: 7.12.23
Beschreibung: Game of life.
Fehler: Funktioniert hoffentlich richtig!
*/

#include<stdio.h>
#include<time.h>
#include<limits.h>
#include<stdlib.h>
#include<math.h>

int nachbar(int zeilen, int  spalten, char mensch[zeilen][spalten], int posX, int posY){
    int neighbor = 0;
    int kontrolle=0;

    if(mensch[posY][posX]=='X'){
        neighbor++;
        kontrolle=1;
    }
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
    if(kontrolle==1 && neighbor == 4){
        neighbor--;
    }

    return neighbor;
}

int spielfeld(int zeilen, int spalten, char mensch[zeilen][spalten], char feld[zeilen][spalten], int i, int j){
    int neighbor;
        
    printf("%c ", feld[i][j]);

    neighbor=nachbar(zeilen, spalten, mensch, j, i);
    if(neighbor==3){
        return 1;
    }else{
        return 0;
    }              
}

int main(){
    srand(time(NULL));
    int i, j, k, zeilen, spalten, count;
    char input;
    printf("Gib die Zeilenanzahl an! ");
    scanf("%d", &zeilen);
    printf("Gib die Spaltenanzahl an! ");
    scanf("%d", &spalten);
    printf("Gib die Anzahl der Menschen an! ");
    scanf("%d", &count);
    char mensch[zeilen][spalten];
    char feld[zeilen][spalten];

    for(i=0;i<count; i++){
        j=rand()%zeilen;
        k=rand()%spalten;
        if(mensch[j][k]=='X'){
            i--;
        }else{
           mensch[j][k]='X'; 
        }
        
    }
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
            spielfeld(spalten, zeilen, mensch, feld, i, j);
        }
        printf("\n");
    }
    int loop = 1;
    int output;
    while(loop==1){
        input=getch();
        if(input=='x'){
            system("cls");
            return 0;
        }else{
            system("cls");
            for(i=0;i<zeilen; i++){
                for(j=0; j<spalten; j++){
                    output=spielfeld(spalten, zeilen, mensch, feld, i, j);
                    if(output==1){
                        feld[i][j]='X';
                    }else if(output==0){
                        feld[i][j]='-';
                    }else{
                        printf("ERROR!");
                        return 0;
                    }
                }
                printf("\n");
            }

            for(i=0;i<zeilen; i++){
                for(j=0; j<spalten; j++){
                    mensch[i][j]=feld[i][j];
                }
            }   
        }
    }
    return 0;
}