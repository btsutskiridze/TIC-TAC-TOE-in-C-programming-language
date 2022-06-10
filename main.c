#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h> //for getch()

/*************** TIC TAC TOE GAME ***************/

//********** WILL Add computerHardMove() and gameHisotry() functons ***********


char board[3][3]; //board
const char PLAYER = 'X';
const char COMPUTER = 'O';
const char PLAYER2 = 'O';

//menu part
void startMenu(); //done
void gameMode(); //done
void gameHistory(); // done

void playWithComputer(int); //done
void playWithHuman(); //done
//game structure
void resetBoard(); //done
void printBoard(); //done
int checkSpaces(); //done
void playerMove(char); //done
void computerEasyMove(); // done
void computerHardMove(); // done????
char checkWinner(); //done
void printWinner(char); //done
void addHistory(char*,char*); //done
unsigned long lfsr32(unsigned long seed);

//driver
int main(){
  printf("\n\n\t\t\tWELCOME!!\n");
  printf("\t\t\tTHIS IS A TIC TAC TOE GAME\n\n");
  startMenu();
  return 0;
}

//menu part
void startMenu(){
  char option;
  printf("\n\t\t\tChoose an option:\n");
  printf("\t\t\t______________________\n");
  printf("\t\t\t1. Start Game\n");
  printf("\t\t\t2. Gameplay History\n");
  printf("\t\t\t3. Quit the Game\n");
  printf("\t\t\t----------------------\n");
  while(1){
    printf("\t\t\t");
    option = getch();
    switch (option)
    {
      case '1':
        system("cls");
        gameMode();
        break;
      case '2':
        system("cls");
        gameHistory();
        break;
      case '3':
        remove("history.txt");
        exit(1);
      default:
        printf("Invalid option!! CHOOSE AGAIN\n");
        continue;
    }
  }
}

void gameMode(){
  printf("\n\n\t\t\t1. PLAYER vs COMPUTER\n");
  printf("\t\t\t2. PLAYER 1 vs PLAYER 2\n");
  printf("\n\t\t\t");
  char option;
  option = getch();
  if(option == '1'){
    system("cls");
    char lvl;
    printf("\n\n\t\t\tChoose difficulty level:\n");
    printf("\n\t\t\t1. Beginner\n");
    printf("\t\t\t2. Proffesional\n");
    do
    {
      printf("\t\t\t\t");
      lvl = getch();
      if(lvl == '1') {
        playWithComputer(0);
      }
      else if(lvl == '2'){
        playWithComputer(1);
      }
      else{
        printf("\t\t\tInvalid Option\n");
      }
    } while (lvl != '1' || lvl != '2');

  }
  else if(option == '2'){
    playWithHuman();
  }
  else{
    printf("\t\t\tInvalid option\n");
  }
}

void gameHistory(){
  FILE *filePtr = fopen("history.txt", "r");
  int counter = 0;
  if (filePtr == NULL){
        printf("Error opening the file history.txt\n");
        return;
  }
  printf("\n\t\t\t\tGAME HISTORY\n");
  printf("\t\t\t---------------------------\n\n");
  char text[50];
  while(fgets(text, 50, filePtr)){
    printf("\t\t\tN%d. %s", ++counter,text);
  } 
  fclose(filePtr);
  getch();
  system("cls");
  startMenu();
}

void playWithComputer(int n){
  if(n == 0){ // easy mode
    char choice;
    do{//looping
      char winner = ' ';
      resetBoard();
      while(winner == ' ' && checkSpaces()!=0 ){
        system("cls");
        printBoard();
        playerMove(PLAYER);
        winner = checkWinner();
        if(winner != ' ' || checkSpaces() == 0){
          break;
        }
        computerEasyMove();
        winner = checkWinner();
        if(winner != ' ' || checkSpaces() == 0){
          break;
        }
        system("cls");
      }
      system("cls");
      printBoard();
      printWinner(winner);
      if(winner == PLAYER) addHistory("Player","Computer");
      else addHistory("Computer","Player");
      printf("\n\t\t\tWould you like to continue the game?\n");
      printf("\n\t\t\t(Y - Play Again // N - Back to Menu)\n");
      printf("\n\t\t\t\t\t");
      choice = getch();
      system("cls");
    }while(choice =='Y' || choice == 'y');
    //calling the startMenu again
    startMenu();
  }
  else if (n == 1){ //hard mode
    char choice;
    do{//looping
      char winner = ' ';
      resetBoard();
      while(winner == ' ' && checkSpaces()!=0 ){
        system("cls");
        printBoard();
        playerMove(PLAYER);
        winner = checkWinner();
        if(winner != ' ' || checkSpaces() == 0){
          break;
        }
        computerHardMove();
        winner = checkWinner();
        if(winner != ' ' || checkSpaces() == 0){
          break;
        }
        system("cls");
      }
      system("cls");
      printBoard();
      printWinner(winner);
      if(winner == PLAYER) addHistory("Player","Computer");
      else addHistory("Computer","Player");
      printf("\n\t\t\t\tWould you like to continue the game?\n");
      printf("\n\t\t\t\t (Y - Play Again // N - Back to Menu)\n");
      printf("\n\t\t\t\t\t\t");
      choice = getch();
      system("cls");
    }while(choice =='Y' || choice == 'y');
    //calling the startMenu again
    startMenu();
  }
}

