/*
Autor: Raja Waleed Ali
Datum: 02.10.23
Beschreibung: Berechnet die Fakultät.
*/

#include<stdio.h>
int main(){
    long long zahl, zahl2;
    do{
        printf("Gib eine positive Zahl ein: ");
        scanf("%lld", &zahl);
    }while(zahl<=0);

    zahl2 = zahl;
    printf("!%lld = %lld ", zahl, zahl);

    while(zahl != 1){
        zahl--;
        printf("* %lld ", zahl);
        zahl2 = zahl * zahl2;
    }
    printf("= %lld", zahl2);
    
    return 0;
}