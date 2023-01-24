#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include<time.h>

int arr[3][3];
int i, j, x, y, input,input2=1;
int loopCondition = 0, winCondition = 0;
void initialize();
void drawBoard();
void takeUserInput();
void cpuInput();
void checkWinCondition();
int main()
{
    initialize();
    drawBoard();
    while (winCondition!=1)
    {
        takeUserInput();
        drawBoard();
        checkWinCondition();
        if(winCondition==1)
        {
            printf("player won");
            break;
        }
        cpuInput();
        drawBoard();
        checkWinCondition();
        if(winCondition==1)
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
    printf("Enter a number between 1-9 to place your move: ");
    scanf(" %d", &input);
    switch (input)
    {
    case 1:
        arr[0][0] = 88;
        break;
    case 2:
        arr[0][1] = 88;
        break;
    case 3:
        arr[0][2] = 88;
        break;
    case 4:
        arr[1][0] = 88;
        break;
    case 5:
        arr[1][1] = 88;
        break;
    case 6:
        arr[1][2] = 88;
        break;
    case 7:
        arr[2][0] = 88;
        break;
    case 8:
        arr[2][1] = 88;
        break;
    case 9:
        arr[2][2] = 88;
        break;
    
    default:
        break;
    }
}

void cpuInput()
{   
    printf("cpu move: \n");
    srand(time(NULL));
    
    input2 = 1 + rand()%9;
    switch (input2)
    {
    case 1:
        arr[0][0] = 79;
        break;
    case 2:
        arr[0][1] = 79;
        break;
    case 3:
        arr[0][2] = 79;
        break;
    case 4:
        arr[1][0] = 79;
        break;
    case 5:
        arr[1][1] = 79;
        break;
    case 6:
        arr[1][2] = 79;
        break;
    case 7:
        arr[2][0] = 79;
        break;
    case 8:
        arr[2][1] = 79;
        break;
    case 9:
        arr[2][2] = 79;
        break;
    
    default:
        break;
    }
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