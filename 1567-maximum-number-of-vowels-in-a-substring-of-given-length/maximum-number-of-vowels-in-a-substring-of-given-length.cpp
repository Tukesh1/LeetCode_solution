class Solution {
public:
    int maxVowels(string s, int k) {
        int i=0,j=0;
        int n= s.size();
        // lenda function 
        auto isVowel =[&](char ch){
            return ch == 'a'||ch == 'e'||ch == 'i'||ch == 'o'||ch == 'u' ;
        } ;
        int cnt= 0;
        int maxCnt=0 ;
        while(j<n){
            if(isVowel(s[j])){
                cnt++;
            }
            if(j-i+1 == k){
                maxCnt= max(maxCnt, cnt);
                if(isVowel(s[i])){
                    cnt--;
                
                }
                i++;
            }
            j++;
        }
        return maxCnt;
    }
};