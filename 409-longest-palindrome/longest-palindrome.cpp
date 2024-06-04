class Solution {
public:
    int longestPalindrome(string s) {
        int OddCount= 0;
        int n= s.size();
        unordered_map<char,int>mp;
        for(auto c:s){
            mp[c]++;
            if(mp[c]% 2 ==1){
                OddCount++;
            }
            else{
                OddCount--;
            }
        }
        
        return OddCount>1 ?(n-OddCount+1):n;
    }
};