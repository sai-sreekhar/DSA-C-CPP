#include <iostream>

using namespace std;
int flag = 0;

void swap(string *x, string *y)
{
    string temp = *x;
    *x = *y;
    *y = temp;
}

void display(string a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}

int validateInput(string a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if ((a[i] >= "0" && a[i] <= "9") || (a[i] >= "a" && a[i] <= "z") || (a[i] >= "A" && a[i] <= "Z"))
        {
            continue;
        }
        else
        {
            flag = 1;
            break;
        }
    }
    return flag;
}

void bubbleSort(string a[], int n)
{
    int i, j, flag;
    for (i = 0; i < n - 1; i++)
    {
        flag = 0;
        for (j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(&a[j], &a[j + 1]);
                flag = 1;
            }
        }
        if (flag == 0)
        {
            break;
        }
    }
}

void insertionSort(string a[], int n)
{
    int i, j;
    string x;
    for (i = 1; i < n; i++)
    {
        j = i - 1;
        x = a[i];
        while (j > -1 && a[j] > x)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = x;
    }
}

void selectionSort(string a[], int n)
{
    int i, j, k;
    for (i = 0; i < n - 1; i++)
    {
        for (j = k = i; j < n; j++)
        {
            if (a[j] < a[k])
            {
                k = j;
            }
            swap(&a[i], &a[k]);
        }
    }
}
int main()
{
    int n;
    cout << "Enter the length of the string: ";
    cin >> n;
    string a[n];
    int flag = 0;
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int isValid = validateInput(a, n);
    if (isValid == 0)
    {

        int opt;
        cout << "Enter 1 for bubble sort" << endl
             << "Enter 2 to insertion sort" << endl
             << "Enter 3 for seletion sort" << endl
             << "Enter 0 for Quit" << endl;
        cin >> opt;
        while (opt != 0)
        {
            switch (opt)
            {
            case 1:
            {
                bubbleSort(a, n);
                display(a, n);
                break;
            }
            case 2:
            {
                insertionSort(a, n);
                display(a, n);

                break;
            }
            case 3:
            {
                selectionSort(a, n);
                display(a, n);

                break;
            }
            default:
            {
                cout << "You have entered wrong input pls try again:" << endl;
            }
            }
            cout << "\nEnter 1 for bubble sort" << endl
                 << "Enter 2 to insertion sort" << endl
                 << "Enter 3 for seletion sort" << endl
                 << "Enter 0 for Quit" << endl;
            cin >> opt;
        }
    }
    else
    {
        cout << "INCORRECT INPUT\n";
    }
    return 0;
}