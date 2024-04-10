/*
Autor: Raja Waleed Ali
Datum: 27.03.2024
Beschreibung: über malloc strings verknüpfen.
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

int string_length(char*);
char* concat(char *, char *);

int main(){
    char* s1="Hallo";
    char* s2="Welt";
    char* result = concat(s1,s2);
    printf("##%s##", result);
    free(result);
    return 0;
}

int string_length(char* string){
    int i;
    for(i=0;string[i]!='\0';i++);
    return i;
}

char* concat(char *s1, char *s2){
    int s1_lenght=string_length(s1);
    int s2_lenght=string_length(s2);
    char* p1 = malloc((s1_lenght+s2_lenght+2)*sizeof(char));

    int i;
    int j=0;
    for(i=0;i<s1_lenght+s2_lenght+2;i++){
        if(i<s1_lenght){
            p1[i]=s1[i];
        }else if(i==s1_lenght){
            p1[i]=' ';
        }else if(i<s1_lenght+s2_lenght+1){
            p1[i]=s2[j];
            j++;
        }else{
            p1[i]='\0';
        }
    }
    return p1;
}