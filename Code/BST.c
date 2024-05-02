/*
Autor: Raja Waleed Ali
Datum: 02.05.2024
Beschreibung: BST.
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

typedef struct knoten{
    int value;
    struct knoten* greater;
    struct knoten* small;
}knoten_t;

void addKnot(knoten_t **, char *, long long number_);
void delKnot(knoten_t **, long long number_);
knoten_t* searchKnot(knoten_t *, long long number_);
void freeList(knoten_t *);
void printList(knoten_t *);
knoten_t* getFirst(knoten_t *);
knoten_t* getLast(knoten_t *);
int countMember(knoten_t *);

int main(){


    return 0;
}

void addKnot(knoten_t** root, int value_){
    knoten_t* searchPtr = *root;
    knoten_t* new_Knot = (knoten_t *) malloc(sizeof(knoten_t));
    new_Knot->value = value_;
    new_Knot->greater = NULL;
    new_Knot->small = NULL;
    int i=0;
    if(*root==NULL){
        *root = new_Knot;
        return;
    }
    while(searchPtr->greater!=NULL||searchPtr->small!=NULL){
        if(strcmp(namen, searchPtr->next->name) < 0){
            new_Knot->next = searchPtr->next;
            searchPtr->next = new_Knot;
            return;
        }
        searchPtr = searchPtr->next;
    }
    searchPtr->next=new_Knot;
}