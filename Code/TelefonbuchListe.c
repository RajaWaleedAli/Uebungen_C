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

void addKnot(knoten_t **, char *, long long);
void delKnot(knoten_t *, long long);
void searchKnot(knoten_t *);
void freeList(knoten_t *);
void printList(knoten_t *);

int main(){
    system("cls");
    knoten_t* head = (knoten_t *) malloc(sizeof(knoten_t));
    head=NULL;
    char namen[30];
    long long number_;
    for(int i=0;i<5;i++){
        printf("\nGib Name ein! ");
        scanf("%s", &namen);
        printf("\nGib number_ ein! ");
        scanf("%lld", &number_);
        addKnot(&head, namen, number_);
    }
    printList(head);
    freeList(head);
    return 0;
}

void printList(knoten_t* head){
    knoten_t * current = head;

    while (current != NULL) {
        printf("Name: %s\tnumber_: %lld\n", current->name, current->number);
        current = current->next;
    }
}

void addKnot(knoten_t** head, char namen[30], long long number_){
    knoten_t* searchPtr = *head;
    knoten_t* new_Knot = (knoten_t *) malloc(sizeof(knoten_t));
    strcpy(new_Knot->name, namen);
    new_Knot->number = number_;
    new_Knot->next = NULL;
    int i=0;
    if(*head==NULL || strcmp(namen, searchPtr->name) < 0){
        new_Knot->next = *head;
        *head = new_Knot;
        return;
    }
    while(searchPtr->next!=NULL){
        if(strcmp(namen, searchPtr->next->name) < 0){
            new_Knot->next = searchPtr->next;
            searchPtr->next = new_Knot;
            return;
        }
        searchPtr = searchPtr->next;
    }
    searchPtr->next=new_Knot;
}

void delKnot(knoten_t* head, long long number_){
    if(head==NULL){
        printf("Liste ist Leer!\n");
        return;
    }
    if(head->number==number_){
        free(head);
        return;
    }

    knoten_t* searchPtr = head;
    knoten_t* temp = head;
    while(searchPtr->next!=NULL){
        if(searchPtr->number==number_){
            temp->next=searchPtr->next;
            free(searchPtr);
            return;
        }
        temp=searchPtr;
        searchPtr=searchPtr->next;
    }
}

void freeList(knoten_t* head){
    if(head==NULL){
        return;
    }
    knoten_t* temp;
    while(head!=NULL){
        temp=head->next;
        free(head);
        head=temp;
    }
}