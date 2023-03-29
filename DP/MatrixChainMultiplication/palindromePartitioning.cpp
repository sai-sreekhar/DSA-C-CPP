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

int min(int a, int b)
{
    return a < b ? a : b;
}

bool isPalindrome(string str, int i, int j)
{
    while (i < j)
    {
        if (str[i] != str[j])
            return false;
        i++;
        j--;
    }
    return true;
}

int mcmRecursion(string x, int i, int j)
{
    int ans = INT_MAX;
    int count;
    if (i >= j)
    {
        return 0;
    }

    if (isPalindrome(x, i, j))
    {
        return 0;
    }

    for (int k = i; k <= (j - 1); k++)
    {
        count = mcmRecursion(x, i, k) + mcmRecursion(x, k + 1, j) + 1;
        ans = min(ans, count);
    }

    return ans;
}

int dp[1001][1001];

int mcmMemoization(string x, int i, int j)
{
    int ans = INT_MAX ;
    int count,left,right;
    if (i >= j)
    {
        return 0;
    }

    if (isPalindrome(x, i, j))
    {
        return 0;
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    for (int k = i; k <= (j - 1); k++)
    {
        // count = mcmMemoization(x, i, k) + mcmMemoization(x, k + 1, j) + 1;
        // if (count < ans)
        // {
        //     ans = count;
        // }

        // BELOW IS OPTIMIZED CODE. THE ABOVE CODE ISNT OPTIMIZED

        if (dp[i][k] != -1)
        {
            left = dp[i][k];
        }
        else
        {
            left = mcmMemoization(x,i,k);
            dp[i][k] = left;
        }

        if (dp[k+1][j] != -1)
        {
            right = dp[k+1][j];
        }
        else
        {
            right = mcmMemoization(x,k+1,j);
            dp[k+1][j] = right; 
        }

        count = 1 + left + right;

        if (count < ans)
        {
            ans = count;
        }     
    }

    dp[i][j] = ans;
    return dp[i][j];
}

int main()
{
    string x = "abcde";
    cout << mcmRecursion(x, 0, x.length() - 1) << endl;
    memset(dp,-1,sizeof(dp));
    cout << mcmMemoization(x,0,x.length()-1) << endl;
    return 0;
}