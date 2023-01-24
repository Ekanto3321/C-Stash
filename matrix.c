#include <stdio.h>
#include <math.h>

int a[3][3];
int b[3][3];
int sum[3][3];
int i, j;
void calculation();
void output();
void userInput();
int main()
{
    printf("this is a program that calculates the addition of 2 4x4 matrices using arrays\n\n");
    userInput();
    calculation();
    output();
    return 0;
}

void userInput()
{
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("value of the %d, %d th element of a: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("value of the %d, %d th element of b: ", i, j);
            scanf("%d", &b[i][j]);
        }
    }
}
void calculation()
{
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            sum[i][j] = a[i][j]*b[j][i];    
        }
    }
}
void output()
{
    printf("The sum of the matrices is\n");
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("%d ", sum[i][j]);
        }
        printf("\n");
    }
}