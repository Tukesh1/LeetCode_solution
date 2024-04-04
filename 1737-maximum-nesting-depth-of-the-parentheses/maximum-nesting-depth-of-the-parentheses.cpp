class Solution {
public:
    int maxDepth(string s) {
        int count = 0;
        int max_ct =0 ;
        for(auto c:s){
            if(c =='('){
                count++;
                if(count > max_ct){
                    max_ct = count;
                }
            }
            if(c==')'){
                count--;
            }
        }
        return max_ct;
    }
};