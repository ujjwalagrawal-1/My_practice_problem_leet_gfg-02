class Solution {
public:
bool f(int grp,vector<int>& grades){
    
    if((1ll*(grp)*(grp+1))/2 > grades.size()){
        return false;
    }
    else{
        return 1;
    }
}
    int maximumGroups(vector<int>& grades) {
        int s = 0;
        int e = grades.size();
        while(s <= e){
            int mid = s + (e -s)/2;

            if(f(mid,grades)){
                s = mid + 1;
            }
            else{
                e = mid-1;
            }
        }

        return e;
    }
};