#include "bst.h"

void printTree_(knoten_t *, int);

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