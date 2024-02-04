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
           // cout<<high<<endl;
            while(low < high){
                int sum = nums[i] + nums[low]+ nums[high];// one num is fixed 
                //we are searching for the other two number now 
                if(sum == target){
                    return target;
                }
                else if(sum < target){
                    low++ ;
                }
                else{
                    high--;
                }

                int Diff_to_Target = abs(sum - target);
                if(Diff_to_Target < minDiff){
                 resultSum = sum ;
                 minDiff = Diff_to_Target;
                }
               
            }
        }
        return resultSum;

    }
};