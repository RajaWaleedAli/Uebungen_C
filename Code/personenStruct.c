/*
Autor: Raja Waleed Ali
Datum: 06.03.2024
Beschreibung: Personen Scuhen datei
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

struct bDay{
    short day;
    short month;
    short year;
};
typedef struct bDay bDay_t;

struct person{
    char vorname[30];
    char nachname[30];
    bDay_t date;
};
typedef struct person person_t;

void printDaten(person_t fill[], int count){
    int i;
    for(i=0;i<count;i++){
        printf("%d. name: %s %s\n", i, fill[i].vorname, fill[i].nachname);
    }
    
}

int main(){
    system("cls");
    FILE* fp;
    char temp[60];
    int count=0;
    char* ptr;
    int i;
    fp=fopen("celebrity.txt", "r");
    	if(fp==NULL){
		printf("Datei Existiert nicht");
		return -1;
	}else{
        while((fgets(temp, sizeof(temp), fp))!=NULL){
            count++; 
        }
    }
    fclose(fp);
    person_t personen[count];
    fp=fopen("celebrity.txt", "r");
    i=0;
    while((fgets(temp, sizeof(temp), fp))!=NULL){
        ptr=strtok(temp, ";");
        strncpy(personen[i].vorname, ptr, sizeof(personen[i].vorname) - 1);
        ptr = strtok(ptr, " ");
        strncpy(personen[i].nachname, ptr, sizeof(personen[i].nachname) - 1);
        /*while(ptr != NULL) {
            
        }*/

        i++;
    }
    printDaten(personen, count);
    printf("6");
    
    fclose(fp);
    return 0;
}