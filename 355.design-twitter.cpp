/*
 * @lc app=leetcode.cn id=355 lang=cpp
 *
 * [355] Design Twitter
 */

#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>


using namespace std;

// @lc code=start
class Twitter {
    int clock;

    struct Tweet {
        int id;
        int time;
    };

    struct TweetCompare {
        bool operator()(Tweet& a, Tweet& b) const {
            return a.time > b.time;
        }
    };

    unordered_map<int, unordered_set<int>> follows;
    unordered_map<int, vector<Tweet>> tweets;

public:
    Twitter(): clock(0) {
        
    }
    
    void postTweet(int userId, int tweetId) {
        clock++;
        tweets[userId].emplace_back(tweetId, clock);
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> ids;
        ids.push_back(userId);
        for (int p: follows[userId]) {
            ids.push_back(p);
        }

        priority_queue<Tweet, vector<Tweet>, TweetCompare> buffer;
        for (int p: ids) {
            auto& ts = tweets[p];
            for (int i = ts.size() - 1; i >= 0; --i) {
                buffer.push(ts[i]);
                if (buffer.size() > 10) {
                    buffer.pop();
                }

                if (ts.size() - i >= 10) {
                    break;
                } 
            }
        }

        vector<int> res(buffer.size());
        for (int i = res.size() - 1; i >= 0; --i) {
            res[i] = buffer.top().id;
            buffer.pop();
        }
        
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        follows[followerId].insert(followerId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if (follows[followeeId].count(followeeId))
            follows[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
// @lc code=end

