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

void addKnot(knoten_t *, char *, long long);
//void delKnot(struct *);
//void searchKnot(struct *);
void printList(knoten_t *);

int main(){
    knoten_t* head;
    head=NULL;
    char namen[30];
    long long nummer;
    for(int i=0;i<5;i++){
        printf("\nGib Name ein! ");
        scanf("%s", namen);
        printf("\nGib Nummer ein! ");
        scanf("%lld", nummer);
        addKnot(head, namen, nummer);
    }
    printList(head);
    return 0;
}

void printList(struct knoten* head){
    knoten_t * current = head;

    while (current != NULL) {
        printf("Name: %s\tNummer: %lld\n", current->name, current->number);
        current = current->next;
    }
}

void addKnot(struct knoten* head, char name[30], long long nummer){
    knoten_t* searchPtr = head;
    knoten_t* new_Knot = (knoten_t *) malloc(sizeof(knoten_t));
    strcpy(new_Knot->name, name);
    new_Knot->number = nummer;
    new_Knot->next = NULL;
    int i=0;
    if(head==NULL || strcmp(name, searchPtr->name) < 0){
        *new_Knot->next = *head;
        *head = *new_Knot;
        return;
    }
    while(searchPtr->next!=NULL){
        if(searchPtr->next->name[0]<new_Knot->name[0]){
            *new_Knot->next = *searchPtr;
            *searchPtr = *new_Knot;
            return;
        }else if(searchPtr->next->next==NULL){
            searchPtr = (knoten_t *) malloc(sizeof(knoten_t));
            *searchPtr->next->next = *new_Knot;
            return;
        }
    }
}
