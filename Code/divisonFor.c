/*
Autor: Raja Waleed Ali
Datum: 06.10.23
Beschreibung: rechnet Division mit for schleife.
*/

#include<stdio.h>

int main(){
    int a, b, c, d;

    printf("Geben Sie a ein: ");
    scanf("%d", &a);
    printf("Geben Sie b ein: ");
    scanf("%d", &b);

    
    for(c=0; a>=b; c++){
        for (d=b; b>=1; b--){
            a--;
        }
        b=d;
    }  
    printf("Die Zahl lautet: %d und %d Rest", c, a);
    
    return 0;
}