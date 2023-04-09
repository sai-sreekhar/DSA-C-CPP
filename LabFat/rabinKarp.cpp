/*
    Author: Sai Sreekar
    Created: 2023/02/13 16:56:57
    Last Modified: 2023/04/09 21:03:27
*/

#include <iostream>
#include <cmath>
#include <vector>
#include <climits>

using namespace std;

#define d 10

void search(string pattern, string text, int q)
{
    int m = pattern.length();
    int n = text.length();
    int p = 0;
    int t = 0;
    int h = 1;

    // setting h as 10 powers
    h = pow(d, m - 1);

    // calculating hash value for pattern and text
    for (int i = 0; i < m; i++)
    {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    int hits = 0;
    for (int i = 0; i <= n - m; i++)
    {
        if (p == t)
        {
            hits++;
            int j;
            bool found = true;
            for (j = 0; j < m; j++)
            {
                if (text[i + j] != pattern[j])
                {
                    found = false;
                    break;
                }
            }

            if (found)
            {
                cout << "Pattern found at index " << i
                     << "\n";
            }
        }

        if (i < n - m)
        {
            t = (d * (t - text[i] * h) + text[i + m]) % q;
            if (t < 0)
            {
                t = t + q;
            }
        }
    }
    cout << hits << "\n";
}

int main()
{
    string text = "3141592653589793";
    string pattern = "26";

    search(pattern, text, 11);
    return 0;
}
