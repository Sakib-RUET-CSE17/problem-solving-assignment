#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define pb push_back
#define pi acos(-1.0)
#define mod 1000000007

int firstOccurance(string haystack, string needle) {
  return haystack.find(needle);
}

int main() {
  cout << firstOccurance("codemama", "ostad") << endl;
  return 0;
}