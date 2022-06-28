#include <iostream>
#include <string>
#include <cstring>
#include <new>
#include <cstdbool>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstdarg>
#include <climits>
#include <bits/stdc++.h>

#define DEBUG

#ifdef DEBUG
#define TRACE(msg, ...) printTrace(__LINE__, __FILE__, msg, __VA_ARGS__)
#else
#define TRACE(msg, ...)
#endif

using namespace std;

void printTrace(int line, const char *fileName, const char *msg, ...)
{
    va_list args;
    char buffer[1024 + 2] = {0};

    snprintf(buffer, sizeof(buffer), "%s(%d) : ", fileName, line);
    int stringLength = strnlen(buffer, 1024);
    int remainingBufferSize = 1024 - stringLength;
    va_start(args, msg);
    vsnprintf(buffer + stringLength, remainingBufferSize, msg, args);
    va_end(args);
    cout << buffer << flush;
}

int max(int a, int b)
{
    return a > b ? a : b;
}

string longestCommonSubsequenceDP(string x, string y, int lenX, int lenY)
{
    int dp[lenX + 1][lenY + 1];

    for (int i = 0; i < lenX + 1; i++)
    {
        dp[i][0] = 0;
    }

    for (int j = 0; j < lenY + 1; j++)
    {
        dp[0][j] = 0;
    }

    for (int i = 1; i < lenX + 1; i++)
    {
        for (int j = 1; j < lenY + 1; j++)
        {
            if (x[i - 1] == y[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }

    string lcs = "";
    int i = lenX;
    int j = lenY;
    while (i != 0 && j != 0)
    {
        if (x[i-1] == y[j-1])
        {
            lcs.push_back(x[i-1]);
            i = i - 1;
            j = j - 1;
        }
        else
        {
            int maxVal = max(dp[i - 1][j], dp[i][j - 1]);
            if (maxVal == dp[i-1][j])
            {
                i = i-1;
            }
            else
            {
                j = j-1;
            } 
        }
    }

    reverse(lcs.begin(),lcs.end());
    return lcs;
}

int main()
{
    // string x = "abcdgh";
    // string y = "abedfgr";
    string x = "abcdaf";
    string y = "acbcf";
    cout << longestCommonSubsequenceDP(x,y,x.length(),y.length()) << endl;
    return 0;
}