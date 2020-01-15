#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
const char* board[9][9] = {
  {"|","-","-","-","-","-","Z","-","|"},
  {"|", 0,  0,  0, "|", 0,  0,  0, "|"},
  {"|","-","|", 0, "|","-","|", 0, "|"},
  {"|", 0, "|", 0, "|", 0, "|", 0, "|"},
  {"|", 0,  0,  0, "|", 0, "|", 0, "|"},
  {"|", 0, "|", 0, "|", 0, "|", 0, "|"},
  {"|", 0, "|", 0,  0,  0, "|", 0, "|"},
  {"|", 0, "|", 0, "|", 0,  0,  0, "|"},
  {"|","X","|","-","-","-","-","-","|"}
};

int BOARD[9][9];  // Spielfeld

int steuern(){
    int Xx,Xy,i,k;
    char b;
    for(i=0;i<9;i++){
        for(k=0;k<9;k++){
            if(BOARD[i][k]=="X"){
                Xy=i;
                Xx=k;
            }
        }
    }
    printf("\n%d%d\n",Xy,Xx);
    printf("\nRenn!!!\n");
    scanf("%c",&b);
    if (b=='w'){
        if (BOARD[Xy-1][Xx]==0||BOARD[Xy-1][Xx]=="Z"){
            BOARD[Xy][Xx]=0;
            Xy-=1;
            BOARD[Xy][Xx]="X";
            print_board();
        } else {
            print_board();
            printf("\nNicht mit dem Kopf durch die Wand");
        }
    }
    if (b=='s'){
        if (BOARD[Xy+1][Xx]==0||BOARD[Xy+1][Xx]=="Z"){
            BOARD[Xy][Xx]=0;
            Xy+=1;
            BOARD[Xy][Xx]="X";
            print_board();
        } else {
            print_board();
            printf("\nNicht mit dem Kopf durch die Wand");
        }
    }
    if (b=='a'){
        if (BOARD[Xy][Xx-1]==0||BOARD[Xy][Xx-1]=="Z"){
            BOARD[Xy][Xx]=0;
            Xx-=1;
            BOARD[Xy][Xx]="X";
            print_board();
        }else{
            print_board();
            printf("\nNicht mit dem Kopf durch die Wand");
        }
    }
    if (b=='d'){
        if (BOARD[Xy][Xx+1]==0||BOARD[Xy][Xx+1]=="Z"){
            BOARD[Xy][Xx]=0;
            Xx+=1;
            BOARD[Xy][Xx]="X";
            print_board();
        }else{
            print_board();
            printf("\nNicht mit dem Kopf durch die Wand");
        }
    }

}

void print_board() {
  printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
  printf("Steuerung:W A S D\n");
  printf("  Löser: ENTER\n\n");
  for (int row = 0; row < 9; row++) {
    for (int col = 0; col < 9; col++) {
      if (BOARD[row][col] == 0) {
        printf("   ");
      } else {
        printf(" %s ", BOARD[row][col]);
      }

    }
    printf("\n");

  }
}

int main() {
    int Xy,Xx;
  for (int row = 0; row < 9; row++) {
    for (int col = 0; col < 9; col++) {
      BOARD[row][col] = board[row][col];
    }
  }

  print_board();

  do{
    steuern();
  }while(BOARD[0][6]=="Z");

  printf("\n  --> Spiel beendet.\n\n\n");

  return 0;
}
