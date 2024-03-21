#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pi acos(-1.0)
#define mod 1000000007

int dfs(int root, int goodCount, int C, vector<int> &isGood,
        vector<vector<int>> &graph, unordered_map<int, bool> &vis) {
  vis[root] = true;
  int ans = 0;
  bool isLeaf = true;
  for (int adj : graph[root]) {
    if (vis.find(adj) == vis.end()) {
      isLeaf = false;
      ans += dfs(adj, goodCount + isGood[adj - 1], C, isGood, graph, vis);
    }
  }
  if (isLeaf && goodCount <= C) {
    return 1;
  }
  return ans;
}

int pathWithGoodNodes(vector<int> &A, vector<vector<int>> &B, int C) {
  vector<vector<int>> graph(A.size() + 1);
  for (auto &edge : B) {
    graph[edge[0]].push_back(edge[1]);
    graph[edge[1]].push_back(edge[0]);
  }
  unordered_map<int, bool> vis;
  return dfs(1, A[0], C, A, graph, vis);
}

int main() {
  vector<int> A{0, 1, 0, 1, 1, 1};
  vector<vector<int>> B{{1, 2}, {1, 5}, {1, 6}, {2, 3}, {2, 4}};
  int C = 1;

  cout << pathWithGoodNodes(A, B, C) << endl;
  return 0;
}

/*
Complexity:
Time: O(V+E), where V is the number of vertices, and E is the number of edges in
the graph.
Space: O(V)
*/