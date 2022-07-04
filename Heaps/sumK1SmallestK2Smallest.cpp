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
int kthSmallest(int *arr, int n, int k)
{
    priority_queue<int> maxHeap;
    for (int i = 0; i < n; i++)
    {
        maxHeap.push(arr[i]);
        if (maxHeap.size() > k)
        {
            maxHeap.pop();
        }    
    }
    return maxHeap.top();
}
int main()
{
    int n = 6;
    int arr[n] = {1,3,12,5,15,11};
    int k1 = 3;
    int k2 = 6;

    int k1Num = kthSmallest(arr,n,k1);
    int k2Num = kthSmallest(arr,n,k2);

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if ((arr[i] > k1Num) && (arr[i] < k2Num))
        {
            sum += arr[i];
        }
    }
    
    cout << sum << endl;
    return 0;
}