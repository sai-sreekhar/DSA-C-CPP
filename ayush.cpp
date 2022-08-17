#include <iostream>
using namespace std;

void display(int *a, int *rear)
{
    for (int i = 0; i <= *rear; i++)
    {
        cout << a[i] << endl;
    }
    return;
}

void insert(int *a, int pos, int val, int *rear)
{
    if (*rear == -1)
    {
        if (pos != 1)
        {
            cout << "Emtpy List" << endl;
            return;
        }
        else
        {
            a[pos - 1] = val;
            *rear = 0;
            return;
        }
    }

    else if (*rear == pos - 2)
    {
        a[pos - 1] = val;
        *rear = *rear + 1;
        return;
    }
    else if (pos - 2 > *rear)
    {
        cout << "Invalid index" << endl;
        return;
    }
    for (int i = *rear + 1; i >= pos; i--)
    {
        a[i] = a[i - 1];
    }

    a[pos - 1] = val;
    *rear = *rear + 1;
    return;
}
int search(int *a, int val, int *rear)
{
    int pos = -1;
    for (int i = 0; i <= *rear; i++)
    {
        if (a[i] == val)
        {
            pos = i;
            break;
        }
    }
    return pos;
}
void remove(int *a, int val, int *rear)
{
    if (*rear == -1)
    {
        cout << "Emtpy List" << endl;
        return;
    }

    int pos = search(a, val, rear);
    if (pos == -1)
    {
        cout << "Element " << val << " not found in list to delete"
             << "\n";
        return;
    }
    for (int i = pos; i <= *rear - 1; i++)
    {
        a[i] = a[i + 1];
    }
    a[*rear] = -1;
    *rear = *rear - 1;
}
void replace(int *a, int val, int changed, int *rear)
{
    int pos = search(a, val, rear);
    if (pos == -1)
    {
        cout << "Element " << val << " not found in list to update"
             << "\n";
        return;
    }
    a[pos] = changed;
    return;
}

int main()
{

    int a[1000];
    int rear = -1;
    int call;
    cout << "Enter " << endl
         << "1 to Insert" << endl
         << "2 to Delete " << endl
         << "3 to Search" << endl
         << "4 to Update" << endl
         << "5 to display" << endl
         << "0 to Quit: " << endl;
    cin >> call;
    while (call != 0)
    {
        int pos, val;
        switch (call)
        {
        case 1:
            cin >> pos;
            cin >> val;
            insert(a, pos, val, &rear);
            break;

        case 2:
            cout << "Enter the value you want to delete:" << endl;
            cin >> val;
            remove(a, val, &rear);
            break;
        case 3:
            cout << "Enter the value you want to search" << endl;
            cin >> val;
            pos = search(a, val, &rear);
            if (pos == -1)
            {
                cout << "Element" << val << "Not Found" << endl;
            }
            else
            {
                cout << "Element " << val << "Found at pos " << pos << "\n";
            }
            break;
        case 4:
            cout << "Enter the value and changed value:";
            int changed;
            cin >> val;
            cin >> changed;
            replace(a, val, changed, &rear);
            break;
        case 5:
            display(a, &rear);
            break;
        default:
            cout << "Entered Invalid Option"
                 << "\n";
            break;
        }
        cout << "Enter " << endl
             << "1 to Insert" << endl
             << "2 to Delete " << endl
             << "3 to Search" << endl
             << "4 to Update" << endl
             << "5 to display" << endl
             << "0 to Quit: " << endl;
        cin >> call;
    }

    return 0;
}