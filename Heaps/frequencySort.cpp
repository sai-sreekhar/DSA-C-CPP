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

struct myComp {
    constexpr bool operator()(pair<int, int> const& a,pair<int, int> const& b)
    {
        if(a.first > b.first)
        {
            return false;
        }

        if(a.first == b.first)
        {
            if (a.second > b.second)
            {
                return true;
            }
            else
            {
                return false;
            } 
        }
        
    return true;

    }
};

int main()
{
    int arr[7] = {1,1,1,3,2,2,4};
    int len = 7;
    int k = 2;

    unordered_map<int,int> mp;
    priority_queue<pi,vector<pi>,myComp> maxHeap;
    
    for (int i = 0; i < len; i++)
    {
        mp[arr[i]] ++;
    };

    for (auto i = mp.begin(); i != mp.end(); i++)
    {
        maxHeap.push({i->second,i->first});        
    }

    while (maxHeap.size() != 0)
    {
        for (int i = 0; i < maxHeap.top().first; i++)
        {
            cout << maxHeap.top().second << endl;
        }
        maxHeap.pop();
    }

    return 0;
}