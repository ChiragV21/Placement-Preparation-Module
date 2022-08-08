class LRUCache {
public:
    int size;
    list<pair<int,int>> a;
    map<int,list<pair<int,int>>::iterator> m;
    LRUCache(int capacity) {
        size=capacity;
    }
    
    int get(int key) {
        if(m.find(key)==m.end())
            return -1;
        auto it=m[key];
        auto p=*it;
        a.erase(it);
        a.push_front(p);
        
        m[key]=a.begin();
        
        return p.second;
    }
    
    void put(int key, int value) {
        pair<int,int> p;
        p.first=key;
        p.second=value;
        if(m.find(key)!=m.end())
        {
            auto it=m[key];
            a.erase(it);
            a.push_front(p);
            m[key]=a.begin();
        }
        else
        {
            if(a.size()==size)
            {
                auto it= a.back();
                int k=it.first;
                a.pop_back();
                m.erase(k);
                a.push_front(p);
                m[key]=a.begin();
            }
            else
            {
                a.push_front(p);
                m[key]=a.begin();
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