class Solution {
public:
    int countSeniors(vector<string>& details) {
      
        int cnt =0 ;
        for(int i =0 ;i<details.size();i++){
           string str= details[i];
           //7868190130M 75 22
           char once= str[12];
           char tens= str[11];
           if(tens >'6' || ( tens =='6' && once >'0'))cnt++;
        }
        return cnt;
    }
};