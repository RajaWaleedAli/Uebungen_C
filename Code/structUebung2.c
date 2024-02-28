/*
Autor: Raja Waleed Ali
Datum: 28.02.24
Beschreibung: Uhrzeit
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

struct time{
    int hour;
    int min;
    int sec;
};

void printDaten(struct time fill){
    printf("\nStunden: %d\n", fill.hour);
    printf("Minuten: %d\n", fill.min);
    printf("Sekunden: %d\n", fill.sec);
}
int cmp2(int a, int b){
    if(a<b){
        return -1;
    }else{
        return 1;
    }
}
int cmp(struct time a1, struct time a2) {
    if(a1.hour != a2.hour){
        return cmp2(a1.hour, a2.hour);
    }
    if(a1.min != a2.min){
        return cmp2(a1.min, a2.min);
    }
    if(a1.sec!=a2.sec){
        return cmp2(a1.sec, a2.sec);
    }
    return 0;
}

int main(){
    int m, s, h;
    typedef struct time zeit;
    zeit arr[2];

    printf("Gib die Uhrzeit an!\n");
    scanf("%d %d %d", &h, &m, &s);
    arr[0].hour=h;
    arr[0].min=m;
    arr[0].sec=s;
    printf("Gib die Uhrzeit an!\n");
    scanf("%d %d %d", &h, &m, &s);
    arr[1].hour=h;
    arr[1].min=m;
    arr[1].sec=s;

    printDaten(arr[0]);
    printDaten(arr[1]);

    printf("\n%d", cmp(arr[0], arr[1]));

    return 0;
}