/*
Autor: Raja Waleed Ali
Datum: 13.11.23
Beschreibung: Tic Tac Toe Singleplayer.
*/

#include<stdio.h>
#include<time.h>
#include<limits.h>
#include<stdlib.h>
#include<math.h>

int main(){
    srand(time(NULL));
    char p1;
    int size, i, j, x, y, lTest, win, oCount=0;
    printf("Gib die Groesse des Spielfeldes ein! ");
    scanf("%d", &size);
    char feld[size][size];
    x=size/2;
    y=x;
    int z=0;
    int life=3;
    lTest=life;
    int points=0;
    win=0;
    for(i=0;i<size;i++){
        for(j=0;j<size;j++){
            feld[j][i]='-';
        }
    }
    for (i=0; i<size; i++){
        feld[rand()%size][rand()%size]='Z';
        feld[rand()%size][rand()%size]='O';
    }
    feld[x][y]='P';
    system("cls");
    printf("\n");
    for(i=0;i<=size;i++){
        for(j=0;j<size;j++){
            printf("\t%c |", feld[j][i]);
            if(feld[j][i]=='O'){
                oCount++;
            }
        }
        printf("\n");
    }

    while(win==0){
        fflush(stdin);
        p1=getch();
        system("cls");
        if (p1=='d'){
            y++;
        }else if(p1=='a'){
            y--;
        }else if(p1=='w'){
            x--;
        }else if(p1=='s'){
            x++;
        }else if(p1=='x'){
            return 0;
        }else{
            printf("Falsche eingabe!\n");
        }
        if(x>=size||x<0||y>=size||y<0){
            if (p1=='d'){
                y=0;
            }else if(p1=='a'){
                y=size;
            }else if(p1=='w'){
                x=size;
            }else if(p1=='s'){
                x=0; 
            }
        }

        if(feld[y][x]=='O'){
            points=points+10;
            if(points==oCount*10){
                win=1;
            }
        }else if(feld[y][x]=='Z'){          //kontrolliert feld auf ein Z
            life--;
            z=1;
            if(life==0){
                printf("!Game Over!\n Points: %d\n!Game Over!", points);
                return 0;
            }
        }

        if (p1=='d'){                       //Setzt Spieler auf Richtigem Feld
            feld[y][x]='P';
            if(feld[y+1][x]!='Z'){                       //schaut ob leben abgezogen wird
                feld[y+1][x]='-';
            }
        }else if(p1=='a'){
            feld[y][x]='P';
            if(feld[y-1][x]!='Z'){
                feld[y-1][x]='-';
            }
        }else if(p1=='w'){
            feld[y][x]='P';
            if(feld[y][x-1]!='Z'){
                feld[y][x-1]='-';
            }
        }else if(p1='s'){
            feld[y][x]='P';
            if(feld[y][x+1]!='Z'){
                feld[y][x+1]='-';
            }
        }
        printf("\n");                                           //Gibt Das Spielfeld aus
        for(i=0;i<size;i++){
            for(j=0;j<size;j++){
                printf("\t%c |", feld[j][i]);
            }
            printf("\n");
        }
        printf("\n Lifes: %d\tPoints: %d", life, points);

        if(z==1){
            feld[y][x]='Z';
            z=0;
        }

    }
    if(win==1){
        printf("\nGewonnen!");
    }
    return 0;
}