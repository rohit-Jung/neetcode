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
  ListNode *reverseLL(ListNode *head) {
    // since we are passing head->next checking
    if (!head || !head->next)
      return head;

    ListNode *endHead = reverseLL(head->next);

    // while unwinding change pointers
    head->next->next = head;
    head->next = NULL;

    return endHead;
  }

  ListNode *findKthNode(ListNode *tmp, int k) {
    k -= 1;
    while (tmp && k > 0) {
      k--;
      tmp = tmp->next;
    };

    return tmp;
  }

  ListNode *reverseKGroup(ListNode *head, int k) {
    ListNode *tmp = head;
    ListNode *prevLast = NULL;

    // visualization of tmp, head and kth
    // 3 -> 2 -> 1    6 -> 5 -> 4   -> 10
    // kth     head/tmp
    //          prev kth       tmp    tmp
    //                         prev   tmp -> null
    while (tmp) {
      ListNode *kth = findKthNode(tmp, k);
      if (!kth) {
        if (prevLast)
          prevLast->next = tmp;
        break;
      }

      ListNode *nextNode = kth->next;

      // you need to mark the kth as null to reverse
      kth->next = NULL;
      reverseLL(tmp);

      // if its first reversal change the head
      if (tmp == head)
        head = kth;
      else
        prevLast->next = kth;

      // mark tmp as prev because we need
      prevLast = tmp;

      // move tmp to nextNode
      tmp = nextNode;
    }

    return head;
  };
};
