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
  // approach naive -> find the index of node to delete
  // maintain two pointer go and delete
  int getLengthOfList(ListNode *head) {
    ListNode *curr = head;
    int length = 0;

    while (curr) {
      length++;
      curr = curr->next;
    }

    return length;
  }

  ListNode *removeNthFromEndNaive(ListNode *head, int n) {
    if (!head)
      return NULL;

    // get length of list
    int lengthOfList = getLengthOfList(head);

    // if we are deleting the head
    // move the head
    if (n == lengthOfList) {
      ListNode *tmp = head;
      head = head->next;
      delete tmp;
      return head;
    }

    int elemLocation = lengthOfList - n;

    ListNode *curr = head;
    ListNode *prev = nullptr;

    while (elemLocation--) {
      prev = curr;
      curr = curr->next;
    }

    prev->next = curr->next;
    delete curr;

    return head;
  }

  // 2nd approach -> tmp goes to n and then you move both tmp
  // and prev -> prev would reach the node you want to delete
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    ListNode *tmp = head;

    // move the tmp
    while (n--) {
      tmp = tmp->next;
    }

    // delete from front -> head
    if (tmp == nullptr) {
      ListNode *delNode = head->next;
      head = head->next;
      delete (delNode);
      return head;
    }

    // move the prev to  its pos
    ListNode *prev = head;
    while (tmp->next) {
      prev = prev->next;
      // mistake dumb;  dont' forget to move
      tmp = tmp->next;
    }

    ListNode *delNode = prev->next;
    prev->next = prev->next->next;
    delete (delNode);
    return head;
  }
};
