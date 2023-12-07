#include<stdio.h>
#include<math.h>

int main(){
    float einkauf, steuer, aufschlag, preis;
    printf("Gib den Einkaufspreis ein! ");
    scanf("%f", &einkauf);
    printf("\nGib die Mehrwertssteuer in Prozent ein! ");
    scanf("%f", &steuer);
    printf("\nGib den Aufschlag in Prozent ein! ");
    scanf("%f", &aufschlag);

    preis = einkauf + (einkauf*(steuer/100));
    preis = preis + (preis*(preis/100));

    printf("Der Preis nach der Merhwertssteuer und dem Aufschlag lautet: %2.f Euro", preis);

    return 0;
}