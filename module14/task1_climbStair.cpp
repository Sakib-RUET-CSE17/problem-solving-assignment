#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pi acos(-1.0)
#define mod 1000000007

unordered_map<int, int> dp;

int climbStairs(int n) {
    if (n <= 3) {
      return n;
    }
    if (dp.find(n) != dp.end()) {
      return dp[n];
    }
    return dp[n] = climbStairs(n - 1) + climbStairs(n - 2);
  }

int main() {
  int n = 4;

  cout << climbStairs(n) << endl;
}

/*
Complexity:
Time: O(n)
Space: O(n)
*/