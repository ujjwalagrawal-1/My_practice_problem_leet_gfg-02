class Solution {
public:
// vector<int> f(vector<int>& temp){
    
    // while(i>=0){
    //     while(!st.empty() && st.top() <= temp[i]){
    //         st.pop();
    //     }
    //     ans[i] = st.top();
    //     st.push(temp[i]);
    //     i--;
    // }


    // for(int i = 0;i<ans.size();i++){
    //     if(ans[i] == INT_MAX){
    //         ans[i] = 0;
    //         continue;
    //     }
    //     else{
    //         int a = temp[i];
    //         int b = ans[i];
    //         int j = INT_MAX;
    //         int k = 0;
    //         while(b != j){
    //             j = temp[i+k];
    //             k++;
    //         }
    //         k--;
    //         ans[i] = k;
    //     }
    // }
    // return ans;
// }
    vector<int> dailyTemperatures(vector<int>& temp) {
        // return f(temp);
        stack<int> st;
        int n = temp.size();
        st.push(n-1);
        vector<int> ans(n,0);

        for(int i=n-2;i>=0;i--){
            while(!st.empty() && temp[i] >= temp[st.top()]) st.pop();

            if(st.empty()){
                ans[i]=0;
            }
            else{
                ans[i]= st.top()-i;
            }
            st.push(i);
        }
        return ans;
    }
};