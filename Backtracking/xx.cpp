/*
    Author: Sai Sreekar
    Created: 2023/02/13 19:42:26
    Last Modified: 2023/02/13 19:47:44
*/

#include <bits/stdc++.h>

using namespace std;

// typedefs
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double lld;
typedef vector<ll> vll;
typedef vector<pair<ll, ll>> vpll;
typedef pair<ll, ll> pll;

// Debug Utils
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

void dfs(vector<int> &arr, int n, vector<int> v, int sum, set<vector<int>> &set)
{
    if (sum == 0)
    {
        sort(v.begin(), v.end());
        set.insert(v);
        return;
    }

    if (n == 0)
    {
        return;
    }

    dfs(arr, n - 1, v, sum, set);
    v.push_back(arr[n - 1]);
    dfs(arr, n - 1, v, sum - arr[n - 1], set);
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    cin >> arr;
    int sum;
    cin >> sum;

    vector<int> v;
    set<vector<int>> s;
    dfs(arr, n, v, sum, s);

    debug(s);
    if (s.size() == 0)
    {
        cout << "Solution cannot be found"
             << "\n";
    }

    int sz = s.size();
    vector<vector<int>> temp;
    for (auto e : s)
    {
        temp.push_back(e);
    }
    debug(temp);
    int j = 0;
    while (sz--)
    {
        for (int i = 0; i < n; i++)
        {
            std::vector<int>::iterator it;
            it = find(temp[j].begin(), temp[j].end(), arr[i]);
            if (it != temp[j].end())
            {
                cout << 1 << " ";
            }
            else
            {
                cout << 0 << " ";
            }
        }
        j++;
        cout << "\n";
    }
    return 0;
}