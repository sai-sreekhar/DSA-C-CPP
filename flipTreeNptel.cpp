#include "bits/stdc++.h"
using namespace std;

void addEdge(vector<int> adj[], int v1, int v2)
{
  adj[v1].push_back(v2);
  adj[v2].push_back(v1);
}
void DFSUtil(int v1, vector<int> adj[], vector<bool> &visited, bool x, bool y, int initial[], int final[], int &ans)
{
  visited[v1] = true;
  if ((initial[v1 - 1] ^ x) ^ final[v1 - 1] == true)
  {
    ans++;
    x ^= 1;
  }
  for (int i = 0;
       i < adj[v1].size(); i++)
  {
    if (visited[adj[v1][i]] == false)

      DFSUtil(adj[v1][i], adj, visited, y, x, initial, final, ans);
  }
}

void DFS(vector<int> adj[], int V, int initial[], int final[])
{
  int total = 0;
  vector<bool> visited(V, false);

  for (int v1 = 1; v1 <= 1; v1++)
  {

    if (visited[v1] == false)
      DFSUtil(v1, adj, visited, 0, 0, initial, final, total);
  }

  cout << total;
}

void count(int N, int initial[], int final[], int Edges[][2])
{
  vector<int> adj[N + 1];

  for (int i = 0; i < N - 1; i++)
  {
    addEdge(adj, Edges[i][0], Edges[i][1]);
  }

  DFS(adj, N + 1, initial, final);
}

int main()
{

  int N;
  cin >> N;
  int Edges[N - 1][2];

  for (int i = 0; i < N - 1; i++)
  {
    cin >> Edges[i][0] >> Edges[i][1];
  }

  // for (int i = 0; i < N - 1; i++)
  // {
  //   for (int j = 0; j < 2; j++)
  //   {
  //     cout << Edges[i][j];
  //   }
  //   cout << "\n";
  // }

  int initial[N];
  for (int i = 0; i < N; i++)
  {
    cin >> initial[i];
  }

  int final[N];
  for (int i = 0; i < N; i++)
  {
    cin >> final[i];
  }
  count(N, initial, final, Edges);

  return 0;
}
