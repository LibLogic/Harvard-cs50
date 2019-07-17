// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents number of buckets in a hash table
#define N 26

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Represents a hash table
node *hashtable[N];
int wordCount = 0;

// Hashes word to a number between 0 and 25, inclusive, based on its first letter
unsigned int hash(const char *word)
{
    return tolower(word[0]) - 'a';
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // Initialize hash table
    for (int i = 0; i < N; i++)
    {
        hashtable[i] = NULL;
    }

    // Open dictionary
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        unload();
        return false;
    }

    // Buffer for a word
    char word[LENGTH]; // Changed by Tom took out LENGTH +!

    // Insert words into hash table
    while (fscanf(file, "%s", word) != EOF)
    {
        int I = hash(word);

        if (hashtable[I] == NULL)
        {
            node *rootNode = malloc(sizeof(node));
            strcpy(rootNode->word, word);
            rootNode->next = NULL;
            hashtable[I] = rootNode;
            // printf("%i\t%s\n", I, hashtable[I]->word);
        }
        else
        {
            node *nextNode = malloc(sizeof(node));
            strcpy(nextNode->word, word);
            nextNode->next = NULL;

            node *trav = hashtable[I];
            while (trav->next != NULL)
            {
                trav = trav->next;
            }
            trav->next = nextNode;
            // printf("%i\t%s\n", I, trav->next->word);
        }
        ++wordCount;
    }

    // Close dictionary
    fclose(file);

    // Indicate success
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return wordCount;
}

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    int test;
    for (int i = 0; i < N; i++)
    {
        node *head = hashtable[i], *temp;
        while (head != NULL)
        {
            temp = head;
            head = head->next;
            test = !strcasecmp(word, temp->word);
            if (test == 1)
            {
                return true;
            }
        }
    }
    return false;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // // empty hashtable elements
    for (int i = 0; i < N; i++)
    {
        node *head = hashtable[i], *temp;
        while (head != NULL)
        {
                temp = head;
                head = head->next;
                free(temp);
        }
    }
    return true;
}