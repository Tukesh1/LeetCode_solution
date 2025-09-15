class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
       /* sort(s.begin(),s.end());
        sort(t.begin(), t.end());
        if(s!=t) return false;
        return true;     //brute force solution
        */


        //using hashmap
        unordered_map<char,int>s_mp;
        unordered_map<char,int>t_mp;
        for(int i=0;i<s.size();i++){
            s_mp[s[i]]++;
            t_mp[t[i]]++;
        }
        for (auto &p : s_mp) {
            if (t_mp[p.first] != p.second) return false;
        }
        return true;
    }
};