/*
 * @lc app=leetcode.cn id=1888 lang=cpp
 *
 * [1888] Minimum Number of Flips to Make the Binary String Alternating
 */

#include <climits>
#include <string>
#include <iostream>

using namespace std;

// @lc code=start


/*
    这道题实际上就是告诉我们，s 是一个环，我们可以任意轮转这个环。在这个环上，我们要找最少变换次数。实际上可以用滑动窗口解决，我们在环上，滑动一个长为 s.length 的窗口，然后统计变换次数，取最小值。
    环实际上遍历两遍数组就可以了
    这里要注意实际上就两种交替可能，要么一开头，要么0开头，分别做一次就可以了
*/
class Solution {
public:
    int minFlips(string s) {
        int ops = 0;
        int minVal = INT_MAX;
        bool currOne = true;
        int k = s.length();
        for (int i = 0; i < 2 * k; i++) {
            currOne = !currOne;
            if (i < k) {
                ops += currOne ? s[i % k] == '0' : s[i % k] == '1';
            } else {
                bool oldOne = k % 2 == 0 ? currOne : !currOne;
                ops -= oldOne ? s[(i - k) % k] == '0' : s[(i - k) % k] == '1';
                ops += currOne ? s[i % k] == '0' : s[i % k] == '1';
            }

            //cout << "i: " << i << " ops: " << ops << endl;

            if (i >= k - 1) {
                minVal = min(minVal, ops);
            }
        }

        currOne = false;
        ops = 0;
        for (int i = 0; i < 2 * k; i++) {
            currOne = !currOne;
            if (i < k) {
                ops += currOne ? s[i % k] == '0' : s[i % k] == '1';
            } else {
                bool oldOne = k % 2 == 0 ? currOne : !currOne;
                ops -= oldOne ? s[(i - k) % k] == '0' : s[(i - k) % k] == '1';
                ops += currOne ? s[i % k] == '0' : s[i % k] == '1';
            }

            //cout << "i: " << i << " ops: " << ops << endl;

            if (i >= k - 1) {
                minVal = min(minVal, ops);
            }
        }

        return minVal;
    }
};
// @lc code=end



int main() {
    string str;
    cin >> str;
    Solution s;
    cout << s.minFlips(str) << endl;
}
