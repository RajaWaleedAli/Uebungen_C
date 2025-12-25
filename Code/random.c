/*
Autor: Raja Waleed Ali
Datum: 15.10.23
Beschreibung: zufällige Zahl.
*/

#include<stdio.h>
#include<time.h>
#include<limits.h>
#include<stdlib.h>
#include<math.h>


int main(){
    srand(time(NULL));
    int i, x;
    int zaeler[6]={0};
    for(i=0; i<1000000;i++){
        x=rand()%6+1;
        printf("%d\n",x);
        switch(x){
            case 1: zaeler[0]++; break;
            case 2: zaeler[1]++; break;
            case 3: zaeler[2]++; break;
            case 4: zaeler[3]++; break;
            case 5: zaeler[4]++; break;
            case 6: zaeler[5]++; break;
        }
    }
    printf("\n\n\n1 = %d\n2 = %d\n3 = %d\n4 = %d\n5 = %d\n6 = %d\n", zaeler[0], zaeler[1], zaeler[2], zaeler[3], zaeler[4], zaeler[5]);

    return 0;
}