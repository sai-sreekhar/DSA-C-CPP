/*
    Author: Sai Sreekar
    Created: 2023/04/09 17:15:59
    Last Modified: 2023/04/11 18:46:29
*/

#include <bits/stdc++.h>

using namespace std;
#define ll long long

void backtrack(int i, int j, vector<vector<ll>> &dp, string a, string b, unordered_set<string> &setOfLCS, string lcs)
{
    if (i == 0 || j == 0)
    {
        reverse(lcs.begin(), lcs.end());
        setOfLCS.insert(lcs);
        return;
    }

    if (a[i - 1] == b[j - 1])
    {
        lcs.push_back(a[i - 1]);
        backtrack(i - 1, j - 1, dp, a, b, setOfLCS, lcs);
        lcs.pop_back();
    }
    else
    {
        ll maxi = max(dp[i - 1][j], dp[i][j - 1]);
        if (dp[i - 1][j] == maxi)
        {
            backtrack(i - 1, j, dp, a, b, setOfLCS, lcs);
        }
        if (dp[i][j - 1] == maxi)
        {
            backtrack(i, j - 1, dp, a, b, setOfLCS, lcs);
        }
    }
    return;
}

ll getLCSLength(vector<vector<ll>> &dp, string a, string b)
{
    ll n = a.size(), m = b.size();
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= m; j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n][m];
}
void solve()
{
    string A = "qpqrr";
    string B = "pqprqrp";
    ll n = A.size(), m = B.size();
    vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, 0));
    cout << getLCSLength(dp, A, B) << "\n";
    unordered_set<string> setOfLCS;
    backtrack(A.size(), B.size(), dp, A, B, setOfLCS, "");
    cout << setOfLCS.size() << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // #ifndef ONLINE_JUDGE
    // freopen("in.txt","r", stdin);
    // freopen("out.txt", "w", stdout);
    // #endif

    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++)
    {
#ifndef ONLINE_JUDGE
        cerr << "\nTest Case #" << i << ":"
             << "\n";
#endif
        solve();
    }

#ifndef ONLINE_JUDGE
    cerr << "\nTime Taken: " << (float)clock() / CLOCKS_PER_SEC << " sec"
         << "\n";
#endif

    return 0;
}