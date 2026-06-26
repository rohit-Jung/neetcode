#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
  // they are sorted; use two pointers ?
  // concept of dummy node;
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    ListNode *dummy = new ListNode(0);
    ListNode *tmp = dummy;
    ListNode *l1 = list1;
    ListNode *l2 = list2;

    // mistake; it's &&  in condition think dumbperson
    while (l1 != nullptr && l2 != nullptr) {
      // start putting in smaller values
      if (l1->val < l2->val) {
        tmp->next = l1;
        tmp = l1;
        l1 = l1->next;
      } else {
        tmp->next = l2;
        tmp = l2;
        l2 = l2->next;
      }
    }

    // what if there are remaining
    if (l1)
      tmp->next = l1;
    else
      tmp->next = l2;

    return dummy->next;
  }

  // recursive kinda hard
  ListNode *mergeTwoListsRecursive(ListNode *list1, ListNode *list2) {
    // base conditions either of is empty
    if (!list1)
      return list1;
    if (!list2)
      return list2;

    // merge em and return would merge into the one that has least first
    if (list1->val <= list2->val) {
      list1->next = mergeTwoListsRecursive(list1->next, list2);
      return list1;
    } else {
      list2->next = mergeTwoListsRecursive(list1, list2->next);
      return list2;
    }
  }
};
