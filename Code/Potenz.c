/*
Autor: Raja Waleed Ali
Datum: 02.10.23
Beschreibung: Berechnet die Potenz mit while schleife.
*/
#include<stdio.h>

int main(){
    int zahl, exp, y;
    do {
        printf("Gib eine Zahl ein: ");
        scanf("%d", &zahl);
        printf("Gib die Potenz ein: ");
        scanf("%d", &exp);  
    } while (exp < 0 || zahl < 0);

    y = zahl;
    if(exp==0 && zahl > 0){
        printf("Die Loesung lautet: 1");
        return 0;
    } else if(exp==0 && zahl == 0){
        printf("Die Loesung ist nicht definiert!");
        return 0;
    } else {
        while(exp > 1){
            exp--;
            zahl=zahl*y;
        }
        printf("Die Loesung lautet: %d", zahl);
    }
    

    return 0;
}