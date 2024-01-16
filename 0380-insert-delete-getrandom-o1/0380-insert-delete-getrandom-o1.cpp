class RandomizedSet {
public:
    set<int> s;
    RandomizedSet() {

    }
    
    bool insert(int val) {
        if(s.find(val) != s.end()){
            return false;
        }
        else{
        s.insert(val);
        return true;
        }
    }
    
    bool remove(int val) {
        if(s.find(val) != s.end()){
            s.erase(val);
            return true;
        }
        return false;
    }

    int getRandom() {
        auto randIndex = rand() % s.size();
        auto it =begin(s);
        advance(it, randIndex);
        return *it;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */