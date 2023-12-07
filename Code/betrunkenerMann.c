/*
Autor: Raja Waleed Ali
Datum: 4.12.23
Beschreibung: Betrunkener Mann simulation.
*/

#include<stdio.h>
#include<time.h>
#include<limits.h>
#include<stdlib.h>
#include<math.h>

void ausgabe(int y, int x, int laenge, int breite){
    char * feld[laenge*2][breite*2];
    int i, j;
    for(i=0;i<laenge*2;i++){
        for(j=0; j<breite*2; j++){
            feld[i][j]="-|";
        }
    }
    feld[y][x-1]="P|";
    //if(feld[y-1][x-1]=="-|"){ 
        system("cls");
        
        for(i=0;i<laenge*2;i++){
            printf("|");
            for(j=0; j<breite*2; j++){
                printf("%s", feld[i][j]);           //füllt feld mit der eingabe
            }
            printf("\n");
        }
    //}
}

int main(){
    srand(time(NULL));
    float laenge, breite;
    int x, y, zahl;
    int bewusstlos = 0;
    int wrongSide = 0;
    int win = 0;
    int loop;
    int durchlauf = 1000;
    printf("Gib die Laenge des Tunnels an!\n");
    scanf("%f", &laenge);
    printf("Gib die breite des Tunnels an!\n");
    scanf("%f", &breite);
    y=0;
    x=laenge;
    ausgabe(y, x, laenge, breite);
    for(int i = 0; i<durchlauf; i++){
        loop=0;
        while(loop==0){
            zahl=rand()%8+1;
            switch(zahl){
                case 1: x++; break;
                case 2: x--; break;
                case 3: y++; break;
                case 4: y--; break;
                case 5: y++; x++; break;
                case 6: y++; x--; break;
                case 7: y--; x++; break;
                case 8: y--; x--; break;
            }
            if (x<0||x>breite*2){
                //printf("Bewusstlos!");
                bewusstlos++;
                loop=1;
            }else if(y<0){
                //printf("Falsche Seite vom Tunnel");
                wrongSide++;
                loop=1;
            }else{
                ausgabe(y, x, laenge, breite);
            }
            if(y>=laenge*2){
                //printf("Ueberlebt!");
                win++;
                loop=1;
            }
            //_sleep(0.5);
        }
        y=0;
        x=laenge;
    }
    printf("Statistik von %d durchlaeufe:\nBewusstlos: %d\nFalsche Seite: %d\nUeberlebt: %d", durchlauf, bewusstlos, wrongSide, win);

    return 0;
}