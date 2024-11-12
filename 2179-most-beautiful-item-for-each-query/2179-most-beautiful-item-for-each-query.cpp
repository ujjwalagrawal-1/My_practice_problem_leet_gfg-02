class Solution {
public:
    // Function to find the upper bound index
    int upperb(vector<vector<int>>& items, int s, int e, int tag) {
        int ans = -1; // Initialize ans to -1, indicating not found
        while(s <= e){
            int mid = s + (e - s) / 2;
            if(items[mid][0] > tag){
                ans = mid;
                e = mid - 1;
            }
            else{
                s = mid + 1;
            }
        }
        return ans;
    }

    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        // Sort items by price
        sort(items.begin(), items.end());

        vector<int> maxBeauty(items.size());
        maxBeauty[0] = items[0][1];
        for(int i = 1; i < items.size(); i++) {
            maxBeauty[i] = max(maxBeauty[i-1], items[i][1]);
        }

        vector<int> result(queries.size());

        for(int i = 0; i < queries.size(); i++) {
            int query = queries[i];
            int idx = upperb(items, 0, items.size() - 1, query);
            if (idx == -1) {
                result[i] = maxBeauty[items.size() - 1];
            } else if (idx == 0) {
                result[i] = 0;
            } else {
                result[i] = maxBeauty[idx - 1];
            }
        }
        return result;
    }
};