void playWithHuman(){
  char choice;
  do{//looping
    char winner = ' ';
    resetBoard();
    while(winner == ' ' && checkSpaces()!=0 ){
      system("cls");
      printBoard();
      playerMove(PLAYER);
      winner = checkWinner();
      if(winner != ' ' || checkSpaces() == 0){
        break;
      }
      system("cls");
      printBoard();
      playerMove(PLAYER2);
      winner = checkWinner();
      if(winner != ' ' || checkSpaces() == 0){
        break;
      }
      system("cls");
    }
    system("cls");
    printBoard();
    printWinner(winner);  
    if(winner == PLAYER) addHistory("Player 1","Player 2");
    else addHistory("Player 2","Player 1");
    printf("\n\t\t\tWould you like to continue the game?\n");
    printf("\n\t\t\t(Y - Play Again // N - Back to Menu)\n");
    printf("\n\t\t\t\t\t");
    choice = getch();
    system("cls");
  }while(choice =='Y' || choice == 'y');
  //calling the startMenu again
  startMenu();

}

//structure part
void resetBoard(){
  int i,j;
  for(i = 0; i < 3; i++){
    for(j = 0; j < 3; j++){
      board[i][j]= ' ';
    }
  }
}

void printBoard(){
  printf("\n\n\t\t\t\t     |     |     \n");
  printf("\t\t\t\t  %c  |  %c  |  %c  \n", board[0][0], board[0][1], board[0][2]);
  printf("\t\t\t\t-----|-----|-----\n");
  printf("\t\t\t\t  %c  |  %c  |  %c \n", board[1][0], board[1][1], board[1][2]);
  printf("\t\t\t\t-----|-----|-----\n");
  printf("\t\t\t\t  %c  |  %c  |  %c \n", board[2][0], board[2][1], board[2][2]);
  printf("\t\t\t\t     |     |    \n");
  printf("\n");
}

int checkSpaces(){
  int freeSpaces = 9;
  int i,j;
  for(i = 0; i < 3; i++){
    for(j = 0; j < 3; j++){
      if(board[i][j] != ' '){
        freeSpaces--;
      }
    }
  }
  return freeSpaces;
}

void playerMove(char player){
  int x,y;
  printf("\n\t\t\t\tPLAYER %c MOVE:\n\n",player);
  do
  {
    printf("\t\t\t\tEnter row #(1-3): ");
    scanf("%d", &x);
    x--;
    printf("\t\t\t\tEnter column #(1-3): ");
    scanf("%d", &y);
    y--;
    if(board[x][y]!=' '){
      printf("\t\t\t\tInvalid Move!!\n");
    }
    else{
      board[x][y] = player;
      break;
    }
  } while (board[x][y]!= ' ');

}

void computerEasyMove(){
  int x;
  int y;
  static unsigned long firstSeed = 0x5AA5F100;
  static unsigned long secondSeed = 0x5AA5F700;

  if(checkSpaces() > 0){
    do{
      firstSeed = lfsr32(firstSeed);
      secondSeed = lfsr32(secondSeed);
      x = firstSeed % 3;
      y = secondSeed % 3;
    }while(board[x][y]!=' ');
    board[x][y] = COMPUTER;
  }
  else{
    printWinner(' ');
  }
}

