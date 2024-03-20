/*
Autor: Raja Waleed Ali
Datum: 013.03.2024
Beschreibung: Monkey Sort
*/

#include<stdio.h>
#include<time.h>
#include<limits.h>
#include<stdlib.h>
#include<stdbool.h>

int main(){
    srand(time(NULL));
    int size=10;
    int i;
    int numbers[size];
    for(i=size;i!=0;i++){
        numbers[i]=rand();
    }
    int rand1, rand2, load, i, j;
    bool right=false;
    while(right==false){
        rand1=rand()%10;
        rand2=rand()%10;
        load=numbers[rand1];
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
    /*for(i=0;i<10;i++){
        printf("%d ", numbers[i]);
    }
    */
    return 0;
}