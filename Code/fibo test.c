//Fibonacci Rekursiv

#include<stdio.h>

int fibo_1(int x, int y){
    int sum=0;
    if(y<x-2){
        sum= y+fibo(x,y+1);
    }
    return sum;
}
int fibo(int x){
    fibo_1(x, 0);
}
int main(){
    printf("%d", fibo(5));
    return 0;
}