void computerHardMove(){
  if(checkSpaces()> 0){
    int i;
    for(i = 0; i < 3; i++){
      //columns check
      if(board[i][0] == COMPUTER && board[i][1] == COMPUTER){
        if(board[i][2] == ' '){
          board[i][2] = COMPUTER;
          return;
        }
      }
      if(board[i][0] == PLAYER && board[i][1] == PLAYER){
        if(board[i][2] == ' '){
          board[i][2] = COMPUTER;
          return;
        }
      }

      if(board[i][1] == COMPUTER && board[i][2] == COMPUTER){
        if(board[i][0] == ' '){
          board[i][0] = COMPUTER;
          return;
        }
      }
      if(board[i][1] == PLAYER && board[i][2] == PLAYER){
        if(board[i][0] == ' '){
          board[i][0] = COMPUTER;
          return;
        }
      }

      if(board[i][0] == COMPUTER && board[i][2] == COMPUTER){
        if(board[i][1] == ' '){
          board[i][1] = COMPUTER;
          return;
        }
      }
      if(board[i][0] == PLAYER && board[i][2] == PLAYER){
        if(board[i][1] == ' '){
          board[i][1] = COMPUTER;
          return;
        }
      }

      //rows check
      if(board[0][i] == COMPUTER && board[1][i] == COMPUTER){
        if(board[2][i] == ' '){
          board[2][i] = COMPUTER;
          return;
        }
      }
      if(board[0][i] == PLAYER && board[1][i] == PLAYER){
        if(board[2][i] == ' '){
          board[2][i] = COMPUTER;
          return;
        }
      }

      if(board[1][i] == COMPUTER && board[2][i] == COMPUTER){
        if(board[0][i] == ' '){
          board[0][i] = COMPUTER;
          return;
        }
      }
      if(board[1][i] == PLAYER && board[2][i] == PLAYER){
        if(board[0][i] == ' '){
          board[0][i] = COMPUTER;
          return;
        }
      }

      if(board[0][i] == COMPUTER && board[2][i] == COMPUTER){
        if(board[1][i] == ' '){
          board[1][i] = COMPUTER;
          return;
        }
      }
      if(board[0][i] == PLAYER && board[2][i] == PLAYER){
        if(board[1][i] == ' '){
          board[1][i] = COMPUTER;
          return;
        }
      }
    }

    //diagonals check
    //first diag
    if(board[0][0] == COMPUTER && board[1][1] == COMPUTER){
      if(board[2][2] == ' '){
        board[2][2] = COMPUTER;
        return;
      }
      else if(board[2][2] == COMPUTER){
        computerEasyMove();
        return;
      }
    }
    if(board[0][0] == PLAYER && board[1][1] == PLAYER){
      if(board[2][2] == ' '){
        board[2][2] = COMPUTER;
        return;
      }
      else if(board[2][2] == COMPUTER){
        computerEasyMove();
        return;
      }
    }

    if(board[1][1] == COMPUTER && board[2][2] == COMPUTER){
      if(board[0][0] == ' '){
        board[0][0] = COMPUTER;
        return;
      }
      else if(board[0][0] == COMPUTER){
        computerEasyMove();
        return;
      }
    }
    if(board[1][1] == PLAYER && board[2][2] == PLAYER){
      if(board[0][0] == ' '){
        board[0][0] = COMPUTER;
        return;
      }
      else if(board[0][0] == COMPUTER){
        computerEasyMove();
        return;
      }
    }

    if(board[0][0] == COMPUTER && board[2][2] == COMPUTER){
      if(board[1][1] == ' '){
        board[1][1] = COMPUTER;
        return;
      }
      else if(board[1][1] == COMPUTER){
        computerEasyMove();
        return;
      }
    }
    if(board[0][0] == PLAYER && board[2][2] == PLAYER){
      if(board[1][1] == ' '){
        board[1][1] = COMPUTER;
        return;
      }
      else if(board[1][1] == COMPUTER){
        computerEasyMove();
        return;
      }
    }

    //second diag
    if(board[0][2] == COMPUTER && board[1][1] == COMPUTER){
      if(board[2][0] == ' '){
        board[2][0] = COMPUTER;
        return;
      }
    }
    if(board[0][2] == PLAYER && board[1][1] == PLAYER){
      if(board[2][0] == ' '){
        board[2][0] = COMPUTER;
        return;
      }
    }

    if(board[1][1] == COMPUTER && board[2][0] == COMPUTER){
      if(board[0][2] == ' '){
        board[0][2] = COMPUTER;
        return;
      }
    }
    if(board[1][1] == PLAYER && board[2][0] == PLAYER){
      if(board[0][2] == ' '){
        board[0][2] = COMPUTER;
        return;
      }
    }

    if(board[0][2] == COMPUTER && board[2][0] == COMPUTER){
      if(board[1][1] == ' '){
        board[1][1] = COMPUTER;
        return;
      }
      else if(board[1][1] == COMPUTER){
        computerEasyMove();
        return;
      }
    }
    if(board[0][2] == PLAYER && board[2][0] == PLAYER){
      if(board[1][1] == ' '){
        board[1][1] = COMPUTER;
        return;
      }
      else if(board[1][1] == COMPUTER){
        computerEasyMove();
        return;
      }
    }

    if(board[0][1] == PLAYER|| board[1][2] == PLAYER || board [2][1] == PLAYER || board[1][0] || board[1][1]){ //maybe leave board[1][1] there
      computerEasyMove();
      return;
    }

    if(board[0][0] == PLAYER || board[0][2] == PLAYER || board[2][0] == PLAYER || board[2][2] == PLAYER ){
      if(board[1][1] == ' '){
        board[1][1] = COMPUTER;
        return;
      }
      if(board[0][0] == ' '){
        board[0][0] == COMPUTER;
        return;
      }
      if(board[0][2] == ' '){
        board[0][2] == COMPUTER;
        return;
      }
      if(board[2][0] == ' '){
        board[2][0] == COMPUTER;
        return;
      }
      if(board[2][2] == ' '){
        board[2][2] == COMPUTER;
        return;
      }
    }
  }
  else{
    printWinner(' ');
  }
}

