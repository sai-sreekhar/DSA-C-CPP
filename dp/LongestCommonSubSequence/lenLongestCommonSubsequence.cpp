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
    char buffer[1024+2] = { 0 };

    snprintf(buffer, sizeof(buffer), "%s(%d) : " , fileName, line);
    int stringLength = strnlen(buffer,1024);
    int remainingBufferSize = 1024 - stringLength;
    va_start(args, msg);
    vsnprintf(buffer+stringLength,remainingBufferSize, msg, args);
    va_end(args);
    cout << buffer << flush;
}

int max(int a, int b)
{
    return a > b ? a : b;
}

int LenlongestCommonSubsequenceRecursive(string x, string y,int lenX,int lenY)
{
    if((lenX == 0) || (lenY == 0))
    {
        return 0;
    }
    else if (x[lenX-1] == y[lenY-1])
    {
        return 1+LenlongestCommonSubsequenceRecursive(x,y,lenX-1,lenY-1);
    }
    else
    {
        return max(LenlongestCommonSubsequenceRecursive(x,y,lenX,lenY-1) , LenlongestCommonSubsequenceRecursive(x,y,lenX-1,lenY));
    }
    
}

int LenlongestCommonSubsequenceMemoize(string x, string y,int lenX,int lenY)
{
    int dp[lenX+1][lenY+1];
    memset (dp,-1,sizeof(dp));

    if((lenX == 0) || (lenY == 0))
    {
        return 0;
    }
    if (dp[lenX][lenY] != -1)
    {
        return dp[lenX][lenY];
    }
    
    else if (x[lenX-1] == y[lenY-1])
    {
        dp[lenX][lenY] = 1+LenlongestCommonSubsequenceMemoize(x,y,lenX-1,lenY-1);
        return dp[lenX][lenY];
    }
    else
    {
        dp[lenX][lenY] =  max(LenlongestCommonSubsequenceMemoize(x,y,lenX,lenY-1) , LenlongestCommonSubsequenceMemoize(x,y,lenX-1,lenY));
        return dp[lenX][lenY];
    }
    
}

int LenlongestCommonSubsequenceDP(string x, string y,int lenX,int lenY)
{
    int dp[lenX+1][lenY+1];
    
    for (int i = 0; i < lenX+1; i++)
    {
        dp[i][0] = 0;
    }
    
    for (int j = 0; j < lenY+1; j++)
    {
        dp[0][j] = 0;
    }
    
    for (int i = 1; i < lenX+1; i++)
    {
        for (int j = 1; j < lenY+1; j++)
        {
             if (x[i-1] == y[j-1])
            {
                dp[i][j] = 1+dp[i-1][j-1];
            }
            else
            {
                dp[i][j] =  max(dp[i][j-1] , dp[i-1][j]);
            }
        }
    }

    return dp[lenX][lenY];
}

int main()
{
    string x = "abcdgh";
    string y = "abedfgr";
    cout << LenlongestCommonSubsequenceRecursive(x,y,x.length(),y.length()) << endl;
    cout << LenlongestCommonSubsequenceMemoize(x,y,x.length(),y.length()) << endl;
    cout << LenlongestCommonSubsequenceDP(x,y,x.length(),y.length()) << endl;
    return 0;
}