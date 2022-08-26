#include <bits/stdc++.h>

using namespace std;

int main()
{

    int noOfTestCases;
    cin >> noOfTestCases;

    while (noOfTestCases--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int res[n];
        for (int i = 0; i < n; i++)
        {
            int count = 1;
            int x = arr[i];
            while (arr[x - 1] != arr[i])
            {
                count++;
                x = arr[x - 1];
            }
            res[i] = count;
        }

        for (int i = 0; i < n; i++)
        {
            cout << res[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}
