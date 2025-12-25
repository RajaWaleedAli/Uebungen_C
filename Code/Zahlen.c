/*
Autor: Raja Waleed Ali
Datum: 27.09.23
Beschreibung: Zählt die Ziffern.
*/

#include<stdio.h>
#include<math.h>

int main(){
    long long zahl, zahl2;
    int ziffer;
    int stellen[10]={0};
    printf("Gib Eine Zahl ein! ");
    scanf("%lld", &zahl);
    ziffer=0;

    while(zahl>0){
        zahl2=zahl-(zahl/10)*10;
        zahl=zahl/10;
        ziffer++;
        printf("Ziffer an stelle %d: %lld\n", ziffer, zahl2);
        switch(zahl2){
            case 0: stellen[0]++; break;
            case 1: stellen[1]++; break;
            case 2: stellen[2]++; break;
            case 3: stellen[3]++; break;
            case 4: stellen[4]++; break;
            case 5: stellen[5]++; break;
            case 6: stellen[6]++; break;
            case 7: stellen[7]++; break;
            case 8: stellen[8]++; break;
            case 9: stellen[9]++; break;
        }
    }
    printf("Nuller: %d\neinser: %d\nzweier: %d\ndreier: %d\nvierer: %d\n", stellen[0], stellen[1], stellen[2], stellen[3], stellen[4]);
    printf("fuenfer: %d\nsecher: %d\nsiebner: %d\nachter: %d\nneuner: %d\n", stellen[5], stellen[6], stellen[7], stellen[8], stellen[9]);
    printf("Ziffern: %d\n", ziffer);
    

    return 0;
}