/*
Autor: Raja Waleed Ali
Datum: 27.11.23
Beschreibung: Betrag.
*/

#include<stdio.h>
#include<time.h>
#include<limits.h>
#include<stdlib.h>
#include<math.h>

double betrag(double a){
    if (a<0){
        a=a*(-1);
    }
    return a;
}

int main(){
    double x=-7;
    printf("%f", betrag(x));

    return 0;
}