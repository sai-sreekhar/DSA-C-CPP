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

typedef pair<int,int> pi;

int main()
{
    int arr[5] = {5,6,7,8,9};
    int len = 5;
    int k = 3;
    int num = 7;

    priority_queue<pi> maxHeap;
    
    for (int i = 0; i < len; i++)
    {
        maxHeap.push({abs(arr[i]-num),arr[i]});

        if (maxHeap.size() > k)
        {
            maxHeap.pop();
        }
        
    };

    while (maxHeap.size() != 0)
    {
        cout << maxHeap.top().second << endl;
        maxHeap.pop();
    }
    
    return 0;
}