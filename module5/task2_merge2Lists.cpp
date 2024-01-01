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

ListNode *insert(ListNode *head, ListNode **tail, int val) {
  if (!head) {
    head = new ListNode;
    head->val = val;
    *tail = head;
  } else {
    ListNode *current = new ListNode;
    current->val = val;
    (*tail)->next = current;
    *tail = current;
  }
  return head;
}

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
  ListNode *head = nullptr;
  ListNode *tail;

  while (list1 && list2) {
    if (list1->val < list2->val) {
      head = insert(head, &tail, list1->val);
      list1 = list1->next;
    } else if (list1->val > list2->val) {
      head = insert(head, &tail, list2->val);
      list2 = list2->next;
    } else {
      head = insert(head, &tail, list1->val);
      head = insert(head, &tail, list2->val);
      list1 = list1->next;
      list2 = list2->next;
    }
  }
  while (list1) {
    head = insert(head, &tail, list1->val);
    list1 = list1->next;
  }
  while (list2) {
    head = insert(head, &tail, list2->val);
    list2 = list2->next;
  }

  return head;
}

int main() {
  int n, m;
  cin >> n >> m;
  ListNode *list1 = nullptr;
  ListNode *list2 = nullptr;
  ListNode *tail1;
  ListNode *tail2;
  int val;
  for (int i = 0; i < n; i++) {
    cin >> val;
    list1 = insert(list1, &tail1, val);
  }
  for (int i = 0; i < m; i++) {
    cin >> val;
    list2 = insert(list2, &tail2, val);
  }

  printList(mergeTwoLists(list1, list2));

  return 0;
}

/*
Complexity:
Time: O(n+m), where n is the number of elements in the list1, m is the number of elements in the list2.
Space: O(n+m)
*/