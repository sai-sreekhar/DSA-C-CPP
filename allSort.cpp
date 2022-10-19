#include <bits/stdc++.h>

using namespace std;

void swap(int *a, int *b)
{
  int t = *a;
  *a = *b;
  *b = t;
}

void bubbleSort(int *arr, int n)
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

void insertionSort(int *arr, int n)
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

void selectionSort(int *arr, int n)
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

int partition(int *arr, int low, int high)
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

void quickSort(int *arr, int low, int high)
{
  if (low < high)
  {
    int pi = partition(arr, low, high);
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}

void merge(int arr[], int l, int m, int r)
{
  int n1 = m - l + 1;
  int n2 = r - m;

  int L[n1], R[n2];

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

void mergeSort(int arr[], int l, int r)
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
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif

  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }

  cout << "\n";

  // bubbleSort(arr, n);
  // insertionSort(arr, n);
  // selectionSort(arr, n);
  // quickSort(arr, 0, n - 1);
  cout << "After Sorting";
  mergeSort(arr, 0, n - 1);
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }

  return 0;
}