#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    // TODO: Prompt for start size
    int PI;
    do
    {
        printf("Start size:");
        scanf("%d", &PI);
        fflush(stdin);
    }
    while(PI<9);
    // TODO: Prompt for end size
    int PE;
    do
    {
        printf("End size:");
        scanf("%d", &PE);
        fflush(stdin);
    }
    while(PE<PI);
    if(PE==PI)
    {
        printf("Years: %d", 0);
        exit(0);
    }
     // TODO: Calculate number of years until we reach threshold
    int born, dead, PO=0;
    int years=0;
    
    {
        if(PO==0)
        {
            PO=PI + PI/3 - PI/4;
            PO++;
        }else
        {
            PO=PO + PO/3 - PO/4;
        }
        years++;
    }
    while(PO<=PE);

    // TODO: Print number of years
    printf("Years: %d", years);
    return 0;
}
