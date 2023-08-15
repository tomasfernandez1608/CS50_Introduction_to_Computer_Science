#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
// index = 0.0588 * L - 0.296 * S - 15.8 (L es el número promedio de letras por cada 100 palabras en el texto
//y S es el número promedio de oraciones por cada 100 palabras en el texto.)
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string texto = get_string("Text: ");
    //printf("%s\n", texto );
    int letters = count_letters(texto);
    int words = count_words(texto);
    int sentences = count_sentences(texto);
    //printf("LETTERS: %i \n WORDS %i \n SENTENCES: %i \n",letters,words,sentences);
    float l = ((float)letters / words)*100;
    float s = ((float)sentences / words)*100;
    float in = 0.0588 * l - 0.296 * s - 15.8;
    int index = round(in);
    if(index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if(index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n",index);
    }
    return 0;
}

int count_sentences(string text)
{
    int i = 0, count = 0;
    char c;
    do
    {
        c = text[i];
        if(c == '.' || c == '!' || c == '?')
        {
            count++;
        }
        i++;
    }
    while(c != '\0');
    return count;
}
int count_words(string text)
{
    int i = 0, count = 1;
    char c;
    do
    {
        c = text[i];
        if(isspace(c))
        {
            count++;
        }
        i++;
    }
    while(c != '\0');
    return count;
}

int count_letters(string text)
{
    int i = 0, count = 0;
    char c;
    do
    {
        c = text[i];
        if(isalpha(c))
        {
            count++;
        }
        i++;
    }
    while(c != '\0');
    return count;
}
