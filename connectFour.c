/* Natalia Lyon and Hannah Willer     3/9/2021*/
/*play a fun two-player game of connect four*/
#include<stdio.h>
#include<unistd.h>

#define COLS 7
#define ROWS 6
int board[ROWS][COLS]={
  {0, 0, 0, 0, 0, 0, 0},  //this array of arrays is the game board. 0 is an empty spot, 1 is a red token, 2 is a yellow token.
  {0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0}
};


void rowDrop(int colSelect,int color){
  //tests from bottom of the column to the top, and puts the color in the lowest empty spot
  int rowCheck;
  for(rowCheck=5;rowCheck>-1;rowCheck--){
    if(board[rowCheck][colSelect-1]==0){
       board[rowCheck][colSelect-1]=color;
       break;
    }
    else if(rowCheck==0){
      printf("Sorry, that column is full of tokens already! Please choose a different one. ");
      int numCheck=2;
      while ((numCheck!=1)||(colSelect<1)||(colSelect>7)){ //looks for if player put a non-int, or too big or too small a number
        scanf("%*[^\n]");
        if (numCheck==0)
          printf("That's not valid! ");
        printf("Enter a number from 1-7. ");
        numCheck= scanf("%d",&colSelect);
      }
      rowDrop(colSelect,color);
    }
  }
}

void printBoard(int color){
  //procedurally prints out the game board, testing each spot to see what color to put in there or if it should be left empty.
  printf("\e[2J\e[H"); //clears the screen
  printf("\e[1;34m ===   ===  \\  | \\  | |===  === ===   |   |\n|     |   | |\\ | |\\ | |=== |     |    |___|\n|___  |___| | \\| | \\| |=== |___  |        |\n"); //prints "CONNECT 4"
  printf("\e[0m                by Natalia L\n");
  if(color==1){
    printf("\e[1;31m*******************************************\n\n                 Red's Turn\n");
  }
  else{
    printf("\e[1;33m*******************************************\n\n               Yellow's Turn\n");
  }
  printf("\e[0m\n   1     2     3     4     5     6     7\n");
  printf("\e[1;34m*******************************************\n");
  int col=0;
  int row=0;
  for(row=0;row<6;row++){
    printf("\e[1;34m*");
    for(col=0;col<7;col++){
      if (board[row][col]==0)
        printf("     \e[1;34m*"); //empty
      else if (board[row][col]==1)
        printf(" \e[1;31mRRR \e[1;34m*");  //red
      else
        printf(" \e[1;33mYYY \e[1;34m*");  //yellow
    }
    printf("\n\e[1;34m*");
    for(col=0;col<7;col++){
      if (board[row][col]==0)
        printf("     \e[1;34m*"); //empty
      else if (board[row][col]==1)
        printf(" \e[1;31mRRR \e[1;34m*");  //red
      else
        printf(" \e[1;33mYYY \e[1;34m*");  //yellow
    }
  printf("\n\e[1;34m*******************************************\n");
  }
  printf("\e[0m   1     2     3     4     5     6     7\n\n\n\n");
  if(color==1)
    printf("\e[1;31mRed\e[0m, in which number column do you want to put your \e[1;31mtoken\e[0m? (1-7): ");
  if(color==2)
    printf("\e[1;33mYellow\e[0m, in which number column do you want to put your \e[1;33mtoken\e[0m? (1-7): ");
}

int horizTest(int color){
  int rowCheck=5;
  int colCheck=0;
  for(colCheck=0;colCheck==3;colCheck++){
    for(rowCheck=5;rowCheck==0;rowCheck--){
      if((board[rowCheck][colCheck]==color)&(board[rowCheck][colCheck+1]==color)&(board[rowCheck][colCheck+2]==color)){
        return 1;
      }
    }
  }
}

int winTest(int color){
  //tests horizontal, vertical, and both diagonals for the whole board to see if anyone has won yet.
}

int main(){
  int win=0;
  int colSelect=0;
  int color=1; //again, 1 is red, 2 is yellow
  while(win==0){ 
    //this part does the actual game by running the above-defined functions in a specific order until it detects somebody won
    printBoard(color); //shows the board, asks the player where they want to put their token
    int numCheck= scanf("%d",&colSelect); //reads in what the player chose
    while ((numCheck!=1)||(colSelect<1)||(colSelect>7)){ //looks for if player put a non-int, or too big or too small a number
      scanf("%*[^\n]");
      printf("That's not valid. Enter a number from 1-7. ");
      numCheck= scanf("%d",&colSelect);
    }
    //puts the token into the lowest empty spot in that column. if that column is full, asks player to choose a different one
    rowDrop(colSelect,color);
    //tests to see if any players won during that turn. if a player one, prints that they did and ends the game
    if (color==1)
      color=2; //if red, switches to yellow
    else
      color=1; //if yellow, switches to red
  }
}
