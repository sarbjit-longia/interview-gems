//The functions get and put must each run in O(1) average time complexity.

class LRUCache {
public:
    LRUCache(int capacity) : cap_(capacity) {

    }

    int get(int key) {
        auto it = cache_.find(key);
        if(it == cache_.end()) return -1;

        keys_.erase(it->second.second);
        keys_.push_front(it->first);
        it->second.second = keys_.begin();
        return it->second.first;
    }

    void put(int key, int value) {
        auto it = cache_.find(key);
        if(it != cache_.end()){
            keys_.erase(it->second.second);
            keys_.push_front(it->first);
            it->second.first = value;
            it->second.second = keys_.begin();
        }
        else{
            if(cache_.size() >= cap_){
                auto k = keys_.back(); keys_.pop_back();
                cache_.erase(k);
            }
            keys_.push_front(key);
            cache_[key] = std::make_pair(value, keys_.begin());
        }
    }

    int cap_;

    unordered_map<int, std::pair<int, std::list<int>::iterator > > cache_;
    list<int> keys_;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */