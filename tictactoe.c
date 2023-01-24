#include <stdio.h>

int i, j, x, y, turns = 1, k = 0;
int array[3][3];
void initialization();
void userInput();
void userInput2();
void drawUpdate();
void checkWinCondition();
int winCondition1 = 0;

int main()
{
    while (k == 0)
    {
        initialization();
        k++;
        drawUpdate();
    }

    while (winCondition1 != 1)
    {
        turns += 1;
        userInput();
        checkWinCondition();
        drawUpdate();
        if (winCondition1 == 1)
        {
            printf("Player 1 wins\n");
            break;
        }
        if (turns > 9)
        {
            break;
        }
        turns += 1;
        userInput2();
        checkWinCondition();
        drawUpdate();
        if (winCondition1 == 1)
        {
            printf("Player 2 wins\n");
            break;
        }
        if (turns > 9)
        {
            break;
        }
    }
    printf("Game over");

    return 0;
}

void initialization()
{
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            array[i][j] = 32;
        }
    }
}

void userInput()
{
    int m = 0;
    while (m != 1)
    {
        printf("P1 Enter where you would like to place x (row, column): ");
        scanf("%d %d", &x, &y);
        x--;
        y--;
        if (x >= 0 && x <= 2 && y >= 0 && y <= 2)
        {
            if (array[x][y] == 32 && array[x][y] != 111 && array[x][y] != 120)
            {
                array[x][y] = 120;
                m++;
            }
            else
            {
                printf("enter a empty spot\n");
            }
        }
        else
        {
            printf("enter a value between 1 and 3.\n");
        }
    }
}

void userInput2()
{
    int n = 0;
    while (n != 1)
    {
        printf("P2 Enter where you would like to place o (row, column): ");
        scanf("%d %d", &x, &y);
        x--;
        y--;
        if (x >= 0 && x <= 2 && y >= 0 && y <= 2)
        {
            if (array[x][y] == 32 && array[x][y] != 120 && array[x][y] != 111)
            {
                array[x][y] = 111;
                n++;
            }
            else
            {
                printf("enter a empty spot\n");
            }
        }
        else
        {
            printf("enter a value between 1 and 3.\n");
        }
    }
}

void drawUpdate()
{
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("|-%c-|", array[i][j]);
        }
        printf("\n");
    }
}

void checkWinCondition()
{
    if (array[0][0] == array[0][1] && array[0][1] == array[0][2] && array[0][0] != 32 && array[0][1] != 32 && array[0][2] != 32)
    {
        winCondition1 = 1;
    }
    else if (array[1][0] == array[1][1] && array[1][1] == array[1][2] && array[1][0] != 32 && array[1][1] != 32 && array[1][2] != 32)
    {
        winCondition1 = 1;
    }
    else if (array[2][0] == array[2][1] && array[2][1] == array[2][2] && array[2][0] != 32 && array[2][1] != 32 && array[2][2] != 32)
    {
        winCondition1 = 1;
    }
    else if (array[0][0] == array[1][0] && array[1][0] == array[2][0] && array[0][0] != 32 && array[1][0] != 32 && array[2][0] != 32)
    {
        winCondition1 = 1;
    }
    else if (array[0][1] == array[1][1] && array[1][1] == array[2][1] && array[0][1] != 32 && array[1][1] != 32 && array[2][1] != 32)
    {
        winCondition1 = 1;
    }
    else if (array[0][2] == array[1][2] && array[1][2] == array[2][2] && array[0][2] != 32 && array[1][2] != 32 && array[2][2] != 32)
    {
        winCondition1 = 1;
    }
    else if (array[0][0] == array[1][1] && array[1][1] == array[2][2] && array[0][0] != 32 && array[1][1] != 32 && array[2][2] != 32)
    {
        winCondition1 = 1;
    }
    else if (array[0][2] == array[1][1] && array[1][1] == array[2][0] && array[0][2] != 32 && array[1][1] != 32 && array[2][0] != 32)
    {
        winCondition1 = 1;
    }
}