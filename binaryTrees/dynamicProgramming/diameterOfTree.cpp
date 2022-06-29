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

typedef struct NODE
{
    int data;
    struct NODE *leftChild;
    struct NODE *rightChild;
} Node;

int getDiameter(Node* node, int &res)
{
    if (node == nullptr)
    {
        return 0;
    }

    int left = getDiameter(node->leftChild,res);
    int right = getDiameter(node->rightChild,res);

    int temp = 1+max(left,right);
    res = max(res,1+left+right);

    return temp;
}

int main()
{
    
    return 0;
}