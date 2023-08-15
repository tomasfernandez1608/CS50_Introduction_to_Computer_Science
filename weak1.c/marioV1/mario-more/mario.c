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
    int cont;
    for(int I=1;I<=height;I++)
    {
        cont=0;
        for(int J=1;J<=height;J++)
        {
            if(J>(height-I)){
                printf("#");
                cont++;
            }
            else
            {
                printf(" ");
            }

        }
        printf("  ");
        for(int J=0;J<cont;J++)
        {
            printf("#");
        }
        printf("\n");
    }
}