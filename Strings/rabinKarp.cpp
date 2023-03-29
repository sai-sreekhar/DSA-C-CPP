/*
    Author: Sai Sreekar
    Created: 2023/02/13 16:56:57
    Last Modified: 2023/02/13 20:38:55
*/

#include <iostream>
#include <vector>
#include <climits>

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

#define d 11

void search(string pattern, string text)
{
    int M = pattern.length();
    int N = text.length();
    int p = 0;
    int t = 0;
    int h = 1;

    for (int i = 0; i < M - 1; i++)
    {
        h = (h * d) % INT_MAX;
    }

    for (int i = 0; i < M; i++)
    {
        p = (d * p + pattern[i]) % INT_MAX;
        t = (d * t + text[i]) % INT_MAX;
    }

    for (int i = 0; i <= N - M; i++)
    {
        if (p == t)
        {
            int j;
            for (j = 0; j < M; j++)
            {
                if (text[i + j] != pattern[j])
                {
                    break;
                }
            }
            if (j == M)
            {
                cout << "Pattern found at index " << i
                     << "\n";
            }
        }

        if (i < N - M)
        {
            t = (d * (t - text[i] * h) + text[i + M]) % INT_MAX;
            t = (t < 0) ? (t + INT_MAX) : t;
        }
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
    for (int k = 1; k <= t; k++)
    {
#ifndef ONLINE_JUDGE
        cerr << "\nTest Case #" << k << ":"
             << "\n";
#endif
        string text = "3141592653589793";
        string pattern = "26";

        int q = 11;
        int P = 26;
        int mod = 26 % 11;
        int i, j, Hit = 0;
        for (i = 0; i < (text.size() - 1); i++)
        {
            int num = 0;
            for (j = i; j < i + 2; j++)
            {
                num = num * 10 + ((int)(text[j]) - 48);
            }
            if (num % 11 == mod)
            {
                if (num != P)
                {
                    Hit++;
                }
            }
        }
        printf("Total Spurious Hits=%d\n", Hit);

        search(pattern, text);
    }

#ifndef ONLINE_JUDGE
    cerr << "\nTime Taken: " << (float)clock() / CLOCKS_PER_SEC << " sec"
         << "\n";
#endif
}
