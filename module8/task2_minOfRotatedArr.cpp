#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pi acos(-1.0)
#define mod 1000000007

int binarySearch(vector<int> &nums, int left, int right) {
  if (left + 1 >= right) {
    return min(nums[left], nums[right]);
  }
  if (nums[right] > nums[0]) {
    return nums[0];
  }
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (nums[mid + 1] < nums[mid]) {
      return nums[mid + 1];
    }
    if (nums[mid - 1] > nums[mid]) {
      return nums[mid];
    }
    if (nums[mid] > nums[0]) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return -1;
}

int main() {
  vector<int> nums{4, 5, 6, 7, 0, 1, 2};
  cout << binarySearch(nums, 0, nums.size() - 1) << endl;

  return 0;
}

/*
Complexity:
Time: O(log n)
Space: O(1), no additional space
*/