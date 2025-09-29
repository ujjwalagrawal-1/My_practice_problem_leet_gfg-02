class dll{
    public:
    int key,val;
    dll* prev = nullptr;
    dll* next = nullptr;
    dll(int key,int val){
        this->key = key;
        this->val = val;
        this->prev = nullptr;
        this->next = nullptr;
    }
};
class LRUCache {
public:
    dll *head,*tail;
    int cnt = 0;
    map<int,dll*> mp;
    LRUCache(int capacity) {
        head = new dll(-1,-1);
        tail = new dll(-1,-1);
        head->next = tail;
        tail->prev = head;
        this->cnt = capacity;
    }
    void deletenode(dll* node){
        dll* prev = node->prev;
        dll* nxt = node->next;
        prev->next = nxt;
        nxt->prev = prev;
        node->prev = nullptr;
        node->next = nullptr;
    }
    void insertnode(dll* node){
        dll* temp = head->next;
        node->next = head->next; 
        node->prev = head;
        head->next = node;
        temp->prev = node;
    }
    int get(int key) {
        if(mp.count(key)){
            dll* temp = mp[key];
            deletenode(temp);
            insertnode(temp);
            return temp->val;
        }
        else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(mp.count(key)){
            dll* temp = mp[key];
            temp->val = value;
            deletenode(temp);
            insertnode(temp);
        }
        else{
            if(!cnt){
                dll* node = tail->prev;
                deletenode(node);
                mp.erase(node->key);
                node->key = key;
                node->val = value;
                mp[key] = node;
                insertnode(node);
            }
            else{
                cnt--;
                dll* newnode = new dll(key,value);
                mp[key] = newnode;
                insertnode(newnode);
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