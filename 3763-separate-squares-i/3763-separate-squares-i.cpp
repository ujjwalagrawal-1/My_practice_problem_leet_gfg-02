typedef double ld;

class Solution {
public:
    double separateSquares(vector<vector<int>>& sq) {
        ld maxi = 0;
        
        for(int i = 0; i < sq.size(); i++) {
            maxi = max(maxi, double(sq[i][1] + sq[i][2]));
        }
        
        ld s = 0;
        ld e = maxi;
        
        while (e - s > 1e-5) {
            ld mid = s + (e - s) / 2.0;
            ld up = 0;
            ld down = 0;
            
            for (int i = 0; i < sq.size(); i++) {
                ld y = sq[i][1];
                ld size = sq[i][2];

                if (mid <= y) {
                    up += size * size;
                }
                else if (mid >= y + size) {
                    down += size * size;
                }
                else {
                    up += ((y + size) - mid) * size;
                    down += (mid - y) * size;
                }
            }
            
            if (up > down) {
                s = mid; 
            } else {
                e = mid;
            }
        }
        
        return s;
    }
};
