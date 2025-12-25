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
    int i, j, k, x, y, z, win;
    printf("Gib die Groesse des Spielfeldes ein! ");
    scanf("%d", &i);
    char feld[i][i];
    x=i/2;
    y=x;
    int lose=3;
    z=lose;
    int points=0;
    win=0;
    for(j=0;j<i;j++){
        for(k=0;k<i;k++){
            feld[k][j]='-';
        }
    }
    for (j=0; j<i; j++){
        feld[rand()%i][rand()%i]='Z';
        feld[rand()%i][rand()%i]='O';
    }
    feld[x][y]='P';
    system("cls");
    printf("\n");
    for(j=0;j<=i;j++){
        for(k=0;k<i;k++){
            printf("\t%c |", feld[k][j]);
        }
        printf("\n");
    }

    while(win==0){
        fflush(stdin);
        p1=getch();
        system("cls");
        if (p1=='d'){
            y++;
            if(feld[y][x]=='Z'){
                lose--;
                if (lose==0){
                    printf("!Game Over!\n Points: %d\n!Game Over!", points);
                    return 0;
                }
            }
            if(feld[y][x]=='O'){
                points=points+10;
                if(points==i*10){
                    win=1;
                }
            }
            feld[y][x]='P';
            feld[y-1][x]='-';
        }else if(p1=='a'){
            y--;
            if(feld[y][x]=='Z'){
                lose--;
                if (lose==0){
                    printf("!Game Over!\n Points: %d\n!Game Over!", points);
                    return 0;
                }
            }
            if(feld[y][x]=='O'){
                points=points+10;
                if(points==i*10){
                    win=1;
                }
            }
            feld[y][x]='P';
            feld[y+1][x]='-';
        }else if(p1=='w'){
            x--;
            if(feld[y][x]=='Z'){
                lose--;
                if (lose==0){
                    printf("!Game Over!\n Points: %d\n!Game Over!", points);
                    return 0;
                }
            }
            if(feld[y][x]=='O'){
                points=points+10;
                if(points==i*10){
                    win=1;
                }
            }
            feld[y][x]='P';
            feld[y][x+1]='-';
        }else if(p1=='s'){
            x++;
            if(feld[y][x]=='Z'){
                lose--;
                if (lose==0){
                    printf("!Game Over!\n Points: %d\n!Game Over!", points);
                    return 0;
                }
            }
            if(feld[y][x]=='O'){
                points=points+10;
                if(points==i*10){
                    win=1;
                }
            }
            feld[y][x]='P';
            feld[y][x-1]='-';
        }else if(p1=='x'){
            return 0;
        }else{
            printf("Falsche eingabe!\n");
        }
        if(x>=i||x<0||y>=i||y<0){
            printf("ausserhalb des Feldes!\n");
            if (p1=='d'){
                y--;
                feld[y][x]='P';
                feld[y+1][x]=' ';
            }else if(p1=='a'){
                y++;
                feld[y][x]='P';
                feld[y-1][x]=' ';
            }else if(p1=='w'){
                x++;
                feld[y][x]='P';
                feld[y][x-1]=' ';
            }else if(p1=='s'){
                x--; 
                feld[y][x]='P';
                feld[y][x+1]=' ';
            }
        }
        printf("\n");
        for(j=0;j<i;j++){
            for(k=0;k<i;k++){
                printf("\t%c |", feld[k][j]);
            }
            printf("\n");
        }
        printf("\n Lifes: %d\tPoints: %d", lose, points);

        if(lose<z){
            if (p1=='d'){
                z=lose;
                feld[y][x]='Z';
                printf("%c x=%d y=%d", p1, x, y);
            }else if(p1=='a'){
                z=lose;
                feld[y][x]='Z';
                printf("%c x=%d y=%d", p1, x, y);
            }else if(p1=='w'){
                z=lose;
                feld[y][x]='Z';
                printf("%c x=%d y=%d", p1, x, y);
            }else if(p1=='s'){
                z=lose;
                feld[y][x]='Z';
                printf("%c x=%d y=%d", p1, x, y);
            }
        }
    }
    if(win==1){
        printf("\nGewonnen!");
    }
    return 0;
}