// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];
int cont=0;
// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO

    int indice = hash(word);
    node * NP=table[indice];
    while(NP)
    {
        if(!strcasecmp(NP->word,word))
        {
            return true;
        }
        NP=NP->next;
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE * FP=fopen(dictionary,"r");
    if(FP==NULL)
    {
        return false;
    }
    char words[LENGTH + 1];
    while(fscanf(FP,"%s",words)!=EOF)
    {
        node *P=malloc(sizeof(node));

        if(P==NULL)
        {
            printf("Error allocate memory");
            return false;
        }
        strcpy(P->word,words);
        int indice = hash(P->word);
        cont++;
        P->next=table[indice];
        table[indice]=P;

    }
    fclose(FP);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return cont;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    int c=0;
    node * FP;
    node * SIG;
    for(int i=0;i<N;i++)
    {
        FP=table[i];
        while(FP)
        {
            SIG=FP;
            FP=FP->next;
            free(SIG);
            c++;
        }
    }
    if(c==cont)
    {
        return true;
    }
    else
    {
        return false;
    }
}
