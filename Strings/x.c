#include <stdio.h>
#include <string.h>

void computeLPSArray(char pattern[], int M, char lps[], char text[])
{
    int len = 0;
    lps[0] = 0;

    int i = 1;
    while (i < M)
    {
        if (pattern[i] == pattern[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }

    int pi[strlen(text)];
    pi[0] = 0;
    int k = 0;
    i = 1;
    while (i < strelen(text))
    {
        if (text[i] == text[k])
        {
            k++;
            pi[i] = k;
            i++;
        }
        else
        {
            if (k != 0)
            {
                k = pi[k - 1];
            }
            else
            {
                pi[i] = 0;
                i++;
            }
        }
    }

    printf("Pi value is :");
    for (i = 0; i < strlen(text); i++)
    {
        printf("%d ", pi[i]);
    }
    printf("\n");
}

void KMPSearch(char pattern[], char text[])
{
    int M = strlen(pattern);
    int N = strlen(text);

    char lps[M];

    computeLPSArray(pattern, M, lps, text);

    int i = 0;
    int j = 0;
    while ((N - i) >= (M - j))
    {
        if (pattern[j] == text[i])
        {
            j++;
            i++;
        }

        if (j == M)
        {
            printf("Found pattern at index %d\n", i - j);
            j = lps[j - 1];
        }

        else if (i < N && pattern[j] != text[i])
        {

            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                i = i + 1;
            }
        }
    }
}

int main()
{
    char text[] = "ababbabbabbababbabb";
    char pattern[] = "bbabb";
    KMPSearch(pattern, text);
}