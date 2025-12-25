#include<stdio.h>

int main(){
    char symbol;
    printf("Gib Ein Symbol ein! ");
    scanf("%c", &symbol);

    if (symbol>=65 && symbol<=90){
        printf("Dein Symbol ist ein grosser Buchstabe im Alphabet!");
    } else if (symbol>=97 && symbol<=122){
        printf("Dein Symbol ist ein kleiner Buchstabe im Alphabet!");
    } else {
        printf("Dein Symbol ist nicht im Alphabet!");
    }

    return 0;
}