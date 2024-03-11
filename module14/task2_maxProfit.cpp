#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pi acos(-1.0)
#define mod 1000000007

int findMaxProfit(int i, vector<int> &prices, vector<int> &dp) {
  if (i == prices.size()) {
    return 0;
  }

  if (dp[i] != -1) {
    return dp[i];
  }

  int maxProfit = 0;
  for (int j = i + 1; j < prices.size(); j++) {
    maxProfit = max(maxProfit,
                    prices[j] - prices[i] + findMaxProfit(j + 1, prices, dp));
  }
  return dp[i] = max(maxProfit, findMaxProfit(i + 1, prices, dp));
}

int main() {
  vector<int> prices{7,1,5,3,6,4};

  vector<int> dp(prices.size(), -1);
  cout << findMaxProfit(0, prices, dp) << endl;
}

/*
Complexity:
Time: O(N^2) where N is the number of days
Space: O(N)
*/