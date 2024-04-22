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
    printf("%d. name: %s %s\n", count, fill[count].vorname, fill[count].nachname);
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

void names(person_t personen[], FILE* fp){
    char temp[60];
    int j, i=0;
    short load;
    char* ptr;
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
}
int search(person_t personen[], int count){
    char search_vorname[30];
    char search_nachname[30];
    printf("Gib Vorname ein!\n");
    scanf("%s", &search_vorname);
    printf("Gib Nachname ein! (falls er keinen hat '/' eingeben)\n");
    scanf("%s", &search_nachname);
    while(strstr(personen[count].vorname,search_vorname)==NULL||strstr(personen[count].nachname,search_nachname)==NULL){
        count--;
        if(count==-1){
            return -1;
        }
    }
    return count;
}

int main(){
    system("cls");
    FILE* fp;
    char temp[60];
    int count=0;
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
    names(personen, fp);
    while(count>=0){
        count=search(personen, count);
        printDaten(personen, count);
        count--;
    }
    
    fclose(fp);

    return 0;
}