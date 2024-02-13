/*
Autor: Raja Waleed Ali
Klasse: 3BT
Datum: 13.02.2024
Fach: TP
Beschreibung: erstellt eine Bitlist.
*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int printAsk(int, int);                 //auflistung der Funktionen, welche verwendet werden
int printAsk2(int);
void printArr(char *);
void clear(char *, int);
int paste(char *, int, int, int);

int main(){
    system("cls");                      //loescht Inhalt vom Terminal (nur Windows)
    char bitList[100]={0};
    int mode, mode2, j, k, load, platzhalter;
    int  i=0;
    bool control;
    int save=0;
    int repeat[100];
    mode2=0;

    for(j=0;j<100;j++){                 //initialisiert den Array
        bitList[j]='-';
    }

    do{
        printf("waehle zwischen:\nFirst Fit(1)\nNext Fit(2)\nBest Fit(3)\nQuick Fit(4)\n");      //Algorithmus auswaelen
        scanf("%d", &mode);    
    }while(mode<1||mode>4);

    while(1){                           //unendliche Schleife
        mode2=printAsk2(mode2);
        if(mode2==3){
            return 0;
        }
        load=printAsk(i, mode2);
        i++;
        if(mode==1){
            if(mode2==1){
                clear(bitList, load);
                i--;
            }else{
                control=false;
                for(j=0; j<100; j++){
                    if(bitList[j]=='-'){
                        load = paste(bitList, j, load, i);
                    }
                }
                if(load!=-1){
                    printf("nicht genug Speicher frei!\n");
                }
            }
        }else if(mode==2){
            if(mode2==1){
                clear(bitList, load);
                i--;
            }else{
                control=false;
                for(j=save; j<100; j++){
                    if(bitList[j]=='-'){
                        save=j;
                        load = paste(bitList, j, load, i);
                    }
                    if(load==-1){
                        break;
                    }
                }
                if(j>=100){
                    save=0;
                }
                if(load!=-1){
                    printf("nicht genug Speicher frei!\n");
                    i--;
                }
            }
        }else if(mode==3){
            if(mode2==1){
                clear(bitList, load);
                i--;
            }else{
                control=false;
                for(j=0;j<100;j++){
                    repeat[j]=100;
                }
                repeat[0]=99;
                for(j=0; j<100; j++){
                    if(bitList[j]=='-'){
                        for(k=load;k>=0;k--){
                            if(bitList[j+k]=='-'){
                                control=true;
                            }else{
                                control=false;
                                break;
                            }
                        }
                    }
                    if(control==true){
                        repeat[j]=0;
                        for(k=j;bitList[j]!='-';j++){
                            repeat[k]++;
                        }
                    }
                }
                platzhalter=100;
                for(j=0;j<100;j++){
                    if(repeat[j]>=0){
                        if(repeat[j]<platzhalter){
                            platzhalter=j;
                        }
                    }
                }
                while(load>=0){
                    bitList[platzhalter+load]='A'+i-1;
                    load--;
                }
            }
            if(load!=-1){
                printf("nicht genug Speicher frei!\n");
                i--;
            }
        }
        printArr(bitList);
    }

    return 1;   //fehler
}

int printAsk(int i, int mode){
    int load;
    if(mode==2){
        printf("Speichergroesse von Prozess %c angeben\n", 'A'+i);
        scanf("%d", &load);
        return load;
    }else{
        printf("Welchen Prozess willst du beenden?(0-26)\n");
        scanf("%d", &load);
        return load-1;
    }
}

int printAsk2(int mode2){
    do{
        printf("\nmoechtest du speicher freigeben (1) oder etwas speichern(2)?\nAlles Beenden(3)\n");
        scanf("%d", &mode2);
    }while(mode2<1||mode2>3);
    return mode2;
}
void printArr(char bitList[]){
    int j;
    for(j=0;j<100;j++){
        printf("%c", bitList[j]);
    }
}

void clear(char bitList[], int load){
    int j;
    for(j=0;j<100;j++){
        if(bitList[j] == load+'A'){
            bitList[j]='-';
        }
    }
}

int paste(char bitList[], int j, int load, int i){
    int k;
    bool control=false;
    for(k=load;k>=0;k--){
        if(bitList[j+k]=='-'){
            control=true;
        }else{
            control=false;
            break;
        }
    }
    if(control==true){
        while(load>=0){
            bitList[j+load]='A'+i-1;
            load--;
        }
    }
    return load;
}