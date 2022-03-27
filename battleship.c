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
  int boatSizeCheck;
  int threeBoatCheck = 0;
  int twoBoatCheck = 0;
  int oneBoatCheck = 0;
  int chooseBoatSize;
  int numPlayers = 3;
  int turnCounter = 1;
  int playerScores[10];
  memset(playerScores, 0, 10);


  printf("\nPlease enter how many rows you want\n");
  scanf("%d", &xFinal);
  while (xFinal > 100) {
    printf("\nPlease enter a number less than 100\n");
    scanf("%d", &xFinal);
  }

  printf("\nPlease enter how many columns you want\n");
  scanf("%d", &yFinal);
  while (yFinal > 100) {
    printf("\nPlease enter a number less than 100\n");
    scanf("%d", &yFinal);
  }

  x = xFinal;
  y = yFinal;

  int playTable[x][y];
  memset(playTable, 0, sizeof(playTable[0][0]) * (x + 1) * y);

  system("clear");
  printf("\n Please enter the size of the ship \n");
  showShipsTable (xFinal, yFinal, playTable);

  do {
    system("clear");
    printf("\n Please enter the size of the ship \n");
    if (oneBoatCheck == 0)
    printf("\n Boat size 1 must be placed\n");
    if (twoBoatCheck == 0)
    printf("\n Boat size 2 must be placed\n");
    if (threeBoatCheck == 0)
    printf("\n Boat size 3 must be placed\n\n");
    showShipsTable (xFinal, yFinal, playTable);
    scanf("%d", &chooseBoatSize);

    if (chooseBoatSize == 1 && oneBoatCheck == 0) {
      system("clear");
      printf("\n Please place the size one ship \n");
      showShipsTable (xFinal, yFinal, playTable);
      scanf("%d %d", &changeRow, &changeColumn);
      while (changeRow > xFinal || changeColumn > yFinal || changeRow < 1 || changeColumn < 1){
        printf("\nInvalid entry, try again \n");
        scanf("%d %d", &changeRow, &changeColumn);
      }
      while (playTable[changeRow - 1][changeColumn - 1] != 0) {
        system("clear");
        printf("\n This square is already taken, enter another square\n");
        showShipsTable (xFinal, yFinal, playTable);
        scanf("%d %d", &changeRow, &changeColumn);
      }
      playTable[changeRow - 1][changeColumn - 1] = 1;
      oneBoatCheck = 1;
      numOfShips++;
      showShipsTable (xFinal, yFinal, playTable);

    } else if (chooseBoatSize == 2 && twoBoatCheck == 0) {
      for (int i = 0; i < chooseBoatSize; i++) {
        system("clear");
        printf("\n Please place the size two ship \n");
        showShipsTable (xFinal, yFinal, playTable);
        scanf("%d %d", &changeRow, &changeColumn);
        while (changeRow > xFinal || changeColumn > yFinal || changeRow < 1 || changeColumn < 1){
          printf("\nInvalid entry, try again \n");
          scanf("%d %d", &changeRow, &changeColumn);
        }
        while (playTable[changeRow - 1][changeColumn - 1] != 0) {
          system("clear");
          printf("\n This square is already taken, enter another square\n");
          showShipsTable (xFinal, yFinal, playTable);
          scanf("%d %d", &changeRow, &changeColumn);
        }
        playTable[changeRow - 1][changeColumn - 1] = 2;
        showShipsTable (xFinal, yFinal, playTable);
      }
      twoBoatCheck = 1;
      numOfShips += 2;

    } else if (chooseBoatSize == 3 && threeBoatCheck == 0) {
      for (int i = 0; i < chooseBoatSize; i++) {
        system("clear");
        printf("\n Please place the size three ship \n");
        showShipsTable (xFinal, yFinal, playTable);
        scanf("%d %d", &changeRow, &changeColumn);
        while (changeRow > xFinal || changeColumn > yFinal || changeRow < 1 || changeColumn < 1){
          printf("\nInvalid entry, try again \n");
          scanf("%d %d", &changeRow, &changeColumn);
        }
        while (playTable[changeRow - 1][changeColumn - 1] != 0) {
          system("clear");
          printf("\n This square is already taken, enter another square\n");
          showShipsTable (xFinal, yFinal, playTable);
          scanf("%d %d", &changeRow, &changeColumn);
        }
        playTable[changeRow - 1][changeColumn - 1] = 3;
        showShipsTable (xFinal, yFinal, playTable);
      }
      threeBoatCheck = 1;
      numOfShips += 3;
    }
  } while(threeBoatCheck == 0 || twoBoatCheck == 0 || oneBoatCheck == 0);

  system("clear");

  printf("\nNow you will shoot ships, there will be 3 players\n");
  for (int i = 0; i < numPlayers; i++) {
  printf("Player %d : %d ", i+1, playerScores[i+1]);
  }
  printf("\n It is now player %d's turn \n", turnCounter);
  //showArray(xFinal, yFinal, playTable);
  showBlankTable (xFinal, yFinal);
  scanf("%d %d", &changeRow, &changeColumn);
  while (changeRow > xFinal || changeColumn > yFinal || changeRow < 1 || changeColumn < 1){
    printf("\nInvalid entry, try again \n");
    scanf("%d %d", &changeRow, &changeColumn);
  }

  do {

    system("clear");
    // printf("\n This is the turn %d you are modifying it \n", turnCounter);
    // printf("\n Player 1 : %d  Players 2 : %d  Player 3 : %d \n", playerScores[1], playerScores[2], playerScores[3]);
    if (playTable[changeRow - 1][changeColumn - 1] == 0)
    printf("\nYou couldn't hit the broad side of a moisture evaporator\n");
    if (playTable[changeRow - 1][changeColumn - 1] == -1){
      printf("\nThis was already shot, you lost your turn\n");
    }
    if (playTable[changeRow - 1][changeColumn - 1] > 0){
      printf("\nAnd the crowd goes wild ! What a collosal hit ! \n");
      playTable[changeRow - 1][changeColumn - 1] = -1;
      numOfShips--;
      ++playerScores[turnCounter];
    }
    if (numOfShips == 0)
    break;
    system("clear");
    if (turnCounter < numPlayers) {
      turnCounter++;
    } else {
      turnCounter = 1;
    }
    printf("\n It is now player %d's turn \n", turnCounter);
    for (int i = 0; i < numPlayers; i++) {
    printf("Player %d : %d ", i+1, playerScores[i+1]);
    }
    printf("\n");
    // printf("Players 2 : %d", playerScores[2]);  Player 3 : %d \n", playerScores[3]);
    showShipsTableOnlyHits (xFinal, yFinal, playTable);
    scanf("%d %d", &changeRow, &changeColumn);
    while (changeRow > xFinal || changeColumn > yFinal || changeRow < 1 || changeColumn < 1){
      printf("\nInvalid entry, try again \n");
      scanf("%d %d", &changeRow, &changeColumn);
    }

    system("clear");

  } while(1 > 0);

  printf("\nAll ships are dead, congratulations murderers\n");

  // printf("\n FINAL SCORE \n Player 1 : %d  Players 2 : %d  Player 3 : %d \n", playerScores[1], playerScores[2], playerScores[3]);
  for (int i = 0; i < numPlayers; i++) {
  printf("Player %d : %d ", i+1, playerScores[i+1]);
  }
  printf("\n");



  return 0;
}