char checkWinner(){
  int i;
  for(i = 0; i < 3; i++){ //column checks
    if(board[i][0] == board[i][1] && board[i][0] == board[i][2]){
      return board[i][0];
    }
  }
  for(i = 0; i < 3; i++){ //row checks
    if(board[0][i] == board[1][i] && board[0][i] == board[2][i]){
      return board[0][i];
    }
  }
  if(board[0][0] == board[1][1] && board[0][0] == board[2][2]){
    return board[0][0];
  }
  if(board[0][2] == board[1][1] && board[0][2] == board[2][0]){
    return board[0][2];
  }
  return ' ';
}

void printWinner(char winner){
if(winner == PLAYER){
    printf("\t\t\t************************************\n");
    printf("\t\t\t\tPLAYER X WINS!!\n");
    printf("\t\t\t************************************\n");
  }
  else if(winner == PLAYER2){
    printf("\t\t\t************************************\n");
    printf("\t\t\t\tPLAYER O WINS!!\n");
    printf("\t\t\t************************************\n");
  }
  else if(winner == COMPUTER){
    printf("\t\t\t************************************\n");
    printf("\t\t\t\tCOMPUTER WINS!! BETTER LUCK NEXT TIME!\n");
    printf("\t\t\t************************************\n");
  }
  else {
    printf("\t\t\t************************************\n");
    printf("\t\t\t\tIT'S A TIE :|\n");
    printf("\t\t\t************************************\n");
  }
}

void addHistory(char winner[], char loser[]){
  FILE* filePtr = fopen("history.txt", "a");

  if (filePtr == NULL){
    printf("Error opening the file history.txt\n");
    return;
  }
  if(checkWinner() == ' '){
    fprintf(filePtr,"%s and %s had a tie!\n", winner, loser);
  }
  fprintf(filePtr,"%s won against %s\n", winner, loser);
  fclose(filePtr);
}

unsigned long lfsr32(unsigned long seed){
    //if seed is equal 0 it will return the next 32-bit value
    if(seed == 0){
        return seed + 1;
    }
    //creating new bit
    unsigned long new_bit;
    // using for loop to generate 32 new bits
    for(int i = 0; i< 32; i++){//calculating new bit
    //feedback polinomial: x^32 + x^30 + x^26 + x^25 + 1
    //               /tap 32/      /tap 30/      /tap 26/      /tap 25/
        new_bit = ( (seed >> 0) ^ (seed >> 2) ^ (seed >> 6) ^ (seed >> 7) ) & 1;
        //modifying seed
        //shifting seed to the right and putting new bit at the front shifted by 31-bit
        seed = (seed >> 1) | (new_bit << 31);
    }
    //returning seed
    return seed;
}
