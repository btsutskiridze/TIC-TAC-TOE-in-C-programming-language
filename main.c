#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h> //for getch()
#include <time.h> // for srand()

/*************** TIC TAC TOE GAME ***************/

//********** WILL Add computerHardMove() and gameHisotry() functons ***********


char board[3][3]; //board
const char PLAYER = 'X';
const char COMPUTER = 'O';
const char PLAYER2 = 'O';

//menu part
void startMenu(); //done
void gameMode(); //done
void gameRules(); //done
void gameHistory(); // isn't started

void playWithComputer(int); //easy part is done working on hard mode
void playWithHuman(); //done
//game structure
void resetBoard(); //done
void printBoard(); //done
int checkSpaces(); //done
void firstPlayerMove(); //done
void secondPlayerMove(); //done
void computerEasyMove(); // done
void computerHardMove(); // doing now
char checkWinner(); //done
void printWinner(char); //done
void print2PlayerWinner(char); //done


int main(){
  srand(time(0));
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
  printf("\t\t\t2. Rules of the Game\n");
  printf("\t\t\t3. Gameplay History\n");
  printf("\t\t\t4. Quit the Game\n");
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
        gameRules();
        break;
      case '3':
        system("cls");
        gameHistory();
        break;
      case '4':
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

void gameRules(){
  printf("\n\n\t\t1. The game is played on a grid \n\t\t that's 3 squares by 3 squares.\n\n");
  printf("\t\t2. You are X, your friend (or the computer in this case) is O.\n\t\t Players take turns putting their marks in empty squares.\n\n");
  printf("\t\t3. The first player to get 3 of her marks \n\t\t in a row (up, down, across, or diagonally) is the winner.\n\n");
  printf("\t\t4. When all 9 squares are full, the game is over.\n\t\t If no player has 3 marks in a row, the game ends in a tie.\n\n");

  printf("\t\tPRESS ANY KEY TO GO BACK TO THE MENU\n");
  char press;
  press = getch();
  system("cls");
  startMenu();
}

void gameHistory(){

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
        firstPlayerMove();
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
        firstPlayerMove();
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

      printf("\n\t\t\t\tTHANKS FOR PLAYING :)\n");
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
      firstPlayerMove();
      winner = checkWinner();
      if(winner != ' ' || checkSpaces() == 0){
        break;
      }
      system("cls");
      printBoard();
      secondPlayerMove();
      winner = checkWinner();
      if(winner != ' ' || checkSpaces() == 0){
        break;
      }
      system("cls");
    }
    system("cls");
    printBoard();
    print2PlayerWinner(winner);

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

void firstPlayerMove(){
  int x,y;
  printf("\n\t\t\t\tPLAYER X MOVE:\n\n");
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
      board[x][y] = PLAYER;
      break;
    }
  } while (board[x][y]!= ' ');

}

void secondPlayerMove(){
  int x,y;
  printf("\n\t\t\t\tPLAYER O MOVE:\n\n");
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
      board[x][y] = PLAYER2;
      break;
    }
  } while (board[x][y]!= ' ');
}

void computerEasyMove(){
  int x;
  int y;

  if(checkSpaces() > 0){
    do{
      x = rand() % 3;
      y = rand() % 3;
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
    printf("\t\t\t\tYOU WIN!\n\t\t\t\tCONGRATULATIONS!!\n");
    printf("\t\t\t************************************\n");
  }
  else if(winner == COMPUTER){
    printf("\t\t\t************************************\n");
    printf("\t\t\t\tYOU LOSE :(\n\t\t\t\tBETTER LUCK NEXT TIME :)\n");
    printf("\t\t\t************************************\n");
  }
  else {
    printf("\t\t\t************************************\n");
    printf("\t\t\t\tIT'S A TIE :|\n");
    printf("\t\t\t************************************\n");
  }
}

void print2PlayerWinner(char winner){
  if(winner == PLAYER){
    printf("\t\t\t************************************\n");
    printf("\t\t\t\tXPLAYER X WINS!!\n");
    printf("\t\t\t************************************\n");
  }
  else if(winner == PLAYER2){
    printf("\t\t\t************************************\n");
    printf("\t\t\t\tPLAYER O WINS!!\n");
    printf("\t\t\t************************************\n");
  }
  else {
    printf("\t\t\t************************************\n");
    printf("\t\t\t\tIT'S A TIE :|\n");
    printf("\t\t\t************************************\n");
  }
}
