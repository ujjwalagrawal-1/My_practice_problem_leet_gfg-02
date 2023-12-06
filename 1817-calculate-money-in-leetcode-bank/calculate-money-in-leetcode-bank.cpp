class Solution {
public:
int find(int n){
    return (n*(n+1))/2;
}
    int totalMoney(int n) {
        int hafta = n/7;
        int days_left = n%7;int i = 0;
        int ans = 0;
        while(i<hafta){
            ans += find(7+i) - find(i);
            i++;
        }
        while(days_left--){
            ans += ++i;
        }

        return ans;
    }
};