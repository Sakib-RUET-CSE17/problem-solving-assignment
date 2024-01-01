#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define pb push_back
#define pi acos(-1.0)
#define mod 1000000007

ll multiply(ll a, ll b) {
  if (a == 0 || b == 0) {
    return 0;
  }
  if (b == 1) {
    return a;
  }
  return a + multiply(a, b - 1);
}

int main() {
  ll a = 3, b = 3;
  cout << multiply(a, b) << endl;
  return 0;
}

/*
Complexity:
Time: O(b), where b is the 2nd number
Space: O(1)
*/