class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        int n = encoded.size() + 1;
        int totalXor = 0;
        
        // XOR of all numbers from 1 to n
        for (int i = 1; i <= n; i++) {
            totalXor ^= i;
        }

        int encodedXor = 0;

        for (int i = 1; i < encoded.size(); i += 2) {
            encodedXor ^= encoded[i];
        }
        int first = totalXor ^ encodedXor;

        vector<int> original(n);
        original[0] = first;
        for (int i = 0; i < encoded.size(); i++) {
            original[i + 1] = original[i] ^ encoded[i];
        }

        return original;
    }
};
