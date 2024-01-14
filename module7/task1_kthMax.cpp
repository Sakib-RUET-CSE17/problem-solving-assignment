#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pi acos(-1.0)
#define mod 1000000007

void merge(vector<int> &arr, int p, int q, int r) {
  int n1 = q - p + 1;
  int n2 = r - q;

  vector<int> L(n1);
  vector<int> R(n2);

  for (int i = 0; i < n1; i++)
    L[i] = arr[p + i];
  for (int j = 0; j < n2; j++)
    R[j] = arr[q + 1 + j];
  int i, j, k;
  i = 0;
  j = 0;
  k = p;
  while (i < n1 && j < n2) {
    if (L[i] >= R[j]) {
      arr[k++] = L[i++];
    } else {
      arr[k++] = R[j++];
    }
  }
  while (i < n1) {
    arr[k++] = L[i++];
  }

  while (j < n2) {
    arr[k++] = R[j++];
  }
}

void mergeSort(vector<int> &arr, int l, int r) {
  if (l >= r) {
    return;
  }

  int m = l + (r - l) / 2;

  mergeSort(arr, l, m);
  mergeSort(arr, m + 1, r);

  merge(arr, l, m, r);
}

int findKthLargest(vector<int> &nums, int k) {
  mergeSort(nums, 0, nums.size() - 1);
  return nums[k - 1];
}

int main() {
  vector<int> nums{3, 2, 3, 1, 2, 4, 5, 5, 6};
  int k = 4;
  cout << findKthLargest(nums, k) << endl;
  return 0;
}

/*
Complexity:
Time: O(nlogn)
Space: O(n)
I used Merge Sort to effectively sort the array in O(nlogn) time & additional
space O(n) is required to store the temporary left & right subarray.
*/