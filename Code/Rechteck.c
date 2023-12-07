#include<stdio.h>
#include<math.h>

int main(){
    int seite1, seite2, umfang, flaeche;
    printf("Gib die erste Seitenlaenge an! ");
    scanf("%d", &seite1);
    printf("\nGib die zweite Seitenlaenge an! ");
    scanf("%d", &seite2);

    flaeche = seite1 * seite2;
    umfang = (seite1 + seite2) * 2;
    float diagonale = sqrt((float)seite1 * seite1 + (float)seite2 * seite2);

    printf("\nFlaeche %d, Umfang %d, Diagonale %.2f", flaeche, umfang, diagonale);

    return 0;
}