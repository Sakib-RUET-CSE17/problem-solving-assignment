#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pi acos(-1.0)
#define mod 1000000007

int lcs(int i, int j, string &text1, string &text2, vector<vector<int>> &dp) {
  if (i == text1.size() || j == text2.size()) {
    return 0;
  }
  if (dp[i][j] != -1) {
    return dp[i][j];
  }
  if (text1[i] == text2[j]) {
    return dp[i][j] = 1 + lcs(i + 1, j + 1, text1, text2, dp);
  }
  return dp[i][j] = max(lcs(i, j + 1, text1, text2, dp),
                        lcs(i + 1, j, text1, text2, dp));
}

int main() {
  string text1 = "abcde";
  string text2 = "ace";

  vector<vector<int>> dp(text1.size(), vector<int>(text2.size(), -1));
  cout << lcs(0, 0, text1, text2, dp) << endl;

  return 0;
}

/*
Complexity:
Time: O(m*n), where m is the length of text1 and n is the length of text2
Space: O(m*n)
*/