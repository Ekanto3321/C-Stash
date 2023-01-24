#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>

int main()
{
    int n,g,h;
    printf("length of the rng word: ");
    scanf("%d",&n);
    
    for(int i=1; i<=n*100; i++)
    {
        srand(clock());
        if(i%2==0)
        {
            g=rand()%26 + 65;
            printf("%c ",g);
        }
        else if(i%2!=0)
        {
            h=rand()%26 + 65;
            printf("%c ",h);
        }
        Sleep(50);

        /*int ran = rand()%26 + 65; // rand()%(Upper - lower + 1) + lower
        printf("%c",ran);*/

    }    
    return 0;
}
