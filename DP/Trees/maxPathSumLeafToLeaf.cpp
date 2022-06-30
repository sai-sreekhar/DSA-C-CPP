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

typedef struct NODE
{
    int value;
    struct NODE *leftChild;
    struct NODE *rightChild;
} Node;

int getMaxPathSum(Node *node, int &res)
{
    if (node == nullptr)
    {
        return 0;
    }

    int left = getMaxPathSum(node->leftChild, res);
    int right = getMaxPathSum(node->rightChild, res);

    int temp = max(left, right) + node->value;
    if ((node->leftChild == nullptr) && (node->rightChild == nullptr))
    {
        int temp = max(max(left, right) + node->value, node->value);
    }

    int ans = max(temp,left + right + node->value);
    res = max(res, ans);

    return temp;
}

int main()
{

    return 0;
}