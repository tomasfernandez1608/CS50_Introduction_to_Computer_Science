#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>

void draw(int n);

int main (void)
{
    draw(4);
}

void draw (int n)
{
    if(n <= 0)
    {
        return;
    }

    draw(n-1);

    for(int i=0;i<n;i++)
    {
        printf("#");
    }
    printf("\n");
}