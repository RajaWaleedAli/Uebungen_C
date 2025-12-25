#include<stdio.h>
#include<math.h>

int main(){
    int x, y, x1, x2, y1, y2;

    printf("Gib x ein! ");
    scanf("%d", &x);
    printf("\nGib y ein! ");
    scanf("%d", &y);
    
    y1 = 10;
    y2 = 20;
    x1 = 10;
    x2 = 20;
    
    if ((x >= x1 && y>= y1) && (x <= x2 && y <= y2)){
        printf("Deine Koordiate befindet sich im Rechteck!");
    } else if (y>y2 && x>x2) {
        printf("Die Y & X Koordinaten sind zu gross!");
    } else if (y<y1 && x>x2) {
        printf("Die Y Koordinate ist zu klein!\nDie X Koordinate ist zu gross");
    } else if (y>y2 && x<x1) {
        printf("Die Y Koordinate ist zu gross\nDie Y Koordinate ist zu klein!");
    } else if (y<y1 && x<x1) {
        printf("Die X & Y Koordinaten sind zu klein!");
    } else if (y>y2) {
        printf("Die Y Koordinate ist zu gross!");
    } else if (y<y1) {
        printf("Die Y Koordinate ist zu klein!");
    } else if (x>x2) {
        printf("Die X Koordinate ist zu gross");
    } else if (x<x1) {
        printf("Die X Koordinate ist zu klein!");
    } 

    return 0;
}
