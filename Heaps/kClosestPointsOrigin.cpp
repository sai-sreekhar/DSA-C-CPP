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

typedef pair<int,pair<int,int>> ppi;

int main()
{
    int n= 4;
    int arr[n][2] = {{1,3},{-2,2},{5,8},{0,1}};
    int k = 2;
    priority_queue<ppi> maxHeap;

    for (int i = 0; i < n; i++)
    {
        maxHeap.push({arr[i][0]*arr[i][0]+arr[i][1]*arr[i][1],{arr[i][0],arr[i][1]}});
        if (maxHeap.size() > k)
        {
            maxHeap.pop();
        }
    }

    while (maxHeap.size() != 0)
    {
        pair<int,int> p = maxHeap.top().second;
        cout << p.first << " " << p.second << endl;
        maxHeap.pop();
    }

    return 0;
}