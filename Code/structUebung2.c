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
    printf("Stunden: %d\n", fill.hour);
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

void fill(struct time arr[], int place, int h, int m, int s){
    arr[place].hour=h;
    arr[place].min=m;
    arr[place].sec=s;
}

void dif(struct time arr[], int time1[], int time2[]){
    if(cmp(arr[0], arr[1])==-1){
        dif2(arr, time1, time2);
    }else if(cmp(arr[0], arr[1])==1){
        dif2(arr, time2, time1);
    }else{
        time1[0]=0;
        time1[1]=0;
        time1[2]=0;
        fill(arr, 2, time1[0], time1[1], time1[2]);
    }
}
void dif2(struct time arr[], int time1[], int time2[]){
    time1[0]=time2[0]-time1[0];
    time1[1]=time2[1]-time1[1];
    time1[2]=time2[2]-time1[2];
    if(time1[2]<0){
        time1[1]-=1;
        time1[2]+=60;
    }
    if(time1[1]<0){
        time1[0]-=1;
        time1[1]+=60;
    }
    if(time1[0]<0){
        time1[0]+=24;
        time1[1]=(60-time1[1])%60;
        time1[2]=(60-time1[2])%60;
    }
    fill(arr, 2, time1[0], time1[1], time1[2]);
}

int main(){
    typedef struct time zeit;
    zeit arr[3];
    int time1[]={14, 10, 20};      //h, min, sec
    int time2[]={13, 20, 20};      //h, min, sec

    fill(arr, 0, time1[0], time1[1], time1[2]);
    fill(arr, 1, time2[0], time2[1], time2[2]);
    printf("1. Zeit:\n");
    printDaten(arr[0]);
    printf("2. Zeit:\n");
    printDaten(arr[1]);

    dif(arr, time1, time2);

    printf("Controlle: %d\n", cmp(arr[0], arr[1]));
    printf("Differenz:\n");
    printDaten(arr[2]);

    return 0;
}