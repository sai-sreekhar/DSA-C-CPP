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
    char buffer[1024+2] = { 0 };

    snprintf(buffer, sizeof(buffer), "%s(%d) : " , fileName, line);
    int stringLength = strnlen(buffer,1024);
    int remainingBufferSize = 1024 - stringLength;
    va_start(args, msg);
    vsnprintf(buffer+stringLength,remainingBufferSize, msg, args);
    va_end(args);
    cout << buffer << flush;
}

int maxProfitRodCuttingDP(int *lenArr, int *priceArr, int totalLen,int n)
{
    int dp[n+1][totalLen+1];
    for (int i = 0; i < n+1; i++)
    {
        for (int j = 0; j < totalLen+1; j++)
        {
            if ((i == 0) || (j == 0))
            {
                dp[i][j] = 0;
                continue;
            }
            if (lenArr[i-1] <= j)
            {
                
                int choice1 = priceArr[i-1]+dp[i][j-lenArr[i-1]];
                int choice2 = dp[i-1][j];
                dp[i][j] = max(choice1,choice2);
            }
            else if (lenArr[i-1] > j)
            {
                dp[i][j] =  dp[i-1][j];
            }
        }
    }

    return dp[n][totalLen];
}

int main()
{
    int lenArr[8] = {1,2,3,4,5,6,7,8};
    int priceArr[8] = {1,5,8,9,10,17,17,20};
    int totalLen = 8;
    cout << maxProfitRodCuttingDP(lenArr,priceArr,8,8) << endl;
    return 0;
}