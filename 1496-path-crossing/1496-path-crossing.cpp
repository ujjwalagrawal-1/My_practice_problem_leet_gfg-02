class Solution {
public:
    bool isPathCrossing(string path) {
        map<int,string> hash;
        hash[0] += '0';
        int x = 0,y = 0;
        for(int i = 0;i<path.size();i++){
            if(path[i] == 'N'){
                y++;
            }
            else if(path[i] == 'S'){
                y--;
            }
            else if(path[i] == 'E'){
                x++;
            }
            else{
                x--;
            }
            
            if(hash[x].find(y+'0') != string::npos){
               return true;
            }
            else if(hash[x].find(y+'0') == string::npos){
                hash[x] += y +'0';
            }
            cout<<"x is "<<x<<"   "<<hash[x]<<endl;
        }
            return false;
    }
};