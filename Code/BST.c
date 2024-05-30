/*
Autor: Raja Waleed Ali
Datum: 02.05.2024
Beschreibung: BST.
*/
#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include<string.h>
#include<unistd.h>
#include<time.h>
#include "bst.h"
/*
typedef struct knoten{
    int value;
    struct knoten* greater; //rechts
    struct knoten* small;   //links
}knoten_t;

void addNode(knoten_t **, int);
void delNode(knoten_t **, knoten_t *, int, bool);

knoten_t* searchNode(knoten_t *, int);
void freeBST(knoten_t *);
void printTree(knoten_t *);
void printTree_(knoten_t *, int);
knoten_t* getFirst(knoten_t *);
knoten_t* getLast(knoten_t *);
*/
int main(){
    printf("Funktion eingebunden!\n");
    srand(time(NULL));
    knoten_t* root=NULL;
    int banane[10];
    printf("Random Zahlen: ");
    for(int i=0;i<10;i++){
        int x= rand()%1000+1;
        banane[i]=x;
        addNode(&root, x);
        printf("%d, ", x);
    }
    printf("\n");
    printTree(root);
    printf("fertig ausgegeben\n\n");
    knoten_t* first=root;
    delNode(&root, root, banane[5], false);
    root=first;
    printTree(root);
    printf("fertig ausgegeben\n\n");
    freeBST(root);
    return 0;
}
/*
void addNode(knoten_t** root, int value_){  //inspiration von Leon
    if(*root==NULL){
        *root = (knoten_t *) malloc(sizeof(knoten_t));
        (*root)->value = value_;
        (*root)->greater = NULL;
        (*root)->small = NULL;
        return;
    }
    if((*root)->value<value_){
        addNode(&(*root)->small, value_);
    }else{
        addNode(&(*root)->greater, value_);
    }
}
/*
void delNode(knoten_t** root, int value_){
    knoten_t* temp = NULL;
    knoten_t* temp2 = NULL;
    knoten_t* first = *root;
    if(*root==NULL){
        printf("Liste ist Leer!\n");
        return;
    }
    while((*root)->small!=NULL||(*root)->greater!=NULL){
        if((*root)->value==value_){
            if((*root)->small==NULL&&(*root)->greater==NULL){
                temp=*root;
                free(temp);
                printf("%d wurde Geloescht!\n", value_);
                *root=first;
                return;
            }
            temp2=*root;
            temp=(*root)->small;
            while(temp->greater==NULL&&temp->small!=NULL){
                temp2=temp;
                temp=temp->small;
            }
            if(temp->greater!=NULL){
                temp=temp->greater;
            }
            while(temp->small!=NULL){
                temp2=temp;
                temp=temp->small;
            }
            temp2->small=temp->greater;
            (*root)->value=temp->value;
            free(temp);
            printf("%d wurde Geloescht!\n", value_);
            *root=first;
            return;
        }
        if((*root)->value < value_){
            *root=(*root)->small;
        }else{
            *root=(*root)->greater;
        }
    }
    *root=first;
    printf("Fehler beim Loeschen\n");
}

//rekursiv loeschen

void delNode(knoten_t** root, knoten_t* temp, int value_, bool gefunden){
    if(*root==NULL){
        //printf("Liste ist Leer!\n");
        return;
    }
    if(gefunden==false && value_==(*root)->value){
        if((*root)->greater==NULL&&(*root)->small==NULL){
            *root=NULL;
            return;
        }else if((*root)->greater->small==NULL){
            (*root)->greater->small=(*root)->small;
            *root=(*root)->greater;
            free(temp);
            return;
        }else if((*root)->greater!=NULL){
            delNode(&root, temp->greater, value_, true);
        }else if((*root)->small!=NULL){
            *root=(*root)->small;
            free(temp);
            return;
        }
    }
    if(gefunden==true){
        if(temp->small->small!=NULL){
            delNode(&root, temp->small, value_, true);
        }else{
            knoten_t* temp2=temp->small;
            (*root)->value=temp2->value;
            temp->small=temp2->greater;
            free(temp2);
            return;
        }
    }
    delNode(&(*root)->greater, (*root)->greater, value_, false);
    delNode(&(*root)->small, (*root)->small, value_, false);
}

void printTree(knoten_t* root){
    printTree_(root, 0);
}

void printTree_(knoten_t* root, int stufe){
    if (root == NULL){
        return;
    }
    printf("Stufe: %d BST Value: %d\n", stufe, root->value);
    printTree_(root->small, stufe + 1);
    printTree_(root->greater, stufe + 1);
}

void freeBST(knoten_t* root){
    if (root == NULL){
        return;
    }
    knoten_t* temp=root;
    freeBST(root->small);
    freeBST(root->greater);
    free(temp);
}
*/