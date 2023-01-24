#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int arr[3][3];
int i, j, x, y, m, n;
int loopCondition = 0, winCondition = 0;
void initialize();
void drawBoard();
void takeUserInput();
void cpuRandomizer();
void cpuInput();
void checkWinCondition();
int main()
{
    initialize();
    drawBoard();
    while (winCondition != 1)
    {
        takeUserInput();
        drawBoard();
        checkWinCondition();
        if (winCondition == 1)
        {
            printf("player won");
            break;
        }
        cpuInput();
        drawBoard();
        checkWinCondition();
        if (winCondition == 1)
        {
            printf("cpu won");
            break;
        }
    }

    return 0;
}

void initialize()
{
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            arr[i][j] = 254;
        }
    }
}
void drawBoard()
{
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%c ", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void takeUserInput()
{
    printf("Enter your move as (row, column): ");
    scanf("%d %d", &x, &y);
    x--;
    y--;
    if ((x > 3 || x < 0) || (y > 3 || y < 0))
    {
        printf("Please enter a valid number between 1-3");
    }
    else if (arr[x][y] == 88 || arr[x][y] == 79)
    {
        printf("Please enter in an empty spot\n");
    }
    else
    {
        arr[x][y] = 88;
    }
}

void cpuInput()
{
    
    while ((arr[m][n] == 88) || (arr[m][n] == 79))
    {
        cpuRandomizer();
    }
    arr[m][n] = 79;

}

void cpuRandomizer()
{
    m = 1 + (rand() % 3);
    n = 1 + (rand() % 3);
    m--;
    n--;
}
void checkWinCondition()
{
    if (arr[0][0] == arr[0][1] && arr[0][1] == arr[0][2] && arr[0][0] != 254 && arr[0][1] != 254 && arr[0][2] != 254)
    {
        winCondition = 1;
    }
    else if (arr[1][0] == arr[1][1] && arr[1][1] == arr[1][2] && arr[1][0] != 254 && arr[1][1] != 254 && arr[1][2] != 254)
    {
        winCondition = 1;
    }
    else if (arr[2][0] == arr[2][1] && arr[2][1] == arr[2][2] && arr[2][0] != 254 && arr[2][1] != 254 && arr[2][2] != 254)
    {
        winCondition = 1;
    }
    else if (arr[0][0] == arr[1][0] && arr[1][0] == arr[2][0] && arr[0][0] != 254 && arr[1][0] != 254 && arr[2][0] != 254)
    {
        winCondition = 1;
    }
    else if (arr[0][1] == arr[1][1] && arr[1][1] == arr[2][1] && arr[0][1] != 254 && arr[1][1] != 254 && arr[2][1] != 254)
    {
        winCondition = 1;
    }
    else if (arr[0][2] == arr[1][2] && arr[1][2] == arr[2][2] && arr[0][2] != 254 && arr[1][2] != 254 && arr[2][2] != 254)
    {
        winCondition = 1;
    }
    else if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] && arr[0][0] != 254 && arr[1][1] != 254 && arr[2][2] != 254)
    {
        winCondition = 1;
    }
    else if (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0] && arr[0][2] != 254 && arr[1][1] != 254 && arr[2][0] != 254)
    {
        winCondition = 1;
    }
}