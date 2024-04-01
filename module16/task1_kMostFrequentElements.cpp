#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pi acos(-1.0)
#define mod 1000000007

vector<int> topKFrequent(vector<int> &nums, int k) {
  unordered_map<int, int> freq;
  for (int num : nums) {
    freq[num]++;
  }
  priority_queue<pair<int, int>> pq;
  for (auto it : freq) {
    pq.push({it.second, it.first});
  }
  vector<int> ans;
  while (k--) {
    ans.push_back(pq.top().second);
    pq.pop();
  }
  return ans;
}

int main() {
  vector<int> nums{1, 1, 1, 2, 2, 3};
  int k = 2;

  vector<int> ans = topKFrequent(nums, k);
  for (auto num : ans) {
    cout << num << " ";
  }
  cout << endl;
  return 0;
}

/*
Complexity:
Time: O(n*logn), where n is the size of nums
Space: O(n)
*/