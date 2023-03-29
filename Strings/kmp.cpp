/*
    Author: Sai Sreekar
    Created: 2023/02/13 16:44:17
    Last Modified: 2023/02/13 20:50:38
*/

#include <iostream>
#include <vector>

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

void computeLPSArray(string pattern, int M, vector<int> &lps, string text)
{
    int len = 0;
    lps[0] = 0;

    int i = 1;
    while (i < M)
    {
        if (pattern[i] == pattern[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
    debug(lps);
    // cout << "LPS: " << ": ";
    // for(int i = 0; i < M; i++)
    // {
    //     cout << lps[i] << " ";
    // }

    int pi[text.size()];
    pi[0] = 0;
    int k = 0;
    i = 1;
    while (i < text.size())
    {
        if (text[i] == text[k])
        {
            k++;
            pi[i] = k;
            i++;
        }
        else
        {
            if (k != 0)
            {
                k = pi[k - 1];
            }
            else
            {
                pi[i] = 0;
                i++;
            }
        }
    }

    printf("Pi value is :");
    for (i = 0; i < text.size(); i++)
    {
        printf("%d ", pi[i]);
    }
    cout << "\n";
}

void KMPSearch(string pattern, string text)
{
    int M = pattern.length();
    int N = text.length();

    vector<int> lps(M, 0);

    computeLPSArray(pattern, M, lps, text);

    int i = 0;
    int j = 0;
    while ((N - i) >= (M - j))
    {
        if (pattern[j] == text[i])
        {
            j++;
            i++;
        }

        if (j == M)
        {
            printf("Found pattern at index %d\n", i - j);
            j = lps[j - 1];
        }

        else if (i < N && pattern[j] != text[i])
        {

            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                i = i + 1;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // #ifndef ONLINE_JUDGE
    // freopen("in.text","r", stdin);
    // freopen("out.text", "w", stdout);
    // #endif

    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++)
    {
#ifndef ONLINE_JUDGE
        cerr << "\nTest Case #" << i << ":"
             << "\n";
#endif
        string text = "ababbabbabbababbabb";
        string pattern = "bbabb";
        KMPSearch(pattern, text);
    }

#ifndef ONLINE_JUDGE
    cerr << "\nTime Taken: " << (float)clock() / CLOCKS_PER_SEC << " sec"
         << "\n";
#endif
}
