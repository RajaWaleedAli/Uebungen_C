/*
Autor: Raja Waleed Ali
Datum: 06.03.2024
Beschreibung: insertion sort
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

void printArr(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void sort(int arr[]){
    int pos2, pos1;
    int temp;
    for(pos2=1;pos2<10; pos2++){
        temp=arr[pos2];
        pos1=pos2-1;
        while(temp<arr[pos1]&&pos1>=0){
            arr[pos2]=arr[pos1];
            pos1--;
        }
        arr[pos1+1]=temp;
    }
}

int main(){
    int arr[]={6, 23 ,2, 7, 3, 8, 9, 11, 10, 45};
    sort(arr);
    printArr(arr, 10);
    return 0;
}