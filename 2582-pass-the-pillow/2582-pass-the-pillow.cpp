class Solution {
public:
    int passThePillow(int n, int time) {
        int ch = time / (n - 1);
        return ch % 2 == 0 ? (time % (n - 1) + 1) : (n - time % (n - 1));
    }
};