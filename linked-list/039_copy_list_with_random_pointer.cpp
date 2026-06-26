#include <bits/stdc++.h>
using namespace std;

class Node {
public:
  int val;
  Node *next;
  Node *random;

  Node(int _val) {
    val = _val;
    next = NULL;
    random = NULL;
  }
};

class Solution {
public:
  // 1st approach: copy all the vals and next
  // keep a map of corresponding nodes and then link the random nodes again
  Node *copyRandomListNaive(Node *head) {
    // make a deep copy
    Node *dummy = new Node(-1);
    Node *tail = dummy;

    unordered_map<Node *, Node *> mp;

    Node *tmp = head;
    while (tmp) {
      int val = tmp->val;
      Node *newNode = new Node(val);

      tail->next = newNode;
      tail = newNode;

      // corresponding newNode Created
      mp[tmp] = newNode;
      tmp = tmp->next;
    }

    // copy the random pointers
    tmp = head;
    Node *curr = dummy->next;

    while (tmp) {
      if (tmp->random == NULL) {
        curr->random = NULL;
      } else {
        curr->random = mp[tmp->random];
      }

      curr = curr->next;
      tmp = tmp->next;
    }

    // return the head
    return dummy->next;
  }

  // same approach but a shorter and concise one
  Node *copyRandomListNaive2(Node *head) {
    // make a deep copy
    if (!head)
      return nullptr;

    unordered_map<Node *, Node *> mp;

    for (Node *curr = head; curr; curr = curr->next) {
      mp[curr] = new Node(curr->val);
    }

    for (Node *curr = head; curr; curr = curr->next) {
      mp[curr]->next = curr->next ? curr->next : nullptr;
      mp[curr]->random = curr->random ? curr->random : nullptr;
    }

    return mp[head];
  }

  // 2nd approach:  insert in midst of the list
  // copy the random ones
  Node *copyRandomList(Node *head) {
    if (!head)
      return NULL;

    // 1. insert new nodes in midst
    Node *curr = head;
    while (curr) {
      Node *currNext = curr->next;
      curr->next = new Node(curr->val); // A -> x
      curr->next->next = currNext;      // A -> x -> B

      curr = currNext;
    }

    // 2. get the random pointers in place
    // mistake; move next to next on each iteration and if you do that check
    // curr->next
    curr = head;
    while (curr && curr->next) {
      if (curr->random == NULL) {
        curr->next->random = NULL;
      } else {
        // 1 -> 1 .. -> 4 4 so if 4 random is 1
        // then 1.random = 1.random.next (4)
        curr->next->random = curr->random->next;
      };

      // move 2 steps a time cause adajcent one is done
      curr = curr->next->next;
    }

    // 3. separate the list
    curr = head;
    Node *newHead = head->next;
    Node *newCurr = newHead;

    while (curr && newCurr) {
      // first list separation
      curr->next = curr->next ? curr->next->next : NULL;

      // second list separation
      newCurr->next = newCurr->next ? newCurr->next->next : NULL;

      // update the pointers
      curr = curr->next;
      newCurr = newCurr->next;
    }

    return newHead;
  }
};
