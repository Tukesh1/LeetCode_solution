class Solution {
public:
    bool canConstruct(string s, int k) {

        // base case
        if (k > s.size())
            return false;
        unordered_map<char, int> mp;
        for (char ch : s) {
            mp[ch]++;
        }
        // char with odd count
        int cnt = 0; // odd no of char cnt
        for (auto it : mp) {
            if (it.second % 2 != 0) {
                cnt++;
            }
        }
        if(cnt >k) return false;
        return true;
    }
};