class Solution {
public:
      int minInsertions(string s) {
        int n=s.size();
        stack<char>stk;
        int minInsert=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                stk.push(s[i]);
            }
            else 
            {
                if( s[i] == ')' && i < n && s[i + 1] == ')')
                {
                    if(!stk.empty())
                    {
                       stk.pop();
                    }
                    else
                    {
                        minInsert++;
                    }
                    
                    i++;
                }
                
                else if(s[i] == ')' && i < n && s[i + 1] != ')' ) {
                    if(!stk.empty()){
                        stk.pop();
                        minInsert++;
                    }
                    else minInsert += 2;
                
            }
        }
        
    }
    return minInsert+2*stk.size();
    }
};