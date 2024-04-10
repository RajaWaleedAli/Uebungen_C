/*
Autor: Raja Waleed Ali
Datum: 27.03.2024
Beschreibung: mittelwert.
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

double average(void);

int main(){
    system("cls");
    printf("average: %f", average());

    return 0;
}

double average(void){
    double* data = malloc((10*sizeof(double)));
    int exit=0;
    int i=0;
    int temp=1;
    double avg=0;
    while(1){
        if(i>10*temp){
            temp = i/10;
            data=realloc(data, (10*sizeof(double))*temp);
        }
        scanf("%lf", &data[i]);
        if(data[i]==-1){
            break;
        }
        avg+=data[i];
        i++;
    }
    avg/=i;

    return avg;
}