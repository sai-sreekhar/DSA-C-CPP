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

int mcmRecursion(string x, int i, int j, bool isTrue)
{
    int ans = 0;
    if (i > j)
    {
        return false;
    }
    if (i == j)
    {
        if (isTrue == true)
        {
            return x[i] == 'T';
        }
        else
        {
            return x[i] == 'F';
        }
    }

    for (int k = i + 1; k <= j - 1; k = k + 2)
    {
        int leftTrue = mcmRecursion(x, i, k - 1, 1);
        int leftFalse = mcmRecursion(x, i, k - 1, 0);
        int rightTrue = mcmRecursion(x, k + 1, j, 1);
        int rightFalse = mcmRecursion(x, k + 1, j, 0);

        if (x[k] == '&')
        {
            if (isTrue == 1)
            {
                ans += (leftTrue * rightTrue);
            }
            else
            {
                ans += ((leftFalse * rightFalse) + (leftFalse * rightTrue) + (leftTrue * rightFalse));
            }
        }
        else if (x[k] == '|')
        {
            if (isTrue == 1)
            {
                ans += ((leftTrue * rightTrue) + (leftFalse * rightTrue) + (leftTrue * rightFalse));
            }
            else
            {
                ans += (leftFalse * rightFalse);
            }
        }
        else if (x[k] == '^')
        {
            if (isTrue == 1)
            {
                ans += ((leftTrue * rightFalse) + (rightTrue * leftFalse));
            }
            else
            {
                ans += ((leftFalse * rightFalse) + (leftTrue * rightTrue));
            }
        }
    }

    return ans;
}

int dp[101][101][2];

int mcmMemoization(string s, int i, int j, int isTrue)
{
    if (i > j)
        return false;
    if (i == j)
    {
        if (isTrue == 1)
            return s[i] == 'T';
        else
            return s[i] == 'F';
    }

    if (dp[i][j][isTrue] != -1)
    {
        return dp[i][j][isTrue];
    }

    int ans = 0;
    for (int k = i + 1; k <= j - 1; k = k + 2)
    {
        int leftF, leftT, rightT, rightF;
        if (dp[i][k - 1][1] == -1)
        {
            leftT = mcmMemoization(s, i, k - 1, 1);
        }
        else
        {
            leftT = dp[i][k - 1][1];
        }

        if (dp[k + 1][j][1] == -1)
        {
            rightT = mcmMemoization(s, k + 1, j, 1);
        }
        else
        {
            rightT = dp[k + 1][j][1];
        }

        if (dp[i][k - 1][0] == -1)
        {
            leftF = mcmMemoization(s, i, k - 1, 0);
        }
        else
        {
            leftF = dp[i][k - 1][0];
        }

        if (dp[k + 1][j][0] == -1)
        {
            rightF = mcmMemoization(s, k + 1, j, 0);
        }
        else
        {
            rightF = dp[k + 1][j][0];
        }

        if (s[k] == '&')
        {
            if (isTrue == 1)
                ans += leftT * rightT;
            else
                ans += leftF * rightF + leftT * rightF + leftF * rightT;
        }
        else if (s[k] == '|')
        {
            if (isTrue == 1)
                ans += leftT * rightT + leftT * rightF + leftF * rightT;
            else
                ans = ans + leftF * rightF;
        }
        else if (s[k] == '^')
        {
            if (isTrue == 1)
                ans = ans + leftF * rightT + leftT * rightF;
            else
                ans = ans + leftT * rightT + leftF * rightF;
        }
        dp[i][j][isTrue] = ans;
    }
    return ans;
}

int main()
{
    string symbols = "TTFT";
    string operators = "|&^";
    string s;
    int j = 0;

    for (int i = 0; i < symbols.length(); i++)
    {
        s.push_back(symbols[i]);
        if (j < operators.length())
            s.push_back(operators[j++]);
    }

    int n = s.length();

    memset(dp, -1, sizeof(dp));
    cout << s << endl;
    cout << mcmRecursion(s, 0, n - 1, 1) << endl;
    cout << mcmMemoization(s, 0, n - 1, 1) << endl;
    return 0;
}