#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define pb push_back
#define pi acos(-1.0)
#define mod 1000000007

struct ListNode {
  int val;
  ListNode *next;
  //     ListNode() : val(0), next(nullptr) {}
  //     ListNode(int x) : val(x), next(nullptr) {}
  //     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void printList(ListNode *head) {
  while (head) {
    printf("%d ", head->val);
    head = head->next;
  }
  printf("\n");
}

ListNode *reverseList(ListNode *head) {
  ListNode *prev = nullptr;
  while (head) {
    ListNode *current = new ListNode;
    current->val = head->val;
    current->next = prev;
    prev = current;
    head = head->next;
  }
  return prev;
}

int main() {
  int n;
  cin >> n;
  ListNode *head = nullptr;
  ListNode *tempHead;
  for (int i = 0; i < n; i++) {
    int val;
    cin >> val;
    if (i == 0) {
      head = new ListNode;
      head->val = val;
      tempHead = head;
    } else {
      ListNode *current = new ListNode;
      current->val = val;
      tempHead->next = current;
      tempHead = current;
    }
  }

  printList(reverseList(head));

  return 0;
}

/*
Complexity:
Time: O(n), where n is the number of elements in the list.
Space: O(n)
*/