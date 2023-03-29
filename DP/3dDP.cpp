/*
    Author: Sai Sreekar
    Created: 2023/02/04 16:47:38
    Last Modified: 2023/02/04 22:58:36
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '"' << x << '"'; }
void __print(const string &x) { cerr << '"' << x << '"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }

template <typename T, typename V>
void __print(const pair<T, V> &x)
{
    cerr << '{';
    __print(x.first);
    cerr << ',';
    __print(x.second);
    cerr << '}';
}
template <typename T>
void __print(const T &x)
{
    int f = 0;
    cerr << '{';
    for (auto &i : x)
        cerr << (f++ ? "," : ""), __print(i);
    cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v)
{
    __print(t);
    if (sizeof...(v))
        cerr << ", ";
    _print(v...);
}

template <typename... Params>
void _print(priority_queue<Params...> q)
{
    while (!q.empty())
    {
        cerr << " " << q.top() << ",";
        q.pop();
    }
    cerr << "]" << endl;
}

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#define debug(x...)               \
    cerr << "[" << #x << "] = ["; \
    _print(x)
#else
#define debug(x...)
#endif
int M = 20;
int N = 5;

int dp(vector<vector<int>> v, int coins, int items, int n)
{
    if ((coins == 0 || n == 0) && items != 0)
    {
        debug("returning INT_MIN");
        return INT_MIN;
    }
    if (items == 0 || coins == 0 || n == 0)
    {
        debug("returning zero");
        return 0;
    }

    // if (n == 0 || items == 0 || coins == 0)
    // {
    //     debug("zero");
    //     debug(coins, items, n);
    //     return 0;
    // }

    if (v[items - 1][n - 1] == 0)
    {
        debug("value is zero");
        debug(coins, items, n);
        return dp(v, coins, items, n - 1);
    }

    if (coins - v[items - 1][n - 1] < 0)
    {
        debug("less than zero");
        debug(coins, items, n);
        return dp(v, coins, items, n - 1);
    }

    debug("Calling for choice 1 for", coins, items, n);
    int choice1 = dp(v, coins - v[items - 1][n - 1], items - 1, N);
    if (choice1 != INT_MIN)
    {
        choice1 += v[items - 1][n - 1];
    }
    debug("Calling for choice 2 for", coins, items, n);
    int choice2 = dp(v, coins, items, n - 1);
    debug(choice1, choice2, coins, items, n);
    return (max(choice1, choice2));
}

void solve()
{
    vector<vector<int>> v{{6, 4, 8, 0, 0}, {5, 10, 0, 0, 0}, {1, 5, 3, 5, 0}};
    int res = dp(v, 20, 3, 5);
    if (res == INT_MIN)
    {
        cout << "Not Possible"
             << "\n";
    }
    else
    {
        cout << res << "\n";
    }
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
        cout << "Test Case #" << i << ":"
             << "\n";
#endif
        solve();
    }

#ifndef ONLINE_JUDGE
    cerr << "Time Taken: " << (float)clock() / CLOCKS_PER_SEC << " sec"
         << "\n";
#endif
}