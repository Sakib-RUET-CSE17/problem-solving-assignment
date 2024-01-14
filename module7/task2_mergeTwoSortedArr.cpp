#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pi acos(-1.0)
#define mod 1000000007

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
  if (m == 0) {
    nums1 = nums2;
    return;
  }
  if (n == 0) {
    return;
  }
  vector<int> tempNums1(nums1.begin(), nums1.begin() + m);
  int i = 0;
  int j = 0;
  int k = 0;
  while (i < m && j < n) {
    if (tempNums1[i] <= nums2[j]) {
      nums1[k++] = tempNums1[i++];
    } else {
      nums1[k++] = nums2[j++];
    }
  }
  while (i < m) {
    nums1[k++] = tempNums1[i++];
  }
  while (j < n) {
    nums1[k++] = nums2[j++];
  }
}

int main() {
  int m = 3;
  vector<int> nums1{1, 2, 3, 0, 0, 0};
  int n = 3;
  vector<int> nums2{2, 5, 6};

  merge(nums1, m, nums2, n);

  for (int num : nums1) {
    cout << num << " ";
  }
  cout << endl;

  return 0;
}

/*
Complexity:
Time: O(m+n)
Space: O(m), additional m space
*/