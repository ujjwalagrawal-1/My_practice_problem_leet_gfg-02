class Solution {
public:
    bool winnerOfGame(string colors) {
        int threeA = 0;
        int threeB = 0;
        int sz = colors.size();
        for(int indx = 1; indx < sz - 1; indx++){
            if(colors[indx] == 'A' && colors[indx+1] == 'A' && colors[indx-1] == 'A'){

               threeA++;
            }else if(colors[indx] == 'B' && colors[indx+1] == 'B' && colors[indx-1] == 'B'){
                threeB++;
            }
        }
        return threeA > threeB;
    }
};