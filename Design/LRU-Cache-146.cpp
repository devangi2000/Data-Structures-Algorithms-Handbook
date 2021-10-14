// Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.
// Implement the LRUCache class:

// LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
// int get(int key) Return the value of the key if the key exists, otherwise return -1.
// void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache.
// If the number of keys exceeds the capacity from this operation, evict the least recently used key.
// The functions get and put must each run in O(1) average time complexity.

// Example 1:

// Input
// ["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
// [[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
// Output
// [null, null, null, 1, null, -1, null, -1, 3, 4]

// Explanation
// LRUCache lRUCache = new LRUCache(2);
// lRUCache.put(1, 1); // cache is {1=1}
// lRUCache.put(2, 2); // cache is {1=1, 2=2}
// lRUCache.get(1);    // return 1
// lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
// lRUCache.get(2);    // returns -1 (not found)
// lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
// lRUCache.get(1);    // return -1 (not found)
// lRUCache.get(3);    // return 3
// lRUCache.get(4);    // return 4

class LRUCache {
public:
    list<pair<int, int>> cache;
    // the key in this map is the page number and the value is the int+address
    unordered_map<int, list<pair<int, int>>::iterator> m; // iterator stores the address
    void refresh(int key, int value){
        cache.erase(m[key]);
        cache.push_front(make_pair(key, value));
        m[key] = cache.begin();
    }
    int capacity;
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(m.find(key) != m.end()){
            refresh(key, (m[key])->second);
            return (m[key]->second);
        }
        return -1;    
    }
    
    void put(int key, int value) {
        if(m.find(key) != m.end())
            refresh(key, value);
        else{
            // Add it to the front if not found/ doesn't exist in map
            cache.push_front(make_pair(key, value));
            m[key] = cache.begin();
            if(m.size() > capacity){
                m.erase(cache.back().first); // remove from map
                cache.pop_back(); // remove from map
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
