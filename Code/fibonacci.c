/*
Autor: Raja Waleed Ali
Datum: 11.10.23
Beschreibung: Berechnet fibonacci.
*/

#include <stdio.h>
int main(){
    int zahl, i;
    do{
        printf("Gib eine Zahl ein!(1-46) ");
        scanf("%d", &zahl);  
    } while (zahl < 1 || zahl > 46);
    
    int fibo[47] = {0, 1};

    printf("Schritt 0 = 0\n");
    for (i=1; i <= zahl; i++){
        fibo[i+1]= fibo[i-1]+fibo[i];
        printf("Schritt %d = %d\n", i, fibo[i]);
    }

    return 0;
}