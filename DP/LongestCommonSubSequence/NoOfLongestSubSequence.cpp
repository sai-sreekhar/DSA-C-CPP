/*
    Author: Sai Sreekar
    Created: 2023/02/10 13:51:10
    Last Modified: 2023/02/10 14:43:15
*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

// typedefs
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double lld;
typedef vector<ll> vll;
typedef vector<pair<ll, ll>> vpll;
typedef pair<ll, ll> pll;

// Debug Utils
#define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#define debug(str1...)               \
    cerr << "[" << #str1 << "] = ["; \
    _print(str1)
#else
#define debug(str1...)
#endif

void __print(int str1)
{
    cerr << str1;
}
void __print(long str1) { cerr << str1; }
void __print(long long str1) { cerr << str1; }
void __print(unsigned str1) { cerr << str1; }
void __print(unsigned long str1) { cerr << str1; }
void __print(unsigned long long str1) { cerr << str1; }
void __print(float str1) { cerr << str1; }
void __print(double str1) { cerr << str1; }
void __print(long double str1) { cerr << str1; }
void __print(char str1) { cerr << '\'' << str1 << '\''; }
void __print(const char *str1) { cerr << '"' << str1 << '"'; }
void __print(const string &str1) { cerr << '"' << str1 << '"'; }
void __print(bool str1) { cerr << (str1 ? "true" : "false"); }

template <typename T, typename V>
void __print(const pair<T, V> &str1)
{
    cerr << '{';
    __print(str1.first);
    cerr << ',';
    __print(str1.second);
    cerr << '}';
}
template <typename T>
void __print(const T &str1)
{
    int f = 0;
    cerr << '{';
    for (auto &i : str1)
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

// Operator Overloads
template <typename T1, typename T2>
istream &operator>>(istream &istream, pair<T1, T2> &p) { return (istream >> p.first >> p.second); }
template <typename T>
istream &operator>>(istream &istream, vector<T> &v)
{
    for (auto &it : v)
        cin >> it;
    return istream;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &ostream, const pair<T1, T2> &p) { return (ostream << p.first << " " << p.second << "\n"); }
template <typename T>
ostream &operator<<(ostream &ostream, const vector<T> &c)
{
    for (auto &it : c)
        cout << it << " ";
    return ostream;
}

void dfs(int i, int j, unordered_set<string> &lcs, string &s, string &str1, string &str2, vector<vector<int>> &dp)
{
    if (i == 0 || j == 0)
    {
        reverse(s.begin(), s.end());
        lcs.insert(s);
        debug(lcs);
        return;
    }

    if (str1[i - 1] == str2[j - 1])
    {
        s.push_back(str1[i - 1]);
        i = i - 1;
        j = j - 1;
        dfs(i, j, lcs, s, str1, str2, dp);
        s.pop_back();
    }
    else
    {
        int maxVal = max(dp[i - 1][j], dp[i][j - 1]);
        if (maxVal == dp[i - 1][j])
        {
            i = i - 1;
            dfs(i, j, lcs, s, str1, str2, dp);
            i = i + 1;
        }

        if (maxVal == dp[i][j - 1])
        {
            j = j - 1;
            dfs(i, j, lcs, s, str1, str2, dp);
            j = j + 1;
        }
    }
    return;
}

void solve(string str1, string str2, int lenX, int lenY)
{
    vector<vector<int>> dp(lenX + 1, vector<int>(lenY + 1, 0));
    for (int i = 0; i < lenX + 1; i++)
    {
        dp[i][0] = 0;
    }

    for (int j = 0; j < lenY + 1; j++)
    {
        dp[0][j] = 0;
    }

    for (int i = 1; i < lenX + 1; i++)
    {
        for (int j = 1; j < lenY + 1; j++)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }

    debug(dp);
    unordered_set<string> lcs;
    string s = "";
    dfs(lenX, lenY, lcs, s, str1, str2, dp);
    debug(lcs);

    int x = dp[lenX][lenY];
    int y = lcs.size();
    cout << x + 10 * y << "\n";
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
        // solve();
        string str1 = "qpqrr";
        string str2 = "pqprqrp";
        solve(str1, str2, str1.length(), str2.length());
    }

#ifndef ONLINE_JUDGE
    cerr << "\nTime Taken: " << (float)clock() / CLOCKS_PER_SEC << " sec"
         << "\n";
#endif
}