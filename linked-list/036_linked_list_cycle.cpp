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
  // fast and slow pointer, floyd's algorithm
  // mistake; both start at head and proceed | condition fast pointer with &&
  bool hasCycle(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head;

    // fast reaches the null first if not cycle
    // while (fast != nullptr && fast->next != nullptr) {
    while (fast && fast->next) {
      slow = slow->next;       // 1step
      fast = fast->next->next; // 2step

      if (fast == slow)
        return true;
    }

    return false;
  }
};
