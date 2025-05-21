/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存
 */

// @lc code=start
#include <unordered_map>

using namespace std;

struct Entry {
    int key;
    int val;
    Entry *prev;
    Entry *next;
};

class LRUCache {
    unordered_map<int, Entry*> map;
    Entry *head;
    int size;
    const int capacity;
public:
    LRUCache(int capacity): capacity(capacity) {
        size = 0;
        head = new Entry;
        head->prev = head->next = head;
    }
    
    int get(int key) {
        if (map.count(key)) {
            Entry* node = map[key];
            node->prev->next = node->next;
            node->next->prev = node->prev;

            node->next = head;
            node->prev = head->prev;
            head->prev->next = node;
            head->prev = node;

            return node->val;
            
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (map.count(key)) {
            Entry* node = map[key];
            node->prev->next = node->next;
            node->next->prev = node->prev;

            node->next = head;
            node->prev = head->prev;
            head->prev->next = node;
            head->prev = node;

            node->val = value;
            return;
        } 

        if (size == capacity) {
            Entry* next = head->next;
            head->next = next->next;
            next->next->prev = head;
            map.erase(next->key);
            delete next;
            size--;
        }

        Entry* node = new Entry;
        node->key = key;
        node->val = value;
        map[key] = node;
        node->next = head;
        node->prev = head->prev;
        head->prev->next = node;
        head->prev = node;
        size++;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

