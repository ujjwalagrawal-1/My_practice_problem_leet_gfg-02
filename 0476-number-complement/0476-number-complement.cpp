class Solution {
public:
    int findComplement(int num) {
        int digi  = log2(num)+1;
        cout<<digi<<endl;
        long long a = ((1ll<<digi) - 1);
        return num ^ a;
    }
};