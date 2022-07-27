#include <iostream>
#include<bits/stdc++.h>
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int arr[7] = {6,2,5,4,5,1,6};
    int len = 7;

    vector<int> left;
    stack<pair<int,int>> s;
    
    for (int i = 0; i < len; i++)
    {
        if (s.empty())
        {
            left.push_back(-1);
        }
        else if ((s.size() > 0) && (s.top().first < arr[i]))
        {
            left.push_back(s.top().second);
        }
        else if ((s.size() > 0) && (s.top().first >= arr[i]))
        {
            while ((s.size() > 0) && (s.top().first >= arr[i]))
            {
                s.pop();
            }
            if (s.size() == 0)
            {
                left.push_back(-1);
            }
            else
            {
                left.push_back(s.top().second);
            }
        }
        s.push({arr[i],i});
    }

    vector<int> right;
    stack<pair<int,int>> s1;
    
    for (int i = len; i >=0; i--)
    {
        if (s1.empty())
        {
            right.push_back(len);
        }
        else if ((s1.size() > 0) && (s1.top().first < arr[i]))
        {
            right.push_back(s1.top().second);
        }
        else if ((s1.size() > 0) && (s1.top().first >= arr[i]))
        {
            while ((s1.size() > 0) && (s1.top().first >= arr[i]))
            {
                s1.pop();
            }
            if (s1.size() == 0)
            {
                right.push_back(len);
            }
            else
            {
                right.push_back(s1.top().second);
            }
        }
        s1.push({arr[i],i});
    }

    int width[len];
    for (int i = 0; i < left.size(); i++)
    {
        width[i] = right[i]-left[i]-1;
    }

    int area[len];
    for (int i = 0; i < left.size(); i++)
    {
        area[i] = width[i]*arr[i];
    }

    //return max in area arr
    return 0;
}