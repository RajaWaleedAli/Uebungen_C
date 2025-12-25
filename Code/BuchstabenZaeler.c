/*
Autor: Raja Waleed Ali
Datum: 15.01.24
Beschreibung: zählt buchstaben in einem dokument.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char* argv[]){
    system("cls");
    int i, temp;
    long long zeichen=0;;
    int alph[27]={0};
    int alph2[27]={0};
    FILE *fp;
    fp = fopen(argv[1], "r");

    if(fp == NULL) {
        printf("Datei konnte NICHT geoeffnet werden.\n");
        return 404;
    }else{
        while((temp = fgetc(fp))!=EOF){
            fscanf(fp, "%d", &temp);
            if(temp>='a' && temp<='z'){
                    alph[temp-'a']++;
            }else if(temp>='A' && temp<='Z'){
                    alph2[temp-'A']++;
            }
            zeichen++;
        }
        for(i=0;i<26;i++){
            printf("%c ist %d Mal enthalten\n", i+'a', alph[i]);
            printf("%c ist %d Mal enthalten\n", i+'A', alph2[i]);
            printf("Zusammen: %d\n\n",i+'a', i+'A', alph2[i]+alph[i]);
        }    
        printf("Zeichen gesamt: %lld\n", zeichen); 
    }
    fclose(fp);

    return 0;
}