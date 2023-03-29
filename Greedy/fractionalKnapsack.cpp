#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define lld long double;

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
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
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
#ifndef ONLINE_JUDGE
#define debug(x...)               \
    cerr << "[" << #x << "] = ["; \
    _print(x)
#else
#define debug(x...)
#endif

void fractionalKnapsack(vector<pair<double, double>> items, int N, double totalWeight)
{
    sort(items.begin(), items.end(), [](pair<double, double> a, pair<double, double> b)
         { return a.second / a.first > b.second / b.first; });

    unordered_map<double, double> umpRatio;
    int profit = 0;
    for (int i = 0; i < N; i++)
    {
        if (totalWeight >= items[i].first)
        {
            umpRatio[items[i].first] = 1;
            totalWeight -= items[i].first;
            profit += items[i].second;
        }
        else
        {
            umpRatio[items[i].first] = totalWeight / items[i].first;
            profit += (double)items[i].second / items[i].first * totalWeight;
            break;
        }
    }

    for (auto item : items)
    {
        printf("%.1f ", umpRatio[item.first]);
    }
    cout << "\n";
    // debug(items, umpRatio, profit);
    return;
}

int main()
{
    double totalWeight = 50;
    vector<pair<double, double>> items = {{10, 60}, {20, 100}, {30, 120}};
    int N = items.size();
    fractionalKnapsack(items, N, totalWeight);
}
