#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pi acos(-1.0)
#define mod 1000000007

bool cmp(vector<int> box1, vector<int> box2) { return box1[1] > box2[1]; }

int maximumUnits(vector<vector<int>> &boxTypes, int truckSize) {
  sort(boxTypes.begin(), boxTypes.end(), cmp);
  int units = 0;
  for (vector<int> &box : boxTypes) {
    if (truckSize <= 0) {
      return units;
    }
    int taken = min(truckSize, box[0]);
    units += taken * box[1];
    truckSize -= taken;
  }
  return units;
}

int main() {
  vector<vector<int>> boxTypes{{5, 10}, {2, 5}, {4, 7}, {3, 9}};
  int truckSize = 10;
  cout << maximumUnits(boxTypes, truckSize) << endl;

  return 0;
}

/*
Complexity:
Time: O(n*logn)
Space: O(1), no additional space
*/