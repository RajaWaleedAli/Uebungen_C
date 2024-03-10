/*
Autor: Raja Waleed Ali
Klasse: 3BT
Fach: TP
Beschreibung: erstellt eine Bitlist.
*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
//auflistung der Funktionen, welche verwendet werden
int printAsk(int, int);                 
int printAsk2(int);
int printErr(int, int);
void printArr(char *);
void clear(char *, int);
int paste(char *, int, int, int);       
//ende der Auflistung
int main(){
    system("cls");                      //Loescht Inhalt vom Terminal (nur Windows)
    char bitList[101];
    int mode, mode2, j, k, load, platzhalter;
    int  i=0;
    bool control;
    bool control2;
    bool again;
    int load2;
    int save=0;
    int saveArr[100];
    int load2;
    mode2=0;

    for(j=0;j<101;j++){                 //initialisiert den Array
        bitList[j]='-';
    }
    do{
        printf("waehle zwischen:\nFirst Fit(1)\nNext Fit(2)\nBest Fit(3)\n");      //Algorithmus auswaelen
        scanf("%d", &mode);    
    }while(mode<1||mode>3);
    while(1){                           //unendliche Schleife
        mode2=printAsk2(mode2);
        if(mode2==3){                   //beendet Programm
            return 0;
        }
        load=printAsk(i, mode2);
        i++;
        //First Fit
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
                i=printErr(load, i);
            }
        //Ende First Fit
        //Anfang Next Fit    
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
                i=printErr(load, i);
            }
        //Ende Next Fit
        //Anfang Best Fit 
        }else if(mode==3){
            if(mode2==1){
                clear(bitList, load);
            }else{
                control=false;
                control2=false;
                again=false;
                platzhalter=0;
                for(j=0;j<100;j++){
                    saveArr[j]=101;
                }
                for(j=0; j<100; j++){
                    if(bitList[j]=='-'){
                        for(k=load-1;k>=0;k--){
                            if(bitList[j+k]=='-'){
                                control=true;
                            }else{
                                control=false;
                                again=false;
                                break;
                            }
                        }
                    }
                    if(control==true){
                        if (again==true){
                            saveArr[j]=saveArr[j-1]+1;
                        }else{
                            saveArr[j]=0;
                            for(k=j;bitList[k]=='-';k++){
                                saveArr[j]++;
                            }
                            control2=true;
                            again=true;
                        }
                        
                    }
                }
                load2=saveArr[0];
                for(j=1;j<100;j++){
                    if(saveArr[j]<101){
                        if(saveArr[j]<load2){
                            platzhalter=j;
                            load2=saveArr[j];
                        }
                    }
                }
                while(load>0 && control2==true){
                    bitList[platzhalter]='A'+i-1;
                    platzhalter++;
                    load--;
                }
                if(control2==false){
                    i--;
                }
            }
            i=printErr(load-1, i);
        }
        //Ende Best Fit
        printArr(bitList);
    }
    return 1;   //Fehler
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
int printErr(int load, int i){
    if(load!=-1){
        printf("nicht genug Speicher frei!\n");
        i--;
    }
    return i;
}
//Gibt die Bitliste aus
void printArr(char bitList[]){
    int j;
    for(j=0;j<100;j++){
        printf("%c", bitList[j]);
    }
}
//Löscht den Speicherplatz, der zuvor von einem bestimmten Prozess belegt wurde
void clear(char bitList[], int load){
    int j;
    for(j=0;j<100;j++){
        if(bitList[j] == load+'A'){
            bitList[j]='-';
        }
    }
}
//Füllt den Speicherplatz mit einem neuen Prozess
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