/*
 * @lc app=leetcode.cn id=68 lang=cpp
 *
 * [68] Text Justification
 */

#include <vector>
#include <string>
#include <queue>
#include <sstream>

using namespace std;

// @lc code=start
class Solution {
    string genLine(queue<string>& line, int width, int maxWidth) {

        stringstream ss;
        if (line.size() == 1) {
            ss << move(line.front());
            line.pop();
            for (int i = 0; i < maxWidth - width; i++) {
                ss << " ";
            }
        } else {
            int space = line.size() - 1;
            int each = (maxWidth - width) / space;
            int spare = (maxWidth - width) % space;
            while (line.size() > 1) {
                ss << move(line.front());
                line.pop();
                for (int i = 0; i < each; i++) {
                    ss << " ";
                }
                if (spare > 0) {
                    ss << " ";
                    spare--;
                }
            }
            ss << line.front();
            line.pop();
        }
        return ss.str();
    }

public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        queue<string> this_line;
        int line_width = 0;

        vector<string> res;

        for (string& w: words) {
            if (line_width + this_line.size() + w.length() > maxWidth) {
                res.push_back(genLine(this_line, line_width, maxWidth));
                line_width = 0;
            }
            this_line.push(w);
            line_width += w.length();
        }

        if (!this_line.empty()) {
            stringstream ss;
            int space = maxWidth - line_width - this_line.size() + 1;
            while (this_line.size() > 1) {
                ss << move(this_line.front());
                ss << " ";
                this_line.pop();
            }
            ss << move(this_line.front());
            
            for (int i = 0; i < space; i++) {
                ss << " ";
            }
            res.push_back(ss.str());
        }

        return res;
    }
};
// @lc code=end

