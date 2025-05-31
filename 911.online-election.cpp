/*
 * @lc app=leetcode.cn id=911 lang=cpp
 *
 * [911] Online Election
 */

#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

// @lc code=start
class TopVotedCandidate {
    vector<int> winner;
    vector<int> &times;
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) : winner(persons.size()), times(times) {
        unordered_map<int, int> voteCnt;
        int winning = -1;
        int i = 0;
        for (int p: persons) {
            voteCnt[p]++;
            if (winning == -1 || voteCnt[p] >= voteCnt[winning]) {
                winning = p;
            }
            winner[i] = winning;
            i++;
        }
    }
    
    int q(int t) {
        int i = upper_bound(times.begin(), times.end(), t) - times.begin() - 1;
        return winner[i];
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */
// @lc code=end

