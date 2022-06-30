#include <iostream>
#include <string>
#include <cstring>
#include <new>
#include <cstdbool>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstdarg>

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

// int dp[102][1002];

int max(int a, int b)
{
    return a > b ? a : b;
}

int knapsackRecursion(int *wtArr, int *valArr, int capacity, int n)
{
    if ((n == 0) || (capacity == 0))
    {
        return 0;
    }

    if (wtArr[n-1] <= capacity)
    {
        int choice1 = valArr[n-1]+knapsackRecursion(wtArr,valArr,capacity-wtArr[n-1],n-1);
        int choice2 = knapsackRecursion(wtArr,valArr,capacity,n-1);
        return(max(choice1,choice2));
    }
    else if (wtArr[n-1] > capacity)
    {
        return knapsackRecursion(wtArr,valArr,capacity,n-1);
    }
}

// int knapsackMemoization(int *wtArr, int *valArr, int capacity,int n)
// {
    
//     if ((n == 0) || (capacity == 0))
//     {
//         return 0;
//     }
//     if (dp[n][capacity] != -1)
//     {
//         return dp[capacity][n];
//     }
//     if (wtArr[n-1] <= capacity)
//     {
        
//         int choice1 = valArr[n-1]+knapsackMemoization(wtArr,valArr,capacity-wtArr[n-1],n-1);
//         int choice2 = knapsackMemoization(wtArr,valArr,capacity,n-1);
//         dp[n][capacity] = max(choice1,choice2);
//         return dp[n][capacity];
//     }
//     else if (wtArr[n-1] > capacity)
//     {
//         dp[n][capacity] =  knapsackMemoization(wtArr,valArr,capacity,n-1);
//         return dp[n][capacity];
//     }
// }

int knapsackTopDownApproach(int *wtArr, int *valArr, int capacity,int n)
{
    int dp[n+1][capacity+1];
    for (int i = 0; i < n+1; i++)
    {
        for (int j = 0; j < capacity+1; j++)
        {
            if ((i == 0) || (j == 0))
            {
                dp[i][j] = 0;
                continue;
            }
            if (wtArr[i-1] <= j)
            {
                
                int choice1 = valArr[i-1]+dp[i-1][j-wtArr[i-1]];
                int choice2 = dp[i-1][j];
                dp[i][j] = max(choice1,choice2);
            }
            else if (wtArr[i-1] > j)
            {
                dp[i][j] =  dp[i-1][j];
            }
        }
    }

    return dp[n][capacity];
}

int main()
{
    int wtArr[4] = {1,3,4,5};
    int valArr[4] = {1,4,5,7};
    int capacity = 10;
    cout << knapsackRecursion(wtArr,valArr,capacity,4) << endl;

    // memset(dp,-1,sizeof(dp));
    // cout << knapsackMemoization(wtArr,valArr,capacity,4)<<endl;

    cout << knapsackTopDownApproach(wtArr,valArr,capacity,4) << endl;
}