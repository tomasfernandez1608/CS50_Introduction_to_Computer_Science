#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define n 26

int main(int argc, string argv[])
{
    if (argc!=2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    if(strlen(argv[1])!=n)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    for(int i=0;i<n;i++)
    {
        if(!isalpha(argv[1][i]))
        {
            printf("Usage: ./substitution key\n");
            return 1;
        }
        for(int j=i+1;j<n;j++)
        {
            if(argv[1][i]==argv[1][j])
            {
                printf("Usage: ./substitution key\n");
                return 1;
            }
        }
    }
    string str=get_string("plaintext: ");
    char str2[strlen(str)];
    int pos;
    printf("ciphertext: ");
    for (int i=0, n2=strlen(str);i<n2;i++)
    {
        if (str[i]>=65 && str[i]<=90)
        {
            pos=str[i]-65;
            printf("%c", toupper(argv[1][pos]));
        }
        else if(str[i]>=97 && str[i]<=122)
        {
            pos=str[i]-97;
            printf("%c", tolower(argv[1][pos]));
        }
        else
        {
            printf("%c",str[i]);
        }
    }
    printf("\n");
}/*if(isupper(str[i]))
            {
                pos=str[i]-65;
                str2[i]=toupper(argv[1][pos]);
            }
            if(islower(str[i]))
            {
                pos=str[i]-97;
                str2[i]=tolower(argv[1][pos]);
            }*/