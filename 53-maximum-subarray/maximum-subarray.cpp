class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // kadens algorithm 
        int ans=INT_MIN;
        int sum =0;

        for(int i =0 ;i<nums.size();i++){
                sum +=nums[i];
                ans = max(ans,sum);
                if(sum <0) sum =0 ;
        }
            return ans;
    }
};