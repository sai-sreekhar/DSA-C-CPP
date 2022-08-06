#include <iostream>
using namespace std;

#define MAX_SIZE 100

void insert(int *arr, int pos, int val, int *lastIdx)
{
    if (*lastIdx == -1)
    {
        if (pos != 1)
        {
            cout << "Incorrect Position. List is Empty\n";
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

    if (pos - 2 > *lastIdx)
    {
        cout << "Invalid Position\n";
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

void update(int *arr, int val, int newVal, int *lastIdx)
{
    int pos = search(arr, val, lastIdx);
    if (pos == -1)
    {
        cout << "Element " << val << " not found in list to update"
             << "\n";
        return;
    }
    arr[pos] = newVal;
    return;
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
    int opt;
    cout << "Enter 1 to Insert, 2 to Delete, 3 to Search, 4 to Update, 5 to display, 0 to Quit: ";
    cin >> opt;
    while (opt != 0)
    {
        int pos, val;
        switch (opt)
        {
        case 1:
            cout << "Enter the position and value to insert: ";
            cin >> pos;
            cin >> val;
            insert(arr, pos, val, &lastIdx);
            break;
        case 2:
            cout << "Enter the value to delete: ";
            cin >> val;
            remove(arr, val, &lastIdx);
            break;
        case 3:
            cout << "Enter the value to search: ";
            cin >> val;
            pos = search(arr, val, &lastIdx);
            if (pos == -1)
            {
                cout << "Element " << val << " Not Found"
                     << "\n";
            }
            else
            {
                cout << "Element " << val << "Found at pos " << pos << "\n";
            }
            break;
        case 4:
            cout << "Enter the value and newValue: ";
            int newVal;
            cin >> val;
            cin >> newVal;
            update(arr, val, newVal, &lastIdx);
            break;
        case 5:
            display(arr, &lastIdx);
            break;
        default:
            cout << "Entered Invalid Option"
                 << "\n";
            break;
        }
        cout << "Enter 1 to Insert, 2 to Delete, 3 to Search, 4 to Update, 5 to display, 0 to Quit: ";
        cin >> opt;
    }
    return 0;
}