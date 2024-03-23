#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pi acos(-1.0)
#define mod 1000000007

int lengthOfLIS(vector<int> &nums) {
  vector<int> lis(nums.size(), 1);
  int ans = 1;
  for (int i = 1; i < nums.size(); i++) {
    for (int j = 0; j < i; j++) {
      if (nums[j] < nums[i]) {
        lis[i] = max(lis[i], lis[j] + 1);
        ans = max(ans, lis[i]);
      }
    }
  }
  return ans;
}

int main() {
  vector<int> nums{10, 9, 2, 5, 3, 7, 101, 18};

  cout << lengthOfLIS(nums) << endl;

  return 0;
}

/*
Complexity:
Time: O(n^2)
Space: O(n)
*/