/*
Autor: Raja Waleed Ali
Datum: 15.01.24
Beschreibung: ersten buchstaben in einem dokument als grossbuchstaben.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int fputc(int c, FILE *fp);
int main(int argc, char* argv[]){
    system("cls");
    int  temp, temp2;
    FILE *fp;
    FILE *fp2;
    fp = fopen(argv[1], "r");
    fp2 = fopen("test.txt", "w");

    if(fp == NULL) {
        printf("Datei konnte NICHT geoeffnet werden.\n");
        return 404;
    }else{
        while((temp = fgetc(fp))!=EOF){
            if(temp2==' '||temp2=='.'||temp2==','||temp2==10){
                if(temp>='a'&&temp<='z'){
                    printf("1. %c\n", temp);
                    temp=temp-'a'+'A';
                    printf("2. %c\n\n", temp);
                }
            }
            fputc(temp, fp2);
            temp2=temp;
        }
    }
    fclose(fp);
    fclose(fp2);

    return 0;
}