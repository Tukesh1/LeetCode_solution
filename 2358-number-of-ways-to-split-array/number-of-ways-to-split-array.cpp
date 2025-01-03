class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int cnt=0;
        int n= nums.size();
        long long int sum = accumulate(nums.begin(), nums.end(),0LL);
        long long int acc= 0LL;
        for(int i=0;i<n-1;i++){
          acc += nums[i];
          cnt+= (2*acc >= sum);
        }
        return cnt;
    }
};