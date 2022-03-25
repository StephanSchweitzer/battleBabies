void generateTable(int x, int y){
  for (int i = 0; i < y; i++) {
    printf(" __ ");
  }
  printf("\n");
  for (int i = 0; i < x; i++) {
    // printf(" __ ");
    for (int j = 0; j < y; j++) {
      printf("|__|");
    }
    printf("\n");
  }
}

void showShipsTable (int x,int y, int playTable[x][y]) {
  for (int i = 0; i < y + 1; i++) {
    i < 10 ? printf(" 0%d ", i) : printf(" %d ", i);
  }
  printf("\n");
  for (int i = 0; i < x; i++) {
    for (int j = -1; j < y; j++) {
       if (j == -1){
        i < 9 ? printf(" 0%d ", i + 1) : printf(" %d ", i + 1);
       } else {
         switch (playTable[i][j]) {
           case 0 : printf("|__|");
           break;
           case 1 : printf("|bT|");
           break;
           case 2 : printf("|XX|");
           break;
           case 3 : printf("|ha|");
           break;
         }
      }
    }
    printf("\n");
  }
}

void showShipsTableOnlyHits (int x,int y, int playTable[x][y]) {
  for (int i = 0; i < y + 1; i++) {
    i < 10 ? printf(" 0%d ", i) : printf(" %d ", i);
  }
  printf("\n");
  for (int i = 0; i < x; i++) {
    for (int j = -1; j < y; j++) {
       if (j == -1){
        i < 9 ? printf(" 0%d ", i + 1) : printf(" %d ", i + 1);
       } else {
         switch (playTable[i][j]) {
           case 0 : printf("|__|");
           break;
           case 1 : printf("|__|");
           break;
           case 2 : printf("|XX|");
           break;
           case 3 : printf("|ha|");
           break;
         }
      }
    }
    printf("\n");
  }
}

void showArray(int x, int y, int playTable[x][y]){

  printf("\n");
  for (int i = 0; i < x; i++) {

    for (int j = 0; j < y; j++) {
      printf(" %d ", playTable[i][j]);
    }
    printf("\n");
  }
}

void showBlankTable(int x,int y) {
  for (int i = 0; i < y + 1; i++) {
    i < 10 ? printf(" 0%d ", i) : printf(" %d ", i);
  }
  printf("\n");
  for (int i = 0; i < x; i++) {
    for (int j = -1; j < y; j++) {
       if (j == -1){
        i < 9 ? printf(" 0%d ", i + 1) : printf(" %d ", i + 1);
       } else {
        printf("|__|");
      }
      //printf(" %d ", playTable[i][j]);
    }
    printf("\n");
  }
}

void fireAtShips(int row, int column) {

}

// void showShipsTable (int x,int y, int playTable[x][y]) {
//   x++;
//   y++;
//   for (int i = 0; i < y; i++) {
//     i < 10 ? printf(" 0%d ", i) : printf(" %d ", i);
//   }
//   printf("\n");
//   for (int i = 0; i < x -1; i++) {
//     for (int j = -1; j < y - 1; j++) {
//        if (j == -1){
//         i < 9 ? printf(" 0%d ", i + 1) : printf(" %d ", i + 1);
//        } else {
//         playTable[i][j] == 1 ? printf("|bT|") : printf("|__|");
//       }
//       //printf(" %d ", playTable[i][j]);
//     }
//     printf("\n");
//   }
// }
