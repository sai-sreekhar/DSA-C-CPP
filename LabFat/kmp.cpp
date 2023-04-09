/*
    Author: Sai Sreekar
    Created: 2023/02/13 16:44:17
    Last Modified: 2023/04/09 23:35:31
*/

#include <iostream>
#include <vector>

using namespace std;

void computeLPSArray(string pattern, vector<int> &lps, string text)
{
    int n = pattern.size();
    lps[0] = 0;
    int i = 1;
    int len = 0;
    while (i < n)
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
    for(int i = 0; i < lps.size(); i++)
    {
        cout << lps[i] << " ";
    }
    cout << "\n";
}

void KMPSearch(string pattern, string text)
{
    int M = pattern.length();
    int N = text.length();

    vector<int> lps(M, 0);

    computeLPSArray(pattern, lps, text);

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
    string text = "ababbabbabbababbabb";
    string pattern = "ababd";
    KMPSearch(pattern, text);
}
