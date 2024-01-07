#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define pb push_back
#define pi acos(-1.0)
#define mod 1000000007

string removeDuplicates(string s) {
    int n = s.size();
    deque<char> dq;
    dq.push_back(s[0]);
    for (int i = 1; i < n; i++) {
      if (!dq.empty() && dq.back() == s[i]) {
        dq.pop_back();
      } else {
        dq.push_back(s[i]);
      }
    }
    if (dq.empty()) {
      return "";
    }
    string ans;
    while (!dq.empty()) {
      ans += dq.front();
      dq.pop_front();
    }
    return ans;
  }

  int main() {

  cout << removeDuplicates("abbaca") << endl;
  return 0;
}

/*
Complexity:
Time: O(n), where n is the length of the string.
Space: O(n)
*/