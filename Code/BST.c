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

typedef struct knoten{
    int value;
    struct knoten* greater; //rechts
    struct knoten* small;   //links
}knoten_t;

void addNode(knoten_t *, int);
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
        addNode(root, x);
        printf("Random Zahl %d = %d\n", i, x);
    }
    printTree(root);
    delNode(&root, banane[3]);
    printTree(root);

    return 0;
}

void addNode(knoten_t* root, int value_){
    //knoten_t* searchPtr = *root;

    if(root==NULL){
        knoten_t* new_node = (knoten_t *) malloc(sizeof(knoten_t));
        new_node->value = value_;
        new_node->greater = NULL;
        new_node->small = NULL;
        root = new_node;
        return;
    }
    if(root->value<value_){
        addNode(root->small, value_);
    }else{
        addNode(root->greater, value_);
    }
    /*
    while(searchPtr!=NULL){
        if(searchPtr->value < value_){
            searchPtr=searchPtr->small;
        }else if(searchPtr->value >= value_){  
            searchPtr=searchPtr->greater;
        }
    }
    searchPtr=new_node;
    */
}

void delNode(knoten_t** root, int value_){
    knoten_t* searchPtr = *root;
    knoten_t* temp = NULL;
    knoten_t* temp2 = NULL;

    if(*root==NULL){
        printf("Liste ist Leer!\n");
        return;
    }
    while(searchPtr->small!=NULL||searchPtr->greater!=NULL){
        if(searchPtr->value==value_){
            temp->greater=searchPtr->greater;
            temp->small=searchPtr->small;
            free(searchPtr);
            return;
        }
        if(searchPtr->value < value_){
            temp=searchPtr;
            searchPtr=searchPtr->small;
        }else{
            temp=searchPtr;
            searchPtr=searchPtr->greater;
        }
    }
}

void printTree(knoten_t* root){
    printTree_(root, 0);
}

void printTree_(knoten_t* root, int level){
    if (root == NULL){
        printf("fertig ausgegeben\n");
        return;
    }
    printf("%d\n", root->value);
    printTree_(root->small, level + 1);
    printTree_(root->greater, level + 1);
}