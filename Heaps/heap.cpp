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

class BinaryHeap
{
private:
    const static int MAX_SIZE = 15;
    int heap[MAX_SIZE];
    int size;

public:
    BinaryHeap()
    {
        size = 0;
    }

    static int parent(int i)
    {
        return (i - 1) / 2;
    }

    static int leftChild(int i)
    {
        return 2 * i + 1;
    }

    static int rightChild(int i)
    {
        return 2 * i + 2;
    }

    static void swap(int *x, int *y)
    {
        int temp = *x;
        *x = *y;
        *y = temp;
    }

    void insert(int data)
    {
        if (size >= MAX_SIZE)
        {
            cout << "The heap is full. Cannot insert" << endl;
            return;
        }

        heap[size] = data;
        size = size + 1;

        int i = size - 1;
        while (i != 0 && heap[BinaryHeap::parent(i)] < heap[i])
        {
            BinaryHeap::swap(&heap[BinaryHeap::parent(i)], &heap[i]);
            i = BinaryHeap::parent(i);
        }
    }


    void deleteRoot()
    {
        int lastElement = heap[size - 1];
        heap[0] = lastElement;
        size = size - 1;
        maxHeapify(0);
    }

    void maxHeapify(int i)
    {
        int left = BinaryHeap::leftChild(i);
        int right = BinaryHeap::rightChild(i);

        int largest = i;

        if (left <= size && heap[left] > heap[largest])
        {
            largest = left;
        }

        if (right <= size && heap[right] > heap[largest])
        {
            largest = right;
        }

        if (largest != i)
        {
            int temp = heap[i];
            heap[i] = heap[largest];
            heap[largest] = temp;
            maxHeapify(largest);
        }
    }

    int getMax()
    {
        return heap[0];
    }

    int extractMax()
    {
        int maxItem = heap[0];
        heap[0] = heap[size - 1];
        size = size - 1;
        maxHeapify(0);
        return maxItem;
    }

    void printHeap()
    {
        for (int i = 0; i < size; i++)
        {
            cout << heap[i] << endl;
        }
    }
};

int main()
{
    BinaryHeap heap;
    heap.insert(15);
    heap.insert(20);
    heap.insert(7);
    heap.insert(9);
    heap.insert(30);
    heap.deleteRoot();
    heap.printHeap();
    return 0;
}
