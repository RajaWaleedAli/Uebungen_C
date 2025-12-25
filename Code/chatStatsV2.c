/*
Autor: Raja Waleed Ali
Datum: 15.01.24
Beschreibung: zählt buchstaben in einem dokument.
Zu Beachten: Funktioniert nur wenn der kontankt Eingespeichert ist und wenn es mit
[Vorname Nachname] gespeichert ist.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <stdbool.h>

int main(int argc, char* argv[]){
    system("cls");
    int i, temp, temp2, count;
    char temp3[30000];
    char load;
    char name[30000];
    char name2[30000];
    char *name3[3000]={0};
    char* ptr;
    bool first = false; 
    bool leertaste = false; 
    i=0;
    FILE *fp;
    fp = fopen(argv[1], "r");
    scanf("%c", &load);
    if(fp == NULL) {
        printf("Datei konnte NICHT geoeffnet werden.\n");
        return 404;
    }
    int j=0;
    //Namen im Array speichern Anfang
    while(fgets(temp3, 30000, fp)!=NULL){
        ptr = strtok(strchr(temp3, (int)']'), ":");

        if(name3[0]==NULL){
                printf("test1\n");
            first=true;
                printf("test2\n");
        }else{
            printf("test3");
            for(i=0; name3[i]!=NULL; i++){
                if(strstr(name3[i], ptr)==NULL){
                    first=true;
                }else{
                    first=false;
                    break;
                }
            }
            printf("test4\n");
        }
        if(first==true){
            name3[j] = ptr;
            j++;
        }
        for(i=0; name3[i]!=NULL; i++){
            printf("%d: %s\n", i, name3[i]);
        }
    }
    fclose(fp);
    //Namen im Array Speichern Ende

    int stats[100]={0};

    fp = fopen(argv[1], "r");

    char* platzhalter;
    int platzhalter2;
    if(argv[2]=="-d"){
        //printf("\ntest1\n");
        while(fgets(temp3, 30000, fp)!=NULL){
            platzhalter=strstr(temp3, ": ");
            if(platzhalter!=NULL){
                platzhalter2=strlen(platzhalter);
            }
            for(i=0; name3[i]!=NULL; i++){
                if(strstr(temp3, name3[i])!= NULL){
                    stats[i]=stats[i]+platzhalter2;
                }
            }
            
            //puts(temp3);
            
            //printf("\ntest3");
        }
        for(i=0; name3[i]!=NULL; i++){
            printf("%s\t\t Zeichen gesendet: %d\n", name3[i], stats[i]);
        }
        printf("\ntest4");
        
    }else if(argv[2]=="-s"){
        
    }else if(argv[2]=="-h"){

    }else{
        fclose(fp);
        return 1;
    }
    fclose(fp);
    /*
    for(i=0; i<100000;i++){
        printf("%c", name2[i]);
    } */

    return 5;
}