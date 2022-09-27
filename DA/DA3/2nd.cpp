#include <bits/stdc++.h>

using namespace std;

void swap(string *x, string *y)
{
    string temp = *x;
    *x = *y;
    *y = temp;
}

void merge(string *arr, int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    string L[n1], R[n2];

    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[l + i];
    }

    for (int j = 0; j < n2; j++)
    {
        R[j] = arr[m + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = l;
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

void mergeSort(string *arr, int l, int r)
{
    if (l < r)
    {

        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

int main()
{
    clock_t start, end;

    start = clock();

    int n;
    cout << "Enter the length of the string: ";
    cin >> n;
    string arr[n];
    int flag = 0;
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    mergeSort(arr, 0, n - 1);

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
