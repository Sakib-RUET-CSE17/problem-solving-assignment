#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pi acos(-1.0)
#define mod 1000000007

int binarySearch(vector<int> &nums, int target) {
  int left = 0;
  int right = nums.size() - 1;
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (nums[mid] == target) {
      return mid;
    }
    if (nums[mid] < target) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return -1;
}

int main() {
  vector<int> nums{-1, 0, 3, 5, 9, 12};
  int target = 9;
  cout << binarySearch(nums, target) << endl;

  return 0;
}

/*
Complexity:
Time: O(log n)
Space: O(1), no additional space
*/