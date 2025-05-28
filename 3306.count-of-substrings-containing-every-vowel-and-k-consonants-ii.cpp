/*
 * @lc app=leetcode.cn id=3306 lang=cpp
 *
 * [3306] Count of Substrings Containing Every Vowel and K Consonants II
 */

#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;

// @lc code=start

/*
    这题同样是数数问题，不是最值问题，不能直接认为一个窗口满足要求就行。而基于滑动窗口的数数要么越长越满足，要么越短越满足，所以将相等问题改为至少问题，至少有 k 个 和至少有 k + 1 个，减一下就是正好 k 个。
*/
class Solution {
    string VOWELS = "aeiou";
public:
    long long countAtLeast(string& word, int k) {
        unordered_map<char, int> vowels;
        int other = 0;
        int lo = 0, hi = 0;
        long long res = 0;
        while (hi < word.length()) {
            if (VOWELS.find(word[hi]) != string::npos) {
                vowels[word[hi]]++;
            } else {
                other++;
            }
            hi++;

            while (vowels.size() == 5 && other >= k) {
                if (VOWELS.find(word[lo]) != string::npos) {
                    vowels[word[lo]]--;
                    if (vowels[word[lo]] == 0) {
                        vowels.erase(word[lo]);
                    }
                } else {
                    other--;
                }
                lo++;
            }

            res += lo; // lo is first substring which does not satisfying the constraints.
        }

        return res;
    }

    long long countOfSubstrings(string word, int k) {
        return countAtLeast(word, k) - countAtLeast(word, k + 1);
    }
};
// @lc code=end


int main() {
    string word;
    int k;
    cin >> word >> k;
    Solution s;
    cout << s.countOfSubstrings(word, k) << endl;
}