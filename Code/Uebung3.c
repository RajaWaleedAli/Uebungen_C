#include<stdio.h>
#include<math.h>

int main() {
    
    float a,b,c;
    printf("Gebe eine Zahl fuer a ein: ");
    scanf("%f", &a);
    printf("Gebe eine Zahl fuer b ein: ");
    scanf("%f", &b); 
    printf("Gebe eine Zahl fuer c ein: ");
    scanf("%f", &c);
    
    float d = (b*b)-(4*a*c);
    if(d>=1) { 
        printf("%f und %f sind die beiden Loesungen\n",-b+sqrt(d),-b-sqrt(d));
    }
    else if(d==0) {
        printf("%f ist die Loesung\n",-b+sqrt(d));
    }
    else if(d<0) {
        printf("Es gibt keine Loesungen\n");
    
}
return(0);
}
