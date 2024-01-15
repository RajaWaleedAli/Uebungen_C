/*
Autor: Raja Waleed Ali
Datum: 15.01.24
Beschreibung: zählt buchstaben in einem dokument.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    system("cls");
    int i, temp;
    long long zeichen=0;;
    int alph[27]={0};
    FILE *fp;
    fp = fopen("alice.txt", "r");

    if(fp == NULL) {
        printf("Datei konnte NICHT geoeffnet werden.\n");
    }else{
            while((temp = fgetc(fp))!=EOF){
                fscanf(fp, "%d", &temp);
                if(temp>='a' && temp<='z'){
                        alph[temp-'a']++;
                }else if(temp>='A' && temp<='Z'){
                        alph[temp-'A']++;
                }
            }
            for(i=0;i<26;i++){
                printf("%c oder %c ist %d Mal enthalten\n", i+'a', i+'A', alph[i]);
                zeichen=zeichen+alph[i];
            }    
            printf("zeichen gesamt: %lld\n", zeichen); 
    }
    fclose(fp);

    return 0;
}