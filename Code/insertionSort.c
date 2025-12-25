/*
Autor: Raja Waleed Ali
Datum: 06.03.2024
Beschreibung: insertion sort
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>

void printArr(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void sort(int arr[]){
    int pos2, pos1;
    int temp;
    int count=0;
    for(pos2=1;pos2<10; pos2++){
        temp=arr[pos2];
        pos1=pos2-1;
        while(temp<arr[pos1]&&pos1>=0){
            arr[pos2]=arr[pos1];
            pos1--;
            count++;
        }
        arr[pos1+1]=temp;
    }
    printf("Druchläufe: %d\n", count);
}


int main(){
    srand(time(NULL));
    int size=10;
    int i;
    int numbers[size];
    for(i=size;i!=0;i++){
        numbers[i]=rand();
    }

    sort(numbers);

    printArr(numbers, 10);

    return 0;
}