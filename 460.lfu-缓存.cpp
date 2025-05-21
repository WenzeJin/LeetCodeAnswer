/*
 * @lc app=leetcode.cn id=460 lang=cpp
 *
 * [460] LFU 缓存
 */

// @lc code=start
#include <unordered_map>
#include <list>

using namespace std;

struct Node {
    int key;
    int val;
    int cnt;

    Node(int key, int val, int cnt) : key(key), val(val), cnt(cnt) {}
};

class LFUCache {
    const int capacity;
    int minFreq;
    // 在 key map 中保存 freq map 中的 iterator，可以保证在 freq map 的list 中调用 erase 的 O1 复杂度。
    unordered_map<int, list<Node>::iterator> keyToNode;
    unordered_map<int, list<Node>> freqToNode;
public:
    LFUCache(int capacity) : capacity(capacity) {
        minFreq = 0;
    }
    
    int get(int key) {
        auto it = keyToNode.find(key);
        if (it == keyToNode.end()) {
            return -1;
        }

        auto nodeIt = it->second;
        int val = nodeIt->val;
        int cnt = nodeIt->cnt;
        freqToNode[cnt].erase(nodeIt);
        if (freqToNode[cnt].size() == 0) {
            freqToNode.erase(cnt);
            if (minFreq == cnt) {
                minFreq++;
            }
        }
        freqToNode[cnt + 1].emplace_front(key, val, cnt + 1);
        keyToNode[key] = freqToNode[cnt + 1].begin();

        return val;
    }
    
    void put(int key, int value) {
        if (capacity == 0) return;
        auto it = keyToNode.find(key);
        if (it == keyToNode.end()) {
            // insert
            if (keyToNode.size() == capacity) {
                Node& node = freqToNode[minFreq].back();
                keyToNode.erase(node.key);
                freqToNode[minFreq].pop_back();
                if (freqToNode[minFreq].size() == 0) {
                    freqToNode.erase(minFreq);
                }
            }
            minFreq = 1;    // new node
            freqToNode[1].emplace_front(key, value, 1);
            keyToNode[key] = freqToNode[1].begin();
        } else {
            auto nodeIt = it->second;
            int cnt = nodeIt->cnt;
            freqToNode[cnt].erase(nodeIt);
            if (freqToNode[cnt].size() == 0) {
                freqToNode.erase(cnt);
                if (minFreq == cnt) {
                    minFreq++;
                }
            }
            
            freqToNode[cnt + 1].emplace_front(key, value, cnt + 1);
            keyToNode[key] = freqToNode[cnt + 1].begin();
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

