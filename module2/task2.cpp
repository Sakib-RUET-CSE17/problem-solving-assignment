#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define pb push_back
#define pi acos(-1.0)
#define mod 1000000007

int maximizeProfit(vector<int> &prices) {
  int n = prices.size();
  int maxProfit = 0;
  vector<int> maxAfter(n);
  maxAfter[n - 1] = prices[n - 1];
  for (int i = n - 2; i >= 0; i--) {
    maxAfter[i] = max(maxAfter[i + 1], prices[i + 1]);
  }
  for (int i = 0; i < n - 1; i++) {
    maxProfit = max(maxProfit, maxAfter[i] - prices[i]);
  }
  return maxProfit;
}

int main() {
  vector<int> prices{7,6,4,3,1};
  printf("%d\n", maximizeProfit(prices));
  return 0;
}

/*
Complexity:
Time: O(n), where n is the length of prices
Space: O(n)
*/