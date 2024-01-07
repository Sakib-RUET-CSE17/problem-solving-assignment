#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define pb push_back
#define pi acos(-1.0)
#define mod 1000000007

bool isValid(string s) {
  stack<char> stck;
  unordered_map<char, char> umap;
  umap['('] = ')';
  umap['{'] = '}';
  umap['['] = ']';
  for (char c : s) {
    if (c == '(' || c == '{' || c == '[') {
      stck.push(c);
    } else {
      if (stck.empty()) {
        return false;
      }
      if (umap[stck.top()] != c) {
        return false;
      }
      stck.pop();
    }
  }

  return stck.empty();
}

int main() {

  cout << isValid("{(})") << endl;
  return 0;
}

/*
Complexity:
Time: O(n), where n is the length of the string.
Space: O(n)
*/