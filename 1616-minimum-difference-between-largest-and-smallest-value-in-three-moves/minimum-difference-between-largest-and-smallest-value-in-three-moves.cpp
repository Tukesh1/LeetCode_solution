class Solution {
public:
    int minDifference(vector<int>& nums) {
        //minimum difference between the largest and smallest value
        //after 3 operation
        sort(nums.begin(), nums.end());
        // start small -> lrage 
        int minVal = INT_MAX;
        int n= nums.size();
        if(n<4) return 0;
        minVal= min(minVal,nums[n-4]- nums[0]);
        minVal=min(minVal,nums[n-1]- nums[3]);
        minVal= min(minVal,nums[n-2]- nums[2]);
        minVal=min(minVal,nums[n-3]- nums[1]);
        return minVal;

    }
};