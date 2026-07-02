#include <bits/stdc++.h>
using namespace std;

// this is the standard trie solution
// O(M×N×4L) where L = length of word
class Trie {
private:
  struct trieNode {
    string word = "";
    bool isEndOfWord = false;
    trieNode *children[26] = {};
  };

  static constexpr char visitMark = '*';
  static constexpr int dr[4] = {1, -1, 0, 0};
  static constexpr int dc[4] = {0, 0, 1, -1};

  trieNode *root;

  void dfs(vector<vector<char>> &board, trieNode *crawler, int r, int c,
           vector<string> &sol) {
    // out of bounds check;
    if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size())
      return;

    // if already visited
    if (board[r][c] == visitMark) {
      return;
    }

    // or pointer doesn't exist
    char ch = board[r][c];
    int idx = ch - 'a';
    if (!crawler->children[idx])
      return;

    // move the crawler aheed
    crawler = crawler->children[idx];

    // if we found the word push it and also mark it as false
    // cause we will be moving forward
    if (crawler->isEndOfWord) {
      sol.push_back(crawler->word);
      crawler->isEndOfWord = false;
    }

    // mark it as visited
    board[r][c] = visitMark;

    // going through directions recursively
    for (int k = 0; k < 4; k++) {
      int new_r = r + dr[k];
      int new_c = c + dc[k];

      dfs(board, crawler, new_r, new_c, sol);
    }

    // mark it as unvisited again
    board[r][c] = ch;
  }

public:
  Trie() { root = new trieNode(); }

  void insert(const string &word) {
    trieNode *crawler = root;

    for (int i = 0; i < word.size(); i++) {
      int idx = word[i] - 'a';

      if (!crawler->children[idx])
        crawler->children[idx] = new trieNode();

      crawler = crawler->children[idx];
    }

    crawler->isEndOfWord = true;
    crawler->word = word;
  }

  vector<string> searchBoard(vector<vector<char>> &board) {
    // check for edge cases
    if (board.empty() || board[0].empty())
      return {};

    vector<string> sol;

    // travel and find all the words in grid at once
    for (int r = 0; r < board.size(); r++) {
      for (int c = 0; c < board[0].size(); c++) {
        dfs(board, root, r, c, sol);
      }
    }

    return sol;
  }
};

class Solution {
private:
public:
  vector<string> findWords(vector<vector<char>> &board, vector<string> &words) {
    Trie trie{};
    for (string &word : words) {
      trie.insert(word);
    }

    return trie.searchBoard(board);
  }
};

// this is from neetcode
// O(W×M×N×4L) where l is word length, M*N is board, W is word
class Solution2 {
public:
  vector<string> findWords(vector<vector<char>> &board, vector<string> &words) {
    int ROWS = board.size(), COLS = board[0].size();
    vector<string> res;

    for (string &word : words) {
      bool flag = false;
      for (int r = 0; r < ROWS && !flag; r++) {
        for (int c = 0; c < COLS; c++) {
          if (board[r][c] != word[0])
            continue;

          if (backtrack(board, r, c, word, 0)) {
            res.push_back(word);
            flag = true;
            break;
          }
        }
      }
    }
    return res;
  }

private:
  bool backtrack(vector<vector<char>> &board, int r, int c, string &word,
                 int i) {
    if (i == word.length())
      return true;

    if (r < 0 || c < 0 || r >= board.size() || c >= board[0].size() ||
        board[r][c] != word[i])
      return false;

    board[r][c] = '*';
    bool ret = backtrack(board, r + 1, c, word, i + 1) ||
               backtrack(board, r - 1, c, word, i + 1) ||
               backtrack(board, r, c + 1, word, i + 1) ||
               backtrack(board, r, c - 1, word, i + 1);
    board[r][c] = word[i];
    return ret;
  }
};
