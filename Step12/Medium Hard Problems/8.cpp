#include<bits/stdc++.h>
using namespace std;
// Class that implements Round Robin scheduling
class LRUCache {
public:
    vector<int> keys; // To maintain the order of keys for LRU
    unordered_map<int, int> cache; // To store key-value pairs
    int capacity; // Maximum capacity of the cache
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    int get(int key) {
        if(cache.find(key) == cache.end()) return -1; // Key not found
        // Move the accessed key to the end to show that it was recently used
        auto it = find(keys.begin(), keys.end(), key);
        keys.erase(it);
        keys.push_back(key);
        return cache[key];
    }
    void put(int key, int value) {
        if(cache.find(key) != cache.end()) {
            // Key already exists, update the value and move it to the end
            cache[key] = value;
            // Move the key to the end to show that it was recently used
            auto it = find(keys.begin(), keys.end(), key);
            keys.erase(it);
            keys.push_back(key);
        } else {
            // Key does not exist, add it to the cache
            if(cache.size() == capacity) {
                // Cache is full, remove the least recently used item
                int lruKey = keys.front();
                keys.erase(keys.begin());
                cache.erase(lruKey);
            }
            // Add the new key-value pair to the cache
            cache[key] = value;
            keys.push_back(key);
        }
    }
};

int main() {
    LRUCache cache(2); // Cache capacity of 2
    cache.put(1, 1);
    cache.put(2, 2);
    cout << cache.get(1) << endl; // Returns 1
    cache.put(3, 3); // Evicts key 2
    cout << cache.get(2) << endl; // Returns -1 (not found)
    cache.put(4, 4); // Evicts key 3
    cout << cache.get(3) << endl; // Returns -1 (not found)
    cout << cache.get(4) << endl; // Returns 4
    return 0;
}