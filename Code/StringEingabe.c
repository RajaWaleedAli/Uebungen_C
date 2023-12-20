/*
Autor: Raja Waleed Ali
Datum: 18.12.23
Beschreibung: funktion strlen.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int big(int i, char string[100]){
    if(string[i]>='a'&&string[i]<='z'){
        string[i]=string[i]-32;
    }
    return (int)string[i];
}

int small(int i, char string[100]){
    if(string[i]<='Z'&&string[i]>='A'){
        string[i]=string[i]+32;
    }
    return (int)string[i];
}
int anfang(int i, char string[100]){
    if(string[i]>='A'&&string[i]<='Z'){
        string[i]=string[i]+32;
        if(i!=0){
            if(string[i-1]==32){
                string[i]=string[i]-32;
            }
        }else{
            string[i]=string[i]-32;
        }
    }else if(string[i]>='a'&&string[i]<='z'){
        if(i!=0){
            if(string[i-1]==32){
                string[i]=string[i]-32;
            }
        }else{
            string[i]=string[i]-32;
        }
    }
    return (int)string[i];  
}

main(){
    char string[100];
    int mode;
    int buchstabe, i;
    printf("Gib etwas ein: ");
    gets(string);
    printf("Alles in Grossbuchstaben(0)\nAlles in Kleinbuchstaben(1)\nAlles klein u nd Anfangsbuchstaben gross(2)\n");
    scanf("%d", &mode);
    if(mode==0){
        for(i=0;i<strlen(string);  i++){
            buchstabe=big(i, string);
            printf("%c", (char)buchstabe);
        }
    }else  if(mode==1){
        for(i=0;i<strlen(string);  i++){
            buchstabe=small(i, string);
            printf("%c", (char)buchstabe);
        }
    }else  if(mode==2){
        for(i=0; i<strlen(string);  i++){
            buchstabe=anfang(i, string);
            printf("%c", (char)buchstabe);
        }
    }else{
        printf("Falsche eingabe!");
    }
    return 0;
}