#include <bits/stdc++.h>
using namespace std;

#define DEBUG

#ifdef DEBUG
#define TRACE(msg, ...) printTrace(__LINE__, __FILE__, msg, __VA_ARGS__)
#else
#define TRACE(msg, ...)
#endif

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
    cout << buffer << "\n"
         << flush;
}

void heapify(int arr[], int n, int k)
{
    int smallest = k;
    int left = 2 * k + 1;
    int right = 2 * k + 2;

    if (left < n && arr[left] < arr[smallest])

        smallest = left;

    if (right < n && arr[right] < arr[smallest])

        smallest = right;

    if (smallest != k)
    {
        swap(arr[k], arr[smallest]);
        heapify(arr, n, smallest);
    }
}

void heapify2(int arr[], int n, int k)
{
    int root = (k - 1) / 2;
    int child = k;

    if (root >= 0 && child >= 0 && arr[root] > arr[child])
    {
        swap(arr[root], arr[child]);
        heapify2(arr, n, root);
    }
}

void printArray(int arr[], int n)
{
    for (int k = 0; k < n; k++)
    {
        cout << arr[k] << " ";
    }
    cout << "\n";
}

void heapSortBottomUp(int arr[], int n)
{

    for (int k = n / 2 - 1; k >= 0; k--)
    {
        heapify(arr, n, k);
    }

    for (int k = n - 1; k >= 0; k--)
    {

        swap(arr[0], arr[k]);
        heapify(arr, k, 0);
    }
}

void heapSortTopDown(int *arr, int n)
{
    for (int k = 0; k < n; k++)
    {
        heapify2(arr, k + 1, k);
    }

    for (int k = n - 1; k >= 0; k--)
    {
        swap(arr[0], arr[k]);
        heapify(arr, k, 0);
    }
}

int main()
{
    int n;
    cout << "Enter the number of elements to sort: ";
    cin >> n;
    int array1[n];
    int array2[n];

    cout << "Enter the Elements to sort: ";
    for (int i = 0; i < n; i++)
    {
        cin >> array1[i];
        array2[i] = array1[i];
    }

    heapSortBottomUp(array1, n); // sorting array1
    cout << "Sorted Array is (Bottom Up Approach): ";
    printArray(array1, n);

    heapSortTopDown(array2, n); // sorting array2
    cout << "Sorted Array is (Top Down Approach): ";
    printArray(array2, n);
}
