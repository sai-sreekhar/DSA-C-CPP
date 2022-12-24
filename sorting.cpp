#include <bits/stdc++.h>
#include <bits/stdc++.h>

using namespace std;

#define lli long long int
#define ONLINE_JUDGE
#define DEBUG

#ifdef DEBUG
#define TRACE(msg, ...) printTrace(__LINE__, __FILE__, msg, __VA_ARGS__)
#define PRINT_ARRAY(arr, n, type) myPrint<type>(arr, n)
#else
#define TRACE(msg, ...)
#define PRINT_ARRAY(arr, n, type)
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

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void insertionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (arr[j] > key && j >= 0)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIdx])
            {
                minIdx = j;
            }
        }
        if (minIdx != i)
        {
            int temp = arr[minIdx];
            arr[minIdx] = arr[i];
            arr[i] = temp;
        }
    }
}

int partition(int arr[], int low, int high)
{
    int i = low;
    int j = high;
    int pivot = arr[low];
    while (i < j)
    {
        while (pivot >= arr[i])
        {
            i++;
        }
        while (pivot < arr[j])
        {
            j--;
        }
        if (i < j)
        {
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[low], arr[j]);
    return j;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[left + i];
    }

    for (int j = 0; j < n2; j++)
    {
        R[j] = arr[mid + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {

        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

void heapify(int arr[], int n, int i)
{

    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void countingSort(int array[], int size)
{
    int resultArr[10];
    int count[10];
    int max = array[0];

    for (int i = 1; i < size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }

    for (int i = 0; i <= max; ++i)
    {
        count[i] = 0;
    }

    for (int i = 0; i < size; i++)
    {
        count[array[i]]++;
    }

    for (int i = 1; i <= max; i++)
    {
        count[i] += count[i - 1];
    }

    for (int i = size - 1; i >= 0; i--)
    {
        resultArr[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }

    for (int i = 0; i < size; i++)
    {
        array[i] = resultArr[i];
    }
}

void printArray(int array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("in.txt", "right", stdin);
    freopen("out.txt", "w", stdout);
#endif

    clock_t time_req;
    int n1 = 10;
    int n2 = 100;
    int n3 = 1000;
    int n4 = 10000;
    int n5 = 100000;
    int n6 = 200000;
    int matrix[7][6];

    for (int i = 0; i < 7; i++)
    {
        for (int k = 0; k < 6; k++)
        {
            matrix[i][k] = 0;
        }
    }

    int row = 0;
    int column = 0;

    int arr1[n1];
    for (int i = 0; i < n1; i++)
    {
        arr1[i] = rand() % n1;
    }

    int arr2[n2];
    for (int i = 0; i < n2; i++)
    {
        arr2[i] = rand() % n2;
    }

    int arr3[n3];
    for (int i = 0; i < n3; i++)
    {
        arr3[i] = rand() % n3;
    }

    int arr4[n4];
    for (int i = 0; i < n4; i++)
    {
        arr4[i] = rand() % n4;
    }

    int arr5[n5];
    for (int i = 0; i < n5; i++)
    {
        arr5[i] = rand() % n5;
    }

    int arr6[n6];
    for (int i = 0; i < n6; i++)
    {
        arr6[i] = rand() % n6;
    }

    time_req = clock();
    bubbleSort(arr1, n1);
    time_req = clock() - time_req;
    matrix[row][column] = time_req;
    row++;

    time_req = clock();
    bubbleSort(arr2, n2);
    time_req = clock() - time_req;
    matrix[row][column] = time_req;
    row++;

    time_req = clock();
    bubbleSort(arr3, n3);
    time_req = clock() - time_req;
    matrix[row][column] = time_req;
    row++;

    time_req = clock();
    bubbleSort(arr4, n4);
    time_req = clock() - time_req;
    matrix[row][column] = time_req;
    row++;

    time_req = clock();
    bubbleSort(arr5, n5);
    time_req = clock() - time_req;
    matrix[row][column] = time_req;
    row++;

    time_req = clock();
    bubbleSort(arr6, n6);
    time_req = clock() - time_req;
    matrix[row][column] = time_req;
    row++;

    row++;
    column = 0;
    time_req = clock();
    selectionSort(arr1, n1);
    time_req = clock() - time_req;
    matrix[row][column] = time_req;
    row++;

    time_req = clock();
    selectionSort(arr2, n2);
    time_req = clock() - time_req;
    matrix[row][column] = time_req;
    row++;

    time_req = clock();
    selectionSort(arr3, n3);
    time_req = clock() - time_req;
    matrix[row][column] = time_req;
    row++;

    time_req = clock();
    selectionSort(arr4, n4);
    time_req = clock() - time_req;
    matrix[row][column] = time_req;
    row++;

    time_req = clock();
    selectionSort(arr5, n5);
    time_req = clock() - time_req;
    matrix[row][column] = time_req;
    row++;

    time_req = clock();
    selectionSort(arr6, n6);
    time_req = clock() - time_req;
    matrix[row][column] = time_req;
    row++;

    row++;
    column = 0;
    time_req = clock();
    insertionSort(arr1, n1);
    time_req = clock() - time_req;
    matrix[row][column] = time_req;
    row++;

    time_req = clock();
    insertionSort(arr2, n2);
    time_req = clock() - time_req;
    matrix[row][column] = time_req;
    row++;

    time_req = clock();
    insertionSort(arr3, n3);
    time_req = clock() - time_req;
    matrix[row][column] = time_req;
    row++;

    time_req = clock();
    insertionSort(arr4, n4);
    time_req = clock() - time_req;
    matrix[row][column] = time_req;
    row++;

    time_req = clock();
    insertionSort(arr5, n5);
    time_req = clock() - time_req;
    matrix[row][column] = time_req;
    row++;

    time_req = clock();
    insertionSort(arr6, n6);
    time_req = clock() - time_req;
    matrix[row][column] = time_req;
    row++;

    row++;
    column = 0;
    time_req = clock();
    mergeSort(arr1, 0, n1 - 1);
    time_req = clock() - time_req;
    matrix[row][column] = time_req;
    row++;

    time_req = clock();
    mergeSort(arr2, 0, n2 - 1);
    time_req = clock() - time_req;
    matrix[row][column] = time_req;
    row++;

    time_req = clock();
    mergeSort(arr3, 0, n3 - 1);
    time_req = clock() - time_req;
    matrix[row][column] = time_req;
    row++;

    time_req = clock();
    mergeSort(arr4, 0, n4 - 1);
    time_req = clock() - time_req;
    matrix[row][column] = time_req;
    row++;

    time_req = clock();
    mergeSort(arr5, 0, n5 - 1);
    time_req = clock() - time_req;
    matrix[row][column] = time_req;
    row++;

    time_req = clock();
    mergeSort(arr6, 0, n6 - 1);
    time_req = clock() - time_req;
    matrix[row][column] = time_req;
    row++;

    row++;
    column = 0;
    time_req = clock();
    quickSort(arr1, 0, n1 - 1);
    time_req = clock() - time_req;
    matrix[row][column] = time_req;
    row++;

    time_req = clock();
    quickSort(arr2, 0, n2 - 1);
    time_req = clock() - time_req;
    matrix[row][column] = time_req;
    row++;

    time_req = clock();
    quickSort(arr3, 0, n3 - 1);
    time_req = clock() - time_req;
    matrix[row][column] = time_req;
    row++;

    time_req = clock();
    quickSort(arr4, 0, n4 - 1);
    time_req = clock() - time_req;
    matrix[row][column] = time_req;
    row++;

    time_req = clock();
    quickSort(arr5, 0, n5 - 1);
    time_req = clock() - time_req;
    matrix[row][column] = time_req;
    row++;

    time_req = clock();
    quickSort(arr6, 0, n6 - 1);
    time_req = clock() - time_req;
    matrix[row][column] = time_req;
    row++;

    row++;
    column = 0;
    time_req = clock();
    heapSort(arr1, n1);
    time_req = clock() - time_req;
    matrix[row][column] = time_req;
    row++;

    time_req = clock();
    heapSort(arr2, n2);
    time_req = clock() - time_req;
    matrix[row][column] = time_req;
    row++;

    time_req = clock();
    heapSort(arr3, n3);
    time_req = clock() - time_req;
    matrix[row][column] = time_req;
    row++;

    time_req = clock();
    heapSort(arr4, n4);
    time_req = clock() - time_req;
    matrix[row][column] = time_req;
    row++;

    time_req = clock();
    heapSort(arr5, n5);
    time_req = clock() - time_req;
    matrix[row][column] = time_req;
    row++;

    time_req = clock();
    heapSort(arr6, n6);
    time_req = clock() - time_req;
    matrix[row][column] = time_req;
    row++;

    row++;
    column = 0;
    time_req = clock();
    countingSort(arr1, n1);
    time_req = clock() - time_req;
    matrix[row][column] = time_req;
    row++;

    time_req = clock();
    countingSort(arr2, n2);
    time_req = clock() - time_req;
    matrix[row][column] = time_req;
    row++;

    time_req = clock();
    countingSort(arr3, n3);
    time_req = clock() - time_req;
    matrix[row][column] = time_req;
    row++;

    time_req = clock();
    countingSort(arr4, n4);
    time_req = clock() - time_req;
    matrix[row][column] = time_req;
    row++;

    time_req = clock();
    countingSort(arr5, n5);
    time_req = clock() - time_req;
    matrix[row][column] = time_req;
    row++;

    time_req = clock();
    countingSort(arr6, n6);
    time_req = clock() - time_req;
    matrix[row][column] = time_req;
    row++;

    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            cout << matrix[i][j] << " ";
        }
    }

    return 0;
}