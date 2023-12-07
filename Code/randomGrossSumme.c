/*
Autor: Raja Waleed Ali
Datum: 15.10.23
Beschreibung: Zufallszahlen 2d mit der größten Summe.
*/

#include<stdio.h>
#include<time.h>
#include<limits.h>
#include<stdlib.h>
#include<math.h>

int main(){
    system("cls");
    srand(time(NULL));
    int j, i, k;
    int a[7][13]={0};
    int b[7]={0};
    int gross;

    for (i=0; i<7; i++){
        for(j=0; j<13; j++){
            a[i][j]=rand()%500+500;
            b[i]= b[i] + a[i][j];
            //printf("%d ", a[i][j]);
        }
        printf("Summe der Zeile %d ist %d\n", i, b[i]);
    }
    gross=b[0];
    k=0;
    for (i=1; i<7; i++){
        if(gross<b[i]){
            gross=b[i];
            k=i;
        }
    }
    printf("\nDie Zeile mit der groesste Summe ist %d mit der Summe %d", k, gross);
}