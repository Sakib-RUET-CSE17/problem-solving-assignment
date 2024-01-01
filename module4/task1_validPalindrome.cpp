#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define pb push_back
#define pi acos(-1.0)
#define mod 1000000007

bool checkPalindrome(string &s, int i, int j) {
  if (i >= j) {
    return true;
  }
  if (s[i] != s[j]) {
    return false;
  }
  return checkPalindrome(s, i + 1, j - 1);
}

int main() {
  string s = "madama";
  cout << checkPalindrome(s, 0, s.size() - 1) << endl;
  return 0;
}

/*
Complexity:
Time: O(n), where n is the size of the string
Space: O(1)
*/