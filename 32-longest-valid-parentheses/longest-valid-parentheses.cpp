class Solution {
public:
    int longestValidParentheses(string s) {
        int max_ct =0 ;
        stack<int>st;
        st.push(-1);
        for(int i = 0 ;i< s.size();i++){
        if(s[i] == '(') {
            st.push(i);
        }
        else{
            st.pop();
            if(st.empty())st.push(i);
            else{
              max_ct = max(max_ct , i - st.top());
            } 
        }
        }
        return max_ct;
    }
};