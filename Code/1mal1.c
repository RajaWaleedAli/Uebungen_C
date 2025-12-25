/*
Autor: Raja Waleed Ali
Datum: 15.10.23
Beschreibung: 1mal1 rechner.
*/

#include<stdio.h>
#include<time.h>
#include<limits.h>
#include<stdlib.h>
#include<math.h>

int main(){
    int j, i;
    int a[10][10]={0};
    for (i=1; i<=10; i++){
        for(j=1; j<=10; j++){
            a[i-1][j-1]=i*j;
            printf("%d ", a[i-1][j-1]);
        }
        printf("\n");
    }
}