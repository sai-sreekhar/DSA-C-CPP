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

int fibonacci(int n,int *dp)
{
    if (n == 0)
    {
        return 0;
    }

    if (n == 1)
    {
        return 1;
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }

    dp[n] = fibonacci(n-1,dp) + fibonacci(n-2,dp);
    return dp[n];
};

int fib(int n)
{
    int a[n+1];
    a[0] = 0;
    a[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        a[i] = a[i-1] + a[i-2];
    }

    return a[n];
}

int main()
{

    int dp[10];
    for (int i = 0; i < 10; i++)
    {
        dp[i] = -1;
    }
    
    cout << fibonacci(6,dp) << endl;
    cout << fib(6) << endl;
    // for (int i = 0; i < 10; i++)
    // {
    //     cout << dp[i] << endl;
    // }
    
    return 0;
}