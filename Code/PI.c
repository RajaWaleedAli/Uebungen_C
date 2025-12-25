/*
Autor: Raja Waleed Ali
Datum: 15.10.23
Beschreibung: Pi berechnen.
*/

#include<stdio.h>
#include<time.h>
#include<limits.h>
#include<stdlib.h>
#include<math.h>

int main(){
    system("cls");
    srand(time(NULL));
    int kreis, nKreis, i, tropfenGes;
    int magischeZahl=1;
    float pytha, x, y;
    kreis=0;
    nKreis=0;

    printf("Wieviele Tropfen fallen auf der Flaeche? ");
    scanf("%d", &tropfenGes);

    for (i=0; i<tropfenGes; i=i+magischeZahl){
        x = rand();
        x /= RAND_MAX;
        y = rand();
        y /= RAND_MAX;
        pytha = x*x+y*y;
        if(pytha>1){
            nKreis=nKreis+magischeZahl;
        } else{
            kreis=kreis+magischeZahl;
        }
    }

    printf("Tropfen im Kreis: %d\nTropfen aussserhalb des Kreises: %d\nTropfen Insgesamt: %d\n", kreis, nKreis, kreis+nKreis);
    printf("PI lautet: %f", 4*(float)kreis/(float)tropfenGes);

    return 0;
}