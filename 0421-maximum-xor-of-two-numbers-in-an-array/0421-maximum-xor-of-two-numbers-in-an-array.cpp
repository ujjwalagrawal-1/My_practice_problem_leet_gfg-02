struct Node{
    Node* links[2] = {NULL};

    bool ispresent(int n){
        return links[n] != NULL;
    }
    void put(int n,Node* node){
        links[n] = node;
    }
    Node* get(int n){
        return links[n];
    }
};
class Trie{
    private:
        Node* root;
    public : 
        Trie(){
            root = new Node();
        }
        void insert(int n){
            Node* temp = root;
            for(int i = 31;i>=0;i--){
                int bit = (n>>i)&1;
                if(!temp->ispresent(bit)){
                    temp->put(bit,new Node());
                }
                temp = temp->get(bit);
            }
        }
        int givemaximum(int n){
            int num = 0;
            Node* temp = root;
            for(int i = 31;i>=0;i--){
                int bit = (n>>i)&1;
                if(temp->ispresent(1 - bit)){
                    num |= 1<<i ;
                    temp = temp->get(1 - bit);
                }
                else{
                    temp = temp->get(bit);
                }
            }
            return num;
        }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        for(auto itr:nums){
            trie.insert(itr);
        }
        int maxnums  = 0;
        for(auto itr:nums){
            maxnums = max(maxnums,trie.givemaximum(itr));
        }

        return maxnums;
    }
};