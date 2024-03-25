#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pi acos(-1.0)
#define mod 1000000007

void dfs(int source, vector<vector<int>> &graph, vector<bool> &vis) {
  vis[source] = true;
  for (int adj : graph[source]) {
    if (!vis[adj]) {
      dfs(adj, graph, vis);
    }
  }
}

bool validPath(int n, vector<vector<int>> &edges, int source, int destination) {
  vector<vector<int>> graph(n);
  for (auto &edge : edges) {
    graph[edge[0]].push_back(edge[1]);
    graph[edge[1]].push_back(edge[0]);
  }
  vector<bool> vis(n);
  dfs(source, graph, vis);
  return vis[destination];
}

int main() {
  int n = 5;
  vector<vector<int>> edges{{0, 1}, {1, 2}, {2, 0}};
  int source = 0, destination = 2;

  cout << (validPath(n, edges, source, destination) ? "true" : "false") << endl;
  return 0;
}

/*
Complexity:
Time: O(V+E), where V is the number of vertices, and E is the number of edges in
the graph.
Space: O(V)
*/