/*
 * @lc app=leetcode.cn id=3442 lang=swift
 *
 * [3442] Maximum Difference Between Even and Odd Frequency I
 */

// @lc code=start
class Solution {
    func maxDifference(_ s: String) -> Int {
        var freq = [Int](repeating: 0, count: 26)
        let base = Character("a").asciiValue!
        for char in s {
            freq[Int(char.asciiValue! - base)] += 1
        }

        var maxOddFreq = 0
        var minEvenFreq = Int.max
        for f in freq {
            if f == 0 {
                continue
            }
            if f % 2 == 0 {
                minEvenFreq = min(minEvenFreq, f)
            } else {
                maxOddFreq = max(maxOddFreq, f)
            }          
        }

        return maxOddFreq - minEvenFreq
    }
}
// @lc code=end

