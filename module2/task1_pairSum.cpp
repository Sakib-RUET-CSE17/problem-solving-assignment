#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define pb push_back
#define pi acos(-1.0)
#define mod 1000000007

vector<int> pairSum(vector<int> &nums, int target) {
  vector<int> ans;
  for (int i = 0; i < nums.size(); i++) {
    for (int j = i + 1; j < nums.size(); j++) {
      if (nums[i] + nums[j] == target) {
        ans.push_back(i);
        ans.push_back(j);
        break;
      }
    }
  }
  return ans;
}

int main() {
  vector<int> nums{3,2,4};
  int target = 6;
  vector<int> ans = pairSum(nums, target);
  printf("%d %d\n", ans[0], ans[1]);
  return 0;
}

/*
Complexity:
Time: O(n^2), where n is the length of nums
Space: O(1)
*/