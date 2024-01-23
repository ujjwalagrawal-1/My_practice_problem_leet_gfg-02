class Solution {
public:
int solve_using_recursion(vector<string>& arr,set<char> st,int ind){
    if(ind >= arr.size()){
        return 0;
    }
    int Not_take = solve_using_recursion(arr,st,ind+1);
    bool flag = 1;
    for(auto itr:arr[ind]){
        if(st.find(itr) == st.end()){
            st.insert(itr);
        }
        else{
            flag = false;
            break;
        }
    }
    int take = 0;
    if(flag)
    take = solve_using_recursion(arr,st,ind+1) + arr[ind].size();
    return max(Not_take,take);
}
    int maxLength(vector<string>& arr) {
        set<char> st;int ind = 0;
        return solve_using_recursion(arr,st,ind);
    }
};