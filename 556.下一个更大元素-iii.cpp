/*
 * @lc app=leetcode.cn id=556 lang=cpp
 *
 * [556] 下一个更大元素 III
 */

#include <algorithm>
#include <climits>
#include <deque>
#include <functional>

using namespace std;

// @lc code=start
class Solution {
public:
    int nextGreaterElement(int n) {
        deque<int> digits;
        while (n > 0) {
            digits.push_back(n % 10);
            n /= 10;
        }

        // 从 digit 从左往右开始，如果一直是单调增的，那么就没法继续扩大，应该返回 -1。 如果从某一位开始，打破了这个单调增，就存在扩大的机会。 3 5 7 1 -> 7 5 1 3; 3 5 7 4 -> 7 4 3 5, 扩大时，找到最小的大于这个新数的数字 (想想 DFS 枚举组合，这个数字开头的组合枚举到最大了，下次就应该找一个最近的大于这个数字的开始枚举)，并交换位置，之后，对低位排序，高位不动。排序时，大数在先（低位）

        int max = -1;
        auto it = digits.begin();
        for (; it != digits.end(); it++) {
            if (*it < max) {
                break;
            }
            max = *it;
        }

        if (it == digits.end()) {
            return -1;
        }

        auto minElem = digits.begin();
        int minVal = INT_MAX;
        for (auto iter = digits.begin(); iter != it; iter++) {
            if (*iter > *it && *iter < minVal) {
                minVal = *iter;
                minElem = iter;
            }
        }
        iter_swap(minElem, it);

        sort(digits.begin(), it, std::greater<int>());

        long long res = 0;
        while(!digits.empty()) {
            res *= 10;
            res += digits.back();
            digits.pop_back();
        }

        return res > INT_MAX ? -1 : res;
    }
};
// @lc code=end

