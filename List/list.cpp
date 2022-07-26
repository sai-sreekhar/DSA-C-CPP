//SAI SREEKAR

#include <iostream>

using namespace std;

#define MAX_SIZE 100

void insert(int *arr, int pos, int val, int *lastIdx)
{
    if (*lastIdx == -1)
    {
        if (pos != 1)
        {
            cout << "Incorrect Position";
            return;
        }

        arr[pos - 1] = val;
        *lastIdx = 0;
        return;
    }

    if (*lastIdx == pos - 2)
    {
        arr[pos - 1] = val;
        *lastIdx = *lastIdx + 1;
        return;
    }

    for (int i = *lastIdx + 1; i >= pos; i--)
    {
        arr[i] = arr[i - 1];
    }

    arr[pos - 1] = val;
    *lastIdx = *lastIdx + 1;
    return;
}

int search(int *arr, int val, int *lastIdx)
{
    int pos = -1;
    for (int i = 0; i <= *lastIdx; i++)
    {
        if (arr[i] == val)
        {
            pos = i;
            break;
        }
    }

    return pos;
}

void remove(int *arr, int val, int *lastIdx)
{
    if (*lastIdx == -1)
    {
        cout << "List is Empty"
             << "\n";
        return;
    }

    int pos = search(arr, val, lastIdx);
    if (pos == -1)
    {
        cout << "Element " << val << " not found in list to delete"
             << "\n";
        return;
    }

    for (int i = pos; i <= *lastIdx - 1; i++)
    {
        arr[i] = arr[i + 1];
    }

    arr[*lastIdx] = -1;
    *lastIdx = *lastIdx - 1;
}

void display(int *arr, int *lastIdx)
{
    for (int i = 0; i <= *lastIdx; i++)
    {
        cout << arr[i] << endl;
    }
    return;
}

int main()
{
    int arr[MAX_SIZE];
    int lastIdx = -1;

    insert(arr, 1, 10, &lastIdx);  // 10
    insert(arr, 2, 20, &lastIdx);  // 10 20
    insert(arr, 3, 30, &lastIdx);  // 10 20 30
    insert(arr, 1, 48, &lastIdx);  // 48 10 20 30
    insert(arr, 1, 100, &lastIdx); // 100 48 10 20 30
    remove(arr, 30, &lastIdx);     // 100 48 10 20
    insert(arr, 2, 90, &lastIdx);  // 100 90 48 10 20
    insert(arr, 3, 80, &lastIdx);  // 100 90 80 48 10 20
    insert(arr, 1, 70, &lastIdx);  // 70 100 90 80 48 10 20
    remove(arr, 48, &lastIdx);     // 70 100 90 80 10 20
    remove(arr, 100, &lastIdx);    // 7- 90 80 10 20
    remove(arr, 25, &lastIdx);     // display error

    display(arr, &lastIdx);
    return 0;
}