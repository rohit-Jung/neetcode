#include <bits/stdc++.h>
using namespace std;

class WordDictionary {
public:
  struct trieNode {
    trieNode *children[26];
    bool isEndOfWord;
  };

  // or you can put default values also in the  struct itself
  trieNode *getNewTrieNode() {
    trieNode *newNode = new trieNode();
    newNode->isEndOfWord = false;
    for (int i = 0; i < 26; i++)
      newNode->children[i] = NULL;

    return newNode;
  }

  trieNode *root;
  WordDictionary() { root = getNewTrieNode(); }

  void addWord(string word) {
    trieNode *crawler = root;

    for (int i = 0; i < word.size(); i++) {
      int idx = word[i] - 'a';
      if (!crawler->children[idx]) {
        crawler->children[idx] = getNewTrieNode();
      }

      crawler = crawler->children[idx];
    }

    crawler->isEndOfWord = true;
  }

  bool searchUtil(trieNode *root, string word) {
    trieNode *crawler = root;

    int i = 0;
    for (; i < word.size(); i++) {
      char ch = word[i];
      int idx = ch - 'a';

      // if char is dot check for each char
      if (ch == '.') {

        for (int j = 0; j < 26; j++) {
          if (crawler->children[j] &&
              searchUtil(crawler->children[j], word.substr(i + 1))) {
            return true;
          }
        }

        return false;
      } else if (!crawler->children[idx])
        return false;

      crawler = crawler->children[idx];
    }

    return (crawler && crawler->isEndOfWord);
  }

  bool search(string word) { return searchUtil(root, word); }
};
