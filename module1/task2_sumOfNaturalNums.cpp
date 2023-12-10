#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define pb push_back
#define pi acos(-1.0)
#define mod 1000000007

class Solution {
public:
  ll sumOfNaturalNums(ll a, ll b) {
    if (a > b) {
      swap(a, b);
    }
    ll n = b - a + 1;
    return (n * (2 * a + (n - 1))) / 2;
  }
};

int main() {
  Solution solution = Solution();
  cout << solution.sumOfNaturalNums(100000, 1) << endl;
  return 0;
}

/*
Complexity:
Time: O(1)
Space: O(1)
*/