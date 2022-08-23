#include <bits/stdc++.h>

using namespace std;

typedef struct Student
{
    string regNo;
    int attendancePer;

} student;

void linearSearch(student *studentArr, int n, string regNo)
{
    bool found = false;
    for (int i = 0; i < n; i++)
    {
        if (studentArr[i].regNo == regNo)
        {
            found = true;
            cout << "Student with Registration Number " << regNo << " has attendance " << studentArr[i].attendancePer << "\n";
            break;
        }
    }

    if (!found)
    {
        cout << "Student with " << regNo << " Not Found\n";
    }
    return;
}

bool compareFunc(student a, student b)
{
    if (a.regNo > b.regNo)
    {
        return false;
    }
    return true;
}

void binarySearch(student *studentArr, int n, string regNo)
{
    sort(studentArr, studentArr + n, compareFunc);
    int low = 0, high = n - 1;
    int mid;
    while (low <= high)
    {
        int mid = (high + low) / 2;

        if (studentArr[mid].regNo == regNo)
        {
            cout << "Student with Registration Number " << regNo << " has attendance " << studentArr[mid].attendancePer << "\n";
            return;
        }

        if (studentArr[mid].regNo < regNo)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    cout << "Student with " << regNo << " Not Found\n";
    return;
}

int main()
{
    int n;
    cout << "Enter Number of Students: ";
    cin >> n;
    student studentArr[n];
    cout << "Enter Students Details\n";
    for (int i = 0; i < n; i++)
    {
        cin >> studentArr[i].regNo;
        cin >> studentArr[i].attendancePer;
    }

    int opt;
    cout << "Enter 1 for LinearSearch 2 for BinarySearch 0 to Quit\n";
    cin >> opt;
    while (opt != 0)
    {
        string regNo;
        switch (opt)
        {
        case 1:
        {
            cout << "Enter the Registration number: ";
            cin >> regNo;
            linearSearch(studentArr, n, regNo);
            break;
        }
        case 2:
        {
            cout << "Enter the Registration number: ";
            cin >> regNo;
            binarySearch(studentArr, n, regNo);
            break;
        }
        default:
        {
            cout << "Invalid Option";
            break;
        }
        }
        cout << "Enter 1 for LinearSearch 2 for BinarySearch 0 to Quit\n";
        cin >> opt;
    }

    return 0;
}