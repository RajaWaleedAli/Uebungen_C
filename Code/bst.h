//bst.h

#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include<string.h>
#include<unistd.h>

#ifndef BST_H
#define BST_H

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
knoten_t* getFirst(knoten_t *);
knoten_t* getLast(knoten_t *);

#endif