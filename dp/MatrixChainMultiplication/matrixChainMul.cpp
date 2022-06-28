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

// ----->GENERAL FORMAT
// int mcmDp(int *arr,int i,int j)
// {
//     if (i > j)
//     {
//         return 0;
//     }
//     for (int k = i; k < j; k++)
//     {
//         return (mcmDp(arr,i,k) + mcmDp(arr,k+1,j));
//     }
// }
//<-------------------

int min(int a, int b)
{
    return a < b ? a : b;
}

int mcmRecursion(int *arr, int i, int j)
{
    int min = INT_MAX;
    
    if (i >= j)
    {
        return 0;
    }

    for (int k = i; k <=(j-1); k++)
    {
        //also we can to k = i+1 to k<= j and divsion is i to k-1 and k to j
        //we took k = i to k = j-1 and divsion is i to k and k+1 to j  
        int tempAns = mcmRecursion(arr,i,k)+mcmRecursion(arr,k+1,j)+arr[i-1]*arr[k]*arr[j];
        if (tempAns < min)
        {
            min = tempAns;
        }
    }

    return min;
}

int dp[1001][1001];

int mcmMemoization(int *arr, int i, int j)
{

    int min = INT_MAX;
    
    if (i >= j)
    {
        return 0;
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    
    for (int k = i; k <=(j-1); k++)
    {
        //also we can to k = i+1 to k<= j and divsion is i to k-1 and k to j
        //we took k = i to k = j-1 and divsion is i to k and k+1 to j  
        int tempAns = mcmMemoization(arr,i,k)+mcmMemoization(arr,k+1,j)+arr[i-1]*arr[k]*arr[j];
        if (tempAns < min)
        {
            min = tempAns;
        }
    }
    dp[i][j] = min;
    return dp[i][j];
}

int main()
{
    int arr[5] = {1,2,3,4,3};
    int len = 5;
    cout << mcmRecursion(arr, 1, len - 1) << endl;
    memset(dp,-1,sizeof(dp));
    cout << mcmMemoization(arr,1,len-1) << endl;
    return 0;
}