#include <iostream>
using namespace std;

void Display1(int *a, int *lastIdx)
{
    cout << "Elements are\n";
    for (int i = 0; i <= *lastIdx; i++)
    {
        cout << a[i] << endl;
    }
}
void insert(int *a, int ind, int val, int *lastIdx)
{
    if (*lastIdx == -1)
    {
        if (ind == 0)
        {
            *lastIdx = *lastIdx + 1;
            a[*lastIdx] = val;
        }
        else
        {
            cout << "Invalid Postion";
        }
        return;
    }

    if (*lastIdx + 1 == ind)
    {
        *lastIdx = *lastIdx + 1;
        a[*lastIdx] = val;
        return;
    }

    if (ind > *lastIdx)
    {
        cout << "Invalid Postion";
        return;
    }

    // 1 2 3 4 5 6
    // 1 2 3 4 4 5 6
    // 1 2 3 10 4 5 6
    *lastIdx = *lastIdx + 1;
    for (int i = *lastIdx; i >= ind + 1; i--)
    {
        a[i] = a[i - 1];
    }
    a[ind] = val;
}

void replace(int *a, int ind, int val, int length)
{

    if (ind >= 0 && ind < length)
    {

        a[ind] = val;
    }
    else
    {
        cout << "Wrong value position" << endl;
    }
}

void Delete(int *a, int j, int length)
{

    for (int i = length + 1; i < j; i++)
    {
        a[i] = a[i + 1];
    }
    length--;

    cout << "Elements are\n";
    for (int i = 0; i < length; i++)
    {
        cout << a[i] << endl;
    }
}

void Search(int *a, int val, int length)
{
    int flag;
    for (int i = 0; i < length; i++)
    {
        if (a[i] == val)
        {
            flag = 1;
            cout << "The value is given at index" << i << endl;
            Delete(a, i, length);
        }
        else
        {
            flag = 0;
        }
    }
    if (flag == 0)
    {
        cout << "The entered element is not in the array" << endl;
    }
    else
    {
        cout << "The entered element is present in the array" << endl;
    }
}

int main()
{
    int a1[100];
    int val;
    int pos;

    int call;
    int del;
    int search;
    int replace;

    int lastIdx = -1;

    cout << "Enter the opertation you want to do according to menue driven below:" << endl;
    cout << "1-Insert" << endl
         << "2-Delete" << endl
         << "3-Search" << endl
         << "4-Replace" << endl
         << "5 - Quit";
    cin >> call;
    while (call != 5)
    {
        if (call == 1)
        {
            cout << "Enter the value and position where u want to insert" << endl;
            cin >> val >> pos;
            insert(a1, pos, val, &lastIdx);
        }
        Display1(a1, &lastIdx);
        cin >> call;
    }

    // }else if (call == 2)
    // {
    //     int del;
    //     cout << "Enter the value you want to delete:" << endl;
    //     cin >> del;
    //     Delete(a1, del, length);
    // }
    // else if (call == 3)
    // {
    // cin >> search;
    // Search(a1, search, length);
    //	else if(call=4){
    //
    //		replace(a1,5,6,length);
    //	}
    // else
    // {
    //     cout << "Invalid input";
    // }

    return 0;
}