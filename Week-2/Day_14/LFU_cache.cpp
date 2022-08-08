class LFUCache {
    unordered_map<int,pair<pair<int,int>,list<int>::iterator>> hash; 
    map<int,list<int>> used;
    int capacity;
public:
    LFUCache(int _capacity) : capacity(_capacity) {
        
    }
    
    int get(int key) {
        if (hash.count(key))
        {
            used[hash[key].first.second].erase(hash[key].second);  
            if (used[hash[key].first.second].empty()) used.erase(hash[key].first.second); 
            hash[key].first.second++;   
            used[hash[key].first.second].push_front(key);  
            hash[key].second = used[hash[key].first.second].begin(); 
            return (hash[key].first.first);        
        }
        else 
            return -1;
    }
    
    void put(int key, int value) {
        if (hash.count(key))
        {
            hash[key].first.first = value;  
            used[hash[key].first.second].erase(hash[key].second);
            if (used[hash[key].first.second].empty()) used.erase(hash[key].first.second);   
            hash[key].first.second++;   
            used[hash[key].first.second].push_front(key);  
            hash[key].second = used[hash[key].first.second].begin();   
            return;
        }
        if (capacity==0)
        {
            if (used.empty()) return;       
            int k = used.begin()->second.back();  
            used.begin()->second.pop_back();      
            if (used.begin()->second.empty()) used.erase(used.begin());   
            hash.erase(k); 
            capacity++;    
        }
        used[1].push_front(key); 
        list<int>::iterator it = used[1].begin();
        hash[key] = {{value,1},it};  
        capacity--;  
    }
};