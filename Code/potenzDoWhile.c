/*
Autor: Raja Waleed Ali
Datum: 05.10.23
Beschreibung: Berechnet die Potenz mit do-while schleife.
*/

#include<stdio.h>

int main(){
    int basis, exp, i;
    do {
        printf("Gib eine Zahl ein: ");
        scanf("%d", &basis);
        printf("Gib die Potenz ein: ");
        scanf("%d", &exp);  
    } while (exp < 0 || basis < 0);
    i = basis;
    if(exp==0 && basis > 0){
        printf("Die Loesung lautet: 1");
        return 0;
    } else if(exp==0 && basis == 0){
        printf("Die Loesung ist nicht definiert!");
        return 0;
    } else {
        do{
            exp--;
            i = basis*i; 
        } while(exp > 1);
        printf("Die Loesung lautet: %d", i);
    }
    return 0;
}