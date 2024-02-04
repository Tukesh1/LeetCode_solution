class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int resultSum = nums[0]+ nums[1]+nums[2];
        int minDiff = INT_MAX;
        //lets search for the rest two number 
        for(int i =0 ;i<nums.size()-2;i++){
            int low = i+1 ;
            int high = nums.size()-1 ;
            while(low < high){
                int sum = nums[i] + nums[low]+ nums[high];
                if(sum == target){
                    return target;
                }
                else if(sum < target){
                    low++ ;
                }
                else{
                    high--;
                }
                int DiffToTarget = abs(sum - target);
                if(DiffToTarget < minDiff){
                 resultSum = sum ;
                 minDiff = DiffToTarget;
                }
               
            }
        }
        return resultSum;

    }
};