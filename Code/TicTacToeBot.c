/*
Autor: Raja Waleed Ali
Datum: 6.11.23
Beschreibung: Tic Tac Toe singleplayer.
*/

#include<stdio.h>
#include<time.h>
#include<limits.h>
#include<stdlib.h>
#include<math.h>

int main(){
    srand(time(NULL));
    system("cls");
    int xP1, yP1, xP2, yP2, i, j, modus;
    int win = 0;
    int k;
    char feld[3][3];
    printf("\n\tTicTacToe\n    _______________________\n    |\tX1|\tX2|\tX3|\n____|_____|_______|_______|\n");
    for(i=0;i<3;i++){
        printf("|Y%d |", i+1);
        for(j=0;j<3;j++){
            feld[i][j]=' ';
            printf("\t%c |", feld[i][j]);
        }
        printf("\n");
    }
    printf("|___|_____|_______|_______|\n");
    i=0;
    printf("Die Koordinaten werden jeweils abwechslend Eingegeben im Format 'y x' (y/x=[1-3])\n");
    while(win==0){
        while(i==0){
            printf("\nP1 Eingabe (y x): ");
            scanf("%d %d", &yP1, &xP1);
            if(feld[yP1-1][xP1-1]==' '){
                feld[yP1-1][xP1-1]='X'; 
                system("cls");
                printf("\n\tTicTacToe\n    _______________________\n    |\tX1|\tX2|\tX3|\n____|_____|_______|_______|\n");
                for(i=0;i<3;i++){
                    printf("|Y%d |", i+1);                      //Beschriftet Y-Koordinate
                    for(j=0; j<3; j++){
                        printf("\t%c |", feld[i][j]);           //füllt feld mit der eingabe
                    }
                    printf("\n");
                }
                printf("|___|_____|_______|_______|\n");
                for(i=0;i<3;i++){                                                               //Bedingungen Für Sieg
                    j=0;
                        if(feld[i][j]=='X'&&feld[i][j+1]=='X'&&feld[i][j+2]=='X'){
                            win=1;
                            printf("Player 1 hat gewonnen!");
                            return 0;
                        }else if(feld[j][i]=='X'&&feld[j+1][i]=='X'&&feld[j+2][i]=='X'){
                            win=1;
                            printf("Player 1 hat gewonnen!");
                            return 0;
                        }else if(feld[0][0]=='X'&&feld[1][1]=='X'&&feld[2][2]=='X'){
                            win=1;
                            printf("Player 1 hat gewonnen!");
                            return 0;
                        }else if(feld[0][2]=='X'&&feld[1][1]=='X'&&feld[2][0]=='X'){
                            win=1;
                            printf("Player 1 hat gewonnen!");
                            return 0;
                        }
                }
                i=1;
            }else if(xP1>3||yP1>3){
                printf("Dieses Feld exestiert nicht! Gib noch eine Koordinate ein (x/y = [1-3])!\n");
                i=0;
            }else{
                printf("Dieses Feld ist schon besetzt! Gib noch eine Koordinate ein!\n");
                i=0;
            }
        }
        while(i==1){
            k=0;
            for(i=0;i<3;i++){
                for(j=0;j<3;j++){
                    if(feld[i][j]!=' '){                    //schaut ob unentschieden
                        k++;
                    }
                    if(k==9){
                        printf("Unentschieden!");
                        return 0;
                    }
                }
            }
            system("cls");
            yP2 = rand()%3+1;                               //erzeugt zufallszahlen für Singleplayer
            xP2 = rand()%3+1;
            printf("\nP2 Eingabe (y x): %d %d", yP2, xP2);
            if(feld[yP2-1][xP2-1]==' '){
                feld[yP2-1][xP2-1]='O'; 
                printf("\n\tTicTacToe\n    _______________________\n    |\tX1|\tX2|\tX3|\n____|_____|_______|_______|\n");
                for(i=0;i<3;i++){
                    printf("|Y%d |", i+1);                  //Beschriftet Y-Koordinate
                    for(j=0; j<3; j++){
                        printf("\t%c |", feld[i][j]);       //füllt feld mit der eingabe
                    }
                    printf("\n");
                }
                printf("|___|_____|_______|_______|\n");
                for(i=0;i<3;i++){                                                               //Bedingungen Für Sieg
                    j=0;
                        if(feld[i][j]=='O'&&feld[i][j+1]=='O'&&feld[i][j+2]=='O'){
                            win=1;
                            printf("Player 2 hat gewonnen!");
                            return 0;
                        }else if(feld[j][i]=='O'&&feld[j+1][i]=='O'&&feld[j+2][i]=='O'){
                            win=1;
                            printf("Player 2 hat gewonnen!");
                            return 0;
                        }else if(feld[0][0]=='O'&&feld[1][1]=='O'&&feld[2][2]=='O'){
                            win=1;
                            printf("Player 2 hat gewonnen!");
                            return 0;
                        }else if(feld[0][2]=='O'&&feld[1][1]=='O'&&feld[2][0]=='O'){
                            win=1;
                            printf("Player 2 hat gewonnen!");
                            return 0;
                        }
                }               
                i=0;     
            }else if(xP2>3||yP2>3){
                printf("Dieses Feld exestiert nicht! Gib noch eine Koordinate ein (x/y = [1-3])!\n");
                i=1;
            }else{
                printf("Dieses Feld ist schon besetzt! Gib noch eine Koordinate ein!\n");
                i=1;
            }
        }
    }
    return 0;
}