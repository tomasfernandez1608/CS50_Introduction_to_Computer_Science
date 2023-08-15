#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    do
    {
        printf("Height: ");
        scanf("%d",&height);
    }
    while (height>8 || height<1);

    for(int I=1;I<=height;I++)
    {
        for(int J=1;J<=height;J++)
        {
            if(J>(height-I)){
                printf("#");
            }
            else
            {
                printf(" ");
            }

        }
        printf("\n");
    }

}