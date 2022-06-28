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

int min(int a, int b)
{
    // if (b == 0)
    // {
    //    return a;
    // }

    // if ( a == 0)
    // {
    //     return b;
    // }
    
    return a < b ? a : b;
}
int getTotalWays(int *coinsArr, int requiredSum, int noOfCoins)
{
    int cols = requiredSum + 1;
    int rows = noOfCoins;

    int dp[rows][cols];
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (j == 0)
            {
                dp[i][j] = 1;
            }
            else if (i == 0 && j == 1)
            {
                dp[0][1] = 0;
            }
            else if (coinsArr[i] > j)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                if (i == 0)
                {
                    dp[i][j] = dp[i][j - coinsArr[i]];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - coinsArr[i]];
                }
            }
        }
    }

    // for (int i = 0; i < rows; i++)
    // {
    //     for (int j = 0; j < requiredSum; j++)
    //     {
    //         cout << dp[i][j] << endl;

    //     }

    // }

    return dp[rows - 1][requiredSum];
}

void displayMinCoinsDenominations(int rows,int cols,int**dp,int* coinsArr,int min)
{
    if ( cols == 1)
    {
        return;
    }
    
    int newI = rows-1; 
    for (int i = rows-2; i > 0; i--)
    {
        if (dp[i][cols-1] > min)
        {
            break;
        }
        else
        {
            newI = i;
            
        }
    }
    cout << coinsArr[newI]<<endl;
    int newJ = (cols-1) - coinsArr[newI];
    int newRows = newI + 1;
    int newCols = newJ + 1;
    
    displayMinCoinsDenominations(newRows,newCols,dp,coinsArr,dp[newI][newJ]);
}

int getMinNoOfCoins(int *coinsArr, int requiredSum, int noOfCoins)
{
    int cols = requiredSum + 1;
    int rows = noOfCoins;
    
    // int **dp = (int **)malloc(rows * sizeof(int *));
    // for (int r = 0; r < cols; r++) 
    // {
    //     dp[r] = (int *)malloc(cols * sizeof(int));
    // }

    int dp[rows][cols];

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (j == 0)
            {
                dp[i][j] = 0;
            }
            else if (i == 0)
            {
                if (j % coinsArr[i] != 0)
                {
                    dp[i][j] = 0;
                }
                else
                {
                    dp[i][j] = (j / coinsArr[i]);
                }
            }
            else if (coinsArr[i] > j)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = min(dp[i - 1][j], j / coinsArr[i] + dp[i][j % coinsArr[i]]);
            }
        }
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << dp[i][j] << " ";

        }
        cout << "\n";
    }

    // int min = dp[rows-1][cols-1];
    // displayMinCoinsDenominations(rows,cols,dp,coinsArr,min);

    return dp[rows - 1][cols - 1];
}

int main()
{
    // int coinsArr[4] = {2,3,5,10};
    // int requiredSum = 15;
    // cout << getTotalWays(coinsArr,requiredSum,4);

    int coinsArr[3] = {4,10,25};
    int requiredSum = 41;
    cout << getMinNoOfCoins(coinsArr, requiredSum, 3)<<endl;;
    return 0;
}