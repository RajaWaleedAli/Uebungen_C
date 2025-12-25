#include<stdio.h>

int main () {
  int zahl1, zahl2, zahl3, zahlGross, zahlKlein1, zahlKlein2;

  printf("Gib die Zahl 1 ein!\n");
  scanf("%d", &zahl1);
  printf("Gib die Zahl 2 ein!\n");
  scanf("%d", &zahl2);
  printf("Gib die Zahl 3 ein!\n");
  scanf("%d", &zahl3);

  if (zahl1 > zahl2 && zahl1 > zahl3) {
    zahlGross = zahl1;
    if (zahl2 > zahl3) {
      zahlKlein1 = zahl2;
      zahlKlein2 = zahl3;
    } else {
      zahlKlein1 = zahl3;
      zahlKlein2 = zahl2;
    }
  } else if (zahl2 > zahl1 && zahl2 > zahl3) {
    zahlGross = zahl2;
    if (zahl1 > zahl3) {
      zahlKlein1 = zahl1;
      zahlKlein2 = zahl3;
    } else {
      zahlKlein1 = zahl3;
      zahlKlein2 = zahl1;
    }
  } else {
    zahlGross = zahl3;
    if (zahl2 > zahl1) {
      zahlKlein1 = zahl2;
      zahlKlein2 = zahl1;
    } else {
      zahlKlein1 = zahl1;
      zahlKlein2 = zahl2;
    }
  }

  printf("Die groeste Zahl lautet: %d\n", zahlGross);
  printf("Die 2. groeste Zahl lautet: %d\n", zahlKlein1);
  printf("Die kleinste Zahl lautet: %d\n", zahlKlein2);

  return 0;
}
