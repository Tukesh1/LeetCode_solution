class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        vector<int>sol(2*n);
        for(int i =0 ;i< n;i++){
            sol[i]= nums[i];
            sol[i+n]= nums[i];
        }
        return sol;

    }
};