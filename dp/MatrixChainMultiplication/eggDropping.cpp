#include <iostream>
#include <bits/stdc++.h>
#include <cstdlib>
#include <new>
#include <cmath>
#include <cstring>
#include <cstdbool>
#include <cctype>
#include <cstdarg>
#include <climits>

#define DEBUG

#ifdef DEBUG
#define TRACE(msg, ...) printTrace(__LINE__, __FILE__, msg, __VA_ARGS__)
#else
#define TRACE(msg, ...)
#endif

#define MAX 1000

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

int eggDroppingRecursion(int e, int f)
{
    if ((f == 0) || (f == 1))
    {
        return f;
    }
    if (e == 1)
    {
        return f;
    }

    int min = INT_MAX;
    int res;
    for (int k = 1; k <= f; k++)
    {
        int a = eggDroppingRecursion(e - 1, f - 1);
        int b = eggDroppingRecursion(e, f - k);
        res = a > b ? a : b;
        if (res < min)
            min = res;
    }

    return min + 1;
}

int memo[MAX][MAX];

int eggDropMemoize(int e, int f)
{

    if (memo[e][f] != -1)
    {
        return memo[e][f];
    }

    if (f == 1 || f == 0)
        return f;

    if (e == 1)
        return f;

    int min = INT_MAX, res;

    for (int k = 1; k <= f; k++)
    {
        int a = eggDropMemoize(e - 1, f - 1);
        int b = eggDropMemoize(e, f - k);

        //here u can optimize code by checking with -1
        res = a > b ? a : b;
        if (res < min)
            min = res;
    }

    memo[e][f] = min + 1;
    return min + 1;
}

int main()
{
    memset( memo, -1,MAX * MAX * sizeof( int ) );
    int n = 2, k = 36;
    printf("%d",eggDropMemoize(n, k));
    return 0;
}