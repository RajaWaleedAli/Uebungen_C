/*
Autor: Raja Waleed Ali
Datum: 02.05.2024
Beschreibung: BST.
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<time.h>
int count=0;
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
void printTree_(knoten_t *, int);
knoten_t* getFirst(knoten_t *);
knoten_t* getLast(knoten_t *);
int countMember(knoten_t *);

int main(){
    srand(time(NULL));
    knoten_t* root=NULL;
    int banane[10];
    for(int i=0;i<10;i++){
        int x= rand()%1000+1;
        banane[i]=x;
        addNode(&root, x);
        printf("Random Zahl %d = %d\n", i, x);
    }
    printTree(root);
    printf("fertig ausgegeben\n\n");
    delNode(&root, banane[5]);
    printTree(root);
    printf("fertig ausgegeben\n\n");

    return 0;
}

void addNode(knoten_t** root, int value_){
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
            if((*root)->greater!=NULL){
                temp=(*root)->greater;
            }else{
                temp=(*root)->small;
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

void printTree(knoten_t* root){
    printTree_(root, 0);
    count=0;
}

void printTree_(knoten_t* root, int level){
    if (root == NULL){
        //printf("fertig ausgegeben\n");
        return;
    }
    printf("%d BST Value: %d\n", count, root->value);
    count++;
    printTree_(root->small, level + 1);
    printTree_(root->greater, level + 1);
}