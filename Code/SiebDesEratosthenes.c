/*
Autor: Raja Waleed Ali
Datum: 12.10.23
Beschreibung: Das Sieb des Eratosthenes.
*/

#include<stdio.h>

int main(){
    int zahl;
    int primzahl[100]= {0,1};
    int bedingungMod[8]={2,3,4,5,6,7,8,9};
    int i = 2;
    printf("Gib eine Zahl ein: ");
    scanf("%d", &zahl);
    int j;

    while(zahl>=2){
        j=0;
        for(int k = 0; k<8; k++){
            if(zahl%bedingungMod[k]==0 && zahl!=bedingungMod[k]){
                j++;
            }else if(zahl==0){
                break;
            }
            else{
                primzahl[i]=zahl;
            }
        }
        if (j>0){
            i++;
        }
        zahl--;
        if (primzahl[i]==0){
            i=i;
        }else{
            printf("Primzahl: %d\n", primzahl[i]);
        }
    }

    return 0;
}