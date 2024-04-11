/*
Autor: Raja Waleed Ali
Datum: 11.04.2024
Beschreibung: Telefonbuch mit Liste.
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

typedef struct knoten{
    char name[30];
    long long number;
    struct knoten* next;
}knoten_t;

void addKnot(struct *, char *, long);
void delKnot(struct *);
void searchKnot(struct *);

int main(){
    knoten_t* head;
    head=NULL;

    return 0;
}

void addknot(struct knoten* head, char name[30], long long nummer){
    knoten_t* searchPtr = head;
    while(searchPtr->next!=NULL){
        if(searchPtr->next->name[0]<searchPtr->name[0]){
            knoten_t
        }
    }
}