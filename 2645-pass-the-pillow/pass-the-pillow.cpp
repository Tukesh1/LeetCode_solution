class Solution {
public:
    int passThePillow(int n, int time) {
        int que = time/(n-1);
        int rem = time% (n-1);
        if(que&1)return n-rem;
        else{
            return rem+1;
        }
    }
    
};