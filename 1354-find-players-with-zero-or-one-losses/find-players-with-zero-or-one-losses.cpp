class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, pair<int, int>> mp;
        for(auto i : matches){
            mp[i[0]].first++;
            mp[i[1]].second++;
        }
        vector<vector<int>> sol(2);
        for(auto [i,v]: mp){
            if(v.second == 0) sol[0].push_back(i);
            if(v.second == 1) sol[1].push_back(i);

        }

     return sol;
    }
};