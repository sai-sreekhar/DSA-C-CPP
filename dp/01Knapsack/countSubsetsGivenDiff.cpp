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
int countSubSetsGivenSumDP(int *arr, int requiredSum, int n)
{
    int dp[n + 1][requiredSum + 1];
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < requiredSum + 1; j++)
        {
            if (j == 0)
            {
                dp[i][j] = 1;
            }
            else if (i == 0)
            {
                dp[i][j] = 0;
            }
            else if (arr[i - 1] <= j)
            {
                dp[i][j] = dp[i - 1][j - arr[i - 1]] + dp[i - 1][j];
            }
            else if (arr[i - 1] > j)
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][requiredSum];
}

int main()
{
    int arr[4] = {1,1,2,3};
    int sum = 0;
    for (int i = 0; i < 4; i++)
    {
        sum += arr[i];
    }
    
    int givenDiff = 1;

    cout << countSubSetsGivenSumDP(arr,(sum+givenDiff)/2,4) << endl;
    return 0;
}