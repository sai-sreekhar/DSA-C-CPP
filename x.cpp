#include <bits/stdc++.h>
using namespace std;

int getDepth(int x, vector<int> child[])
{
    int i = 0;

    for (auto j : child[x])
        i = max(i, getDepth(j, child));

    return i + 1;
}

int minimumGroups(int n, int arr[])
{
    vector<int> child[n + 1];

    for (int i = 1; i <= n; i++)
        if (arr[i] != -1)
            child[arr[i]].push_back(i);
    int res = 0;

    for (int i = 1; i <= n; i++)
        if (arr[i] == -1)
            res = max(res, getDepth(i, child));

    return res;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << minimumGroups(n - 1, arr);
}
