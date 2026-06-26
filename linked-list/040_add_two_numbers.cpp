#include <bits/stdc++.h>
using namespace std;

template <typename Set, typename T> bool contains(const Set &s, const T &x) {
  return s.find(x) != s.end();
}

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
  // naive: you make up numbers add it and form ListNode again
  // move through it and add em with carry
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *t1 = l1;
    ListNode *t2 = l2;

    // since we are making a new list node we need a dummy head
    ListNode *dummy = new ListNode(-1);
    ListNode *curr = dummy;

    // we need for carry
    int carry = 0;

    // until t1 is null
    // mistake; don't forget t1 and t2 may not exist
    while (t1 != nullptr || t2 != nullptr) {
      int sum = carry;

      if (t1)
        sum += t1->val;
      if (t2)
        sum += t2->val;

      ListNode *newNode = new ListNode(sum % 10);
      carry = sum / 10;

      curr->next = newNode;
      // move the tmp
      curr = curr->next;

      if (t1)
        t1 = t1->next;
      if (t2)
        t2 = t2->next;
    }

    // see if carry is left
    if (carry) {
      ListNode *newNode = new ListNode(carry);
      curr->next = newNode;
    }
    return dummy->next;
  }
};
