#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void)
{
    string str=get_string("Message: ");

    char binario[8];

    for(int i = 0, n = strlen(str); i < n; i ++)
    {
        int num=str[i];
        int j=0;
        do
        {
            if (num%2==0 || num==0)
            {
                binario[j]=0;
            }
            else
            {
                binario[j]=1;
            }
            num=num/2;
            j++;
        }
        while(j<8);
        for(j=7;j>=0;j--)
        {
            print_bulb(binario[j]);
        }
        printf("\n");
    }
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
