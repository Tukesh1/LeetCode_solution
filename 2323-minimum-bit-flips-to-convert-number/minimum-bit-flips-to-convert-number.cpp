class Solution {
public:
    vector<int> inBinary(int n){
        int idx=0 ;
        vector<int> bn(35,0);
       while(n>0){ 
        bn[idx]= n%2;
        n= n/2;
        idx++;
       }
       return bn;
    }
    int minBitFlips(int start, int goal) {
       // convert in binary 
       int flip = 0;
       vector<int> st= inBinary(start);
        vector<int> go= inBinary(goal);
        int s_size = st.size();
        int g_size= go.size();
        while(s_size--){
            if(st[s_size] != go[s_size]){
             flip ++;
            }
        }
        return flip ;

    }
};