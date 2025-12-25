/*
Autor: Raja Waleed Ali
Datum: 12.10.23
Beschreibung: Prüft ob inhalt der 2 Arrays gleich sind.
*/

#include <stdio.h>
#include <stdbool.h>
int main()
{
    int array1[100] = {0};
    int array2[100] = {0};
    int array3[100] = {0};
    int i = 0;
    int j = 0;
    int k=0;
    int test;

    int zahl;
    printf("Gib eine Zahlenmenge ein! (negative Zahl eingeben um zur 2. Menge zu wechseln):\n");
    do
    {
        scanf("%d", &zahl);
        array1[i] = zahl;
        i++;
    } while (zahl >= 0);    //negative zahl eingeben um do while zu beenden
    i = i - 2;
    test = i;
    printf("Gib eine zweite Zahlenmenge ein! (negative Zahl eingeben zum beenden):\n");
    do
    {
        scanf("%d", &zahl);
        array2[j] = zahl;
        j++;
    } while (zahl >= 0);   //negative zahl eingeben um do while zu beenden
    j = j - 2;

    if (i != j)
    {
        printf("Die 2 Zahlenmengen sind nicht Gleich![1]");
        return 0;
    }
    else
    {
        i=test;
        while (i >= 0)
        {
            for (j=test; j>=0; j--){
                if (array1[i]==array2[j])
                {
                    array3[i]=array2[j];
                    k++;
                }
            }
            i--;
        }
    }
    for (i=test; i>=0; i--)
    {
        if(array1[i]!=array3[i])
        {
            printf("Die 2 Zahlenmengen sind nicht Gleich![2]");
            return 0;
        }
    }

    if (k == test+1)
    {
        printf("Die 2 Zahlenmengen sind Gleich!");
    }

    return 0;
}
