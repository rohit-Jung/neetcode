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
  // naive maintain a stack
  // replace the values
  ListNode *reverseListNaive(ListNode *head) {
    stack<int> st;

    ListNode *tmp = head;
    while (tmp != nullptr) {
      st.push(tmp->val);
      tmp = tmp->next;
    }

    tmp = head;
    while (tmp != nullptr) {
      tmp->val = st.top();
      st.pop();
      tmp = tmp->next;
    }

    // its just replacing the values so head is still head
    return head;
  }

  // 1 -> 2 -> 3 -> 4
  // prev, tmp and front
  ListNode *reverseList(ListNode *head) {
    ListNode *tmp = head;
    ListNode *prev = nullptr;

    while (tmp != nullptr) {
      // mistake; order and visualization matters
      // take  front as tmp next
      // move tmp's next to prev
      // move both prev and tmp
      ListNode *front = tmp->next;
      tmp->next = prev;
      prev = tmp;
      tmp = front;
    }

    return prev;
  }

  // using recursion cause if you can use stack ?
  ListNode *reverseListRecursive(ListNode *head) {
    // base case
    /// when 1 elem or null
    if (head == nullptr || head->next == nullptr)
      return head;

    // get new head
    ListNode *newHead = reverseListRecursive(head->next);
    // visualize for only first two node ?
    ListNode *front = head->next;
    front->next = head;
    head->next = nullptr;

    return newHead;
  }
};
