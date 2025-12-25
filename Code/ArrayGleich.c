/*
Autor: Raja Waleed Ali
Datum: 12.10.23
Beschreibung: Prüft ob 2 Arrays gleich sind.
*/

#include <stdio.h>
#include <stdbool.h>
int main()
{
    int array1[100] = {0};
    int array2[100] = {0};
    int i = 0;
    int j = 0;
    bool test = false;

    int zahl;
    do
    {
        printf("Gib eine Zahlenmenge ein: ");
        scanf("%d", &zahl);
        array1[i] = zahl;
        i++;
    } while (zahl >= 0);
    i = i - 2;
    do
    {
        printf("Gib eine zweite Zahlenmenge ein: ");
        scanf("%d", &zahl);
        array2[j] = zahl;
        j++;
    } while (zahl >= 0);
    j = j - 2;

    if (i != j)
    {
        printf("Die 2 Zahlenmengen sind nicht Gelich![1]");
    }
    else
    {
        while (i >= 0)
        {
            if (array1[i] == array2[i])
            {
                test = true;
            }
            else
            {
                printf("Die 2 Zahlenmengen sind nicht Gelich![2]");
                return 0;
            }
            i--;
        }
    }
    if (test == true)
    {
        printf("Die 2 Zahlenmengen sind Gelich!");
    }

    return 0;
}
