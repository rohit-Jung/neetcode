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
  // divide and conquer
  // partiton it and then use mergeTwoLists method
  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    if (!l1)
      return l2;
    if (!l2)
      return l1;

    if (l1->val <= l2->val) {
      l1->next = mergeTwoLists(l1->next, l2);
      return l1;
    }

    l2->next = mergeTwoLists(l1, l2->next);
    return l2;
  }

  ListNode *partitionAndMerge(int start, int end, vector<ListNode *> lists) {
    if (start > end)
      return NULL;
    if (start == end)
      return lists[start];

    int mid = end + ((start - end) >> 1);

    // divide
    ListNode *left = partitionAndMerge(start, mid, lists);
    ListNode *right = partitionAndMerge(mid + 1, end, lists);

    // conquer
    return mergeTwoLists(left, right);
  }

  ListNode *mergeKLists(vector<ListNode *> &lists) {
    if (lists.empty())
      return NULL;
    return partitionAndMerge(0, lists.size() - 1, lists);
  }
};
