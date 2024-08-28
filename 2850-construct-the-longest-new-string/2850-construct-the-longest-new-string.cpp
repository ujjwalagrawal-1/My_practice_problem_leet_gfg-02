class Solution {
public:
    int longestString(int x, int y, int z) {
        int ans = min({x,y,z});
        int val = INT_MIN;
        x -= ans;
        y -= ans;
        z -= ans;
        int e = 0;
        if(x > 0 && y > 0){
            e = x != y ? (2*min(x,y))+1 : 2*x;
        }
        else if(y > 0 &&  z > 0){
            e = (z + 1);
        }
        else if(x > 0 && z > 0){
            e = (z + 1);
        }
        else{
            if(z > 0){
                e = z;
            }
            else if(x > 0){
                e = 1;
            }
            else if(y > 0){
                e = 1;
            }

        }
        return ans*6 + e*2;
    }
};