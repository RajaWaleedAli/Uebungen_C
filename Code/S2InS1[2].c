/*
Autor: Raja Waleed Ali
Datum: 08.01.24
Beschreibung: string vergleich mit string.h funktionen.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int amount(char s1[], char s2[]){
    int count =0;
    char *ptr;
    ptr = strtok(s1, s2);
    while(ptr != NULL) {
        if(strstr(ptr, s2) != NULL){
            count++;
        }
        ptr = strtok(ptr+1, s2);
    }
    return count;
}

int compare(char s1[], char s2[]){
    if(strstr(s1, s2) != NULL){
        return 1;
    }else{
        return 0;
    }
}
int anfang(char s1[], char s2[]){
    int i, j, k, gleich;
    for(i=0; i<(int)strlen(s1); i++){
        printf("Kontrolle!");
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
    printf("\n%d\ni = %d\n", gleich, i);
    return 255;
}
int main(){
    char s1[]="Kukuk fisch\nHallo Hallo Hallo Hallo Hallo Hallo";
    char s2[]="Hallo";

    if(compare(s1,s2) != 0){
        printf("s2 ist in s1 enthalten!\n");
    }else{
        printf("s2 ist nicht in s1 enthalten!\n");
    }

    printf("Anfangsbuchstabe an Stelle: %d\nAnzahl der gleichen Woerter: %d", anfang(s1,s2), amount(s1,s2));

    return 0;
}