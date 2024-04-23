class Solution {
public:
    bool isValid(string s) {
        stack<char> st;	
	int i = 0;
        while(i<s.size()){
		if(s[i] != 'c'){
			st.push(s[i]);
		}
		else{
			if(st.size() >= 2){
				if(st.top() == 'b'){
					st.pop();
					if(st.top() == 'a'){
					st.pop();
					}
					else{return false;}
				}
				else{
					return false;
				}
			}
			else{
				return false;
			}
		}
        i++;
	}
	return 1;
	
    }
};