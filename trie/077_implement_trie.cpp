#include <bits/stdc++.h>
using namespace std;

// solve; trie struct which has isEnd and children of 26
// take a crawler check if the chilren pointer for that idx (ch - 'a') present
// if not make a node (getnewTrieNode)
class PrefixTree {
public:
  struct trieNode {
    bool isEndOfWord;
    trieNode *children[26];
  };

  trieNode *getNewTrieNode() {
    trieNode *newNode = new trieNode();
    newNode->isEndOfWord = false;

    for (int i = 0; i < 26; i++) {
      newNode->children[i] = NULL;
    }

    return newNode;
  }

  trieNode *root;

  PrefixTree() { root = getNewTrieNode(); }

  void insert(string word) {
    trieNode *crawler = root;

    for (int i = 0; i < word.size(); i++) {
      int idx = word[i] - 'a';
      if (crawler->children[idx] == NULL) {
        crawler->children[idx] = getNewTrieNode();
      }

      // move the crawler to the index
      crawler = crawler->children[idx];
    }

    // without null check also okay
    if (crawler != NULL)
      crawler->isEndOfWord = true;
  }

  bool search(string word) {
    trieNode *crawler = root;

    for (int i = 0; i < word.size(); i++) {
      int idx = word[i] - 'a';
      // it doesn't exist
      if (crawler->children[idx] == NULL) {
        return false;
      }

      // it exist then move forward
      crawler = crawler->children[idx];
    }

    if (crawler != NULL && crawler->isEndOfWord == true)
      return true;

    return false;
  }

  bool startsWith(string prefix) {
    trieNode *crawler = root;

    int i = 0;
    for (; i < prefix.size(); i++) {
      int idx = prefix[i] - 'a';
      if (crawler->children[idx] == NULL) {
        return false;
      }

      crawler = crawler->children[idx];
    }

    // make sure it has travelled all and not met end
    if (crawler != NULL && i == prefix.size()) {
      return true;
    }

    return false;
  }
};
