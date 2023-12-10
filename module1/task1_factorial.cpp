#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define pb push_back
#define pi acos(-1.0)
#define mod 1000000007

class Solution {
public:
  int factorial(int n) {
    if (n <= 2) {
      return n;
    }
    return n * factorial(n - 1);
  }
};

int main() {
  Solution solution = Solution();
  cout << solution.factorial(4) << endl;
  return 0;
}
/*
Complexity:
Time: O(n)
Space: O(1)
*/