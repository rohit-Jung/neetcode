#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
  ListNode *curr;

private:
  void solve(ListNode *head) {
    // mistake; base case is when head reaches null ?
    if (head == NULL)
      return;

    // go to the end and solve during unwind of stack
    solve(head->next);

    ListNode *currNext = curr->next;

    // two conditions
    if (curr->next == NULL) {
      return;
    } else if (curr == head) {
      // curr and head pointing to same node
      // we have reached the end
      head->next = NULL;
      return;
    }

    // change the pointers
    curr->next = head;
    head->next = (currNext == head) ? NULL : currNext;

    // move the curr
    curr = currNext;
  }

  // for other approach
  // recursive
  ListNode *reverseLL(ListNode *head) {
    if (head == nullptr || head->next == nullptr)
      return head;

    // mistake; be careful on what are you reversing
    ListNode *newHead = reverseLL(head->next);
    ListNode *front = head->next;

    front->next = head;
    head->next = nullptr;

    return newHead;
  }

  // fast and slow pointer
  ListNode *findMid(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }

    return slow;
  }

public:
  void reorderList(ListNode *head) {
    curr = head;
    solve(head);
  }

  // with reverse List
  void reorderListWithReverse(ListNode *head) {
    ListNode *midNode = findMid(head);
    ListNode *revHead = reverseLL(midNode);

    ListNode *currNode = head;

    // visualize the 1 - 4 - 3 - 2 thing or draw it out
    // pure drawing ? and implementation
    while (revHead->next != NULL) {
      ListNode *currNext = currNode->next;
      ListNode *revNext = revHead->next;

      currNode->next = revHead;
      revHead->next = currNext;

      currNode = currNext;
      revHead = revNext;
    }
  }
};
