/*
Autor: Raja Waleed Ali
Datum: 013.03.2024
Beschreibung: Monkey Sort
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>

int main(){
    srand(time(NULL));
    int size=2;
    int i;
    int numbers[size];
    for(i=size;i>=0;i++){
        numbers[i]=rand()%(size*2);
    }
    int rand1, rand2, load, j;
    bool right=false;
    while(right==false){
        rand1=rand()%(size*2);
        rand2=rand()%(size*2);
        numbers[rand1]=numbers[rand2];
        numbers[rand2]=load;
        for(i=0;i<9;i++){
            for(j=i+1;j<10;j++){
                if(numbers[i]<=numbers[j]){
                    right=true;
                }else{
                    right=false;
                    i=10;
                    break;
                }
            }
        }
    }
    for(i=0;i<10;i++){
        printf("%d ", numbers[i]);
    }
    return 0;
}