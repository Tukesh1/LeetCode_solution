class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int n= pref.size();
        vector<int> ans(n,pref[0]);
        int curr = pref[0];
        for(int i =1 ;i< n ;i++){
            ans[i]= curr ^ pref[i];
            curr=pref[i];
        }

     return ans;
    }
};