class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int cnt =0 ;
        int maxsum = 0;
        for(int i=0 ;i<nums.size()-1;i++){
          if(nums[i+1]<= nums[i]){
            int c_sum = nums[i]- nums[i+1]+1;
            nums[i+1] += c_sum;
            cnt += c_sum;

          }
        }
        return cnt;
    }
};