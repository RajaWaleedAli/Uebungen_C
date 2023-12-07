/*
Autor: Raja Waleed Ali
Datum: 12.10.23
Beschreibung: Macht Statistiken.
*/

#include <stdio.h>

int main(){
    int zahl[100]={0};
    int i = 0;
    int zahlGross, zahlKlein;
    float zahlMitte;
    do{
        printf("Gib eine Zahl ein: ");
        scanf("%d", &zahl[i]);
        i++;
    }while(zahl[i-1]>=0);                            //wiederholt die schleife bis zahl negativ ist
    i=i-2;
    zahlMitte = zahl[i];
    for(int j=i-1; j>=0; j--){
        zahlMitte=zahl[j]+zahlMitte;
    }
    zahlMitte=zahlMitte/(i+1);
    zahlGross=zahl[i];
    zahlKlein=zahl[i];
    while (i>0){
        i--;
        if(zahl[i]>zahlGross){
            zahlGross=zahl[i];
        }
        if(zahl[i]<zahlKlein){
            zahlKlein=zahl[i];
        }
    }
    printf("Die kleinste Zahl lautet: %d\nDie groesste Zahl lautet: %d\nMittelwert lautet: %.2f", zahlKlein, zahlGross, zahlMitte);

    return 0;
}