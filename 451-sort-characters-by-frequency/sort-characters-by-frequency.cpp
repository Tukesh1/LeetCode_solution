class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        for(char ch:s){
            mp[ch]++;
        }
        
        vector<pair<int,int>>freqvec(mp.begin(), mp.end());
        // sort the vector that contains pair
        sort(freqvec.begin(), freqvec.end(),[](const pair<char,int>&a, const pair<char,int>&b){
            return a.second > b.second; // decrising order 
        });
        // add vector in the result
        string ans;
        for( auto& it:freqvec){
          ans.append(it.second , it.first);// append n times 
        }
        return ans;
    }
};