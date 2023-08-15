#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int conver(char * c);


int main(int argc, string argv[])
{
    if( argc != 2)
        {
            printf("Usage: ./caesar %s\n",argv[1]);
            return 1;
        }
    for(int I=0; I<strlen(argv[1]);I++)
    {
        if( ! isdigit(argv[1][I]) || argc != 2)
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    string str=get_string("plaintext:  ");
    printf("ciphertext:  ");
    int suma = conver(argv[1]);
    for(int i = 0, n = strlen(str); i < n; i ++)
    {
        char cifra = str[i];
        int c=cifra;
        if(cifra >= 65 && cifra <= 90)
        {
            c= c + suma;
            if( c > 90 )
            {
                int dif=c-90;
                c=64+dif;
            }
            cifra = c;
        }
        else if (cifra >= 97 && cifra <= 122)
        {
            c= c + suma;
            while( c > 122 )
            {
                int dif=c-122;
                c=96+dif;
            }
            cifra = c;
        }
        printf("%c",cifra);
    }
    printf("\n");
}

int conver(char  c[])
{
    int suma=0;
    for(int i =0, n=strlen(c); i < n; i++)
    {
        if(i>0)
        {
            suma=suma*10;
        }
        switch(c[i])
        {
            case 49:
                suma+=1;
                break;
            case 50:
                suma+=2;
                break;

            case 51:
                suma+=3;
                break;

            case 52:
                suma+=4;
                break;

            case 53:
                suma+=5;
                break;

            case 54:
                suma+=6;
                break;

            case 55:
                suma+=7;
                break;

            case 56:
                suma+=8;
                break;

            case 57:
                suma+=9;
                break;
            default:
                suma+=0;
                break;
        }
    }
    return suma;
}