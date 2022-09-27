#include <iostream>
using namespace std;

void display(string a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}

void swap(string *x, string *y)
{
    string temp = *x;
    *x = *y;
    *y = temp;
}

int partition(string a[], int l, int h)
{
    string pivot = a[l];
    int i = l, j = h;
    do
    {
        do
        {
            i++;
        } while (a[i] <= pivot);
        do
        {
            j--;
        } while (a[j] > pivot);
        if (i < j)
            swap(&a[i], &a[j]);
    } while (i < j);

    swap(&a[l], &a[j]);
    return j;
}

void quicksort(string a[], int l, int h)
{
    int j;
    if (l < h)
    {
        j = partition(a, l, h);
        quicksort(a, l, j);
        quicksort(a, j + 1, h);
    }
}

int main()
{
    int n;
    cout << "Enter the length of the array: ";
    cin >> n;
    string a[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    quicksort(a, 0, n);
    display(a, n);
    return 0;
}