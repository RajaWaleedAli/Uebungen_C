/*
Autor: Raja Waleed Ali
Datum: 28.02.24
Beschreibung: Autos struct
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
                    arr[i].marke=argv[j+2+i*4];
                    break;
                case 1:
                    arr[i].vMax=atoi(argv[j+2+i*4]);
                    break;
                case 2:
                    arr[i].door=atoi(argv[j+2+i*4]);
                    break;
                case 3:
                    if(argv[j+2+i*4]=="Ja"){
                        arr[i].ABS=TRUE;
                    }else{
                        arr[i].ABS=FALSE;
                    }
                    break;
            }
        }
        i++;
    }
}

int price(car_t arr[]){
    int i;
    for(i=0; i<3; i++){
        arr[i].price=arr[i].vMax*50*arr[i].door;
        if(arr[t].ABS==TRUE){
            arr[i].price+=5000;
        }
    }
}

int main(int argv, char* argv[]){
    car_t arr[3];
    


    return 0;
}