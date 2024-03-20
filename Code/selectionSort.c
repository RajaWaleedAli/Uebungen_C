#include <stdio.h>

void sortiere(int groesse, int array[]);
void ausgeben(int groesse, int array[]);

int main(){
    srand(time(NULL));
    int size=10;
    int i;
    int numbers[size];
    sortiere(groesse, numbers);
    //ausgeben(groesse, array);
    return 0;
}

void ausgeben(int groesse, int array[]){
    int i;
    for (i = 0; i < groesse; i++) {
        printf("%d ", array[i]);
    }
}

void sortiere(int groesse, int array[]){
    int j, i, stelle = 0;
    int temp2;
    
    for (i = stelle; i < groesse; i++) {
        int temp = array[i];
        int minIndex = i;
        
        for (j = stelle; j < groesse; j++) {
            if (array[j] < temp) {
                temp = array[j];
                minIndex = j;
            }
        }
        
        temp2 = array[i];
        array[i] = temp;
        array[minIndex] = temp2;
        
        stelle++;
    }
}

