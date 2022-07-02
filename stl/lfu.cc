class LFUCache {
public:
    LFUCache(int capacity) {
        size_ = capacity;
    }

    int get(int key) {

        if(cache_.find(key) == cache_.end()) return -1;
        update_freq(key);
        return cache_[key].value;
    }

    void update_freq(int key){
        freq_key_map_[cache_[key].freq].erase(cache_[key].pos);

        if(freq_key_map_[cache_[key].freq].size() == 0){
            freq_key_map_.erase(cache_[key].freq);
            if(cache_[key].freq == min_freq)
                min_freq++;
        }

        cache_[key].freq++;
        freq_key_map_[cache_[key].freq].push_back(key);
        cache_[key].pos = std::prev(freq_key_map_[cache_[key].freq].end());
    }

    void put(int key, int value) {

        if(size_ == 0) return;

        auto it = cache_.find(key);

        if(it == cache_.end()){
            if(cache_.size() == size_){
                // Full
                cache_.erase(freq_key_map_[min_freq].front());
                freq_key_map_[min_freq].pop_front();

                if(min_freq != 1 && freq_key_map_[min_freq].empty()){
                    freq_key_map_.erase(min_freq);
                }
            }
            KeyInfo info;
            info.value = value;
            info.freq = 1;
            cache_[key] = info;
            freq_key_map_[info.freq].push_back(key);
            cache_[key].pos = std::prev(freq_key_map_[info.freq].end());

            min_freq = 1;
        }
        else{
            cache_[key].value = value;
            update_freq(key);
        }
    }

    struct KeyInfo{
        int value;
        int freq;
        list<int>::iterator pos;
    };

    map<int, KeyInfo> cache_;
    map<int, list<int> > freq_key_map_;
    int size_;
    int min_freq;
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */