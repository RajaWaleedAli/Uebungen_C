#include<stdio.h>
#include<math.h>

int main(){
	int x1, y1, x2, y2, x3, y3, distanzX, distanzY, distanz, distanzX2, distanzY2, distanz2;
	
	printf("Gib x1 ein!\n");
	scanf("%d", &x1);
	printf("Gib y1 ein!\n");
	scanf("%d", &y1);
	printf("Gib x2 ein!\n");
	scanf("%d", &x2);
	printf("Gib y2 ein!\n");
	scanf("%d", &y2);
	printf("Gib x3 ein!\n");
	scanf("%d", &x3);
	printf("Gib y3 ein!\n");
	scanf("%d", &y3);
	
	if(x2<x1){
		distanzX = x1-x2;
	}else{
		distanzX = x2-x1;
	}
	if(y2<y1){
		distanzY = y1-y2;
	}else{
		distanzY = y2-y1;
	}
	if(x3<x2){
		distanzX2 = x2-x3;
	}else{
		distanzX2 = x3-x2;
	}
	if(y3<y2){
		distanzY2 = y2-y3;
	}else{
		distanzY2 = y3-y2;
	}
	
	printf("X: %d\nY: %d\n", distanzX, distanzY);
	printf("X2: %d\nY2: %d\n", distanzX2, distanzY2);
	
	distanz = sqrt((float)distanzX*distanzX+(float)distanzY*distanzY);
	distanz2 = sqrt((float)distanzX2*distanzX2+(float)distanzY2*distanzY2);
	printf("Die Distanz zwischen den Punkten P1 & P2 Lautet: %d\nDie Distanz zwischen den Punkten P1, P2 & P3 Lautet: %d\n", distanz, distanz2);
	
	return 0;
}
