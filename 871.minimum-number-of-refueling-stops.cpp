/*
 * @lc app=leetcode.cn id=871 lang=cpp
 *
 * [871] Minimum Number of Refueling Stops
 */

#include <vector>
#include <queue>

using namespace std;

// @lc code=start
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        // 当车辆经过一个加油站时，相当于获得了一次加油机会，可以选择加或不加，可以当作从这一刻起车上放了个能随时加油的油桶，那么当车没油的时候，就可以从油桶中贪心地选最大的加进去。
        // 每次耗尽车内的油，先判断有没有到达终点，没到达的话，将经过的所有加油站的油放进 pq 里，加最大的油，循环这一过程。
        priority_queue<int> pq;
        int sp = 0;
        int curr = 0;
        int cnt = 0;
        int fuel = startFuel;
        while (true) {
            curr += fuel;
            fuel = 0;
            if (curr >= target) {
                return cnt;
            }
            for (;sp < stations.size() && stations[sp][0] <= curr; sp++) {
                pq.push(stations[sp][1]);
            }
            if (pq.empty()) {
                return -1; //无法到达了
            } else {
                cnt++;
                fuel += pq.top();
                pq.pop();
            }
        }
    }
};
// @lc code=end

