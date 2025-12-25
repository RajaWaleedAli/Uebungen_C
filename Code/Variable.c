#include<stdio.h>

int main(){
	char x;
	int y, alter;
	float z;
	
	x='A';
	y=15;
	z=3.1415;
	
	printf("Wie alt sind Sie?\n");
	
	scanf("%d", &alter);
	
	printf("Sie sind %d Jahre alt\n", alter);
	
	printf("char x = %c, int y = %d, float z = %f\n", x, y, z);
	
	return 0;
}
