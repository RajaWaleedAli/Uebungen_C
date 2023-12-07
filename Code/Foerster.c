#include<stdio.h>

int main(){
    int alter, hoehe;
    printf("Gib die Hoehe vom Baum an: ");
    scanf("%d", &hoehe);
    printf("\nGib das Alter vom Baum an: ");
    scanf("%d", &alter);

    if (alter<=70 && hoehe<=20){
        printf("\nDer Baum soll nicht gefaellt werden, da er %d Jahre zu jung ist & %dm zu niedrig ist!", 70 - alter, 20 - hoehe);
    } else if (alter>70 && hoehe>20){
        printf("\nDer Baum soll gefaellt werden, da er %d Jahre zu alt ist & %dm zu hoch ist!", alter - 70, hoehe - 20);
    } else if (alter>70 && hoehe<=20){
        printf("\nDer Baum soll nicht gefaellt werden, da er %d Jahre zu alt ist & %dm zu niedrig ist!", alter - 70, 20 - hoehe);
    } else if (alter<=70 && hoehe>20){
        printf("\nDer Baum soll nicht gefaellt werden, da er %d Jahre zu jung ist & %dm zu hoch ist!", 70 - alter, hoehe - 20);
    }

    return 0;
}