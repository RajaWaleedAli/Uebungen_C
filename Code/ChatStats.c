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
#include<stdbool.h>

int namen(int temp, int temp2){
    if(temp2==']'&&temp!=':'){
        return temp;
    }else if(temp==':'){
        return ';';
    } 
    return 0;
}

int main(int argc, char* argv[]){
    system("cls");
    int i, temp, temp2, count;
    char temp3[30000];
    char load;
    char name[30000];
    char name2[30000];
    char *name3[3000]={0};
    char* ptr;
    bool leertaste = false; 
    i=0;
    FILE *fp;
    fp = fopen("_chat.txt", "r");
    scanf("%c", &load);
    if(fp == NULL) {
        printf("Datei konnte NICHT geoeffnet werden.\n");
        return 404;
    }
    //Namen im Array speichern Anfang
    while((temp = fgetc(fp))!=EOF){
        if(temp2==']'){
            name[i]=namen(temp, temp2);
            //printf("%c", namen(temp, temp2));
            i++;
        }
        if(temp==']'){
            temp2=']';
        }else if(temp==':'){
            temp2=':';
        }
        
    }
    ptr = strtok(name, ";");
    while(ptr != NULL) {
        if(strstr(name2, ptr)==NULL){
            strcat(name2, ptr);
        } 
        ptr = strtok(NULL, ";");
    }
    count=0;
    for(i=0; name2[i]!='\0'; i++){
        if(name2[i]==' ' && leertaste==false){
            leertaste=true;
            count++;
        }else if(name2[i]==' ' && leertaste==true){
            leertaste=false;
            if(count>0){
                name2[i]=';';
            }
            
            printf("\n");
            count++;
        }
        //printf("%c", name2[i]);    
    }
    int stats[100]={0};
    fclose(fp);
    //Namen im Array Speichern Ende

    ptr = strtok(name2, ";");
    i=0;
    while(ptr != NULL) {
        //printf( " %s\n", ptr);
        name3[i]=ptr;
        ptr = strtok(NULL, ";");
        i++;
    }
    fp = fopen("_chat.txt", "r");

    char* platzhalter;
    int platzhalter2;
    if(load=='d'){
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