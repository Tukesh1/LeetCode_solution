class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if (n % groupSize)
            return false;
        map<int, int> mp;
        for (auto it : hand){
            mp[it]++;}

        while (!mp.empty()) {
            int curr = mp.begin()->first;
            for (int i = 0; i < groupSize; i++) {
                // check is next no in the map

                if (mp[i + curr] == 0) {
                    // no freq is left means no number presend
                    return false;
                } // if found then decrease the freq by 1
                mp[i + curr]--;
                if (mp[i + curr] < 1) {
                    mp.erase(i + curr);
                }
            }
        }
        return true;
    }
};