/*
Autor: Raja Waleed Ali
Datum: 25.09.23
Beschreibung: Wandelt eine Dezimalzahl in einer Binärzahl um.
*/

#include<stdio.h>
#include<math.h>

int main (){
    int i, a, zahl, c, d;
    int j[100] = {0};
    b = 0;
    c = 0;
    printf("Gib Eine Zahl ein! ");
    scanf("%d", &zahl);

    printf("Die Zahl %d ist die zahl\n", zahl);

    while (i>0){
        a = zahl;
        j[i] = zahl%2;
        zahl = zahl/2;

        printf("%d\t : 2 = %d \tund Rest\t %d\n",a , zahl, j[i]);
        i++;
    }
    printf("Die Zahl lautet: ");
    while (i >= 0){
        printf("%d", j[i]);
        i--;
    }
    /*printf(" 1 kommt %d Mal vor und 0 kommt %d Mal vor! Die Binaerzahl hat %d stellen!\n0er: ", c, b, b + c);

    while(b != 0){
        printf("#");
        b--;
    }
    printf("\n1er: ");
    while(c != 0){
        printf("#");
        c--;
    }*/

    return 0;
}