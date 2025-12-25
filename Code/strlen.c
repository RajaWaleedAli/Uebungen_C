/*
Autor: Raja Waleed Ali
Datum: 18.12.23
Beschreibung: funktion strlen.
*/

#include<stdio.h>
#include<stdlib.h>

int strlen(char string[]){
    int i=0;
    while(string[i]!='\0'){
        i++;
    }
    return i;
}

int main(){
    char string[]="Hallo";
    printf("Laenge: %d", strlen(string));

    return 0;
}