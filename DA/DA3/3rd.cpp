#include <bits/stdc++.h>
using namespace std;

void swap(string *a, string *b)
{
    string t = *a;
    *a = *b;
    *b = t;
}

int partition(string *arr, int low, int high)
{
    string pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(string *arr, int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    clock_t start, end;

    start = clock();

    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    string arr[n];
    int flag = 0;
    
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the String in position " << i+1 << ": ";
        cin >> arr[i];
    }

    quickSort(arr, 0, n - 1);

    cout << "Sorted Order: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";

    end = clock();

    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Time taken by program is : " << fixed
         << time_taken << setprecision(5);
    cout << " sec " << endl;
    return 0;
}
