class LRUCache {
public:
    int cap;
    list<int> lru;
    unordered_map<int, pair<int, list<int>::iterator>> mp;

    LRUCache(int capacity) {
        cap = capacity;    
    }
    
    int get(int key) {
        if(!mp.count(key)) return -1;
        lru.erase(mp[key].second);
        lru.push_back(key);
        mp[key].second = --lru.end();
        return mp[key].first;
    }
    
    void put(int key, int value) {
        if(mp.count(key)){
            lru.erase(mp[key].second);
        }
        else if (mp.size()==cap){
            int recent = lru.front();
            lru.pop_front();
            mp.erase(recent);
        }
        lru.push_back(key);
        mp[key] = {value, --lru.end()};
    }
};
