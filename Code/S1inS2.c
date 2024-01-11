/*
Autor: Raja Waleed Ali
Datum: 08.01.24
Beschreibung: string vergleich.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int same(char s1[], char s2[]){
    int i, j, k, gleich;
    int count=0;
    for(i=0; i<(int)strlen(s1); i++){
        if(s1[i]==s2[0]){
            k=i;
            for(j=0;j<(int)strlen(s2);j++){
                if(s1[k]==s2[j]){
                    gleich=1;
                }else{
                    gleich=0;
                    break;
                }
                k++;
            }
            if(gleich==1){
                count++;
            }
        }
    }
    return count;
}

int anfang(char s1[], char s2[]){
    int i, j, k, gleich;
    for(i=0; i<(int)strlen(s1); i++){
        if(s1[i]==s2[0]){
            k=i;
            for(j=0;j<(int)strlen(s2);j++){
                if(s1[k]==s2[j]){
                    gleich=1;
                }else{
                    gleich=0;
                    break;
                }
                k++;
            }
            if(gleich==1){
                return i+1;
            }
        }
    }
    return 255;
}

int compare(char s1[], char s2[]){
    int i, j, k, gleich;
    for(i=0; i<(int)strlen(s1); i++){
        if(s1[i]==s2[0]){
            k=i;
            for(j=0;j<(int)strlen(s2);j++){
                if(s1[k]==s2[j]){
                    gleich=1;
                }else{
                    gleich=0;
                    return 0;
                }
                k++;
            }
            if(gleich==1){
                return 1;
            }
        }
    }
    return 0;
}
int main(){
    char s1[]="Kukuk fisch\nHHHHHHHHHHHH";
    char s2[]="H";

    if(compare(s1,s2) == 1){
        printf("s2 ist in s1 enthalten!\n");
    }else{
        printf("s2 ist nicht in s1 enthalten!\n");
    }
    
    printf("Anfangsbuchstabe an Stelle: %d\nAnzahl der gleichen Woerter: %d", anfang(s1, s2), same(s1, s2));

    return 0;
}