#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define pb push_back
#define pi acos(-1.0)
#define mod 1000000007

string shuffleString(string s, vector<int> &indices) {
  string ans = s;
  for (int i = 0; i < indices.size(); i++) { // O(n)
    ans[indices[i]] = s[i];
  }
  return ans;
}

int main() {
  string s = "mamacode";
  vector<int> indices{4, 5, 6, 7, 0, 1, 2, 3};
  cout << shuffleString(s, indices) << endl;
  return 0;
}

/*
Complexity:
Time: O(n), where n is the length of `s` or `indices`
Space: O(n)
*/