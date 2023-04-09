/*
    Author: Sai Sreekar
    Created: 2023/04/09 17:45:36
    Last Modified: 2023/04/09 21:06:05
*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

void backtrack(vector<ll> &arr, ll sum, ll n, set<vector<ll>> &st, vector<ll> vec)
{
    if (sum == 0)
    {
        st.insert(vec);
        return;
    }

    if (n == 0)
    {
        return;
    }

    backtrack(arr, sum, n - 1, st, vec);
    vec[n - 1] = 1;
    backtrack(arr, sum - arr[n - 1], n - 1, st, vec);
}

void solve()
{
    int n = 5;
    vector<ll> vec{1, 2, 3, 5, 6};
    ll sum = 8;
    vector<ll> temp(n, 0);
    set<vector<ll>> st;
    backtrack(vec, sum, vec.size(), st, temp);
    for (auto it : st)
    {
        for (auto e : it)
        {
            cout << e << " ";
        }
        cout << "\n";
    }
    int i = 0;
}

int main()
{
    solve();
    return 0;
}