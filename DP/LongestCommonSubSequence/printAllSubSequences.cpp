/*
    Author: Sai Sreekar
    Created: 2023/03/23 17:51:09
    Last Modified: 2023/03/23 18:36:43
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
#define debug(x...)               \
    cerr << "[" << #x << "] = ["; \
    _print(x)
#else
#define debug(x...)
#endif

void __print(int x)
{
    cerr << x;
}
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

unordered_set<string> subSequences;

void getAllSubSequences(string s1, string s2)
{
    if (s1.empty())
    {
        subSequences.insert(s2);
        return;
    }
    getAllSubSequences(s1.substr(1), s2 + s1[0]);
    getAllSubSequences(s1.substr(1), s2);
}

void getAllSubSequences2(string s1, string s2, int k)
{
    if (s1.empty())
    {
        if (subSequences.find(s2) != subSequences.end() && s2.length() < k)
        {
            cout << s2 << "\n";
        }
        return;
    }
    getAllSubSequences2(s1.substr(1), s2 + s1[0], k);
    getAllSubSequences2(s1.substr(1), s2, k);
}

int getLenLongestCommonSubsequenceDP(string x, string y, int lenX, int lenY)
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
            if (x[i - 1] == y[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }

    return dp[lenX][lenY];
}

void solve()
{
    string str1, str2;
    cin >> str1 >> str2;
    str1 =  str1.substr(1,str1.length()-2);
    str2 =  str2.substr(1,str2.length()-2);
    int k = getLenLongestCommonSubsequenceDP(str1, str2, str1.length(), str2.length());
    cout << "Length of Longest Common Subsequence: " << k << "\n";
    cout << "All Subsequences of length less than " << k << " are: \n";
    getAllSubSequences(str1, "");
    getAllSubSequences2(str2, "", k);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

// #ifndef ONLINE_JUDGE
//     freopen("in.txt", "r", stdin);
//     freopen("out.txt", "w", stdout);
//     freopen("err.txt", "w", stderr);
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