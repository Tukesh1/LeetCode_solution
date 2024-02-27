class Solution {
public:
    vector<int> findDuplicates(vector<int>& vec) {
        
        unordered_map<int, int> ump;
        for(auto i : vec) {
            ump[i]++;
           // cout<<i<<" "<<ump[i]<<endl;
            }
        
        vector<int> ans;
        for(int i=0;i<vec.size();i++) {
           //  cout<<ump[vec[i]]<<endl ;
            if(ump[vec[i]] > 1) {
                ans.push_back(vec[i]);
                ump[vec[i]]--;
            }
        }
        return ans;
    }
};