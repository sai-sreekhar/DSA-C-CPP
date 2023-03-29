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

#ifndef ONLINE_JUDGE
#define debug(x...)               \
    cerr << "[" << #x << "] = ["; \
    _print(x)
#else
#define debug(x...)
#endif

string remove_zeros_from_front(string a)
{
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] != '0')
        {
            return a.substr(i, a.size() - i);
        }
    }
    return "0";
}

string str_add(string a, string b)
{
    if (a.size() > b.size())
    {
        swap(a, b);
    }

    int n = a.size();
    int diff = b.size() - a.size();
    string ans;
    int carry = 0;
    for (int i = n - 1; i > -1; i--)
    {
        int sum_d = (a[i] - '0') + (b[i + diff] - '0') + carry;
        carry = sum_d / 10;
        ans.push_back(sum_d % 10 + '0');
    }
    for (int i = diff - 1; i > -1; i--)
    {
        int sum_d = (b[i] - '0') + carry;
        carry = sum_d / 10;
        ans.push_back(sum_d % 10 + '0');
    }
    if (carry)
    {
        ans.push_back(carry + '0');
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

string str_sub(string b, string a)
{
    if (a.size() > b.size())
    {
        swap(a, b);
    }

    int n = a.size();
    int diff = b.size() - a.size();
    string ans;
    int carry = 0;
    for (int i = n - 1; i > -1; i--)
    {
        int diff_d = (b[i + diff] - '0') - (a[i] - '0') - carry;
        carry = (diff_d < 0);
        diff_d += 10 * carry;
        ans.push_back(diff_d + '0');
    }
    for (int i = diff - 1; i > -1; i--)
    {
        int diff_d = (b[i] - '0') - carry;
        carry = (diff_d < 0);
        diff_d += 10 * carry;
        ans.push_back(diff_d + '0');
    }
    assert(carry == 0);
    reverse(ans.begin(), ans.end());
    return ans;
}

string single_dig_mul(string b, char a)
{
    string ans;
    int d = a - '0', carry = 0;
    for (int i = b.size() - 1; i > -1; i--)
    {
        int mul_d = (b[i] - '0') * d + carry;
        carry = mul_d / 10;
        ans.push_back(mul_d % 10 + '0');
    }
    if (carry)
    {
        ans.push_back(carry + '0');
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

string karatsuba(string a, string b)
{
    if (a.size() > b.size())
    {
        swap(a, b);
    }

    int A = a.size(), B = b.size();
    if (A == 1)
    {
        return single_dig_mul(b, a[0]);
    }

    string copy_A, copy_B;
    if (B & 1)
    {
        copy_B.push_back('0');
        B += 1;
    }
    for (int i = 0; i < B - A; i++)
    {
        copy_A.push_back('0');
    }

    copy_A = copy_A + a;
    copy_B = copy_B + b;

    string A_l, A_r, B_l, B_r;
    A_l = copy_A.substr(0, B / 2);
    A_r = copy_A.substr(B / 2, B / 2);
    B_l = copy_B.substr(0, B / 2);
    B_r = copy_B.substr(B / 2, B / 2);

    string I_1 = karatsuba(A_l, B_l);
    string I_2 = karatsuba(A_r, B_r);
    string I_3 = karatsuba(str_add(A_l, A_r), str_add(B_l, B_r));
    string sum_I1_I2 = str_add(I_1, I_2);
    I_3 = str_sub(I_3, sum_I1_I2);
    I_1 += string(B, '0');
    I_3 += string(B / 2, '0');
    string I_4 = str_add(I_3, str_add(I_1, I_2));

    debug(I_1, I_2, I_3, I_4);
    return remove_zeros_from_front(I_4);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // #ifndef ONLINE_JUDGE
    //  freopen("in.txt", "r", stdin);
    //  freopen("out.txt", "w", stdout);
    // #endif

    string a;
    cin >> a;
    string b;
    cin >> b;
    string ans = karatsuba(a, b);
    cout << "Result: " << ans << "\n";
}
