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

short semikolon(char line[]){
    char *ptr = line;
	short count = 0;
	while((ptr = strstr(ptr, ";")) != NULL){
		ptr++;
		count++;
	}
	return count;
}

int main(){
    system("cls");
    FILE* fp;
    char temp[60];
    int count=0;
    char* ptr;
    int i, j;
    short load;
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
        load=semikolon(temp);
        ptr=strtok(temp, ";");
        strncpy(personen[i].vorname, ptr, sizeof(personen[i].vorname) - 1);
        for(j=load-1;j>0;j--){
            char* vorname_ptr = strtok(NULL, ";");
            if(vorname_ptr != NULL){
                strcat(personen[i].vorname, " ");
                strcat(personen[i].vorname, vorname_ptr);
            }
        }
        if(load!=0){
            char* nachname_ptr = strtok(NULL, " ");
            if(nachname_ptr != NULL){
                strncpy(personen[i].nachname, nachname_ptr, sizeof(personen[i].nachname) - 1);
            }
        }
        i++;
    }
        printDaten(personen, count);
    
    fclose(fp);
    return 0;
}