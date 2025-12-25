/*
Autor: Raja Waleed Ali
Datum: 20.12.23
Beschreibung: caesar entschluesslung.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int small(int i, char string[100]){
    if(string[i]<='Z'&&string[i]>='A'){
        string[i]=string[i]+32;
    }
    return (int)string[i];
}

int caesar(char string[100], int i, int shift){
    string[i]=small(i, string)-97;
    string[i]=((string[i]-97+shift+26)%26)+97;

    return (int)string[i];
}

int alph(char string[100], int i, int shift){
    return caesar(string, i, -shift);  
}

int main(){
    char string[100];
    int mode;
    int buchstabe, i, shift;
    printf("Gib etwas ein: ");
    gets(string);
    printf("Verschluesseln(0)\nEntschluesseln(1)\n");
    scanf("%d", &mode);
    if(mode==0){
        printf("Um wieviele Buchstaben soll es verschoben werden?\n");
        scanf("%d", &shift);
        shift=shift%26;
        for(i=0; i<strlen(string); i++){
            buchstabe=caesar(string, i, shift);
            printf("%c", (char)buchstabe);
        }
    }else  if(mode==1){
        for(shift=1; shift<26; shift++){
            for(i=0; i<strlen(string); i++){
                buchstabe=alph(string, i, shift);
                printf("%c", (char)buchstabe);
            }
            printf("\n");
        }
        
    }else{
        printf("Falsche eingabe!");
    }
    return 0;
}


    
