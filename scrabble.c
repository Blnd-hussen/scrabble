#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(char *word);
char *get_string(char *text);

int main(void)
{
    // Get input words from both players
    char *word1 = get_string("Player 1: ");
    char *word2 = get_string("Player 2: ");
    
   

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if (score1 > score2)
    {
        printf("player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("player 2 wins!\n");
    }
    else
    {
        printf("tie!\n");
    }

    free(word1);
    free(word2);
}
char *get_string(char *text)
{
    char *str = malloc(sizeof(char) * 100);
    if (str == NULL)
    {
        return NULL;
    }
    printf("%s", text);
    scanf("%ms", &str);
    return str;
}

int compute_score(char *word)
{
    int score = 0;
    int letter_value;
    int index;
    
    for (int i = 0; i < strlen(word); i++)
    {
        letter_value = tolower(word[i]);

        if (letter_value >= 97 && letter_value <= 122)
        {
            index = letter_value - 97;
            score += POINTS[index];
        }
    }
    return score;
}

