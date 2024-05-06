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
    struct knoten* greater; //rechts
    struct knoten* small;   //links
}knoten_t;

void addNode(knoten_t **, int);
void delNode(knoten_t **, int);
knoten_t* searchNode(knoten_t *, int);
void freeList(knoten_t *);
void printTree(knoten_t *);
knoten_t* getFirst(knoten_t *);
knoten_t* getLast(knoten_t *);
int countMember(knoten_t *);

int main(){


    return 0;
}

void addNode(knoten_t** root, int value_){
    knoten_t* searchPtr = *root;
    knoten_t* new_node = (knoten_t *) malloc(sizeof(knoten_t));
    new_node->value = value_;
    new_node->greater = NULL;
    new_node->small = NULL;

    if(*root==NULL){
        *root = new_node;
        return;
    }
    while(searchPtr!=NULL){
        if(searchPtr->value < value_){
            searchPtr=searchPtr->small;
        }else if(searchPtr->value >= value_){
            searchPtr=searchPtr->greater;
        }
    }
    searchPtr=new_node;
}

void delNode(knoten_t** root, int value_){
    knoten_t* searchPtr = *root;
    knoten_t* temp = NULL;

    if(*root==NULL){
        printf("Liste ist Leer!\n");
        return;
    }
    while(searchPtr!=NULL){
        if(searchPtr->value==value_){
            temp->greater=searchPtr->greater;
            temp->small=searchPtr->small;
            free(searchPtr);
            return;
        }
        if(searchPtr->value < value_){
            temp=searchPtr;
            searchPtr=searchPtr->small;
        }else if(searchPtr->value >= value_){
            temp=searchPtr;
            searchPtr=searchPtr->greater;
        }
    }
}

void printTree(knoten_t* root){
    if(root==NULL){
        return;
    }
    printf("Value: %d\n", root->value);
}