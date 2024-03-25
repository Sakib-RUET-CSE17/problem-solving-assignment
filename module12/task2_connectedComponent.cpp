#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pi acos(-1.0)
#define mod 1000000007

void dfs(int root, vector<vector<int>> &graph, vector<bool> &vis) {
  vis[root] = true;
  for (int adj : graph[root]) {
    if (!vis[adj]) {
      dfs(adj, graph, vis);
    }
  }
}

int countComponents(int n, vector<vector<int>> &edges) {
  vector<vector<int>> graph(n + 1);
  for (auto &edge : edges) {
    graph[edge[0]].push_back(edge[1]);
    graph[edge[1]].push_back(edge[0]);
  }
  vector<bool> vis(n + 1);
  int connectedComponent = 0;
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      dfs(i, graph, vis);
      connectedComponent++;
    }
  }
  return connectedComponent;
}

int main() {
  int A = 4;
  vector<vector<int>> B{{1, 2}, {2, 3}};

  cout << countComponents(A, B) << endl;
  return 0;
}

/*
Complexity:
Time: O(V+E), where V is the number of vertices, and E is the number of edges in
the graph.
Space: O(V)
*/