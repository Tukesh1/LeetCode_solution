class Solution {
public:
    int scoreOfString(string s) {
        int diff = 0;
        for(int i= 1;i<s.size();i++){
            diff += abs(s[i] -s[i-1]);
        }
        return diff;
    }
};