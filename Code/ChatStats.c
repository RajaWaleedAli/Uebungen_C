/*
Autor: Raja Waleed Ali
Datum: 15.01.24
Beschreibung: zählt buchstaben in einem dokument.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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
    int i, temp, temp2;
    char load;
    char name[1000000];
    char name2[1000000];
    char* ptr;
    i=0;
    FILE *fp;
    fp = fopen("_chat.txt", "r");
    scanf("%c", &load);

    if(fp == NULL) {
        printf("Datei konnte NICHT geoeffnet werden.\n");
        return 404;
    }else{
        if(load=='d'){
            while((temp = fgetc(fp))!=EOF){
                if(temp2==']'){
                    name[i]=namen(temp, temp2);
                    printf("%c", namen(temp, temp2));
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
        }else if(argv[2]=="-s"){
            
        }else if(argv[2]=="-h"){

        }else{
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    for(i=0; i<100000;i++){
        printf("%c", name2[i]);
    }
        

    return 0;
}