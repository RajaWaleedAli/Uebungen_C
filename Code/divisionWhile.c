/*
Autor: Raja Waleed Ali
Datum: 06.10.23
Beschreibung: rechnet Division mit while schleife.
*/

#include<stdio.h>

int main(){
    int a, b, c, d;
    c=0;

    printf("Geben Sie a ein: ");
    scanf("%d", &a);
    printf("\nGeben Sie b ein: ");
    scanf("%d", &b);
    
    while(a>=b||b>=a){
        d=b;
        while(b>=1||-1>=b){
            a--;
            b--;
        }
        c++;
        b=d;
    }
    printf("Die Zahl lautet: %d und %d Rest", c, a);
    return 0;
}