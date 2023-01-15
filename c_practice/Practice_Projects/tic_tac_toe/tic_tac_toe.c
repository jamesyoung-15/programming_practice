#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

void printBoard();
void playerMove();
int checkWin();
int checkFreeSpace();
void resetBoard();
void aiMove();
void printWinner(int);

char gameBoard[3][3];

int main()
{
    resetBoard();
    int winner = -1;
    while(checkFreeSpace()!=0 && winner==-1)
    {
        printBoard();
        playerMove();
        winner = checkWin();
        if(winner!=-1 || checkFreeSpace() == 0)
        {
            break;
        }
        aiMove();
        winner = checkWin();
        if(winner!=-1 || checkFreeSpace() == 0)
        {
            break;
        }
    }
    printBoard();
    printWinner(winner);
    return 0;
}

//reset board before game
void resetBoard()
{
    int counter =0;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            gameBoard[i][j]=' ';
        }
    }
}

//print board function
void printBoard()
{
    printf("\nWelcome to Tic Tac Toe Game! \n\n");
    printf("Player (X) vs AI (O) \n\n");
    printf(" %c | %c | %c\n", gameBoard[0][0],gameBoard[0][1],gameBoard[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c\n", gameBoard[1][0],gameBoard[1][1],gameBoard[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c\n\n", gameBoard[2][0],gameBoard[2][1],gameBoard[2][2]);
}

//check for free space by looping through rows and columns
int checkFreeSpace()
{
    int freeSpace = 9;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(gameBoard[i][j]!=' ')
            {
                freeSpace--;
            }
        }
    }
    return freeSpace;
}

//place x depending on player input
void playerMove()
{
    int option_x,option_y,x,y;
    do{
        printf("Enter the column to place your move: ");
        scanf("%d", &option_x);
        switch (option_x) {
            case 1:
                x=0;
                break;
            case 2:
                x=1;
                break;
            case 3:
                x=2;
                break;
            default:
                printf("Invalid option.");
        }
        printf("Enter the row to place your move: ");
        scanf("%d", &option_y);
        switch (option_y) {
            case 1:
                y=0;
                break;
            case 2:
                y=1;
                break;
            case 3:
                y=2;
                break;
            default:
                printf("Invalid option.");
        }
        //if input isnt empty
        if(gameBoard[x][y]!=' ')
        {
            printf("Invalid move.\n");
        }
        else 
        {
            gameBoard[x][y] = 'X';
            break;
        }
    } while(gameBoard[x][y]!= ' ');
}
void aiMove()
{
    //random number to get ai move, use time as seeding
    srand(time(0));
    int x;
    int y;
    if (checkFreeSpace()>0)
    {
        do 
        {
            x = rand() % 3;
            y = rand() % 3;
        }while (gameBoard[x][y]!=' ');
        gameBoard[x][y] = 'O';
    }
    else
    {
        printWinner(0);
    }
}

//function checks if someone won, returns -1 to continue, 0 for draw, 1 for player, 2 for AI
int checkWin()
{
    //check for three of a kind in rows
    for(int i=0; i<3; i++)
    {
        if(gameBoard[i][0] == gameBoard[i][1] && gameBoard[i][0] == gameBoard[i][2])
        {
            if(gameBoard[i][0]=='X')
            {
                return 1;
            }
            else if(gameBoard[i][0]=='O')
            {
                return 2;
            }
            else if(gameBoard[i][0]==' ')
            {
                return -1;
            }
        }
    }
    //check for three of a kind in columns
    for(int i=0; i<3; i++)
    {
        if(gameBoard[0][i] == gameBoard[1][i] && gameBoard[0][i] == gameBoard[2][i])
        {
            if(gameBoard[0][i]=='X')
            {
                return 1;
            }
            else if(gameBoard[0][i]=='O')
            {
                return 2;
            }
            else if(gameBoard[0][i]==' ')
            {
                return -1;
            }
        }
    }
    //check for three of a kind diagonally
    if(gameBoard[0][0]==gameBoard[1][1] && gameBoard[0][0]==gameBoard[2][2])
    {
        if(gameBoard[0][0]=='X')
        {
            return 1;
        }
        else if(gameBoard[0][0]=='O')
        {
            return 2;
        }
        else if(gameBoard[0][0]==' ')
        {
            return -1;
        }
    }
    if(gameBoard[0][2]==gameBoard[1][1] && gameBoard[0][2]==gameBoard[2][0])
    {
        if(gameBoard[0][2]=='X')
        {
            return 1;
        }
        else if(gameBoard[0][2]=='O')
        {
            return 2;
        }
        else if(gameBoard[0][2]==' ')
        {
            return -1;
        }
    }
    if(checkFreeSpace() == 0)
    {
        return 0;
    }
    return -1;
}

void printWinner(int z)
{
    if(z == 0)
    {
        printf("Draw.\n");
    }
    else if (z==1)
    {
        printf("You win!\n");
    }
    else if (z==2)
    {
        printf("Computer wins!\n");
    }
    else
    {
        printf("Error.");
    }
}