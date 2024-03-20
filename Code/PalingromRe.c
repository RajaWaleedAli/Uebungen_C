/*
Autor: Raja Waleed Ali
Datum: 06.03.2024
Beschreibung: rekursiv palindrom
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

int palindrom_(char* s1, int pos){
    int size=strlen(s1);
    if(s1[pos]==s1[size-pos]&&pos<(size/2)){
        return palindrom_(s1, pos+1);
    }else if(pos==(size/2)){
        return 1;
    }else{
        return 0;
    }
}
int palindrom(char* s1){
    int i;
    for(i=0;i<strlen(s1);i++){
        if(s1[i]<="Z"&&s1[i]>="A"){
            s1[i]+="a"-"A";
        }
    }
    int load=palindrom_(s1, 0);
    return load;
}
int main(){
    char* s1;
    scanf("%s", &s1);
    int load = palindrom(s1);
    if(load==1){
        printf("Palingom = Ja!\n");
    }else{
        printf("Palingom = Nein!\n");
    }
    return 0;
}