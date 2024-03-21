#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pi acos(-1.0)
#define mod 1000000007

bool dfs(int root, vector<vector<int>> &graph, unordered_map<int, bool> &vis,
         unordered_map<int, bool> &inStack) {
  if (inStack[root]) {
    return true;
  }
  if (vis[root]) {
    return false;
  }

  vis[root] = true;
  inStack[root] = true;
  for (int adj : graph[root]) {
    if (dfs(adj, graph, vis, inStack)) {
      return true;
    }
  }
  inStack[root] = false;
  return false;
}

int hasCycle(int A, vector<vector<int>> &B) {
  vector<vector<int>> graph(A + 1);
  for (auto &edge : B) {
    graph[edge[0]].push_back(edge[1]);
  }
  unordered_map<int, bool> vis, inStack;
  for (int i = 1; i <= A; i++) {
    if (dfs(i, graph, vis, inStack)) {
      return 1;
    }
  }
  return 0;
}

int main() {
  int A = 5;
  vector<vector<int>> B{{1, 2}, {4, 1}, {2, 4}, {3, 4}, {5, 2}, {1, 3}};

  cout << hasCycle(A, B) << endl;
  return 0;
}

/*
Complexity:
Time: O(V+E), where V is the number of vertices, and E is the number of edges in
the graph.
Space: O(V)
*/