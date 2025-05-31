/*
 * @lc app=leetcode.cn id=981 lang=java
 *
 * [981] Time Based Key-Value Store
 */

import java.util.ArrayList;
import java.util.HashMap;

// @lc code=start
class TimeMap {
    static record ValueNode(String value, int timestamp) {}

    HashMap<String, ArrayList<ValueNode>> valueMap;

    public TimeMap() {
        valueMap = new HashMap<>();
    }
    
    public void set(String key, String value, int timestamp) {
        if (valueMap.containsKey(key)) {
            valueMap.get(key).add(new ValueNode(value, timestamp));
        } else {
            var list = new ArrayList<ValueNode>();
            list.add(new ValueNode(value, timestamp));
            valueMap.put(key, list);
        }
    }
    
    public String get(String key, int timestamp) {
        var list = valueMap.get(key);
        if (list == null) {
            return "";
        }
        int l = 0, r = list.size() - 1;
        if (list.get(l).timestamp > timestamp) {
            return "";
        }

        while(l < r) {
            // invariant: list[l].timestamp <= timestamp;
            // 二分的时候，如果我们有闭区间二分，选定了一侧作为不变式，那么就要确保取 mid 的时候和不变式这一侧变量不同，否则有可能永远不动。
            int mid = l + (r - l) / 2 + 1; // 为了保证 l = mid 时不会卡住，保证 mid > l
            var nodeMid = list.get(mid);
            if (nodeMid.timestamp <= timestamp) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return list.get(l).value;

    }
}

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap obj = new TimeMap();
 * obj.set(key,value,timestamp);
 * String param_2 = obj.get(key,timestamp);
 */
// @lc code=end

