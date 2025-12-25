



int ausgabe(int y, int x, int player, char feld[3][3]){
    char eingabe;
    if(player==0){
        eingabe='X';
    }else{
        eingabe='O';
    }
    if(feld[y-1][x-1]==' '){
        feld[y-1][x-1]=eingabe; 
        system("cls");
        printf("\n\tTicTacToe\n___________________________\n|   |\tX1|\tX2|\tX3|\n|___|_____|_______|_______|\n");
        for(i=0;i<3;i++){
            printf("|Y%d |", i+1);                      //Beschriftet Y-Koordinate
            for(j=0; j<3; j++){
                printf("\t%c |", feld[i][j]);           //füllt feld mit der eingabe
            }
            printf("\n");
        }
        printf("|___|_____|_______|_______|\n");

        return 1;

    }else if(xP1>3||yP1>3){
        printf("Dieses Feld exestiert nicht! Gib noch eine Koordinate ein (x/y = [1-3])!\n");
        return 0;
    }else{
        printf("Dieses Feld ist schon besetzt! Gib noch eine Koordinate ein!\n");
        return 0;
    }
}

int winX(int player){
    char eingabe;
    if(player==0){
        eingabe='X';
    }else{
        eingabe='O';
    }
    for(i=0;i<3;i++){                                                               //Bedingungen Für Sieg
        j=0;
            if(feld[i][j]==eingabe &&feld[i][j+1]==eingabe &&feld[i][j+2]==eingabe){
                win=1;
                printf("Player 1 hat gewonnen!");
                return 0;
            }else if(feld[j][i]==eingabe &&feld[j+1][i]==eingabe &&feld[j+2][i]==eingabe){
                win=1;
                printf("Player 1 hat gewonnen!");
                return 0;
            }else if(feld[0][0]==eingabe &&feld[1][1]==eingabe &&feld[2][2]==eingabe){
                win=1;
                printf("Player 1 hat gewonnen!");
                return 0;
            }else if(feld[0][2]==eingabe &&feld[1][1]==eingabe &&feld[2][0]==eingabe){
                win=1;
                printf("Player 1 hat gewonnen!");
                return 0;
            }
    }
    return 1;
}

int winO(int feld[3][3]){
    for(i=0;i<3;i++){                                                               //Bedingungen Für Sieg
        j=0;
            if(feld[i][j]=='X'&&feld[i][j+1]=='X'&&feld[i][j+2]=='X'){
                win=1;
                printf("Player 1 hat gewonnen!");
                return 0;
            }else if(feld[j][i]=='X'&&feld[j+1][i]=='X'&&feld[j+2][i]=='X'){
                win=1;
                printf("Player 1 hat gewonnen!");
                return 0;
            }else if(feld[0][0]=='X'&&feld[1][1]=='X'&&feld[2][2]=='X'){
                win=1;
                printf("Player 1 hat gewonnen!");
                return 0;
            }else if(feld[0][2]=='X'&&feld[1][1]=='X'&&feld[2][0]=='X'){
                win=1;
                printf("Player 1 hat gewonnen!");
                return 0;
            }
    }
    return 1;
}