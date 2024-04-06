class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int>st;
        for(int i =0 ;i< s.size();i++){
            if(s[i] == '('){
                st.push(i);
            }
            else if(s[i] == ')'){
                if(!st.empty()){
                    st.pop();
                }
                else{
                    s[i] = '*'; // this is done so that in the last it can be removed from the
                    // string 
                }
            }
        }

        // if ( is left in stack then make it also *
        while(!st.empty()){
              s[st.top()] = '*'; // as the top of the stack contains the index of the 
              // s where ( is present 
              st.pop();  
        }

        // remove the * from the string and get your ans 
        string ans ="";
        for(auto c :s){
        if(c != '*'){
            ans += c;
        }
        }
      return ans;
    }
};