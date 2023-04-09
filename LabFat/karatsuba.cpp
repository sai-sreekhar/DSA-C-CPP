/*
    Author: Sai Sreekar
*/

#include <iostream>
#include <cmath>

#define ll long long
using namespace std;

ll karatsuba(ll X, ll Y)
{
    if (X < 10 && Y < 10)
    {
        return X * Y;
    }

    int sz = max(to_string(X).size(), to_string(Y).size());
    int n = (int)ceil(sz / 2.0);
    ll p = (ll)pow(10, n);
    ll a = (ll)floor((X / double(p)));
    ll b = X % p;
    ll c = (ll)floor((Y / double(p)));
    ll d = Y % p;

    ll ac = karatsuba(a, c);
    ll bd = karatsuba(b, d);
    ll e = karatsuba(a + b, c + d) - ac - bd;

    return (ll)(pow(10 * 1L, 2 * n) * ac + (pow(10 * 1L, n) * e + bd));
}

int main()
{
    cout << karatsuba(111, 13131) << "\n";
}