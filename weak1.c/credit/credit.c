#include <cs50.h>
#include <stdio.h>
#include <string.h>
/*So what’s the secret formula? Well, most cards use an algorithm invented by Hans Peter Luhn of IBM. According to Luhn’s algorithm, you can determine if a credit card number is (syntactically) valid as follows:

Multiply every other digit by 2, starting with the number’s second-to-last digit, and then add those products’ digits together.
Add the sum to the sum of the digits that weren’t multiplied by 2.
If the total’s last digit is 0 (or, put more formally, if the total modulo 10 is congruent to 0), the number is valid!*/

int tabla(int n);
bool validacion(char t[], int i);

int main(void)
{
    bool valid = false;
    long number;
    char tarjeta[21];

    number = get_long("Number: ");
    //American Express uses 15-digit numbers, MasterCard uses 16-digit numbers, and Visa uses 13- and 16-digit number
    // all Visa numbers start with 4.
    /*sprintf(buferEnDondePonerLaCadenaFormateada, formato, cosaQueFormatear); Por ejemplo:sprintf(bufer, "%llu", numero);*/
    int I = 0;
    sprintf(tarjeta,"%ld",number);
    do
    {
        I++;
    }
    while (tarjeta[I]);
    switch(I)
    {
        case 15://American Express numbers start with 34 or 37
            if(tarjeta[0]==51 && (tarjeta[1]==52 || tarjeta[1]==55) && validacion(tarjeta,I))
            {
                printf("AMEX\n");
                break;
            }
        case 16://MasterCard numbers start with 51, 52, 53, 54, or 55
            if(tarjeta[0]==53 && (tarjeta[1]==49 || tarjeta[1]==50 ||tarjeta[1]==51 || tarjeta[1]==52 || tarjeta[1]==53)
            && validacion(tarjeta,I))
            {
                printf("MASTERCARD\n");
                break;
            }

        default:
            if(I>=13 && I<=16)
            {
                if(tarjeta[0]==52 && validacion(tarjeta,I))
                {
                    printf("VISA\n");
                    break;
                }
            }
            printf("INVALID\n");
            break;
    }
}

bool validacion(char t[], int i)
{
    int suma = 0, cont = 0, integer, cont2 = 0;
    int suma_nomulti = tabla(t[i - 1]);
    bool flag2 =true;
    for (int I = i - 2; I >= 0; I--)
    {
        if(cont == 2 || flag2)
        {
            integer = tabla(t[I])*2;
            if(integer >= 10)
            {
                char inte[4];
                sprintf(inte,"%d", integer);
                suma = suma + tabla(inte[0]) + tabla(inte[1]);
            }
            else
            {
                suma = suma + integer;
            }
            printf("\n %c suma=%d", t[I], suma);
            cont = 0;
            cont2++;
        }
        else
        {
            if(cont2 != 0)
            {
                suma_nomulti += tabla(t[I]);
                //printf("\n suma multi= %d", suma_nomulti);
            }
        }
        cont++;
        flag2 = false;
    }

    suma = suma + suma_nomulti;
    char valido[11];
    sprintf(valido, "%d", suma);
    int J = 0;
    do
    {
        J++;
    }
    while (valido[J]);

    printf("\n %s", valido);

    if (valido[J - 1] == 48)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int tabla(int n)
{
    switch (n)
    {
        case 48:
            return 0;
            break;
        case 49:
            return 1;
            break;
        case 50:
            return 2;
            break;
        case 51:
            return 3;
            break;
        case 52:
            return 4;
            break;
        case 53:
            return 5;
            break;
        case 54:
            return 6;
            break;
        case 55:
            return 7;
            break;
        case 56:
            return 8;
            break;
        case 57:
            return 9;
            break;
        default:
            return 0;
            break;
    }
}
