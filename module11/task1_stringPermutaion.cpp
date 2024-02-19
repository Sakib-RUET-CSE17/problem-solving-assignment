#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pi acos(-1.0)
#define mod 1000000007

void genPermutation(unordered_map<char, bool> &taken, string &str,
                    string &permutation, vector<string> &result) {
  if (permutation.size() == str.size()) {
    result.push_back(permutation);
    return;
  }

  for (char ch : str) {
    if (!taken[ch]) {
      taken[ch] = true;
      permutation += ch;
      genPermutation(taken, str, permutation, result);
      taken[ch] = false;
      permutation.pop_back();
    }
  }
}

vector<string> permute(string &str) {
  unordered_map<char, bool> taken;
  string permutation;
  vector<string> result;

  genPermutation(taken, str, permutation, result);
  return result;
}

void printPermutation(vector<string> &result) {
  for (string &permutation : result) {
    cout << permutation << " ";
  }
  cout << endl;
}

int main() {
  string str = "abc";
  vector<string> result = permute(str);

  printPermutation(result);

  return 0;
}

/*
Complexity:
Time: O(n!). Here, n represents the length of the string
Space: O(n*n!)
*/