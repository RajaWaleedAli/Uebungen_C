/*
Autor: Raja Waleed Ali
Datum: 06.10.23
Beschreibung: rechnet Multiplikation mit For schleife.
*/

#include<stdio.h>

int main(){
    int a, b, c, d;

    printf("Geben Sie a ein: ");
    scanf("%d", &a);
    printf("\nGeben Sie b ein: ");
    scanf("%d", &b);
    c=a;
    if(b>0){
        for(b=b; b>1; b--){
            c=c+a;
        }
    
    }elso{
        for(b=b; b<1; b++){
            c=c-a;
        }
    }
    printf("Die Zahl lautet: %d", c);

    return 0;
}