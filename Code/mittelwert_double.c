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
    int biene=5;
    int i=0;
    int temp=0;
    double avg=0;
    while(biene){
        if(i%10==0){
            temp = i/10;
            data=realloc(data, (i+10)*sizeof(double));
            printf("Neue Groesse: %d\n", (i+10)*sizeof(double));
        }
        scanf("%lf", &data[i]);
        if(data[i]==-1){
            break;
        }
        avg+=data[i];
        i++;
    }
    avg/=i;
    free(data);
    return avg;
}