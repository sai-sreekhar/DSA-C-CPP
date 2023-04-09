/*
    Author: Sai Sreekar
    Created: 2023/03/07 19:33:05
    Last Modified: 2023/04/09 21:30:14
*/

#include <iostream>
#include <limits.h>
#include <vector>
#include <queue>
#include <string.h>

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

bool bfs(vector<vector<int>> &rGraph, int s, int t, int parent[], int vertices)
{
    bool visited[vertices];
    memset(visited, 0, sizeof(visited));

    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while (!q.empty())
    {	 	  	 	  		      	      	     		    	 	
        int u = q.front();
        q.pop();

        for (int v = 0; v < vertices; v++)
        {
            if (visited[v] == false && rGraph[u][v] > 0)
            {
                if (v == t)
                {
                    parent[v] = u;
                    return true;
                }
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }

    return false;
}

int fordFulkerson(vector<vector<int>> &graph, int s, int t, int vertices)
{
    int u, v;

    vector<vector<int>> rGraph(vertices, vector<int>(vertices, 0));

    for (u = 0; u < vertices; u++)
    {
        for (v = 0; v < vertices; v++)
        {
            rGraph[u][v] = graph[u][v];
        }
    }

    int parent[vertices];

    int max_flow = 0;

    while (bfs(rGraph, s, t, parent, vertices))
    {	 	  	 	  		      	      	     		    	 	

        int path_flow = INT_MAX;
        for (v = t; v != s; v = parent[v])
        {
            u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }

        for (v = t; v != s; v = parent[v])
        {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }

        max_flow += path_flow;
    }

    return max_flow;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++)
    {	 	  	 	  		      	      	     		    	 	
#ifndef ONLINE_JUDGE
        cerr << "\nTest Case #" << i << ":"
             << "\n";
#endif
        int vertices;
        cin >> vertices;
        int edges;
        cin >> edges;
        vector<vector<int>> graph(vertices, vector<int>(vertices, 0));

        for (int i = 0; i < edges; i++)
        {
            int a, b, w;
            cin >> a >> b >> w;
            graph[a][b] = w;
        }

        int s, t;
        cin >> s >> t;

        cout << "Number of Vertices: " << vertices << "\n";
        cout << "Edges: " << edges << "\n";
        for (int i = 0; i < vertices; i++)
        {
            for (int j = 0; j < vertices; j++)
            {
                if (graph[i][j] != 0)
                {
                    cout << "A: " << i << " B: " << j << " Capacity: " << graph[i][j] << "\n";
                }
            }
        }

        cout << "Source: " << s << " Sink: " << t << "\n";
        cout << "Max flow: " << fordFulkerson(graph, s, t, vertices) << "\n";
    }	 	  	 	  		      	      	     		    	 	

#ifndef ONLINE_JUDGE
    cerr << "\nTime Taken: " << (float)clock() / CLOCKS_PER_SEC << " sec"
         << "\n";
#endif

    return 0;
}