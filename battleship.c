#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "battleFunctions.h"

int main(int argc, char **argv) {

  int x, xFinal;
  int y, yFinal;
  int shipPiece = 1;
  int changeRow, changeColumn;
  int continuePlaying;
  int numOfShips = 0;

  printf("\nPlease enter how many rows you want\n");
  scanf("%d", &xFinal);
  while (x > 100) {
    printf("\nPlease enter a number less than 100\n");
  }

  printf("\nPlease enter how many columns you want\n");
  scanf("%d", &yFinal);
  while (y > 100) {
    printf("\nPlease enter a number less than 100\n");
  }

  x = xFinal;
  y = yFinal;

  int playTable[x][y];
  memset(playTable, 0, sizeof(playTable[0][0]) * (x + 1) * y);

  system("clear");
  printf("\nPlease enter the squares (seperated by a space) you want to place your ship,\n then type 99 99 when done\n");
  showShipsTable (xFinal, yFinal, playTable);
  scanf("%d %d", &changeRow, &changeColumn);
  while ((changeRow > xFinal || changeColumn > yFinal || changeRow < 1 || changeColumn < 1) && changeRow != 99){
    printf("\nInvalid entry, try again \n");
    scanf("%d %d", &changeRow, &changeColumn);
    numOfShips++;
  }

  do {
    system("clear");
    printf("\nOK, assigning a piece to row %d and to column %d\n", changeRow, changeColumn);
    playTable[changeRow - 1][changeColumn - 1] = 1;
    showShipsTable (xFinal, yFinal, playTable);
    scanf("%d %d", &changeRow, &changeColumn);
    while ((changeRow > xFinal || changeColumn > yFinal || changeRow < 1 || changeColumn < 1) && changeRow != 99) {
      printf("\nInvalid entry, try again \n");
      scanf("%d %d", &changeRow, &changeColumn);
    }
    if (changeRow == 99 && changeColumn == 99) {
      printf("\nAre you sure you're done ? Type 99 99 again to confirm and continue\n");
      scanf("%d %d", &changeRow, &changeColumn);
    }
    numOfShips++;
    system("clear");
  } while (changeRow != 99 && changeColumn != 99);

  //showArray (xFinal, yFinal, playTable);
  showBlankTable (xFinal, yFinal);

  system("clear");
  printf("\nNow you will shoot ships, there will be 3 players\n");
  showBlankTable (xFinal, yFinal);
  scanf("%d %d", &changeRow, &changeColumn);

    do {
      system("clear");
      if (playTable[changeRow - 1][changeColumn - 1] == 0)
        printf("\nYou couldn't hit the broad side of a moisture evaporator\n");
      if (playTable[changeRow - 1][changeColumn - 1] == 1){
        printf("\nAnd the crowd goes wild ! What a collosal hit !\n %d \n", numOfShips);
        playTable[changeRow - 1][changeColumn - 1] = 2;
        numOfShips--;
      }
      if (numOfShips == 0)
      break;

      showShipsTableOnlyHits (xFinal, yFinal, playTable);
      scanf("%d %d", &changeRow, &changeColumn);
      system("clear");

    } while(1 > 0);

    printf("\nAll ships are dead, congratulations murderer\n");



  return 0;
}
