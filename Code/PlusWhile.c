/*
Autor: Raja Waleed Ali
Datum: 06.10.23
Beschreibung: rechnet Plus oder minus mit while schleife.
*/

#include<stdio.h>

int main(){
    int a, b;

    printf("Geben Sie a ein: ");
    scanf("%d", &a);
    printf("\nGeben Sie b ein: ");
    scanf("%d", &b);

    while(b>=1||b<0){
        a=a+1;
        b--;
    }
    prinf("\nDie Zahl lautet: ");
    scanf("%d", a);

    return 0;
}