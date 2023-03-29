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

#define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#define debug(x...)               \
    cerr << "[" << #x << "] = ["; \
    _print(x)
#else
#define debug(x...)
#endif

void displayBoard(vector<vector<int>> &board, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    return;
}

bool isValidMove(vector<vector<int>> &board, int n, int row, int col)
{
    for (int i = 0; i < col; i++)
    {
        if (board[row][i] == 1)
        {
            return false;
        }
    }

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
    }
    for (int i = row, j = col; j >= 0 && i < n; i++, j--)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
    }
    return true;
}

bool nQueenBacktracking(vector<vector<int>> &board, int n, int col)
{
    if (col >= n)
    {
        return true;
    }

    for (int i = 0; i < n; i++)
    {
        if (isValidMove(board, n, i, col))
        {
            board[i][col] = 1;
            if (nQueenBacktracking(board, n, col + 1))
            {
                return true;
            }
            board[i][col] = 0;
        }
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // #ifndef ONLINE_JUDGE
    //	freopen("in.txt", "r", stdin);
    //	freopen("out.txt", "w", stdout);
    // #endif

    int n;
    cin >> n;
    vector<vector<int>> board(n, vector<int>(n, 0));

    if (nQueenBacktracking(board, n, 0) == false)
    {
        cout << "No Solution";
        return false;
    }

    debug(board);
    displayBoard(board, n);
    return true;
}
