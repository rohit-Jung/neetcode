#include <bits/stdc++.h>
using namespace std;

// simple way intutive not efficient
class TwitterInefficent {
private:
  // priority_queue<int> tweets;
  int timestamp;
  unordered_map<int, unordered_set<int>> follows;

  priority_queue<vector<int>> timeline; // min heap minimum time at top

public:
  TwitterInefficent() {
    timestamp = 0;
    follows = unordered_map<int, unordered_set<int>>();
    timeline = priority_queue<vector<int>>();
  }

  void postTweet(int userId, int tweetId) {
    timeline.push({timestamp++, tweetId, userId});
  }

  // getNewsFeed
  vector<int> getNewsFeedUsingTimeline(int userId) {
    vector<int> ans;
    priority_queue<vector<int>> userTimeline = timeline;
    while (!userTimeline.empty() && ans.size() < 10) {
      vector<int> topTweet = userTimeline.top();
      userTimeline.pop();

      int topUserId = topTweet[2];
      int topTweetId = topTweet[1];
      // if its the user itself or if the user followers has it
      if (topUserId == userId || follows[userId].count(topUserId)) {
        ans.push_back(topTweetId);
      }
    }
    return ans;
  }

  void follow(int followerId, int followeeId) {
    follows[followerId].insert(followeeId);
  }

  void unfollow(int followerId, int followeeId) {
    follows[followerId].erase(followeeId);
  }
};

// simple way intutive
class Twitter {
private:
  // priority_queue<int> tweets;
  int timestamp;
  unordered_map<int, unordered_set<int>> follows;
  // userId => {timestamp, tweetId}
  unordered_map<int, vector<pair<int, int>>> tweets;

  struct TweetNode {
    int userId;
    int tweetId;
    int time;
    int index;

    bool operator<(const TweetNode &other) const { return time < other.time; }
  };

public:
  Twitter() {
    timestamp = 0;
    follows = unordered_map<int, unordered_set<int>>();
    tweets = unordered_map<int, vector<pair<int, int>>>();
  }

  void postTweet(int userId, int tweetId) {
    tweets[userId].push_back({timestamp++, tweetId});
  }

  // getNewsFeed
  vector<int> getNewsFeed(int userId) {
    vector<int> ans;
    priority_queue<TweetNode> pq;

    // push the users tweet first
    if (!tweets[userId].empty()) {
      int idx = tweets[userId].size() - 1;
      auto [time, tweetId] = tweets[userId][idx];
      pq.push({userId, tweetId, time, idx});
    }

    // insert into the queue latest tweets of followers
    for (int user : follows[userId]) {
      // we have already pushed user Tweets so
      if (user == userId)
        continue;

      if (tweets[user].empty())
        continue;

      int idx = tweets[user].size() - 1;
      auto [time, tweetId] = tweets[user][idx];
      pq.push(TweetNode{user, tweetId, time, idx});
    }

    // pop out the tweets from the queue
    while (!pq.empty() && ans.size() < 10) {
      TweetNode topTweet = pq.top();
      pq.pop();

      ans.push_back(topTweet.tweetId);

      int idx = topTweet.index;
      if (idx != 0) {
        auto [time, tweetId] = tweets[topTweet.userId][idx - 1];
        pq.push(TweetNode{topTweet.userId, tweetId, time, idx - 1});
      }
    }

    return ans;
  }

  void follow(int followerId, int followeeId) {
    follows[followerId].insert(followeeId);
  }

  void unfollow(int followerId, int followeeId) {
    follows[followerId].erase(followeeId);
  }
};
