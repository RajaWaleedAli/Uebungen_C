/*
Autor: Raja Waleed Ali
Datum: 27.11.23
Beschreibung: veränderung auf funktion variable testen.
*/

#include<stdio.h>
#include<time.h>
#include<limits.h>
#include<stdlib.h>
#include<math.h>

int primzahl(float a){
    float b;
    for (int i=a-1;i>=2; i--){
        b = a/i;
        if (b==(int)b){
            return 1;
        }
    }
    return 0;
}

int main(){
    for (int i=2;i<=100;i++){
        if(primzahl(i)==0){
            printf("Primzahl: %d\n", i);
        }
    }

    return 0;
}