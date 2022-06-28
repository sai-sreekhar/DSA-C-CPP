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

// int coinChangeMaxWaysDP(int *coinArr, int requiredSum, int n)
// {
//     int dp[n + 1][requiredSum + 1];
//     for (int j = 0; j < requiredSum + 1 ; j++)
//     {
//         dp[0][j] = INT_MAX -1;
//     }
//     for (int i = 0; i < n + 1 ; i++)
//     {
//         dp[i][0] = 1;
//     }

//     for (int j = 1; j < requiredSum + 1; j++)
//     {
//         if (j % coinArr[0] == 0)
//         {
//             dp[1][j] = j/coinArr[0];
//         }
//         else
//         {
//             dp[1][j] = INT_MAX-1;
//         }
//     }

//     for (int i = 2; i < n+1; i++)
//     {
//         for (int j = 1; j < requiredSum+1; j++)
//         {
//             if (coinArr[i - 1] <= j)
//             {
//                 dp[i][j] = min(dp[i][j - coinArr[i - 1]]+1, dp[i - 1][j]);
//             }
//             else
//             {
//                 dp[i][j] = dp[i - 1][j];
//             }
//         }

//     }

//     return dp[n][requiredSum];
// }
#include <bits/stdc++.h>
using namespace std;

int coins[] = {1, 2, 3, 4, 5};
int dp[1000] = {0};
int minCoins(int N, int M)
{
    // Initializing all values to INT_MAX i.e. minimum coins to make any
    // amount of sum is INT_MAX
    for (int i = 0; i <= N; i++)
        dp[i] = INT_MAX;

    // Base case
    // Minimum coins to make sum = 0 cents is 0
    dp[0] = 0;

    // Iterating in the outer loop for possible values of sum between 1 to N
    // Since our final solution for sum = N might depend upon any of these values
    for (int i = 1; i <= N; i++)
    {
        // Inner loop denotes the index of coin array.
        // For each value of sum, to obtain the optimal solution.
        for (int j = 0; j < M; j++)
        {
            // i —> sum
            // j —> next coin index
            // If we can include this coin in our solution
            if (coins[j] <= i)
            {
                // Solution might include the newly included coin
                dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
            }
        }
    }
    return dp[N];
}

int main()
{
    int coinArr[3] = {3, 5, 2};
    int requiredSum = 4;
    return 0;
}



/* -------------------------------Recursive Solution-------------------------------------------------------------

#include<bits/stdc++.h> 
using namespace std;

// Recursive Function
int minCoins(int coins[], int m, int N)
{
  // base case
  if (N == 0)
    return 0;
  
  // Initialize result
  int res = INT_MAX;
  
  // Try every coin that has smaller value than m
  for (int i=0; i<m; i++)
  {
    if (coins[i] <= N)
    {
      int sub_res = 1 + minCoins(coins, m, N-coins[i]);
      // see if result can minimized
      if (sub_res < res)
        res = sub_res;
    }
  }
  return res;
}

int main() {
  int coins[] = {1,2,3,4,5};
  int sum = 11; 
  int total_coins = 5;
  cout << minCoins(coins,total_coins,sum);
}

//link-> https://www.educative.io/answers/minimum-coin-change-in-cpp---a-dynamic-programming-question

------------------------------------------------------------------*/

