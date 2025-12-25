/*
Autor: Raja Waleed Ali
Datum: 27.03.2024
Beschreibung: Rekursiv Selection Sort
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>

void fill(int arr[], int size){
    int i;
    for(i=0;i<size;i++){
        arr[i]=rand();
    }
}
void sort(int arr[]){
    sort_(arr, 0, 1);
}
void sort_(int arr[], int pos1, int pos2){
    int temp;
    if(pos1+1<sizeof(arr)/sizeof(arr[0])){
        while(pos2<sizeof(arr)/sizeof(arr[0])){
            if(arr[pos1]<arr[pos2]){
                temp=arr[pos2];
            }
            pos2++;
        }
        arr[pos1]=arr[pos2];
        arr[pos2]=temp;
        sort_(arr, pos1+1, pos1+2);
    }
}
void printArr(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){
    srand(time(NULL));
    int size=10;
    int arr[size];
    fill(arr, size);
    printArr(arr, size);
    sort(arr);
    printArr(arr, size);

    return 0;
}