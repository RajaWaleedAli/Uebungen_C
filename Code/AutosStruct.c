/*
Autor: Raja Waleed Ali
Datum: 28.02.24
Beschreibung: Autos Preis rechner
Beispiel Kommandozeilenparameter:
    VW 150 5 Ja Porsche 230 3 Ja Lamborghini 320 3 Nein
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

struct car{
    char* marke;
    int vMax;
    int door;
    int price;
    bool ABS;

};
typedef struct car car_t;

void fill(car_t arr[], char* daten[]){
    int i, j;
    i=0;
    while(i<3){
        for(j=0; j<4;j++){
            switch(j){
                case 0:
                    arr[i].marke=daten[(j+1)+i*4];
                    break;
                case 1:
                    arr[i].vMax=atoi(daten[(j+1)+i*4]);
                    break;
                case 2:
                    arr[i].door=atoi(daten[(j+1)+i*4]);
                    break;
                case 3:
                    if(strcmp(daten[(j+1)+i*4], "Ja")==0){
                        arr[i].ABS=true;
                    }else{
                        arr[i].ABS=false;
                    }
                    break;
            }
        }
        
        i++;
    }
}

void preis(car_t arr[]){
    int i;
    for(i=0; i<3; i++){
        arr[i].price= arr[i].vMax*50*arr[i].door;
        if(arr[i].ABS==true){
            arr[i].price+=5000;
        }
        if(strcmp(arr[i].marke, "porsche")==0){
            arr[i].price=arr[i].price*2;
        }else if(strcmp(arr[i].marke, "lamborghini")==0){
            arr[i].price=arr[i].price*20;
        }
    }
}

void printDaten(car_t fill[]){
    int i;
    for(i=0;i<3;i++){
        printf("Marke: %s\n", fill[i].marke);
        printf("Anzahl Tueren: %d\n", fill[i].door);
        printf("MAX Geschwindigkeit: %d\n", fill[i].vMax);
        if(fill[i].ABS==true){
            printf("ABS: Ja\n");
        }else{
            printf("ABS: Nein\n");
        }
        printf("Preis: %d\n", fill[i].price);
    }
    
}


int main(int argc, char* argv[]){
    if(argc<13){
        printf("Nicht genug Parameter!");
        return -1;
    }
    car_t arr[3];
    fill(arr, argv);
    preis(arr);
    printDaten(arr);
    return 0;
}