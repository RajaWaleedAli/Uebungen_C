/*
Autor: Raja Waleed Ali
Datum: 26.02.24
Beschreibung: 
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

struct daten{
    int plz;
    char ort[100];
    char street[100];
    int hausNummer;
};

void printDaten(struct daten fill){
    printf("PLZ: %d\n", fill.plz);
    printf("Ort: %s\n", fill.ort);
    printf("Strasse: %s\n", fill.street);
    printf("Hausnummer: %d\n", fill.hausNummer);
}

int cmp_adressen(struct daten a1, struct daten a2) {
    if(strcmp(a1.ort, a2.ort)!=0){
        return 0;
    }
    if(strcmp(a1.street, a2.street)!=0){
        return 0;
    }
    if(a1.plz!=a2.plz){
        return 0;
    }
    if(a1.hausNummer!=a2.hausNummer){
        return 0;
    }
    return 1;
}

int main(){

    struct daten a1={39042, "Brixen", "Datenstrasse", 39};
    struct daten a2=a1;
    a1.hausNummer=40;
    printDaten(a1);
    printDaten(a2);

    return 0;
}