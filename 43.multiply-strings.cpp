/*
 * @lc app=leetcode.cn id=43 lang=cpp
 *
 * [43] Multiply Strings
 */

#include <string>
#include <vector>
#include <sstream>

using namespace std;

// @lc code=start
class Solution {
public:
    string multiply(string num1, string num2) {
        // Handle edge cases
        if (num1 == "0" || num2 == "0") {
            return "0";
        }
        
        int m = num1.length(), n = num2.length();
        vector<int> result(m + n, 0);
        
        // Multiply each digit
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int p1 = i + j, p2 = i + j + 1;
                int sum = mul + result[p2];
                
                result[p2] = sum % 10;
                result[p1] += sum / 10;
            }
        }
        
        // Convert result to string using stringstream for better performance
        stringstream ss;
        bool leadingZero = true;
        for (int i = 0; i < result.size(); i++) {
            if (result[i] != 0) {
                leadingZero = false;
            }
            if (!leadingZero) {
                ss << result[i];
            }
        }
        
        string str = ss.str();
        return str.empty() ? "0" : str;
    }
};

// @lc code=end
#include <iostream>

int main() {
    string a, b;
    Solution s;
    cin >> a >> b;
    cout << s.multiply(a, b) << endl;
}

