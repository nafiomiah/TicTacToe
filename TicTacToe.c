/* Description: This program allows two users to play a Tic-Tac-Toe game  
 * in the terminal window.
 */

#include <stdio.h>
#include <stdbool.h>

// Declare functions
void printGameBoard(int board[], int playerA, int playerB);
int getValidInput(int board[], int playerA, int playerB);
int checkForWinner(int board[], int playerA, int playerB);
bool checkForDraw(int board[], int playerA, int playerB);

int main(void)
{
    int gameBoard[] = {49, 50, 51, 52, 53, 54, 55, 56, 57};
    int playerOne = 88, playerTwo = 79; // Player One is "X", Player Two is "O"
    int currentPlayer = playerOne; // Start game with Player X
    bool gameOver = false;
    int winner;
   
    //Game Loop
    while (gameOver != true)
    {
        // Display the state of the board
        printf("The current state of the Tic-tac-toe Board:\n");
        printGameBoard(gameBoard, playerOne, playerTwo);
       
        //Indicate which player's turn it is and prompt the user for a valid position on the board
        printf("It is Player %c's turn.\n", currentPlayer);
        printf("Please enter a valid position to play.\n");
        int position = getValidInput(gameBoard, playerOne, playerTwo);
       
        //Update the gameboard
        *(gameBoard+position -1) = currentPlayer;
       
        //Check if there is a winner
        winner = checkForWinner(gameBoard, playerOne, playerTwo);
       
        //Switch the current player
        if (currentPlayer == playerOne)
            currentPlayer = playerTwo;
        else
            currentPlayer = playerOne;
           
        //End the game if a winner exists or check if the game is over due to a draw
        if (winner != 0)
        {
            gameOver = true;
            //Display the winner of the game
            printf("Player %c wins!\n", winner);
        }
        else if (checkForDraw(gameBoard, playerOne, playerTwo) == false)
        {
            gameOver = true;
            printf("It's a draw!\n");
        }
    }
   
    //Display the board at the end of the game
    printGameBoard(gameBoard, playerOne, playerTwo);
   
    return 0;
}

// Print the Gameboard
void printGameBoard(int board[], int playerOne, int playerTwo)

{
    printf("\n");
    printf(" %c %c %c\n", board[0], board[1], board[2]);
    printf(" %c %c %c\n", board[3], board[4], board[5]);
    printf(" %c %c %c\n", board[6], board[7], board[8]);
    printf("\n");
}

//Prompt user for valid position inputs
int getValidInput(int board[], int playerA, int playerB)
{
    int position;
    bool isInvalidPosition = true;
    do
    {
        scanf("%d", &position);
        if (position <1 || position > 9)
            printf("Invalid input, please try again.\n");
        else if (board[position - 1] == playerA || board[position - 1] == playerB)
            printf("That position has already been played, please try again.\n");
        else
            isInvalidPosition = false;
   
    } while (isInvalidPosition == true);
   
    return position;
}

// Determine if there is a winner
int checkForWinner(int board[], int playerA, int playerB)
{
    //Check if a player filled an entire column
    for (int i = 0; i < 3; i++)
    {
        if (board[i] == playerA && board[i+3] == playerA && board[i+6] == playerA)
            return playerA;
        else if (board[i] == playerB && board[i+3] == playerB && board[i+6] == playerB)
            return playerB;
    }
   
    //Check if a player filled any rows        
    for (int i = 0; i < 7; i+=3)
    {
        if (board[i] == playerA && board[i+1] == playerA && board[i+2] == playerA)
            return playerA;
        else if (board[i] == playerB && board[i+1] == playerB && board[i+2] == playerB)
            return playerB;  
    }
   
    //Check if a player filled a downwards diagonal
    if (board[0] == playerA && board[4] == playerA && board[8] == playerA)
        return playerA;
    else if (board[0] == playerB && board[4] == playerB && board[8] == playerB)
        return playerB;
   
    //Check if a player filled an upwards diagonal
    if (board[2] == playerA && board[4] == playerA && board[6] == playerA)
        return playerA;
    else if (board[2] == playerB && board[4] == playerB && board[6] == playerB)
        return playerB;
       
    //Return a value of 0 if no player won
    return 0;

}

//Determine if the game is a draw
bool checkForDraw(int board[], int playerA, int playerB)
{
    bool isUnmarkedPosition;
    for (int i=0; i < 9; i++)
    {
        if (board[i] == playerA || board[i] == playerB)
       
            isUnmarkedPosition = false;
         else
            return true;
    }
    return isUnmarkedPosition;
}
