class Solution {
public:
    int firstUniqChar(string s) {
      // hashmap ka use kr k 
      vector<int> store(26);
      for(auto i:s) store[i-'a']++;
      //first character with frequency 1 is the answer 
      for(int i =0 ;i< s.size();i++){
          if(store[s[i]-'a']==1) return i;
      }
      return -1;
    }
};