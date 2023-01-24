#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

int arr[5][5];
int i, j, x, p1 = 0, p2 = 0, winCondition = 0, turns = 8, loopCondition = 0;
int a1, a2, b1, b2, c1, c2, d1, d2, e1, e2;
char move, pick, pick2;

void mainMenu();
void init();
void randomize();
void reset();
void drawBoard();
void playerMovement();
void checkWincondition();
void gameLoop();

int main()
{
    while (x != 1)
    {
        mainMenu();
    }

    return 0;
}

void mainMenu()
{
    printf("Enter 1 to start the game\nEnter 2 for instructions\nEnter 3 to exit\nEnter: ");
    scanf(" %c", &pick);
    if (pick == '1')
    {
        reset();
        gameLoop();
    }
    else if (pick == '2')
    {
        Sleep(500);
        printf("\nInstructions\n\nYou play as the player 'P'\nThe goal to reach the Throne 'T' \nAvoid the mines that look like this %c \n\nEnter the 'w' key to move up\nEnter the 's' key to move down\nEnter the 'a' key to move left\nEnter the 'd' key to move right\n\n", 31);
    }
    else if (pick == '3')
    {
        x++;
    }
    else if (pick == '4')
    {
        printf("\nSecret credit screen hehe.. This shit took me 2 days to get right :V\n\n");
    }
    else
    {
        printf("\nPlease enter a valid number\n\n");
    }
}

void gameLoop()
{
    init();
    randomize();
    drawBoard();
    while (winCondition != 1)
    {
        printf("\nTurns remaining: %d\n", turns);
        turns--;
        playerMovement();
        drawBoard();
        checkWincondition();
        printf("\n");
    }
}

void init()
{
    p1 = 0;
    p2 = 0;
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            arr[i][j] = 254;
        }
    }
    arr[4][4] = 'T';
    arr[p1][p2] = 'P';
}

void randomize()
{
    srand(time(NULL));

    while ((a1 == b1 && a2 == b2) || (a1 == c1 && a2 == c2) || (a1 == d1 && a2 == d2) || (a1 == e1 && a2 == e2) || (b1 == c1 && b2 == c2) || (b1 == d1 && b2 == d2) || (b1 == e1 && b2 == e2) || (c1 == d1 && c2 == d2) || (c1 == e1 && c2 == e2) || (d1 == e1 && d2 == e2) || (a1 == 4 && a2 == 4) || (b1 == 4 && b2 == 4) || (c1 == 4 && c2 == 4) || (d1 == 4 && d2 == 4) || (e1 == 4 && e2 == 4) || (a1 == 0 && a2 == 0) || (b1 == 0 && b2 == 0) || (c1 == 0 && c2 == 0) || (d1 == 0 && d2 == 0) || (e1 == 0 && e2 == 0))
    {
        a1 = rand() % 5;
        a2 = rand() % 5;

        b1 = rand() % 5;
        b2 = rand() % 5;

        c1 = rand() % 5;
        c2 = rand() % 5;

        d1 = rand() % 5;
        d2 = rand() % 5;

        e1 = rand() % 5;
        e2 = rand() % 5;
    }
    arr[a1][a2] = 31;
    arr[b1][b2] = 31;
    arr[c1][c2] = 31;
    arr[d1][d2] = 31;
    arr[e1][e2] = 31;
}

void reset()
{
    Sleep(250);
    a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0, e1 = 0, e2 = 0;
    winCondition = 0;
    turns = 8;
}

void drawBoard()
{
    arr[p1][p2] = 'P';
    printf("\n");
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            printf("%c ", arr[i][j]);
        }
        printf("\n");
    }
}

void playerMovement()
{
    printf("Enter your move: ");
    scanf(" %c", &move);
    if (move == 'a')
    {
        arr[p1][p2] = 254;
        if (p2 == 0)
        {
            p2 += 5;
        }
        p2 -= 1;
    }
    else if (move == 'd')
    {
        arr[p1][p2] = 254;
        if (p2 == 4)
        {
            p2 -= 5;
        }
        p2 += 1;
    }
    else if (move == 's')
    {
        arr[p1][p2] = 254;
        if (p1 == 4)
        {
            p1 -= 5;
        }
        p1 += 1;
    }
    else if (move == 'w')
    {
        arr[p1][p2] = 254;
        if (p1 == 0)
        {
            p1 += 5;
        }
        p1 -= 1;
    }
    else
    {
        printf("Please enter a valid move\n");
        playerMovement();
    }
}

void checkWincondition()
{
    if ((p1 == a1 && p2 == a2) || (p1 == b1 && p2 == b2) || (p1 == c1 && p2 == c2) || (p1 == d1 && p2 == d2) || (p1 == e1 && p2 == e2))
    {
        printf("\nGame over!\n");
        printf("You stepped on a mine.. **BOOM** \nYou exploded and it was very gruesome.\n");
        winCondition++;
    }
    else if (p1 == 4 && p2 == 4)
    {
        printf("\nYou have reached the throne. You won!!\n");
        winCondition++;
    }
    else if (turns <= 0)
    {
        printf("\nGame over!\n");
        printf("You ran out of moves\n");
        winCondition++;
    }
}
