// Implement cache with two methods get(), which given a key returns a value if 
// it is in the cache, and put() which given a key and a value associates the key 
// to the value in the cache. If a key is already in the cache, a put() operation 
// replaces the old association with the new one.



// Master (Writes)
// Slave Kafka to write adn read from master

// key: string
// value string
// upper limit: k entries
// oldest value to replace in case of LRU

struct CacheSorter{
    bool operator()(const Node& first, const Node& second){
        return first.timestamp < second.timestamp;
    }
}


class Cache{
public:
    struct Node{
        long timestamp;
        std::string value;
    };
    Cache(int max_size);
    // return the cache value
    std::string get(std::string& key);  
    void put(std::string& key, std::string& value);
private:
    void handleOverflow();
private:
    typedef std::map<std::string, std::string>::iterator MapIterator;
    std::map<std::string, Node> cache_;
    std::priority_queue<MapIterator, std::vector<MapIterator>, CacheSorter> sorter_;
    int max_size_;
    std::recursive_mutex lock_;
};

Cache::Cache(int max_size) : max_size_(max_size) {}

void Cache::handleOverflow(){ // O(1)
    if(cache_.size() > max_size_){
        auto to_remove = sorter_.top();
        sorter_.pop();
        cache_.erase(to_remove); 
    }
}


std::string Cache::get(std::string& key){
    // TODO protect in case of multithreaded access
    std::unique_lock<std::recursive_mutex> guard(lock_);
    auto it = cache_.find(key);
    if(it != cache_.end()){
        // found id
        it->timestamp = time();
        return it->value;
    }
    throw std::runtime_error("Unable to find entry in cache");
}

void Cache::put(std::string& key, std::string& value){
    std::unique_lock<std::recursive_mutex> guard(lock_);
    handleOverflow();
    // Overwrite in case of collision
    Node n;
    n.value = value;
    n.timetamp = time();
    cache_[key] = n;
    
    auto it = cache_.find(key);
    sorter_.push(it);
}
