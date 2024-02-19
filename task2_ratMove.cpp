#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pi acos(-1.0)
#define mod 1000000007

bool move(int i, int j, vector<vector<int>> &cell, vector<vector<bool>> &vis) {
  //   cout << "i=" << i << ", j=" << j << endl;
  if (i < 0 || j < 0 || i == cell.size() || j == cell.size() ||
      cell[i][j] == 0 || vis[i][j]) {
    return false;
  }
  if (i == j && i == cell.size() - 1) {
    return true;
  }
  vis[i][j] = true;
  return move(i + 1, j, cell, vis) || move(i, j + 1, cell, vis) ||
         move(i, j - 1, cell, vis) || move(i - 1, j, cell, vis);
}

int main() {
  int n = 4;
  vector<vector<int>> cell{
      {1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}};

  vector<vector<bool>> vis(n, vector<bool>(n));
  if (move(0, 0, cell, vis)) {
    cout << "true" << endl;
  } else {
    cout << "false" << endl;
  }
  vis.clear();
}

/*
Complexity:
Time: O(n^2)
Space: O(n^2)
*/