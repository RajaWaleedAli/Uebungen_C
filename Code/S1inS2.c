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
    for(i=0; i<strlen(s1); i++){
        if(s1[i]==s2[0]){
            k=i;
            for(j=0;j<strlen(s2);j++){
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
    for(i=0; i<strlen(s1); i++){
        if(s1[i]==s2[0]){
            k=i;
            for(j=0;j<strlen(s2);j++){
                if(s1[k]==s2[j]){
                    gleich=1;
                }else{
                    gleich=0;
                    break;
                }
                k++;
            }
            if(gleich==1){
                return i;
            }
        }
    }
    return 255;
}
int main(){
    int i, j, k, gleich;
    char s1[]="Kukuk Hallo Hallo Hallo Hallo Hallo";
    char s2[]="Hallo";

    for(i=0; i<strlen(s1); i++){
        if(s1[i]==s2[0]){
            k=i;
            for(j=0;j<strlen(s2);j++){
                if(s1[k]==s2[j]){
                    gleich=1;
                }else{
                    gleich=0;
                    break;
                }
                k++;
            }
            if(gleich==1){
                printf("S2 ist in S1 enthalten!\n");
                break;
            }
        }
    }
    printf("Anfangsbuchstabe an Stelle: %d\nAnzahl der gleichen Woerter: %d", anfang(s1, s2), same(s1, s2));

    return 0;
}