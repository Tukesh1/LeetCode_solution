class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int s= nums.size();
        int count =0 ;
        int maxCount =0;
        for(int i =0 ;i< s;i++){
            if(nums[i]==1){
                count +=1;
            }
            else{
                count =0;
            }
          maxCount = max(count, maxCount);
        }

        return maxCount;
        
    }
};