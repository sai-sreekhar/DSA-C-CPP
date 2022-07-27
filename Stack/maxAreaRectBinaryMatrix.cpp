// MAX RECT AREA IN A BINARY MATRIX
#include <iostream>
#include <stack>
using namespace std;
int *NSLi(int arr[], int n)
{
    int *NSLi = new int[n];
    stack<pair<int, int>> st;
    for (int i = 0; i < n; i++)
    {
        if (!st.size())
            NSLi[i] = -1;
        else if (st.top().first < arr[i])
            NSLi[i] = st.top().second;
        else
        {
            while (st.size() > 0 && st.top().first >= arr[i])
                st.pop();
            if (!st.size())
                NSLi[i] = -1;
            else
                NSLi[i] = st.top().second;
        }
        st.push({arr[i], i});
    }
    return NSLi;
}
int *NSRi(int arr[], int n)
{
    int *nsri = new int[n];
    stack<pair<int, int>> st;
    for (int i = n - 1; i >= 0; i--)
    {
        if (!st.size())
            nsri[i] = n;
        else if (st.top().first < arr[i])
            nsri[i] = st.top().second;
        else
        {
            while (st.size() > 0 && st.top().first >= arr[i])
                st.pop();
            if (!st.size())
                nsri[i] = n;
            else
                nsri[i] = st.top().second;
        }
        st.push({arr[i], i});
    }
    return nsri;
}
int MAH(int arr[], int n)
{
    int *nsli = NSLi(arr, n);
    int *nsri = NSRi(arr, n);

    int area[n];
    for (int i = 0; i < n; i++)
        area[i] = arr[i] * (nsri[i] - nsli[i] - 1);
    int max = 0;
    for (int i = 0; i < n; i++)
        if (area[i] >= max)
            max = area[i];

    return max;
}
int main()
{
    freopen("input.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    int arr[n][m];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j]; // input

    for (int i = 1; i < n; i++)
        for (int j = 0; j < m; j++)
            if (arr[i][j] > 0)
                arr[i][j] += arr[i - 1][j];

    int ans[n];
    for (int i = 0; i < m; i++)
        ans[i] = MAH(arr[i], m);

    int max = 0;
    for (int i = 0; i < n; i++)
        if (ans[i] >= max)
            max = ans[i];

    cout << max << endl;
}