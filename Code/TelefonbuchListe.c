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

void addKnot(knoten_t **, char *, long long number_);
void delKnot(knoten_t **, long long number_);
knoten_t* searchKnot(knoten_t *, long long number_);
void freeList(knoten_t *);
void printList(knoten_t *);
knoten_t* getFirst(knoten_t *);
knoten_t* getLast(knoten_t *);
int countMember(knoten_t *);

int askMode(void);
void loop(knoten_t *);



int main(){
    system("cls");
    knoten_t* head = (knoten_t *) malloc(sizeof(knoten_t));
    head=NULL;
    /*addKnot(&head, "Hello World", 1);
    addKnot(&head, "Max Mustermann", 2);
    printList(head);*/
    loop(head);
    return 0;
}

void printList(knoten_t* head){
    knoten_t * current = head;

    while (current != NULL) {
        printf("Name: %s\tNummer: %lld\n", current->name, current->number);
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

void delKnot(knoten_t** head, long long number_){
    knoten_t* searchPtr = *head;
    knoten_t* temp = *head;
    if(*head==NULL){
        printf("Liste ist Leer!\n");
        return;
    }
    if(searchPtr->number==number_&&searchPtr->next==NULL){
        free(searchPtr);
        *head=NULL;
        return;
    }

    if(searchPtr->number==number_){
        *head=searchPtr->next;
        free(searchPtr);
        return;
    }
    searchPtr=searchPtr->next;
    while(searchPtr->next!=NULL){
        if(searchPtr->number==number_){
            temp->next=searchPtr->next;
            free(searchPtr);
            return;
        }
        temp=searchPtr;
        searchPtr=searchPtr->next;
    }
    if(searchPtr->number==number_){
        temp->next=NULL;
        free(searchPtr);
        return;
    }else{
        printf("Nummer exestiert nicht!\n");
        return;
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

int countMember(knoten_t* head){
    if(head==NULL){
        return 0;
    }
    if(head->next==NULL){
        return 1;
    }
    knoten_t* temp = head;
    int count=0;
    while(temp->next!=NULL){
        count++;
        temp=temp->next;
    }
    return count;
}

knoten_t* searchKnot(knoten_t* head, long long number_){
    if(head==NULL){
        printf("Liste ist Leer!\n");
        return NULL;
    }
    knoten_t* searchPtr = head;
    while(searchPtr->next!=NULL){
        if(searchPtr->number==number_){
            return searchPtr;
        }
        searchPtr=searchPtr->next;
    }
    printf("Nicht Gefunden!\n");
    return NULL;
}
knoten_t* getFirst(knoten_t* head){
    return head;
}

knoten_t* getLast(knoten_t* head){
    knoten_t* searchPtr = head;
    if(head==NULL){
        printf("Liste ist Leer!\n");
        return NULL;
    }
    while(searchPtr->next!=NULL){
        searchPtr=searchPtr->next;
    }
    return searchPtr;
}

int askMode(void){
    int mode = 0;
    do{
        printf("\n(1) Element hinzufuegen!\n(2) Element loeschen!\n(3) Element suchen!\n");
        printf("(4) Elemente ausgeben!\n(5) Elemente zaelen!\n(6) Erstes Element Ausgeben\n");
        printf("(7) Letztest Element Ausgeben\n(8) Beenden\nEingabe: ");
        scanf("%d", &mode);
    }while(mode<1 || mode>8);

    return mode;
}

void loop(knoten_t* head){
    char namen[30];
    long long number_;
    knoten_t* temp;
    while(1){
        int mode = askMode();
        switch (mode){
            case 1:
                printf("\nGib Name ein! ");
                scanf("%s", &namen);
                /*fflush(stdin);
                fgets(namen, 30, stdin);
                fflush(stdin);*/
                printf("\nGib Nummer ein! ");
                scanf("%lld", &number_);
                addKnot(&head, namen, number_);
                break;
            case 2:
                printf("\nGib Nummer ein! ");
                scanf("%lld", &number_);
                delKnot(&head, number_);
                break;
            case 3:
                printf("\nGib Nummer ein! ");
                scanf("%lld", &number_);
                temp = searchKnot(head, number_);
                temp->next=NULL;
                printList(temp);
                break;
            case 4:
                printList(head);
                break;
            case 5:
                printf("Eintraege im Telefonbuch: %d\n", countMember(head));
                break;
            case 6:
                temp = getFirst(head);
                temp->next=NULL;
                printList(temp);
                break;
            case 7:
                temp = getLast(head);
                printList(temp);
                break;
            case 8:
                freeList(head);
                return;
        }
    }
}